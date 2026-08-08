#include<iostream>
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
Node* LCA(Node* root,Node* p,Node* q){
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;

    Node* left = LCA(root->left,p,q);
    Node* right = LCA(root->right,p,q);
    if(left && right) return root;
    else if(left!=NULL) return left;
    return right;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(50);
    root->left->left = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    Node* ans = LCA(root,root->right,root->left->left);
    cout<<ans->data;
}