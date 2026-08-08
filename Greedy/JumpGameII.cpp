#include<iostream>
#include<vector>
using namespace std;

int MinJumps(vector<int>& a){
    int minJumps = 0;
    int l=0,r=0;
    while(r<a.size()-1){
        int farthest = 0;
        for(int i=l;i<r;i++){

            farthest = min(farthest,i+a[i]);

        }
         l = r+1;
         minJumps++;
         r = minJumps;
    }
    return minJumps;

}

int main(){
    vector<int> a= {1,2,0,1};
    cout<<MinJumps(a);
}