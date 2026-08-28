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
int water(vector<int>& a){
    int l =0;
    int r = a.size()-1;
    int maxWater = 0;
    while(l<r){
        int width = r-l;
        int height = min(a[l],a[r]);
        int currWater = height * width;
        maxWater = max(maxWater,currWater);
        if(a[l]<a[r]) l++;
        else r--;

    }
    return maxWater;
}
int main(){
    vector<int> ht = {1,2,3};
    cout<<"Container with Most Water is :"<<water(ht);
}