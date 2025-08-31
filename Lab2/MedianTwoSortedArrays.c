#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++) scanf("%d", &arr1[i]);
    for(int i = 0; i < m; i++) scanf("%d", &arr2[i]);

    int total = n + m;
    int median1 = -1, median2 = -1;
    int i = 0, j = 0, count;
    for(count = 0; count <= total/2; count++){
        median2 = median1;
        if(i < n && (j >= m || arr1[i] <= arr2[j])){
            median1 = arr1[i++];
        } else {
            median1 = arr2[j++];
        }
    }
    if(total % 2 == 1){
        printf("%d\n", median1);
    } else {
        double median = (median1 + median2) / 2.0;
        printf("%.1f\n", median);
    }
    return 0;
}
