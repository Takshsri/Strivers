#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int Longest(vector<int>& a){
    int Longest =0;
    unordered_set<int> st;
    for(int i : a){
      st.insert(i);
    }
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int count =1;
            int num = it;
            while(st.find(num+1)!=st.end()){
                count++;
                num++;
            }
            Longest = max(Longest,count);
        }
    }
    return Longest;

}
int main(){
    vector<int> a = {4,2,1,5,6};
    cout<<Longest(a);
}