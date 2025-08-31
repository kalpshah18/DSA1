#include <stdio.h>

int main(){
    int n; scanf("%d", &n);
    
    int nums[n];
    for(int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int v; scanf("%d", &v);
    
    int low = 0, high = n - 1;
    int mid = -1;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(nums[mid] == v){
            printf("%d", mid);
            return 0;
        }
        if(nums[mid] >= nums[low]){
            if(v >= nums[low] && v < nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if(v > nums[mid] && v <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    printf("-1");
    return 0;
}