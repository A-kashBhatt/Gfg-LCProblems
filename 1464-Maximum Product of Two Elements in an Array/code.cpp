// Time Complexity :O(n)
// Space Complexity:O(1)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int mx = 0, secondMx = 0;
        for (auto it : nums)
        {
            if (it >= mx)
            {
                secondMx = mx;
                mx = it;
                continue;
            }
            if (it > secondMx)
                secondMx = it;
        }
        return (mx - 1) * (secondMx - 1);
    }
};