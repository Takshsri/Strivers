#include<iostream>
#include<vector>
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
bool helper(Node* root,Node* min,Node* max){
    if(root == nullptr) return true;
    if(min!=NULL && root->data <= min->data) return false;
    if(max!=nullptr && root->data >= max->data) return false;
    return helper(root->left,min ,root) && helper(root->right,root,max);
}   
bool IsThisBST(Node* root){
   return helper(root,NULL,NULL);

}