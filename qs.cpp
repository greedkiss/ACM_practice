#include <iostream>

using namespace std;

void qs(int* arr, int l, int r){
    int begin = l, end = r;
    int val = arr[l];
    while(l<r){
        while(l<r && arr[r] >= val) r--;
        arr[l] = arr[r];
        while(l<r && val >= arr[l]) l++; 
        arr[r] = arr[l];
    }
    arr[l] = val;
    if(begin < l) qs(arr, begin, l-1);
    if(l < end) qs(arr, l+1, end);
}

int main(){
    int arr[] = {3, 4, 1, 8, 6, 2};
    qs(arr, 0, 5);
    for(int i = 0; i<6;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}