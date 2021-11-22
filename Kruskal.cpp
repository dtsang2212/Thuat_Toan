#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define maxn 100000

int n, m;
int par[maxn], ans = 0, t;

struct krus
{
    int fi, se, wi;
    bool check;
};
krus a[maxn];
bool cmp(krus x, krus y)
{
    return x.wi < y.wi;
}
void read()
{
    cin >> t >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> a[i].fi >> a[i].se >> a[i].wi;
        a[i].check = false;
    }
    sort(a + 1, a + m + 1, cmp);
}
int find_set(int u)
{
    if(par[u] == u)
        return u;
    else
        return par[u] = find_set(par[u]);
}
int uion_set(int x, int y)
{
    if(par[x] < par[y])
        par[y] = par[x];
    else
        par[x] = par[y];
    return par[x];
}
void kruskal()
{
    for(int i = 1; i <= n; i++)
        par[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        x = find_set(a[i].fi);
        y = find_set(a[i].se);
        if(x!=y)
        {
            a[i].check = true;
            par[a[i].se] = uion_set(x,y);
            par[a[i].fi] = uion_set(x,y);
        }
    }
    for(int i = 1; i <= m; i++)
        if(a[i].check == true)
            cout << i << " ";
}
int main()
{
    read();
    kruskal();
    return 0;
}
