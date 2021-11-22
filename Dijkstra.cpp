////////// ??????̀?? ? ?????????? ? ????????  ////////////



#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

#define oo 1e9+7
#define endl "\n"

int kn[10000] = {0};
bool check[10000];
int f[10000];
int a[10000][10000] = {0};
int trace[10000];
int n, m;
int d, c;

void dijkstra(int s, int e)
{
    for(int i = 1; i <= n; i++)
    {
        f[i] = oo;
        check[i] = true;
    }
    int v = s;
    f[s] = 0;
    check[s] = false;
    trace[s] = -1;
    while(v != e)
    {
        long long minn = oo;
        for(int i = 1; i <= n; i++)
        {
            if(check[i] == true && minn > f[i])
            {
                minn = f[i];
                v = i;
            }
        }
        check[v] = false;
        for(int i = 1; i <= n; i++)
        {
            if(a[v][i] > 0 && f[i] > f[v] + a[v][i])
            {
                f[i] = f[v]+a[v][i];
                trace[i] = v;
            }
        }
    }
    cout << f[e] << endl;
    int u=trace[e];
    int dem = 0, truyvet[10000];
    while(u != -1)
    {
        dem++;
        truyvet[dem] = u;
        u = trace[u];
    }
    cout << dem + 1 << " ";
    for(int i = dem; i >= 1; i--)
        cout << truyvet[i] << " ";
    cout << e;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("dt.inp","r",stdin);
    freopen("dt.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i<= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    cin >> d >> c;
    dijkstra(d, c);
}
