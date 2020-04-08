#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

int dp(string a , string b, int memo[][5], int i, int j){
   if(memo[i][j] != 8) return memo[i][j];
   if(i == -1) return j+1;
   if(j == -1) return i+1;
   if(a[i] == b[j]){
    dp(a, b, memo, i-1, j-1);
   }
   else{
       return min(dp(a, b, memo, i-1, j), dp(a, b, memo, i, j-1), dp(a, b, memo, i-1, j-1)); 
   }
}

int main(){
    string a ("apple");
    string b("rad");
    int memo[a.length()][b.length()] = {8};
    int res = dp(a, b, memo,4,2);
    printf("%d", res);
    return 0;
}