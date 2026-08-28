#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
void print(Node* root){
    Node* curr = root;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* reverse(Node* root){
    if(root == NULL || root->next==NULL) return root;
    Node* curr=root;
    Node* forward = NULL;
    Node* prev = NULL;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}
int MiddleNode(Node* root){
    Node* fast = root;
    Node* slow = root;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        
    }
    return slow->data;
}
int main(){
    Node* root = new Node(10);
    root->next = new Node(20);
    root->next->next = new Node(30);

    print(root);

    Node* res = reverse(root);
    print(res);

    cout << MiddleNode(res);
}