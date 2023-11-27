class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int i = 0, sz = people.size(), j = sz - 1;
        int bt = 0;
        while (j >= i)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
            }
            j--;
            bt++;
        }
        return bt;
    }
};