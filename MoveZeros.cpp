#include<iostream>
#include<vector>

using namespace std;
void Move(vector<int>& a){
    int i=0,j=0;
    int n = a.size();
    while(i<n){
        if(a[i]==0){
            i++;
        }
        else{
            swap(a[i],a[j]);
            i++;
            j++;
    }
}
}
int main(){
    vector<int> a = {0,1,0,3,12};
    Move(a);
    for(int i : a){
        cout<<i<<" ";
    }
}