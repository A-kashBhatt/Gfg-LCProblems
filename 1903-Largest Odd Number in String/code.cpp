// O(N)---->time complexity
// O(1)----->space complexity

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int sz = num.size(), i = sz - 1;
        while (i >= 0 && ((num[i] - '0') % 2 == 0))
        {
            i--;
        }
        return num.substr(0, i + 1);
    }
};