#include <bits/stdc++.h>
using namespace std;
int prims(vector<vector<int>> edges, int n, int source)
{
    vector<vector<pair<int, int>>> adj(n);
    for (auto x : edges)
    {
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    // if no need to return tree no need of parent in pq
    // minHeap->{ew,{node,parent}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> vis(n);
    // vector<pair<int, int>> edgesOfMst;
    int wtMst = 0;
    pq.push({0, {source, -1}});
    while (!pq.empty())
    {
        int edgeWt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if (!vis[node])
        {
            vis[node] = 1;
            if (parent != -1)
            {
                wtMst += edgeWt;
                // edgesOfMst.push_back({parent, node});
            }
            for (auto x : adj[node])
            {
                int adjNode = x.first;
                int ew = x.second;
                if (!vis[adjNode])
                {
                    pq.push({ew, {adjNode, node}});
                }
            }
        }
    }
    // for (auto x : edgesOfMst)
    // {
    //     cout << x.first << "->" << x.second << endl;
    // }
    return wtMst;
}
int kruskal(vector<vector<int>> edges, int n, int source)
{

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int e, n;
    cin >> e >> n;
    vector<vector<int>> edges;
    while (e--)
    {
        int from, to, wt;
        cin >> from >> to >> wt;
        edges.push_back({from, to, wt});
    }
    cout << prims(edges, n, 0);
    // cout << kruskal(edges, n);
    return 0;
}