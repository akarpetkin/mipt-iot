#include <stdio.h>

const char INPUT_FILENAME[] = "input.txt";
const char RESULT_FILENAME[] = "output.txt";
const int MAX_STRING_SIZE = 1000;

int collectResult(signed char result[]) {
    FILE *inFile = fopen(INPUT_FILENAME, "r");
    int resultIdx = 0;

    signed char ch = fgetc(inFile);
    while (ch != EOF && resultIdx < MAX_STRING_SIZE) {
        switch (ch) {
            case 'a':
                result[resultIdx] = ch + 1;
            break;

            case 'A':
                result[resultIdx] = ch + 1;
            break;

            case 'b':
                result[resultIdx] = ch - 1;
            break;

            case 'B':
                result[resultIdx] = ch - 1;
            break;
  
            default:
                result[resultIdx] = ch;
        }

        resultIdx++;
        ch = fgetc(inFile);
    }

    fclose(inFile);
    return resultIdx;
}

void writeResut(signed char result[], int size) {
    FILE *outFile = fopen(RESULT_FILENAME, "w");

    for (int i = 0; i < size; i++) {
        fprintf(outFile, "%c", result[i]);
    }

    fclose(outFile);
};

int main(void) {   
    signed char result[MAX_STRING_SIZE];
    int resultIdx = collectResult(result);

    writeResut(result, resultIdx);
    
    return 0;         
} 