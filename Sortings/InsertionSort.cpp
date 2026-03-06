#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        int j = i;
        while(j>0 && a[j-1]>a[j]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }

    }
}

void insertion(vector<int>& a){
    for(int i=0;i<a.size()-1;i++){
        int j= i;
        while(j>0 && a[j-1]>a[j]){
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
        }
        
    }
}
int main(){
    vector<int> arr = {23,4,6,1,5,67};
    for(int i : arr){
        cout<<i<<"  ";
    }
    cout<<endl;
    insertion(arr);
    for(int i : arr){
        cout<<i<<"  ";
    }

}