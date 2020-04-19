#include <cstdio>

using namespace std;

struct tree{
    int value;
    struct tree* left;
    struct tree* right;
};
tree* pre,* first, *second;
int recover(tree* root){
    recover(root->left);
    if(pre && pre->value > root->value){
        if(!first) first = pre;
        second = root;
    }
    pre = root;
}

tree* getNew(int data){
    tree* node = new tree();
    node->value = data;
    return node;
}

tree* instertNode(int len, int array[], int index){
    tree* node = NULL;
    if(index < len && *(array + index) != -1 ){
        node = getNew(array[index]);
        node->left = instertNode(len, array, 2*index+1);
        node->right = instertNode(len, array, 2*index+2);
    }
    return node;
}

int main(){
    tree* node = NULL;
    int arr[] = {1, 3, -1, -1, 2};
    node = instertNode(4, arr, 0);

    recover(node);

    return 0;
}