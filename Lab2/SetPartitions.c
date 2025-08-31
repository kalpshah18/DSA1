#include <stdio.h>

int countSetBits(int n){
    int count = 0;
    while n:
        count += n & 1;
        n >>= 1;
    return count;
}

void print_subset(int mask) {
    printf("{");
    int first = 1;
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            if (!first) printf(",");
            printf("%d", i + 1);
            first = 0;
        }
    }
    printf("}");
}

int main(){
    int n, k; scanf("%d %d", &n, &k);

    int limit = 1 << n;
    

    return 0;
}