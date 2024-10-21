#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char INPUT_FILENAME[] = "input.txt";
const char RESULT_FILENAME[] = "output.txt";
const int MAX_STRING_SIZE = 1000;

int getCharIndex(signed char ch, signed char st[], int size) {
    for (int i = 0; i < size; i++) {
        if (st[i] == ch) {
            return i;
        }
    }

    return -1;
}

void collectResult(signed char result[]) {
    FILE *inFile = fopen(INPUT_FILENAME, "r");
    int resultIdx = 0;

    signed char ch = fgetc(inFile);
    while (ch != EOF && resultIdx < MAX_STRING_SIZE) {
        if (getCharIndex(ch, result, resultIdx) == -1 && ch != ' ') {
            result[resultIdx] = ch;
            resultIdx++;
        }

        ch = fgetc(inFile);
    }

    result[resultIdx] = '\0';
    fclose(inFile);
}

void writeResut(signed char result[]) {
    FILE *outFile = fopen(RESULT_FILENAME, "w");
    fprintf(outFile, "%s", result);

    fclose(outFile);
};


int main(void) {   
    signed char result[MAX_STRING_SIZE];

    collectResult(result);
    writeResut(result);

    return 0;         
} 