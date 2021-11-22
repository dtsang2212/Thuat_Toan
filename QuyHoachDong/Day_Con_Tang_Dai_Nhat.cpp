#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define N 1000000

int n, a[N], b[N], f[N], m = 0;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        f[i] = lower_bound(b+1,b+m+1,a[i])-b;
        m = max(m,f[i]);
        b[f[i]] = a[i];
    }
    for(int i = 1; i <= n; i++)
        cout << f[i] << " " << b[i] <<endl;
    cout << m;
    return 0;
}
