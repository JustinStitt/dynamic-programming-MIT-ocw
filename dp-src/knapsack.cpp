#include <bits/stdc++.h>

using namespace std;

/*
 *  subproblems: capacity from 0 to capacity
 *  what to memoize: max value from items so far :: Int
 */

int knapsack(vector<int>& values, vector<int>& weights, int capacity){
    const int n = capacity;
    vector<int> dp(n + 1);
    // solve basis step (easy part, bottom-up basic)
    dp[0] = 0; // reads: with capacity 0, our max value will be 0
    
    for(int x = 1; x <= n; ++x){
        // overlapping subproblem relation usually has min or max for optimization problems
        for(int y{}; y < values.size(); ++y){
            int v = values[y],
                w = weights[y];
            if(w > x) { dp[x] = max(dp[x], dp[x-1]); continue; } // must use previous if our current weight too big to fit
            // otherwise max between previous soln. (not including this item) or x-w soln. (including this item)
            dp[x] = max(dp[x-1], dp[x-w] + v); 
        }   
    }
    // goal at the end: return dp[n]
    return dp[n];
}

int main(){
    vector<int> values{60,100,120, 200};
    vector<int> weights{10,20,30, 40};
    int capacity = 50;
    int ans = knapsack(values, weights, capacity);
    printf("Maximum value: %d\n", ans);
    return 0;
}
