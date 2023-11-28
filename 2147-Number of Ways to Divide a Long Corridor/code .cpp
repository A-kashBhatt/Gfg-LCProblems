// using memoization
// T.C--->O(n)
// S.C-->O(n)
class Solution
{
    int modulo = 1e9 + 7;
    int helper(string &corridor, int curr, int seats, vector<vector<int>> &dp)
    {
        if (curr == corridor.size())
        {
            if (seats == 2)
                return 1;
            return 0;
        }
        if (dp[curr][seats] != -1)
            return dp[curr][seats];
        int ans = 0;
        if (seats < 2)
        {
            if (corridor[curr] == 'S')
            {
                ans = helper(corridor, curr + 1, seats + 1, dp);
            }
            else
                ans = helper(corridor, curr + 1, seats, dp);
        }
        else
        {
            // place the divider here if it is not the last element of the corridor
            if (corridor[curr] == 'S')
                ans = helper(corridor, curr + 1, 1, dp);
            else
                ans = helper(corridor, curr + 1, 0, dp);
            // dont place
            if (corridor[curr] != 'S')
                ans = (ans + helper(corridor, curr + 1, seats, dp)) % modulo;
        }
        return dp[curr][seats] = ans;
    }

public:
    int numberOfWays(string corridor)
    {
        int sz = corridor.size();
        vector<vector<int>> dp(sz + 1, vector<int>(3, -1));
        return helper(corridor, 0, 0, dp);
    }
};

// ************** Another better solution ************************

// using combination technique maths
// T.C --->O(n)
// S.C --->O(1)

class Solution
{
    int modulo = 1e9 + 7;

public:
    int numberOfWays(string corridor)
    {
        int indexOfPrevPlant = -1, seats = 0, sz = corridor.size();
        long long ans = 1;
        for (int i = 0; i < sz; i++)
        {
            if (corridor[i] == 'P')
                continue;
            seats++;
            if (seats > 2 && (seats % 2))
            {
                ans = (ans * (i - indexOfPrevPlant)) % modulo;
            }
            indexOfPrevPlant = i;
        }
        if ((seats % 2) || seats == 0)
            return 0;
        return ans;
    }
};