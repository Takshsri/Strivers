#include<iostream>
#include<vector>
using namespace std;
bool Jump(vector<int>& a){
    int maxIdx =0;
    for(int i=0;i<a.size();i++){
        if(i>maxIdx) return false;
        maxIdx = max(maxIdx,i+a[i]);
    }
    return true;

}

int main(){
    vector<int> a = {1,2,3,1,1,0,2,5};
    cout<<Jump(a); 
}