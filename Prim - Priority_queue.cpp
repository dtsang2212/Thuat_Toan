#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define maxn 1000000

int n, m;
const int INF = 1e9;
typedef pair<int, int> ii;
vector<ii> x[maxn];
int dis[maxn] = {INF};
int ans = 0;

void read()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		x[u].push_back({v,w});
		x[v].push_back({u,w});
	}
}
void prim(int s)
{
	priority_queue<ii, vector<ii>, greater<ii>> q;
	for(int i = 1; i <= n; i++)
        dis[i] = INF;
	q.push({0,s});
	dis[s] = 0;
	while(!q.empty())
	{
		auto o = q.top();
        q.pop();
		int  du = o.first, u = o.second;
		if(du != dis[u]) continue;
		ans += dis[u];
		dis[u] = 0;
		for(auto &e:x[u])
		{
			int v = e.first, w = e.second;
			if(dis[v] > w)
			{
				dis[v] = w;
				q.push({dis[v],v});
			}
		}
        for(int i = 1; i <= n; i++)
        {
            cout << dis[i] << " ";
        }
        cout << endl;
	}

    cout << endl << ans;
}
int main()
{
	read();
	prim(1);
}
