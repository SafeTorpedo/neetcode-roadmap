#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> adj(n, vector<int>(n));
        for (int i = 0; i < flights.size(); i++)
        {
            vector<int> flight = flights[i];
            adj[flight[0]][flight[1]] = flight[2];
        }

        vector<int> distances(n, INT_MAX);
        distances[src] = 0;

        vector<int> currStops(n, INT_MAX);
        currStops[src] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        while (!pq.empty())
        {
            int cost = pq.top()[0];
            int node = pq.top()[1];
            int stops = pq.top()[2];
            pq.pop();

            if (node == dst)
                return cost;

            if (stops == k + 1)
                continue;

            for (int neighbor = 0; neighbor < n; neighbor++)
            {
                if (adj[node][neighbor] > 0)
                {
                    int currCost = cost;
                    int neighborDist = distances[neighbor];
                    int neighborWeight = adj[node][neighbor];

                    int currDist = currCost + neighborWeight;
                    if (currDist < neighborDist || stops + 1 < currStops[neighbor])
                    {
                        pq.push({currDist, neighbor, stops + 1});
                        distances[neighbor] = currDist;
                        currStops[neighbor] = stops;
                    }
                    else if (stops < currStops[neighbor])
                        pq.push({currDist, neighbor, stops + 1});

                    currStops[neighbor] = stops;
                }
            }
        }

        if (distances[dst] == INT_MAX)
            return -1;

        return distances[dst];
    }
};