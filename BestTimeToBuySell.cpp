#include<iostream>
#include<vector>
using namespace std;
int SellStock(vector<int>& a){
    int n = a.size();
    int maxProfit = INT_MIN;
    for(int i=0;i<n;i++){
        int currProft = INT_MIN;
        for(int j=i+1;j<n;j++){
            currProft = a[j]-a[i];  
            maxProfit = max(maxProfit,currProft);
        }  
    }
    
    return (maxProfit<0)?0:maxProfit;
}

//my approach
int BestTime(vector<int>& a){
    int maxProfit = 0;
    int minPrice = INT_MAX;
    for(int i=0;i<a.size();i++){
        minPrice = min(a[i],minPrice);
        int profit = a[i] - minPrice;
        maxProfit = max(maxProfit,profit);
    
    
    }
    return maxProfit;
}
int Best(vector<int>& a){
    int maxPrice =0;
    int minPrice = INT_MAX;
    for(int i=0;i<a.size();i++){
        minPrice = min(minPrice,a[i]);
        int profit = a[i]-minPrice;
        maxPrice = max(maxPrice,profit);
    }
    return maxPrice;
}
int main(){
    vector<int> a = {2,5,7,9};
    cout<<Best(a)<<endl;
    //cout<<SellStock(a);
}