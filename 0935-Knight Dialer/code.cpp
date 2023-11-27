class Solution
{
    int modulo = 1e9 + 7;
    int helper(int n, vector<vector<int>> &moves, int start, vector<vector<int>> &dp)
    {
        if (n == 1)
            return 1;
        if (dp[n][start] != -1)
            return dp[n][start];
        int ans = 0;
        for (auto it : moves[start])
        {
            ans = (ans + helper(n - 1, moves, it, dp)) % modulo;
        }
        return dp[n][start] = ans;
    }

public:
    int knightDialer(int n)
    {
        if (n == 1)
            return 10;
        vector<vector<int>> moves = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<int>> dp(n + 1, vector<int>(10, -1));
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            if (i == 5)
                continue;
            ans = (ans + helper(n, moves, i, dp)) % modulo;
        }
        return ans;
    }
};