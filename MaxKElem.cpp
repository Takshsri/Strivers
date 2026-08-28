#include<iostream>
#include<vector>
using namespace std;
void heapify(vector<int>& a,int n,int i){
    int large = i;
    int left = 2*i+1;
    int right = 2*i+2;
    while(left<n && a[left]>a[large]){
        large = left;
    }
    while(right<n && a[right]>a[large]){
        large = right;
    }
    if(large!=i){
        swap(a[i],a[large]);
        heapify(a,n,large);
    }
    
}
void HeapSort(vector<int>& a,int n){
    //building heap
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
int main(){
    vector<int> a  = {5,6,7,1,2,3};
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    
    HeapSort(a,a.size());
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<a[3];
}