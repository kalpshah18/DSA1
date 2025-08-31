#include <stdio.h>

/*
Given two permutations p1 and p2 of the numbers from 1 to n, determine if permutation p1 is lexicographically less than or equal to permutation p2.
A permutation p is lexicographically smaller than a permutation q if at the first position where they differ, the element in p is smaller than the element in q.
*/

int main(){
    int n; scanf("%d", &n);
    int p1[n];
    int p2[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &p1[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &p2[i]);
    }

    for(int i = 0; i < n; i++){
        if(p1[i] > p2[i]){
            printf("NO");
            return 0;
        } else if(p1[i] < p2[i]){
            printf("YES");
            return 0;
        }
    }
    printf("YES");
    return 0;
}