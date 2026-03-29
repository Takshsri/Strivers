#include<iostream>
#include<vector>
using namespace std;
bool Search(vector<vector<int>>& a,int target){
    int m = a.size();
    int n = a[0].size();
    int i=0;
    int j = n-1;
    while(i<m && j>=0){
        if(a[i][j]==target){
            return true;
        }
        else if(a[i][j]>target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 5;
    cout<<"Target Found at :"<<Search(mat,target);
}