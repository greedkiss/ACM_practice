#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string a("aaacaaac");
    string b("aaab");
    int x = 0;
    vector< vector<int> > dp(b.size(), vector<int>(256, 0));
    dp[0][b[0]] = 1;
    for(int i = 1; i < b.size() ; i++){
        for(int j = 0 ; j < 256; j++){
            if(b[i] == (char)j)
                dp[i][j] = i+1;
            else
                dp[i][j] = dp[x][j];
        }
        x = dp[x][b[i]]; 
    }

    int res, status = 0;
    for(int i = 0; i < a.size() - b.size(); i++){
        status = dp[status][(int)a[i]];
        if(status == b.size() - 1){
            res = i - b.size() + 1;
            break;
        }
        res = -1;
    }
    cout<<res<<endl;
    return 0;
}