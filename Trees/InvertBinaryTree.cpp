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
Node* invertTree(Node* root){
    if(root == NULL) return NULL;
    Node* left = invertTree(root->left);
    Node* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;

}
void Inorder(Node* root){
    if(root == NULL) return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);  
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    
    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(90);
    Inorder(root);
    cout<<endl;
    root = invertTree(root);
    Inorder(root);
}