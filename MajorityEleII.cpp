#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<int> Majority(vector<int>& a){
    vector<int>res;
    for(int i=0;i<a.size();i++){
        int count=0;
        for(int j=0;j<a.size()-1;j++){
            if(a[j]==a[i]){
                count++;
            }
        }

    }
}
int main(){
    vector<int> a = {1,1,1,3,3,2,2,2};
    vector<int> res = Majority(a);
    for(int i : res){
        cout<<i<<" ";
    }
}