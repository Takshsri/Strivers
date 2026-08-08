#include<iostream>
#include<vector>
using namespace std;
    //better approach
    int candyB(vector<int>& ratings){
        int n = ratings.size();
        vector<int> left (n,1);
        vector<int> right (n,1);
        //left to right
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                le ft[i] = left[i-1]+1;
            }
            
        }
        //right to left;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i] = right[i+1]+1;
            }
        } 
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(left[i],right[i]);
        }
        return ans;
    }
    //optimal approach
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int sum=1; 
        while(i<n) {
            if(ratings[i]==ratings[i-1]) {
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]) {
                peak+=1;
                i++;
                sum+=peak;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]) {
                down+=1;
                i++;
                sum+=down;
            }
            down++;
            if(down>peak) {
                sum+=down-peak;
            }
        }
        return sum;
    }

int main(){
    
    vector<int> ratings = {1,0,2};
    cout<<candy(ratings);
}