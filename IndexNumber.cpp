#include<iostream>
#include<vector>
using namespace std;
int Index(vector<int>& a){
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]==i){
            return i;
        }
    }
    return -1;
}

int main(){
     vector<int> arr = {-6,-4,1,5,7};
     if(Index(arr)!=-1){
        cout<<"Index Number is :"<<Index(arr)<<endl;
     }
     else{
        cout<<"No Index Number Found"<<endl;
     }
     
}