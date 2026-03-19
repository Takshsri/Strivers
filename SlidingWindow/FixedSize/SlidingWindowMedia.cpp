#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k){

    multiset<int> window(nums.begin(), nums.begin()+k);
    auto mid = next(window.begin(), k/2);

    vector<double> result;

    for(int i=k;;i++){

        if(k%2)
            result.push_back(*mid);
        else
            result.push_back((double(*mid)+*prev(mid))/2);

        if(i==nums.size()) break;

        window.insert(nums[i]);

        if(nums[i] < *mid) mid--;

        if(nums[i-k] <= *mid) mid++;

        window.erase(window.lower_bound(nums[i-k]));
    }

    return result; 
}

int main(){

    vector<int> a = {1,3,-1,-3,5,3,6,7};

    vector<double> res = medianSlidingWindow(a,3);

    for(double i:res)
        cout<<i<<" ";
}