#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;
string a = "rad";
string b = "apple";
vector<vector<int> > dp(3, vector<int>(5, -1));

int solve(int i, int j){
    if(i == -1) return j+1;
    if(j == -1) return i+1;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(a[i] == b[j]){
        dp[i][j] = solve(i-1, j-1);
    }
    if(a[i] != b[j]){
        int a  = min(solve(i-1, j)+1, solve(i, j-1)+1);
        dp[i][j] = min(solve(i-1, j-1)+1, a);
    }
    return dp[i][j];
}

int main(){
    int res = solve(2, 4);
    cout<<res;
    return 0;
}