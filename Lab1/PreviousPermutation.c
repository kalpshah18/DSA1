#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int perm[n];
    for (int i = 0; i < n; i++) scanf("%d", &perm[i]);

    // Step 1: Find the first index i such that perm[i] > perm[i+1] from the right
    int i = n - 2;
    while (i >= 0 && perm[i] < perm[i + 1]) i--;

    if (i < 0) {
        printf("-1\n"); // Already the smallest permutation
        return 0;
    }

    // Step 2: Find the largest j > i such that perm[j] < perm[i]
    int j = n - 1;
    while (perm[j] > perm[i]) j--;

    // Step 3: Swap perm[i] and perm[j]
    swap(&perm[i], &perm[j]);

    // Step 4: Reverse the part from i+1 to end
    int l = i + 1, r = n - 1;
    while (l < r) {
        swap(&perm[l], &perm[r]);
        l++;
        r--;
    }

    // Output result
    for (int k = 0; k < n; k++) {
        printf("%d ", perm[k]);
    }
    printf("\n");

    return 0;
}
