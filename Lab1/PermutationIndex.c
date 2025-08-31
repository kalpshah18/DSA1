#include <stdio.h>
#include <string.h>

#define MAXN 100005

long long fact[MAXN];
int BIT[MAXN];
int n;

void update(int idx, int delta) {
    while (idx <= n) {
        BIT[idx] += delta;
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

int main() {
    scanf("%d", &n);
    int perm[n];
    for (int i = 0; i < n; i++) scanf("%d", &perm[i]);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;

    memset(BIT, 0, sizeof(BIT));
    for (int i = 1; i <= n; i++) update(i, 1);

    long long rank = 1;
    for (int i = 0; i < n; i++) {
        int smaller = query(perm[i] - 1);
        rank += (long long)smaller * fact[n - i - 1];
        update(perm[i], -1);
    }

    printf("%lld\n", rank);
    return 0;
}
