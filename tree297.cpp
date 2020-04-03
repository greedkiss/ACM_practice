#include <cstdio>
#include <string>
#include <vector>

using namespace std;

struct treeNode{
    int value;
    struct treeNode* left;
    struct treeNode* right;
};

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

string serialize(treeNode* root){
    string res ='[';
    vector<treeNode> queue;
    if(!root) return NULL;
    queue.push_back(root);
    while(!queue.empty()){
        res += to_string(queue.begin()->value);
        res += ',';
        queue.push_back(root->left);
        queue.push_back(root->right);
    }
    res.back = ']';
    return res;
}

treeNode* deserlialize(string data){
    

}

int main(){
    
}