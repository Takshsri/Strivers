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

void  KthLevel(Node* root,int k,vector<int>& res){
    if(root == NULL) return ;
    
    if(k==1){
        res.push_back(root->data);
        return ;
    }
    KthLevel(root->left,k-1,res);
    KthLevel(root->right,k-1,res);
   
   

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
   
    vector<int> res;
    KthLevel(root,2,res);
    for(int i : res){
        cout<<i<<" ";
    }
}