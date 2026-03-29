#include<iostream>
#include<vector>
using namespace std;
bool Search(vector<vector<int>>& mat,int target){
    int m = mat.size();
    int n = mat[0].size();
    int l =0;
    int r = m*n;
    while(l<=r){
        int mid = l + (r-l)/2;
        int d = mid/n;
        int c = mid%n;
        if(mat[d][c]== target){
            return true;
        }
        else if(mat[d][c]<target){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int target = 4;
    cout<<"Target Found at:"<<Search(matrix,target);
}