#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int stock[6] = {2, 1, 5 ,5, 2, 6};

// int main(){
//     int dp_0 = 0;
//     int dp_1 = INT_MIN;
//     for(int i =0; i< 6;i++){
//         dp_0 = max(dp_0, dp_1 + stock[i]);
//         dp_1 = max(dp_1, -stock[i]);
//     }
//     cout<<dp_0;
//     return 0;
// }
int main(){
    int dp_0 = 0;
    int dp_1 = INT_MIN;
    int tmp;
    for(int i =0; i< 6;i++){
        tmp = dp_0;
        dp_0 = max(dp_0, dp_1 + stock[i]);
        dp_1 = max(dp_1, dp_0 - stock[i]);
    }
    cout<<dp_0;
    return 0;
}