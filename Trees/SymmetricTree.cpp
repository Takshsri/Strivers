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
bool Mirror(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)return true;
    if(root1==nullptr || root2==nullptr) return false;
    return (root1->data == root2->data) && Mirror(root1->left,root2->right) && Mirror(root1->right,root2->left);
}
bool Symmetric(Node* root){
    return Mirror(root->left,root->right);
}
int main(){
    Node* root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    cout<<Symmetric(root1);

}