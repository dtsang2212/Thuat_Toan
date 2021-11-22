#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define N 10000
#define MAX 10000000

typedef pair<int, int> ii;
int n, m, dis[N];
vector <ii> a[N];
int trace[N] = {0}, truyvet[N] = {0}, d = 1;

void dijkstra(int s)
{
    priority_queue <ii, vector<ii>, greater<ii>> q;
    for(int i = 1; i <= n; i++)
        dis[i] = MAX;
    dis[s] = 0;
    q.push({0,s});
    trace[s] = 0;
    while(!q.empty())
    {
        int du = q.top().first, u = q.top().second;
        q.pop();
        if(du != dis[u]) continue;
        for(auto &x : a[u])
        {
            int dv = x.first, v = x.second;
            if(dis[v] > du + dv)
            {
                dis[v] = du + dv;
                trace[v] = u;
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w,v});
        a[v].push_back({w,u});
    }
    int dau, cuoi;
    cin >> dau >> cuoi;
    dijkstra(dau);
    if(dis[cuoi] > 0)
    {
        int u = trace[cuoi];
        truyvet[d] = cuoi;
        while(u != 0)
        {
            d++;
            truyvet[d] = u;
            u = trace[u];
        }
        cout << dis[cuoi] << endl << d << " ";
        for(int i = d; i >= 1; i--)
        {
            cout << truyvet[i] << " ";
        }
    }
}


