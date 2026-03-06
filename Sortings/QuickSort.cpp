#include<iostream>
#include<vector>
using namespace std;

int Pivot(vector<int>& a,int l ,int r){
    int pivot = a[l];
    int i = l;
    int j = r;

    while(i < j){

        while(i <= r && a[i] <= pivot) i++;
        while(j >= l && a[j] > pivot) j--;

        if(i < j) swap(a[i], a[j]);
    }

    swap(a[l], a[j]);
    return j;
}

void Quicksort(vector<int>& a,int l,int r){
    if(l < r){
        int p = Pivot(a, l, r);

        Quicksort(a, l, p-1);
        Quicksort(a, p+1, r);
    }
}
int main(){
    vector<int> a = {23,56,3,1,67,33,12};

    Quicksort(a,0,a.size()-1);

    for(int x : a)
        cout<<x<<" ";
}