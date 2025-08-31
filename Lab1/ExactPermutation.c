#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int BIT[MAXN], n;

void update(int idx, int val) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int findKth(int k) {
    int idx = 0;
    int bitMask = 1 << 17;
    while (bitMask > 0) {
        int next = idx + bitMask;
        if (next <= n && BIT[next] < k) {
            k -= BIT[next];
            idx = next;
        }
        bitMask >>= 1;
    }
    return idx + 1;
}

void findPermutation(int n_input, long long i) {
    n = n_input;

    // Reset Fenwick Tree properly
    for (int j = 1; j <= n; j++) BIT[j] = 0;
    for (int j = 1; j <= n; j++) update(j, 1);

    i--; // convert to 0-based

    for (int pos = 0; pos < n; pos++) {
        long long fact = 1;
        for (int k = 2; k <= n - 1 - pos; k++) {
            if (fact > i) break;
            fact *= k;
        }

        long long index = (fact == 0) ? 0 : (i / fact);
        int num = findKth(index + 1);

        printf("%d ", num);
        update(num, -1);

        if (fact != 0) i %= fact;
    }
    printf("\n");
}


int main() {
    int n;
    long long i;
    scanf("%d %lld", &n, &i);
    findPermutation(n, i);
    return 0;
}
