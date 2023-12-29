#include <bits/stdc++.h>
using namespace std;

class DetectSquares
{
public:
    DetectSquares()
    {
    }

    void add(vector<int> p)
    {
        cntPoints[p[0]][p[1]]++;
        points.emplace_back(p[0], p[1]);
    }

    int count(vector<int> p1)
    {
        int x1 = p1[0], y1 = p1[1], ans = 0;
        for (auto &[x3, y3] : points)
        {
            if (abs(x1 - x3) == 0 || abs(x1 - x3) != abs(y1 - y3))
                continue;
            ans += cntPoints[x1][y3] * cntPoints[x3][y1];
        }

        return ans;
    }

private:
    int cntPoints[1001][1001] = {};
    vector<pair<int, int>> points;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */