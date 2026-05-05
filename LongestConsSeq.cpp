#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
using namespace std;
bool LS(vector<int>& a,int num){
    for(int i : a){
        if(i == num){
            return true;
        }
    }
    return false;
}
//This is Brute Force Approcah and it takes approxiamtely O(n^2) Time Complexity and Space Complexity is O(1)
int Longest(vector<int>& a){
    cout<<"Brute Force Solution"<<endl;

    int longest = 1;
    for(int i=0;i<a.size();i++){
        int num = a[i];
        int cnt = 1;
        while(LS(a,num+1)== true){
            num = num+1;
            cnt++;
        }
        longest = max(longest,cnt);
    }
    return longest;
}
//Better Approach is to sort the array and then check for the longest sequence but it takes O(nlogn) Time Complexity and O(1) Space Complexity
int LongestBetter(vector<int>& a){
    cout<<"Better Solution"<<endl;
    sort(a.begin(),a.end());
    int longest = 1;
    int cnt = 0;
    int leastSmall = INT_MIN;
    for(int i=0;i<a.size();i++){
        if(a[i]-1 == leastSmall){
            cnt++;
            leastSmall = a[i];
        }
        else if(a[i]!=leastSmall){
            cnt = 1;
            leastSmall = a[i];
        }
        longest = max(longest,cnt);
    }
    return longest;

}

int LongestOptimal(vector<int>& a){
    cout<<"OPtimal Solution"<<endl;
    unordered_set<int> s;
    for(int i : a){
        s.insert(i);
    }
    int longest = 0;
    for(auto it: s){
        if(s.find(it-1) == s.end()){
            int cnt =1;
            int num = it;
            while(s.find(num+1)!=s.end()){
                num = num+1;
                cnt++;
            }
            longest = max(longest,cnt);
        }

    }
    return longest;
}
int main(){
    vector<int> a = {102,4,100,1,101,3,1};
    cout<<LongestOptimal(a);
}