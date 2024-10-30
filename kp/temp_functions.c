#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "temp_functions.h"

bool validateSensor(sensor_t sensor) {
    if (sensor.month < 1 || sensor.month > 12) {
        return false;
    }
    if (sensor.day < 1 || sensor.day > 31) {
        return false;
    }
    if (sensor.hour < 0 || sensor.hour > 24) {
        return false;
    }
    if (sensor.minute < 0 || sensor.minute > 60) {
        return false;
    }
    if (sensor.temperature < MIN_TEMPERATURE || sensor.temperature > MAX_TEMPERATURE) {
        return false;
    }

    return true;
}

sensors_t loadFromCsv(const char *fileName) {
    sensors_t sensors;
    sensors.size = 0;

    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return sensors;
    }

    uint32_t maxRecords = 0;
    char row[MAX_ROW_SIZE];
    while (!feof(file)) {
        fgets(row, MAX_ROW_SIZE, file);
        maxRecords++;
    }       

    sensors.data = (sensor_t*)malloc(maxRecords * sizeof(sensor_t));
    sensors.size = 0;  
    sensors.errors = 0;

    sensors.successByMonth = (uint32_t*)malloc(MAX_RESULT_SIZE * sizeof(uint32_t));
    memset(sensors.successByMonth, 0, MAX_RESULT_SIZE * sizeof(uint32_t));

    rewind(file);       

    sensor_t sensor;
    uint8_t read = 0;
    do {
        read = fscanf(file, "%"SCNu16";%"SCNu8";%"SCNu8";%"SCNu8";%"SCNu8";%"SCNi8"\n",
                      &sensor.year,
                      &sensor.month,
                      &sensor.day,
                      &sensor.hour,
                      &sensor.minute,
                      &sensor.temperature);

        if (read == CSV_COLUMNS_NUMBER && validateSensor(sensor)) {
            sensors.data[sensors.size] = sensor;
            sensors.size++;

            sensors.successByMonth[sensor.month] = sensors.successByMonth[sensor.month] + 1;
            sensors.successByMonth[0] = sensors.successByMonth[0] + 1;
        } else {
            fgets(row, MAX_ROW_SIZE, file);
            printf("File format incorrect in row: %s\n", row);
            sensors.errors++;
        }
        
        if (ferror(file)) {
            printf("Error reading file.\n");
            return sensors;
        }

    } while (!feof(file));

    fclose(file);

    return sensors;
}

statistic_t* initStatistics() {
    statistic_t *stats = (statistic_t*)malloc(MAX_RESULT_SIZE * sizeof(statistic_t));

    for (uint8_t i = 0; i < MAX_RESULT_SIZE; i++ ) {
        stats[i].month = i;
        stats[i].total = 0;
        stats[i].count = 0;
        stats[i].min = MAX_TEMPERATURE + 1;
        stats[i].max = MIN_TEMPERATURE - 1;
    }

    return stats;
}

void calcResults(sensors_t sensors, uint8_t selectedMonth, statistic_t *stats) {
    for (uint32_t i = 0; i < sensors.size; i++) {
        if (selectedMonth !=0 && sensors.data[i].month != selectedMonth) {
            continue;
        }

        uint8_t month = sensors.data[i].month;
        stats[month].total += sensors.data[i].temperature;
        stats[month].count++;

        if (stats[month].max < sensors.data[i].temperature) {
            stats[month].max = sensors.data[i].temperature;
        }
        if (stats[month].min > sensors.data[i].temperature) {
            stats[month].min = sensors.data[i].temperature;
        }
      
        // yearly
        stats[0].total += sensors.data[i].temperature;
        stats[0].count++;

        if (stats[0].max < sensors.data[i].temperature) {
            stats[0].max = sensors.data[i].temperature;
        }
        if (stats[0].min > sensors.data[i].temperature) {
            stats[0].min = sensors.data[i].temperature;
        }
    }
}

void printStatistic(statistic_t *stats, bool isSelectedMonth, sensors_t sensors) {
    if (sensors.errors > 0) {
        printf("Total error rows: %d\n", sensors.errors);
    }

    printf("Monthly statistics:\n");
    printf("%-10s%-10s%-10s%-10s%-10s\n", "Month", "Rows", "Avg", "Min", "Max");
    
    for (uint32_t i = 1; i < MAX_RESULT_SIZE; i++) {
        if (stats[i].count > 0) {
            printf("%-10d%-10d%-9.2f%-9d%-9d\n",
                stats[i].month, 
                sensors.successByMonth[i],
                (float)stats[i].total / stats[i].count,
                stats[i].min,
                stats[i].max);
        }
    }

    if (stats[0].count > 0 && !isSelectedMonth) {
        printf("Yearly statistics:\n");
        printf("Avg: %2.2f Min: %2d Max: %2d\n",
            (float)stats[0].total / stats[0].count,
            stats[0].min,
            stats[0].max);
    }
}