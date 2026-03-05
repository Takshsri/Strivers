#include<iostream>
#include<vector>
using namespace std;
void MoveEvenOdd(vector<int>& a){
    int i =0 ;
    int j = a.size()-1;
    while(i<j){
        if(a[i]%2==0){
            i++;
        }
        else {

            swap(a[i],a[j]);
            j--;
        }
        
    }
}
int main(){
    vector<int> a = {34,5,43,78,9};
    MoveEvenOdd(a);
    for(int i : a){
        cout<<i<<" ";
    }
}