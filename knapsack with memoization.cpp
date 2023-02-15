#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, vector<int>& wt, vector<int>& val, int n, unordered_map<string, int>& memo)
{
    if(n == 0 || W == 0)
    {
        return 0;
    }
    string key = to_string(n) + "|" + to_string(W);
    if(memo.count(key))
    {
        return memo[key];
    }
    if(wt[n-1] > W)
    {
        memo[key] = knapsack(W, wt, val, n-1, memo);
    }
    else
    {
        memo[key] = max(val[n-1] + knapsack(W-wt[n-1], wt, val, n-1, memo), knapsack(W, wt, val, n-1, memo));
    }
    return memo[key];
}
//syed mahmudul hasan
//ID:C213080
int main()
{
    int W = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};

    int n = wt.size();
    unordered_map<string, int> memo;
    cout << knapsack(W, wt, val, n, memo) << endl;

    return 0;
}

