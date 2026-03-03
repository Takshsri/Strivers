#include<iostream>
#include<vector>
using namespace std;
int removeDupli(vector<int>& a ){
    int i =0;
    for(int j=1;j<a.size();j++){
        if(a[j]!=a[i]){
            i++;
            a[i] = a[j];
            
        }
    }
    return i+1;
}


int removedupli(vector<int>& a){
    int n = a.size();
    if(n<=1) return n;
    int i=1;
    for(int j=1;j<a.size();j++){
        if(a[j]!=a[i-1]){
            a[i]= a[j];
            i++;
        }
    }
    return i;
}
int main(){
    vector<int> a = {1,1,2};
    int n= removedupli(a);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}