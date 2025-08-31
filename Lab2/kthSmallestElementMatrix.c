#include <stdio.h>
#include <stdlib.h>

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n * n];
    for(int i = 0; i < n * n; i++){
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    qsort(arr, n * n, sizeof(int), compareIntegers);

    printf("%d\n", arr[k - 1]);
    return 0;
}