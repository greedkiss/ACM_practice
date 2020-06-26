#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

string a = "abcabcdeabcd";
string b = "abcd";

void getnext(string b, int n, int* next){
    int len = 0;
    next[0] = 0;
    int i = 1;
    while(i < n){
        if(b[len] == b[i]){
            len++;
            next[i] = len;
            i++;
        }else{
            if(len){
                len = next[len - 1];
            }else{
                next[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    int next[255];
    int m = a.size(), n = b.size();
    getnext(b, n, next);
    int i=0, j=0;
    while(i < m){
        if(a[i] == b[j]){
            i++;
            j++;
        }
        if(j == n){
            printf("匹配下标%d", i-j);
            j = next[j-1];
        }
        else if(j<n && a[i]!=b[j]){
            if(j)
                j = next[j-1];
            else
            {
                i++;
            }
        }
    }
}