#include <stdio.h>
#include <string.h>

const int ARRAY_MAX_SIZE = 100;

int input_array(int arr[]) {
    int i = 0;
    do {
        int num;
        if (scanf("%d", &num) == 1) {
            arr[i++] = num;
        }

    } while (getchar() != '\n' && i < ARRAY_MAX_SIZE);
    arr[i];

    return i;
}

int get_key_index(int val, int size, int keys[]) {
    for (int i = 0; i < size; i++) {
        if (keys[i] == val) {
            return i;
        }
    }

    return -1;
}

int is_two_same(int size, int arr[]) {
    int keys[size];
    int values[size];
    int mapSize = 0;

    memset(values, 0, sizeof(values));

    for (int i = 0; i < size; i++) {
        int mapPosition = get_key_index(arr[i], mapSize, keys);

        if (mapPosition == -1) {
            keys[mapSize] = arr[i];
            values[mapSize] += 1;

            mapSize++;
        } else {
            values[mapPosition] += 1;
        }
    }

    for (int i = 0; i < mapSize; i++) {
        if  (values[i] > 1) {
            return 1;
        }
    }

    return 0;
}

int main(void) {   
    int arr[ARRAY_MAX_SIZE];
    int size = input_array(arr);
    
    printf("%s\n", is_two_same(size, arr) == 1 ? "YES" : "NO");

    return 0;         
} 