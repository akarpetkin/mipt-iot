#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"

#define DEFAULT_FILENAME "temperature_big.csv"

int main(int argc, char *argv[]) {   
    char *fileName = DEFAULT_FILENAME;
    uint8_t selectedMonth = 0;

    int ch = 0;
    opterr = 0;
    while ( (ch  = getopt(argc, argv,"f:m:h")) != -1){
        switch (ch) {
            case 'f': 
                fileName = optarg;
                break;

            case 'm':
                selectedMonth = atoi(optarg);
                break;

            case 'h': 
                printf("Usage: temp [options]\n -h This help text\n");
                printf("-f Specify path to CSV file (default is temperature_big.csv).\n");
                printf("-m Specify month number (not required).\n\n");
                printf("Example: %s -f temperature_big.csv\n", argv[0]);
                return 0;
            case '?': 
                printf("Unknown argument: %s Try -h for help\n", argv[optind-1]);
                return 0;  
        }
    }

    sensors_t sensors = loadFromCsv(fileName);
    if (sensors.size > 0) {
        statistic_t *stats = initStatistics();

        calcResults(sensors, selectedMonth, stats);
        printStatistic(stats, selectedMonth > 0, sensors);

        if (stats != NULL) {
            free(stats);
        }
    }

    if (sensors.data != NULL) {
        free(sensors.data);
    }
    if (sensors.successByMonth != NULL) {
        free(sensors.successByMonth);
    }
    
    return 0;         
} 