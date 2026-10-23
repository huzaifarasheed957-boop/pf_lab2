#include <stdio.h>

void computeTotals(int (*marks)[3], int rows, int totals[]) {
    for (int i = 0; i < rows; i++) {
        totals[i] = 0;
        for (int j = 0; j < 3; j++)
            totals[i] += *(*(marks + i) + j);
    }
}

int findTopper(const int *totals, int rows) {
    int best = 0;
    for (int i = 1; i < rows; i++)
        if (*(totals + i) > *(totals + best)) best = i;
    return best;
}

int main(void) {
    int marks[3][3], totals[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter marks for Student %d (3 subjects): ", i + 1);
        for (int j = 0; j < 3; j++)
            scanf("%d", &marks[i][j]);
    }

    computeTotals(marks, 3, totals);
    for (int i = 0; i < 3; i++)
        printf("Total for Student %d: %d\n", i + 1, totals[i]);

    int t = findTopper(totals, 3);
    printf("Student %d is the topper with total %d\n", t + 1, totals[t]);
    return 0;
}