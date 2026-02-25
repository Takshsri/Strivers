#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string name = "ramya";
    vector<int> count (255,0);
    for(int i=0;i<name.size();i++){
        count[name[i]]++;
    }
    cout<<count['t'];
}