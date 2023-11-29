
// O(total number of bits)

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            if (n & 1)
                ans++;
            n = (n >> 1);
        }
        return ans;
    }
};
// O(no. of 1 bits)

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            ans++;
            n = (n & (n - 1));
        }
        return ans;
    }
};