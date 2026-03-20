#include<iostream>
#include<vector>
#include<map>
using namespace std;
int SubArrays(vector<int>& a,int k){
    map<int,int> prefix;
    prefix[0] = 1;
    int count = 0;
    int currSum =0;
    for(int i : a){
        currSum+=i;
        if(prefix.find(currSum-k)!=prefix.end()){
            count+= prefix[currSum-k];
        }
        prefix[currSum]++;

    }
   return count;
    


}
int main(){
    vector<int> a = {1,1,1};
    cout<<"Count of SubArrays :"<<SubArrays(a,2);
}