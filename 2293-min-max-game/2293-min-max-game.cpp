class Solution {
public:
    int minMaxGame(vector<int>& num) {
    if (num.size() == 1)
    {
        return num[0];
    }
    vector<int> newNum(num.size() / 2, 0);
    for (int i = 0; i < (num.size()) / 2; i++)
    {
        if (i % 2 == 0)
        {
            newNum[i] = min(num[2 * i], num[(2 * i) + 1]);
        }
        else
        {
            newNum[i] = max(num[2 * i], num[(2 * i) + 1]);
        }
    }
    return minMaxGame(newNum);        
        
    }
};