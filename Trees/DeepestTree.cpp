#include<iostream>
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
int DeepestNode(Node* root){
    if(root == NULL) return 0;
    int deepestSum =0;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        int level = q.size();
        deepestSum =0;
        for(int i=0;i<level;i++){
            Node* curr = q.front();
            q.pop();
            deepestSum += curr->data;
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
    return deepestSum;
}
vector<int> DeepestNodes(Node* root){
    if(root == NULL) return {};
    queue<Node*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int level = q.size();
        res.clear();
        for(int i=0;i<level;i++){
            Node* curr = q.front();
            q.pop();
            res.push_back(curr->data);

            if(curr->left){q.push(curr->left);}
            if(curr->right) q.push(curr->right);
        }
    }
    return res;
}
int main(){

    Node* root1 = new Node(10);
    root1->left = new Node(60);
    root1->right = new Node(30);
    root1->left->left = new Node(40);
    root1->left->right = new Node(100);
    cout<<DeepestNode(root1);
    cout<<endl;
    vector<int> res = DeepestNodes(root1);
    for(int i:res){
        cout<<i<<" ";
    }
}