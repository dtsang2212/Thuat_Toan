#include<bits/stdc++.h>
using namespace std;

int a[1000][1000],s[100000];
int n,m,x=1,sum=0;
int sodinh;
bool kt[100000];
void nhap(void)
{
 	int u,v,w;
 	cin>>n>>m;
 	for (int i = 1; i <= n; i++)
	{
 		kt[i] = false;
  		for (int j = 1; j <= n; j++)
  		{
   			a[i][j]=INT_MAX;
   			a[j][i]=INT_MAX;
   		}
 	}
 	for (int i = 1; i <= m; i++)
	{
  		cin>>u>>v>>w;
  		a[u][v] = w;
  		a[v][u] = w;
 	}
}
void prim(int u)
{
 	int MIN, k, t;
 	sodinh = 0;
 	s[x] = u;
 	kt[u] = true;
 	while (sodinh<n - 1)
	{
 		MIN = INT_MAX;
  		for (int i = 1; i <= x; i++)
		{
   			t = s[i];
   			for (int j = 1; j <= n; j++)
			{
   				 if (kt[j]==false && MIN>a[t][j])
				{
    				MIN = a[t][j];
    				k = j;
    			}
   			}
  		}
 		sodinh++;
  		sum =sum + MIN;
  		kt[k] = true;
 		x++;
  		s[x] = k;
 	}
 	cout<<sum;
 	//for(int i=1;i<=n;i++)
 	//	if(kt[i] == true)
	//	 	cout << i << " ";
}
int main()
{
 	nhap();
	prim(1);
}
