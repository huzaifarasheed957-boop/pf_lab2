#include <stdio.h>

void printGrid(int (*grid)[5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            printf("%d", grid[r][c]);
            if (c < 4) printf(" ");
        }
        printf("\n");
    }
}

int countNeighbours(int (*grid)[5], int row, int col) {
    int count = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) continue;      
            int r = row + dr, c = col + dc;
            if (r < 0 || r >= 5 || c < 0 || c >= 5) continue;  
            count += (grid[r][c] & 1);             
        }
    }
    return count;
}

void nextGeneration(int (*grid)[5]) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int n = countNeighbours(grid, r, c);
            int alive = grid[r][c] & 1;
            if ((alive && (n == 2 || n == 3)) || (!alive && n == 3))
                grid[r][c] |= 2;                   
        }
    }
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++)
            grid[r][c] >>= 1;                      
}

int main(void) {
    int grid[5][5] = {0};
    grid[1][2] = grid[2][2] = grid[3][2] = 1;

    int gens;
    do {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &gens);
        if (gens < 0 || gens > 50) printf("Invalid number\n");
    } while (gens < 0 || gens > 50);

    for (int g = 0; g <= gens; g++) {
        printf("Generation %d:\n", g);
        printGrid(grid);
        if (g < gens) nextGeneration(grid);
    }
    return 0;
}