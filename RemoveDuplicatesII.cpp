#include<iostream>
#include<vector>
using namespace std;
int RemoveDupli(vector<int>& a){

    int n = a.size();
    if(n<=2) return n;
    int i = 2;
    for(int j=2;j<a.size();j++){
        if(a[j]!=a[i-2]){
            a[i] = a[j];
            i++;
        }
    }
    return i;
}
int main(){

    vector<int> a= {1,1,2,2,2,2,2,2,3,3,3};
    int n = RemoveDupli(a);
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}