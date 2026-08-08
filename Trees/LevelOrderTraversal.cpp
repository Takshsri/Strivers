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

vector<vector<int>> LevelOrder(Node* root){
    vector<vector<int>> res;
    if(root == NULL) return res;
    queue<Node* > q;
    q.push(root);
    while(q.size()>0){
        int level = q.size();
        vector<int> ans;
        for(int i=0;i<level;i++){
            Node* curr = q.front();
            q.pop();
            ans.push_back(curr->data);
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        res.push_back(ans);
    }
    return res;
}

