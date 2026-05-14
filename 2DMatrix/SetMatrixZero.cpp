#include<iostream>
#include<vector>
using namespace std;
//brute force approach is to check for every element if it is zero then make its row and column as zero but it takes O(m*n*(m+n)) Time Complexity and O(m*n) Space Complexity
vector<vector<int>> SetZeros(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> res(mat);
    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                for(int k=0;k<n;k++){
                    res[i][k]=0;
                }
                for(int k=0;k<m;k++){
                    res[k][j]=0;
                }
            }
        }
    }
    return res;

}
//better approach is to use two sets to store the row and column index of the zero elements and then make the row and column as zero but it takes O(m*n) Time Complexity and O(m+n) Space Complexity
vector<vector<int>> SetMatrixZeroB(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<int> row(m,0);
    vector<int> col(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    //traverse the row and column array and make the row and column as zero
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1 || col[j]==1){
                mat[i][j]=0;
            }
        }
    }
    return mat;

}

//using optimal approach we can use the first row and first column of the matrix to store the row and column index of the zero elements and then make the row and column as zero but it takes O(m*n) Time Complexity and O(1) Space Complexity
 vector<vector<int>> SetMatrixZeroO(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    int col0 = 1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                mat[i][0] = 0;
                if(j!=0){
                    mat[0][j]=0;
                }
                else{
                    col0 =0;
                }
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(mat[i][j]!=0){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
    }

    if(mat[0][0]==0){
        for(int j=0;j<n;j++){
            mat[0][j] = 0;
        }
    }
    if(col0==0){
        for(int i=0;i<m;i++){
            mat[i][0]=0;
        }
    }
    return mat;
 }
int main(){
    vector<vector<int>> mat = {
        {1,1,1,1},
        {1,0,0,1},
        {1,1,0,1}, 
        {1,1,0,1}
    };
    vector<vector<int>> res = SetMatrixZeroO(mat);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}