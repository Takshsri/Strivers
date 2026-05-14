#include<iostream>
#include<vector>
using namespace std;
//Brute Force and Optimal and Better approach is to create a new matrix and then fill the new matrix by rotating the original matrix but it takes O(m*n) Time Complexity and O(m*n) Space Complexity
vector<int> RotateSpiral(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    int top = 0,bottom = m-1;
    int left = 0,right = n-1;
    vector<int> res;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            res.push_back(mat[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res.push_back(mat[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i= right;i>=left;i--){
                res.push_back(mat[bottom][i]);
            }
        }
        bottom--;
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                res.push_back(mat[i][left]);
            }
        }
        left++;
    }
    return res;

}
int main(){
    vector<vector<int>> mat = {
        {1,2,3,4,5,6},
        {7,8,9,10,11,12},
        {13,14,15,16,17,18},
        {19,20,21,22,23,24},
        {25,26,27,28,29,30}
    };
    vector<int> res = RotateSpiral(mat);
    for(int i : res){
        cout<<i<<" ";
    }
}