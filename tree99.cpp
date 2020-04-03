#include <cstdio>

using namespace std;

struct treeNode{
    int value;
    struct treeNode* left;
    struct treeNode* right;
};

treeNode * pre, *first, *second;

void recover(treeNode* root){
    if(root == NULL) return;
    recover(root->left);
    if(pre && pre->value > root->value){
        if(first == NULL)
            first = pre;
        second = root;
    }
    pre = root;
    recover(root->right);
}

treeNode* getNew(int data){
    treeNode* node = new treeNode();
    node->value = data;
    return node;
}

treeNode* insertNode(int array[], int len, int index){
    treeNode* node = NULL;
    if(index < len && array[index] != -1){
        node = getNew(array[index]);
        node->left = insertNode(array, len, index*2+1);
        node->right = insertNode(array, len, index*2+2);
    }
    return node;
}


int main(){
    int array[] = {1, 3, -1, -1, 2};
    treeNode* root = NULL;
    root = insertNode(array, 5, 0);
    recover(root);
    printf("%d,%d",first->value, second->value);
    return 0;
}