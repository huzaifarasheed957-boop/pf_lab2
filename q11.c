#include <stdio.h>

int square(int x)     { return x * x; }
int negate(int x)     { return -x; }
int isEven(int x)     { return x % 2 == 0; }
int isPositive(int x) { return x > 0; }

void applyToArray(int *arr, int n, int (*fn)(int)) {
    for (int i = 0; i < n; i++)
        arr[i] = fn(arr[i]);
}

int countIf(const int *arr, int n, int (*pred)(int)) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (pred(arr[i])) count++;
    return count;
}

void printGeneric(void *data, char type, int n) {
    switch (type) {
        case 'i':
            for (int i = 0; i < n; i++) printf("%d ", ((int *)data)[i]);
            break;
        case 'f':
            for (int i = 0; i < n; i++) printf("%.2f ", ((float *)data)[i]);
            break;
        case 'c':
            for (int i = 0; i < n; i++) printf("%c ", ((char *)data)[i]);
            break;
        default:
            printf("Invalid type '%c' for printGeneric", type);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {3, -2, 8, -5, 6};
    float fl[] = {1.5f, 2.25f};
    int n;

    do {
        printf("Enter n (1-50): ");
        scanf("%d", &n);
        if (n < 1 || n > 50) printf("Invalid n\n");
    } while (n < 1 || n > 50);
    if (n > 5) n = 5;   

    printf("Original: ");
    printGeneric(arr, 'i', n);

    applyToArray(arr, n, negate);
    printf("After negate: ");
    printGeneric(arr, 'i', n);

    printf("Positive values after negate: %d\n", countIf(arr, n, isPositive));
    printf("Even values after negate: %d\n", countIf(arr, n, isEven));

    printf("Float print (type f): ");
    printGeneric(fl, 'f', 2);
    printGeneric(arr, 'x', n);
    return 0;
}