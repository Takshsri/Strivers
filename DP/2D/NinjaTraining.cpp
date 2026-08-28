#include<iostream>
#include<vector>
using namespace std;
//recursion 
int f(int day,int last,vector<vector<int>>&a){
    if(day ==0 ){
        int maxi =0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi,a[0][task]);
            }
        }
        return maxi;
    }
    int maxi =0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int points  = a[day][task] + f(day-1,task,a);
            maxi = max(maxi,points);
        }
    }
    return maxi;
}
int fM(int day,int last,vector<vector<int>>&a,vector<vector<int>>& dp){
    if(day ==0 ){
        int maxi =0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi,a[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi =0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int points  = a[day][task] + fM(day-1,task,a,dp);
            maxi = max(maxi,points);
        }
    }
    return dp[day][last]=maxi;
}

//Tabulation
int Tabulation(int n, vector<vector<int>>& a) {
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(a[0][1], a[0][2]);
    dp[0][1] = max(a[0][0], a[0][2]);
    dp[0][2] = max(a[0][0], a[0][1]);
    dp[0][3] = max(a[0][0], max(a[0][1], a[0][2]));

    for (int day = 1; day < n; day++) {

        for (int last = 0; last < 4; last++) {

            dp[day][last] = 0;

            for (int task = 0; task < 3; task++) {

                if (task != last) {

                    int point = a[day][task] + dp[day - 1][task];

                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    } 

    return dp[n - 1][3];
}




int NinjaTraining(vector<vector<int>>& a,int n){
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return fM(n-1,3,a,dp);
    // return f(n-1,3,a);
}
int main(){
    vector<vector<int>> a ={{1,2,5},{3,1,1},{3,3,3}};
    int n = a.size();
    cout<<NinjaTraining(a,n);
}