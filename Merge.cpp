#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            this->next =  NULL;
        }
};
Node* merge(Node* head1,Node* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
}
int main(){

}