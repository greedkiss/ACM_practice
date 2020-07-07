#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int> > memo(4, vector<int>(11, -1));

int solve(int k, int n){
    int res = INT_MIN;
    if(k == 1) return n;
    if(n == 0) return 0;
    if(memo[k][n] != -1) return memo[k][n];
    for(int i = 1; i<=n; i++){
        res = max(res, min(solve(k-1, i-1),solve(k, n-i)+1));
    }
    return memo[k][n] = res;
}

int main(){
    int res = solve(3, 10);
    cout<<res;
    return 0;
}