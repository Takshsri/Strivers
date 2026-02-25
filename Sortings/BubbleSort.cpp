#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        for(int j=0;j<a.size()-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1]= temp;
            }
        }
    }
}
int main(){
    vector<int> arr = {261,78,45,32};
    for(int i : arr){
        cout<<i<<" ";
    }
    bubbleSort(arr);
    cout<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
} 