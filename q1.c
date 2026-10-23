#include <stdio.h>

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void printArray(const int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

int main(void) {
    int n, scores[20];
    do {
        printf("Enter number of scores: ");
        scanf("%d", &n);
        if (n < 1 || n > 20) printf("Invalid size\n");
    } while (n < 1 || n > 20);

    printf("Enter scores: ");
    for (int i = 0; i < n; i++) scanf("%d", &scores[i]);

    printf("Before sorting: ");
    printArray(scores, n);
    bubbleSort(scores, n);
    printf("After sorting: ");
    printArray(scores, n);
    return 0;
}