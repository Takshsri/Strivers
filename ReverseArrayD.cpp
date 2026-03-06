#include<iostream>
#include<vector>
using namespace std;
void reverseArray(vector<int> &arr , int m) {
    // Write your code here  
    int n = arr.size()-1;
    m = m+1;
    while(m<n){
        int temp = arr[m];
        arr[m] = arr[n];
        arr[n] = temp;
        m++;
        n--;
    }  
    for(int i : arr){
        cout<<i<<" ";
    }  	
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    reverseArray(arr,3);
}