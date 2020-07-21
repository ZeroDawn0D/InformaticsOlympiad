#include <bits/stdc++.h>
#define ll long long
#define INF 100000000
#define PB push_back
#define umap unordered_map
#define uset unordered_set
#define MP make_pair
#define NL cout<<'\n'
#define debug1(n) cout<<"Reached: "<<n
#define debug(n) cout<<"Reached: "<<n
using namespace std;
ll graph[232][232];
void prog()
{
	ll c,f;
	cin>>c>>f;
	for(int i = 0; i<232;i++)
    {
        for(int j = 0;j<232;j++)
            graph[i][j] = -INF;
    }
	for(int i = 1; i <= f;i++)
    {
        ll x,y,p;
        cin>>x>>y>>p;
        graph[x][y] = p;
        graph[y][x] = p;
    }
    ll dp[232][232];
    for(int i = 0; i<232;i++)
    {
        for(int j = 0;j<232;j++)
            dp[i][j] = graph[i][j];
    }
    for(int k = 1; k <= c;k++)
    {
        for(int i = 1; i <= c; i++)
        {
            for(int j = 1; j <= c;j++)
            {
                if(i==j)
                    break;
                if(dp[i][k] != -INF && dp[k][j] != -INF)
                {
                    if((dp[i][j] > dp[i][k] + dp[k][j])||(dp[i][j]==-INF))
                    {
                        dp[i][j] = dp[i][k] + dp[k][j];
                        dp[j][i] = dp[i][j];
                    }
                }

            }
        }
    }
    ll ans = -INF;
    for(int i = 1; i <=c;i++)
    {
        for(int j = 1; j<=c;j++)
        {
            if(dp[i][j] != -INF)
            {
                //cout<<i<<" to "<<j<<" : "<<dp[i][j];NL;
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout<<ans;NL;
}
int main()
{

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--)
		prog();
	return 0;
}
