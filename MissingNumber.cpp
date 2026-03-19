#include<iostream>
#include<vector>
using namespace std;
//Only for Positive Numbers  
int Hash(vector<int>& a){
    int n = a.size();
    vector<int> hash(n+2,0);
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i=1;i<=n+1;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1;
}


//using xor
int Missing(vector<int>& a){
    int n = a.size();
    int xorSum =0;
    for(int i=0;i<n;i++){
        xorSum ^= a[i];
    }
    for(int i=1;i<=n+1;i++){
        xorSum ^= i;
    }
    return xorSum;
}
int main(){
    vector<int> a = {1,2,3,5};
    cout<<"The Missing Number is :"<<Missing(a)<<endl;
}