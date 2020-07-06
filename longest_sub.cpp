#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
using namespace std;
int arr[8] = {10, 9, 2 ,5 ,3 ,7, 101, 23};

int main(){
    vector<int> dp(8, 1); 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }
    for(int i = 1 ; i<8;i++){
        dp[0] = max(dp[0], dp[i]);
    }
    cout<<dp[0];
    return 0;
}