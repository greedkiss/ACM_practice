#include <iostream>
#include <stack>

using namespace std;

int qs(int * arr, int l , int r){
    int val = arr[l];
    int begin = l, end = r;
    while(l<r){
        while(l<r && arr[r] >= val) r--;
        arr[l] = arr[r];
        while(l<r && arr[l] <= val) l++;
        arr[r] = arr[l];
    }
    arr[l] = val;
    return l;
}

int main(){
    stack<int> tmp;
    int arr[] = {2, 1, 4, 2, 5};
    int i = 0 , j = 4;
    tmp.push(4);
    tmp.push(0);
    while(!tmp.empty()){
        i = tmp.top();
        tmp.pop();
        j = tmp.top();
        tmp.pop();
        if(i<j){
            int k = qs(arr, i, j);
            if(j>k){
                tmp.push(j);
                tmp.push(k+1);
            }
            if(i<k){
                tmp.push(k-1);
                tmp.push(i);
            }
        }
    }
    for(i = 0; i< 5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}