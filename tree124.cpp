#include <iostream>
#include <cstdio>
using namespace std;

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

int maxLength(treeNode* root){

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
    printf("%d", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    treeNode* root = NULL;
    int arr[] = {1, 2, 3, 4};
    root = insertNode(arr, 4, 0);
    preOrder(root);
    // int res = maxLength()

    return 0;
}