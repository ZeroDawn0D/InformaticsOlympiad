#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000000000
#define PB push_back
#define umap unordered_map
#define uset unordered_set
#define yeet return 0
#define ff first
#define ss second
#define NL cout<<'\n'
#define debug1(n) cout<<"Reached: "<<n
#define debug(n) cout<<"Reached: "<<n
using namespace std;

void prog()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> c(n+1);
    vector<pair<ll,ll>> tp(m+1);
    for(int i = 1; i<=n;i++)
        cin>>c[i];
    for(int i = 1; i<=m;i++)
        cin>>tp[i].ss;
    for(int i = 1; i<=m;i++)
        cin>>tp[i].ff;
    sort(tp.begin(), tp.end());
    //vector<vector<ll>> dp (n+1, vector<ll> (m+1));
    ll dp[5005][5005];
    dp[0][0] = 0;
    for(int i = 0; i<=n;i++)
    {
        for(int j = 0; j<=m;j++)
        {
            if(i||j) dp[i][j] = INF;
            if(j)
            {
                ll cost;
                if(dp[i][j-1] > tp[j].ff ) cost = INF;
                else if (dp[i][j-1]+tp[j].ss  < tp[j].ff ) cost = tp[j].ff;
                else cost = dp[i][j-1] + tp[j].ss;

                dp[i][j] = cost;
            }
            if(i)
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + c[i]);
            }
        }
    }
    dp[n][m]!=INF?cout<<dp[n][m]:cout<<-1;NL;
}
int main()
{

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--)
		prog();
	yeet;
}
