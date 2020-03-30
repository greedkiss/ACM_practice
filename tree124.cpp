#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};


int res = INT_MIN;
int maxLength(treeNode* root){
    if(root == NULL) return 0;
    int left = maxLength(root->left);
    int right = maxLength(root->right);
    res = max(res, left+right+root->val);
    return max(left, right)+ root->val;
}

treeNode* getNewNode(int data){
    treeNode* node = new treeNode();
    node->val = data;
    return node;
}

treeNode* insertNode(int array[], int len, int index){
    treeNode* p = NULL;
    if(index < len){
        p = getNewNode(array[index]);
        p->left = insertNode(array, len, index*2 + 1);
        p->right = insertNode(array, len, index*2 + 2);
    }
    return p;
}

void preOrder(treeNode* root){
    if(root == NULL)
        return;
    printf("%d\n", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    treeNode* root = NULL;
    int arr[] = {-10,9,20,-1,-1,15,7};
    root = insertNode(arr, 7, 0);
    preOrder(root);
    maxLength(root);
    printf("%d\n", res);

    return 0;
}