#include<iostream>
#include<vector>
using namespace std;
int MaxSum(vector<int>& a){
    if(a.size()==1 && a[0]>0) return a[0];
    int maxSum =a[0];
    int currSum =a[0];
    for(int i=1;i<a.size();i++){
        currSum = max(a[i],a[i]+currSum);
        maxSum = max(maxSum,currSum);
    }
        
    return maxSum;
}
int maxProd(vector<int>& a){
    int maxProd = a[0];
    int minProd = a[0];
    int ans = a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]<0){
            swap(maxProd,minProd);
        }
        maxProd = max(a[i],a[i]*maxProd);
        minProd = min(a[i],a[i]*minProd);
        ans = max(ans,maxProd);
    }
    return ans;
}
double Median(vector<int>& a,vector<int>& b){
    int n = a.size();
    int m = b.size();
    int i=0,j=0,k=0;
    vector<int> res(n+m);
    while(i<n && j<m){
        if(a[i]<=b[j]){
            res[k++] = a[i++];
        }
        else{
            res[k++] = b[j++];
        }
    }
    while(i<n){
        res[k++] = a[i++];
    }
    while(j<m){
        res[k++] = b[j++];
    }
    int total = m+n;
    if(total%2==0){
        return ((double) res[total/2]+(double) res[(total-1)/2])/2;
    }
    else{
        return (double) res[total/2];
    }
}

int Reverse(int x){
    int sum =0;
    while(x!=0){
        int d = x%10;
        sum = sum*10 +d;
        x /= 10;
    }
    if(sum>INT_MAX || sum<INT_MIN) return 0;
    return sum;
}
bool Palindrome(int x){
    int temp = x;
    int sum =0;
    while(x!=0){
        int d = x%10;
        sum = sum*10 +d;
        x/=10;
    }
    if(sum == temp) return true;
    else return false;
}
int main(){
    // vector<int> a = {1,3,-2,5,7};
    // cout<<maxProd(a);

    // vector<int> a = {1,3};
    // vector<int> b = {2,4};
    // cout<<Median(a,b);
    // cout<<endl<<Reverse(21);
    cout<<Palindrome(787);
} 