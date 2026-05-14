#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Brute Force approach is to create a new matrix and then fill the new matrix by rotating the original matrix but it takes O(m*n) Time Complexity and O(m*n) Space Complexity
vector<vector<int>> Rotate(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size(); 
    vector<vector<int>> res(n,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            res[j][n-1-i] = mat[i][j];
        }
    }
    return res;
}
//Better and Optimal Approach is same we can first transpose the matrix and then reverse the rows of the matrix to get the rotated matrix but it takes O(m*n) Time Complexity and O(1) Space Complexity
vector<vector<int>> RotateBetter(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    //Transpose the matrix
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
    //Reverse the rows of the matrix
    for(int i=0;i <m;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    return mat;
}
int main(){
    vector<vector<int>> mat = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    vector<vector<int>> res = RotateBetter(mat);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}