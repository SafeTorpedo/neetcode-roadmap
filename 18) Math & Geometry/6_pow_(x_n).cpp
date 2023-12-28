#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long r = n;

        if (r < 0)
            r *= -1;

        while (r != 0)
        {
            if (r % 2)
            {
                ans = ans * x;
                r--;
            }
            else
            {
                x = x * x;
                r /= 2;
            }
        }

        if (n < 0)
            ans = (double)1.0 / (double)ans;

        return ans;
    }
};