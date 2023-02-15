#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int>& wt,vector<int>& val, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(W+1));

    for(int i=0; i<=n; i++) {
        for(int w=0; w<=W; w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w] = 0;
            }
            else if(wt[i-1] <= w)
            {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int W = 50;
    vector<int> wt = {30, 10, 20};
    vector<int> val = {40, 115, 130};
    int n = wt.size();
    cout << knapsack(W, wt, val, n) << endl;

    return 0;
}
