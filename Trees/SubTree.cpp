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

bool Identical(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    if(root1 == NULL || root2 == NULL) return false;
    if(root1->data != root2->data) return false;

    return Identical(root1->left,root2->left) && Identical(root1->right,root2->right);
}

bool SubTree(Node* root,Node* subTree){
    if(root == NULL || subTree == NULL ) return root == subTree;
    if(root->data == subTree->data && Identical(root,subTree)) return true;

    return SubTree(root->left,subTree) || SubTree(root->right,subTree);
}
int main(){
    Node* root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(40);
    root1->left->right = new Node(80);


    Node* root2 = new Node(20);
    root2->left = new Node(40);
    root2->right = new Node(80);
    cout<<SubTree(root1,root2);
}
