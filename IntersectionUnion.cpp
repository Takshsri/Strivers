#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> intersection(vector<int>&a,vector<int>& b){
    set<int> s1(a.begin(),a.end());
    set<int> s2(b.begin(),b.end());
    vector<int> res;
    for(auto x : s1){
        if(s2.find(x)!=s2.end()){
            res.push_back(x);
        }
    }
    s1.insert(s2.begin(),s2.end());
    int unionCount = s1.size();
    cout<<"The size of Union of 2 Arrays:"<<unionCount<<endl;

    return res;
}
//without using Sets 
vector<int> intersectionArrs(vector<int>& a, vector<int>& b){
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    vector<int> res;

    while(i < n && j < m){
        if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res;
}//only works if arrays are sorted 
int main(){
    vector<int> a = {1,2,3,4,1,2};
    vector<int> b = {2,3,4,5,6};
    vector<int> Intersection = intersection(a,b);
    for(int i : Intersection){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> IntersectionArrs = intersectionArrs(a,b);
    for(int i : IntersectionArrs){
        cout<<i<<" ";
    }
}