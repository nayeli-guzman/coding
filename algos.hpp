int knapsack(vi weights, vi values, int W) {

    int n=weights.size()+1, m=W+1;
    vvi dp(n, vi(m, 0));

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (j<weights[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(
                    dp[i-1][j], 
                    dp[i-1][j - weights[i-1]] + values[i-1]
                );
            }
        }
    }
    
    return dp[n-1][m-1];

}