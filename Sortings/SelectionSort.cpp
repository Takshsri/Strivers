#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>& a){
    
    for(int i=0;i<a.size()-1;i++){
        int minIdx = i;
        for(int j=i+1;j<a.size();j++){
        if(a[j]<a[minIdx]){

            minIdx = j;
        }
    }
    int temp = a[i];
    a[i] = a[minIdx];
    a[minIdx] = temp;

}
}
int main(){
    vector<int> arr = {261,49,5,9,100};
    for(int i : arr){
        cout<<i<<" ";
    }
    selectionSort(arr);
    cout<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
}