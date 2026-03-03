#include<iostream>
#include<vector>
using namespace std;
bool IsSorted(vector<int>& a){
    if(a.size() == 1) return true;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]) return false;
    }
    return true;
}
int main(){
    vector<int> a = {23,45,63,21};
    cout<<IsSorted(a);
}