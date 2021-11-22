/////////// 🅓🅞🅐̀🅝 ​ 🅣🅗🅐🅝🅗 ​ 🅢🅐🅝🅖  ////////////



#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, dp[1000][1000];
int w[1000], gt[1000];
int q;
int res=0;
int kt[1000],d=0;

void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)
    {
        cin>> w[i] ;
    }
    for(int i = 1; i <= n; i ++)
    {
        cin>> gt[i] ;
    }
    dp[0][0]=0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= q; j ++)
        {
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] =  max(dp[i-1][j], dp[i-1][j-w[i]] + gt[i]);
        }
    }
    int x = q;
    for(int i = n; i >= 1; i --)
    {
        if(x >= w[i] && dp[i][x] == dp[i-1][x-w[i]] + gt[i])
        {
            d++;
            kt[d]=i;
            res += w[i];
            x -= w[i];
        }
    }
    cout << dp[n][q] ;
    /*for(int i = d; i>= 1; i--)
    {
        cout<<kt[i]<<" ";
    }
    cout << endl << res;*/
}
int main()
{
    freopen("knapsack.inp","r",stdin);
    freopen("knapsack.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}