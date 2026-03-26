#include<iostream>
#include<vector>
using namespace std;
int maxWater(vector<int>& ht){
    int l =0,r=ht.size()-1;
    int maxwater =0;
    while(l<r){
        int width = r-l;
        int height = min(ht[l],ht[r]);
        int currwater = width*height;
        maxwater = max(currwater,maxwater);
        if(ht[l]<ht[r]){
            l++;
        }
        else{
            r--;
        }
    }
    return maxwater;
}
int main(){
    vector<int> ht = {1,2,3};
    cout<<"Container with Most Water is :"<<maxWater(ht);
}