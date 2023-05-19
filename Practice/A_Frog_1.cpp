#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int i, vector<int> &mem, vector<int> &cost){
    if(i == 0) return 0;
    if(mem[i]!=-1) return mem[i];
    int oneStep = f(i-1, mem, cost) + abs(cost[i] - cost[i-1]);
    int twoStep = INT_MAX;
    if(i>1)
        twoStep = f(i-2, mem, cost)+ abs(cost[i] - cost[i-2]);
    return mem[i] = min(oneStep, twoStep);
    
}

int fTopDown(int N, vector<int> &cost){
    vector<int> dp(N, -1);
    dp[0] = 0;
    for(int i = 1; i<N; i++){
        int oneStep = dp[i-1] + abs(cost[i] - cost[i-1]);
        int twoStep = INT_MAX;
        if(i>1)
            twoStep = dp[i-2] + abs(cost[i] - cost[i-2]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[N-1];
}

int fTopDownOptimised(int N, vector<int> &cost){
    vector<int> dp(N, -1);
    dp[0] = 0;
    for(int i = 1; i<N; i++){
        int oneStep = dp[i-1] + abs(cost[i] - cost[i-1]);
        int twoStep = INT_MAX;
        if(i>1)
            twoStep = dp[i-2] + abs(cost[i] - cost[i-2]);
        dp[i] = min(oneStep, twoStep);
    }
    return dp[N-1];
}

// Function to solve the problem for each test case
void solve() {
    int N;
    cin >> N;

    vector<int> cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    vector<int> mem(N, -1);

    f(N-1, mem, cost);
    // cout<<mem[N-1]<<endl;
    cout<<fTopDown(N, cost)<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}