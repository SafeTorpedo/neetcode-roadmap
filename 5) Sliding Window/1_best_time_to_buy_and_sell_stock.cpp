#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MAX, sell = 0;
        for (int i : prices)
        {
            buy = min(buy, i);
            sell = max(sell, i - buy);
        }
        return sell;
    }
};