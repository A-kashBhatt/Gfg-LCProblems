// using count of each and every weight ,kinda count sort algo
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        vector<int> v(limit + 1, 0);
        int sz = people.size();
        for (auto it : people)
            v[it]++;

        int j = 0;
        for (int i = 0; i < v.size(); i++)
        {
            while (v[i])
            {
                people[j++] = i;
                v[i]--;
            }
        }
        int boats = 0;
        int left = 0, right = sz - 1;
        while (right >= left)
        {
            if (people[left] + people[right] <= limit)
                left++;
            right--;
            boats++;
        }
        return boats;
    }
};