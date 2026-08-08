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

int SumTree(Node* root){
    if(root == NULL) return 0;
    int left = SumTree(root->left);
    int right = SumTree(root->right);
    root->data += left+ right;
    return root->data;
}
void Inorder(Node* root){
    if(root == NULL) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(10);
    root->right->right = new Node(30);
    cout<<SumTree(root);
    cout<<endl;
    Inorder(root);
}