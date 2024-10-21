#include <stdio.h>
#include <string.h>

const char INPUT_FILENAME[] = "input.txt";
const char RESULT_FILENAME[] = "output.txt";
const int MAX_STRING_SIZE = 10000;

void collectResult(int *n, int *m) {
    FILE *inFile = fopen(INPUT_FILENAME, "r");

    signed char ch = fgetc(inFile);
    int i = 1;
    while (ch != EOF && i < MAX_STRING_SIZE) {
        if (ch >= 'A' && ch <= 'Z') {
            *m = *m + 1;
        }
        if (ch >= 'a' && ch <= 'z') {
            *n = *n + 1;
        }

        ch = fgetc(inFile);
        i++;
    }

    fclose(inFile);
}

void writeResult(int n, int m) {
    FILE *outFile = fopen(RESULT_FILENAME, "w");
    fprintf(outFile, "%d %d", n, m);

    fclose(outFile);
};


int main(void) {   
    int n, m = 0;

    collectResult(&n, &m);
    writeResult(n, m);

    return 0;         
} 