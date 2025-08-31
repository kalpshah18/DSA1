#include <stdio.h>

int possibleArrangement(int capacity, int arr[], int n, int D){
    int days = 1;
    int current = 0;
    for(int i = 0; i < n; i++){
        if(current + arr[i] > capacity){
            days++;
            current = 0;
        }
        current += arr[i];
    }
    if(days <= D) return 1;
    return 0;
}

int main(){
    int n, D;
    scanf("%d %d", &n, &D);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int low = arr[0];
    int high = arr[0];
    for(int i = 1; i < n; i++){
        low = arr[i] > low ? arr[i] : low;
        high += arr[i];
    }
    for(int capacity = low; capacity <= high; capacity++){
        if(possibleArrangement(capacity, arr, n, D)){
            printf("%d", capacity);
            break;
        }
    }
    return 0;
}