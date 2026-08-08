#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
int height(Node* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}
bool isSymmetric(Node* root){
    if(root == NULL){
        return true;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(abs(left-right)>1){
        return false;
    }
    return isSymmetric(root->left) && isSymmetric(root->right);
}
int main(){

    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    cout<<isSymmetric(root);
}