#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const char INPUT_FILENAME[] = "input.txt";
const char RESULT_FILENAME[] = "output.txt";
const int MAX_STRING_SIZE = 1000;

int collectResult(signed char result[]) {
    FILE *inFile = fopen(INPUT_FILENAME, "r");
    int resultIdx = 0;

    signed char ch = fgetc(inFile);
    while (ch != EOF && resultIdx < MAX_STRING_SIZE) {
        if (isdigit(ch)) {
            result[resultIdx] = ch;
        } else {
            result[resultIdx] = ' ';
        }

        resultIdx++;

        ch = fgetc(inFile);
    }

    fclose(inFile);
    return resultIdx;
}


void swap(int n[], int i, int j) {
    int temp = n[i];
    n[i] = n[j];
    n[j] = temp;
}

void bubbleSort(int n[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (n[j] > n[j + 1])
                swap(n, j, j + 1);
        }
    }
}

int convertToNumbers(signed char result[], int size, int numbers[]) {
    char *token = strtok(result, " "); 
    int numbersIdx = 0;

    while (token != NULL) {
        if (isdigit(*token)) {
            numbers[numbersIdx] = atoi(token);
            numbersIdx++;
        }
            
        token = strtok(NULL, " ");
    } 

    return numbersIdx;
}

void writeResult(int result[], int size) {
    FILE *outFile = fopen(RESULT_FILENAME, "w");

    if (size > 0) {
        fprintf(outFile, "%d", result[0]);
        for (int i = 1; i < size; i++) {
            fprintf(outFile, " %d", result[i]);
        }
    }

    fclose(outFile);
};

int main(void) {   
    signed char result[MAX_STRING_SIZE];
    int numbers[MAX_STRING_SIZE];

    int resultIdx = collectResult(result);
    int numbersIdx = convertToNumbers(result, resultIdx, numbers);

    bubbleSort(numbers, numbersIdx);
    writeResult(numbers, numbersIdx);

    return 0;         
} 