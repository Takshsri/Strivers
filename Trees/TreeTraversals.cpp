#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

void Inorder(Node* root){
    if(root == NULL) return ;
    
        Inorder(root->left);
        cout<<root->data<<"->";
        Inorder(root->right);

    
}
void PreOrder(Node* root){
    if(root == NULL) return ;
    
        cout<<root->data<<"->";
        PreOrder(root->left);
        PreOrder(root->right);
    
}
void PostOrder(Node* root){
        if(root == NULL) return ;
       
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<root->data<<"->";
        }

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Inorder: ";
    Inorder(root);

    cout << "\nPreorder: ";
    PreOrder(root);

    cout << "\nPostorder: ";
    PostOrder(root);

    return 0;


}