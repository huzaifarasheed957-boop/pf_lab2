#include <stdio.h>

int isValidMark(int m) {
    return (m >= 0 && m <= 100) ? 1 : 0;
}

void findMinMax(int arr[], int size, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

int main(void) {
    int marks[5], lo, hi;
    for (int i = 0; i < 5; i++) {
        int m;
        while (1) {
            printf("Enter mark %d: ", i + 1);
            scanf("%d", &m);
            if (isValidMark(m)) break;
            printf("Invalid mark, enter again\n");
        }
        marks[i] = m;
    }
    findMinMax(marks, 5, &lo, &hi);
    printf("Lowest mark: %d\n", lo);
    printf("Highest mark: %d\n", hi);
    return 0;
}