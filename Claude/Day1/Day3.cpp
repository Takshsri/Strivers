#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void swap(int*a,int * b){
    int temp = *a;
    *a = *b;
    *b= temp;
}
void MoveZeros(vector<int>& a){
    int l=0,r=a.size()-1;
    while(l<=r){
        if(a[l]==0){
            swap(&a[l],&a[r]);
            l++;
            r--;
        }
        else{
            l++;
        }
    }
}
int Longest(vector<int>& a){
    int n = a.size();
    unordered_set<int> st;
    for(int i : a){
        st.insert(i);
    }

    int maxCount =0;
    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int num = it;
            int count =1;
            while(st.find(num+1)!=st.end()){
                num+=1;
                count++;
            }
            maxCount = max(maxCount,count);
        }
    }
    return maxCount;
}
int main(){
    vector<int> a = {2,4,0,1,0,3};
    MoveZeros(a);
    for(int i: a){
        cout<<i<<" ";
    }
    cout<<endl<<Longest(a);
}