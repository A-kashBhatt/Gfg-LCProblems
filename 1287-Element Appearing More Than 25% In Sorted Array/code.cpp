// Time Complexity------> O(n)
// Space Complexity-----> O(1)

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int sz = arr.size(), curr = -1, freq = 0;
        if (sz == 1)
            return arr[0];
        for (auto it : arr)
        {
            if (it == curr)
            {
                freq++;
                if (4 * freq > sz)
                    return it;
            }
            else
            {
                curr = it;
                freq = 1;
            }
        }
        return -1;
    }
};