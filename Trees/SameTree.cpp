#include<iostream>
#include<vector>
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
bool SameTree(Node* root1,Node* root2){
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1 == nullptr || root2 == nullptr) return false;
    if(root1->data != root2->data) return false;
    return SameTree(root1->left,root2->left) && SameTree(root1->right,root2->right);
}
int main(){
    Node* root1 = new Node(10);
    root1->left = new Node(60);
    root1->right = new Node(30);

    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);
    cout<<SameTree(root1,root2);
}