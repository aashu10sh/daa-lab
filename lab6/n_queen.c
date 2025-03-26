#include <stdio.h>
#include <math.h>

int x[30], count = 0;

int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void print_sol(int n) {
    count++;
    printf("\n\nSolution # %d:\n", count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            if (k == n)
                print_sol(n);
            else
                nqueen(k + 1, n);
            x[k] = -1; // Backtrack: Reset the position of the current queen.
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        x[i] = -1; // Initialize the column positions of queens.
    }

    nqueen(1, n); // Start the N-Queens problem with a call to nqueen(1, n).

    printf("\nTotal solutions = %d\n", count);
    return 0;
}
