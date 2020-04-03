#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int arr[] = {1,2,2,4,5,3,6};
    vector<int> dp(7, 1);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < dp.size(); i++){
        if(dp[i] > res)
            res = dp[i];
    }
    printf("%d", res);
    
    return 0;    
}