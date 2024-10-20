#include <stdio.h>

const char INPUT_FILENAME[] = "resources/g4_input.txt";
const char RESULT_FILENAME[] = "resources/g4_result.txt";
const int MAX_WORD_SIZE = 100;
const int WORD_DELIMITER = 32;

struct stat{
    signed char ch;
    int counter[2];
};

int getCharIndex(signed char ch, struct stat st[], int size) {
    for (int i = 0; i < size; i++) {
        if (st[i].ch == ch) {
            return i;
        }
    }

    return -1;
}

int collectStat(struct stat st[]) {
    FILE *inFile = fopen(INPUT_FILENAME, "r");

    signed char ch = fgetc(inFile);
    int statIdx = 0;
    int counterIdx = 0;

    while (ch != EOF) {
        if (ch != WORD_DELIMITER) {
            int current = getCharIndex(ch, st, statIdx);
            if (current == -1) {
                current = statIdx;

                st[current].ch = ch; 
                st[current].counter[0] = 0; 
                st[current].counter[1] = 0; 
                statIdx++;
            }

            st[current].counter[counterIdx] += 1;
        } else {
            counterIdx++;
        }

        ch = fgetc(inFile);
    }

    fclose(inFile);
    return statIdx;
}

void swap(struct stat st[], int i, int j) {
    struct stat temp = st[i];
    st[i] = st[j];
    st[j] = temp;
}

void bubbleSort(struct stat st[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (st[j].ch > st[j + 1].ch)
                swap(st, j, j + 1);
        }
    }
}

void writeResut(struct stat st[], int size) {
    FILE *outFile = fopen(RESULT_FILENAME, "w");

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (st[i].counter[0] == 1 && st[i].counter[1] == 1) {
            if (count > 0) {
                fprintf(outFile, "%c", ' ');
            }
            fprintf(outFile, "%c", st[i].ch);
            count++;
        }
    }

    fclose(outFile);
};

int main(void) {   
    struct stat st[MAX_WORD_SIZE * 2]; 
    int statSize = collectStat(st);

    bubbleSort(st, statSize);
    writeResut(st, statSize);
    
    return 0;         
} 