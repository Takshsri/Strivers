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
void SortSelect(vector<int>& arr){
    for(int i=0;i<arr.size()-1;i++){
        int mini = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[mini]){
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}

int main(){
    vector<int> arr = {261,49,5,9,100};
    for(int i : arr){
        cout<<i<<" ";
    }
    SortSelect(arr);
    cout<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
}