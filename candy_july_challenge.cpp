// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3793/

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> res(ratings.size(), 1); //initialize all values with 1 (minimum 1)
        int val = 0;
        // checking from left
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                res[i] = res[i - 1] + 1;
            }
        }
        // checking from right
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                res[i] = max(res[i], res[i + 1] + 1);
            }
        }
        for (int i = 0; i < res.size(); i++)
        {
            val += res[i];
        }
        return val;
    }
};