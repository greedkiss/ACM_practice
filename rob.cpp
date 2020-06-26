#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int rob[6] = {1, 4, 6, 4, 3, 1};
int mon[6];
int robbery(int rob[], int i){
    if(i > 5)
        return 0;
    if(mon[i] != -1)
        return mon[i];
    int res = max(robbery(rob, i+1), robbery(rob, i+2)+rob[i]);
    mon[i] = res;
    return res;
}

int main(){
    int start = 0;
    memset(mon, -1, sizeof(mon));
    int res = robbery(rob, 0);
    cout<<res;
    return 0;
}