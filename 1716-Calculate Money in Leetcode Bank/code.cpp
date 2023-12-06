// O(n)---->Time complexity
// O(1)---->Space Complexity

class Solution
{
public:
    int totalMoney(int n)
    {
        int mon = 1, ans = 0;
        while (n)
        {
            for (int i = 0; ((i < 7) && n); i++)
            {
                ans += (mon + i);
                n--;
            }
            mon++;
        }
        return ans;
    }
};

// O(1)--->Time Complexity
// O(1)--->Space Complexity

class Solution
{
public:
    int totalMoney(int n)
    {
        int x = n / 7, ans = 0;
        ans += (28 * x + 7 * x * (x - 1) / 2);
        int rem = n % 7, mon = x + 1;
        for (int i = 0; i < rem; i++)
        {
            ans += (mon);
            mon++;
        }
        return ans;
    }
};
