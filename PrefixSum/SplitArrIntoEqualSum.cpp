#include<iostream>
#include<vector>
using namespace std;
bool Equal(vector<int>& a){
    int sum =0;
    for(int i : a){
        sum += i;
    }
    int leftSum =0;
    for(int i=0;i<a.size();i++){
        leftSum += a[i];
        int rightSum = sum - leftSum;
        if(leftSum == rightSum){
            return true;
        } 
    }
    return false;
}
int min_operations_to_maximize(int n, char s[]) {
    int minOperations = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '1') {
            swap(s[i], s[i + 1]);
            minOperations++;
        }
    }
    return minOperations;
}


int main(){
    // vector<int> a = {1,2,3,4,5,5};
    // cout<<Equal(a);
    char a[] = {'1', '1', '0', '1'};
    
    // Calculate size of the array
    int n = sizeof(a) / sizeof(a[0]);
    
    cout << "Operations needed: " << min_operations_to_maximize(n, a) << endl;
    
}