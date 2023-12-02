class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> v1(26, 0);
        for (auto it : chars)
            v1[it - 'a']++;
        int ans = 0;
        for (auto it : words)
        {
            vector<int> v2(26, 0);
            for (auto x : it)
                v2[x - 'a']++;
            bool flag = true;
            for (int i = 0; i < 26; i++)
            {
                if (v2[i] > v1[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                (ans += it.size());
        }
        return ans;
    }
};