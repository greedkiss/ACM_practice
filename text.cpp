#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string a = "abcdabcdeabcde";
string b = "abcde";

void getnext(string b, int * next, int n){
    int tmp = 0, i = 1;
    next[tmp] = 0;
    while(i<n){
        if(b[tmp] == b[i]){
            tmp++;
            next[i] = tmp;
            i++;
        }
        else{
            if(tmp) tmp = next[tmp - 1];
            else i++;
        }
    }
}

int main(){
    int m = a.size(), n = b.size();
    int next[255];
    getnext(b, next, n);
    int i = 0, j =0;
    while(i<m){
        if(a[i] == b[j]){
            i++;
            j++;
        }
        if(j==n){
            printf("匹配%d\n", i-j);
            j = next[j-1];
        }
        else if(a[i] != b[j] && j<n){
            if(j) j = next[j-1];
            else i++;
        }
    }
    return 0;
}