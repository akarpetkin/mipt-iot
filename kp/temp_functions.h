#include <inttypes.h>
#include <stdbool.h>

#ifndef TEMP_FUNCTIONS_H_INCLUDED
#define TEMP_FUNCTIONS_H_INCLUDED

#define CSV_COLUMNS_NUMBER 6
#define MAX_RESULT_SIZE 13
#define MIN_TEMPERATURE -99
#define MAX_TEMPERATURE 99
#define MAX_ROW_SIZE 255

typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
} sensor_t;

typedef struct {
    uint32_t size;
    sensor_t *data;
    uint32_t errors;
    uint32_t *successByMonth;
} sensors_t;

typedef struct {
    uint8_t month;
    int32_t total;
    uint32_t count;
    int8_t min;
    int8_t max;
} statistic_t;

bool validateSensor(sensor_t sensor);

sensors_t loadFromCsv(const char *fileName);

statistic_t* initStatistics();

void calcResults(sensors_t sensors, uint8_t selectedMonth, statistic_t *stats);

void printStatistic(statistic_t *stats, bool isSelectedMonth, sensors_t sensors);

#endif