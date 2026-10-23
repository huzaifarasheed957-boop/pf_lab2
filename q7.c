#include <stdio.h>

void reverseArray(int *arr, int n) {
    int *start = arr;
    int *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void printArray(const int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

int main(void) {
    int n, songs[20];
    do {
        printf("Enter number of songs: ");
        scanf("%d", &n);
        if (n < 1 || n > 20) printf("Invalid size\n");
    } while (n < 1 || n > 20);

    printf("Enter song IDs: ");
    for (int i = 0; i < n; i++) scanf("%d", &songs[i]);

    printf("Original: ");
    printArray(songs, n);
    reverseArray(songs, n);
    printf("Reversed: ");
    printArray(songs, n);
    return 0;
}