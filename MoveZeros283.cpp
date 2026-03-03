#include<iostream>
#include<vector>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    * b = temp;
}
void moveZeros(vector<int>& a){
    int i =0,j=0;
    int n= a.size();
    while(i<n){
        if(a[i]==0){
            i++;
        }
        else{
            swap(&a[i],&a[j]);
            i++;
            j++;
        }
    }
}
int main(){
    vector<int> a = {0,1,2,0,6};
    moveZeros(a);
    for(int i : a){
        cout<<i<<" ";

    }
}