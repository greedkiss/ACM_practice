#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define MAXN 500

string tmp, comp, chan, text, text1;

void input(string &a, string &b){
    getline(cin, tmp);
    while(tmp.compare("START")){
        getline(cin, tmp);
    }
    while(getline(cin, tmp)){
        if(!tmp.compare("END")) break;
        a += tmp;
    }
    for(int i = 0, j = 0; i < a.length(); i++, j++){
        if(a[i] == ' ' || a[i] == '\t' || a[i] == '\n')
            continue;
        b += a[i];
    }
}

int main(){
    input(comp, chan);
    input(text, text1);
    cout<<chan<<"  "<<text1<<endl;
    if(!comp.compare(text))  printf("AC\n");
    else if(!chan.compare(text1)) printf("PE\n");
    else printf("WR\n");
    return 0; 
}