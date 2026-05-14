#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//This is Brute Force approach to find the number of subarrays with sum k and it takes O(n^3) Time Complexity and O(1) Space Complexity
int SubArr(vector<int>& a,int k){
    int count =0;
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(sum == k){
                count++;
            }
        }
        
    }
    return count;
}
//This is Better approach to find the number of subarrays with sum k and it takes O(n^2) Time Complexity and O(1) Space Complexity
int SubArrBetter(vector<int>& a,int k){
    int count =0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum == k){
                count++;
            }
           
        }
         
    }
    return count;
}
//The Most Optimal approach is to find the subarrays with prefix sum and store the prefix sum in a hash map 
//and then check if the prefix sum - k is present in the hash map or not if it is present then we can add 
//the count of prefix sum - k to the count of subarrays with sum k and it takes O(n) Time Complexity 
//and O(n) Space Complexity
int SubArrOptimal(vector<int>& a,int k){
    int count =0;
    int n = a.size();
     unordered_map<int,int> mpp;
     int prefixSum =0;
     mpp[0]=1;//This is to handle the case when the prefix sum is equal to k
     for(int i=0;i<n;i++){
        prefixSum+=a[i];
        int remove = prefixSum - k;
        count+=mpp[remove];
        mpp[prefixSum]++;
     }
     return count;

}
int main(){
    vector<int> a = {1,2,3,-3,1,1,1,4,2,-3};
    int k =3;
    cout<<"The number of subarrays with sum k is : "<<  SubArrOptimal(a,k)<<endl;
}