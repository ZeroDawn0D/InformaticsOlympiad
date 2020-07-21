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
#define ff first
#define ss second
using namespace std;
ll n, s_in;
ll sumdig(ll n)
{
    ll ans = 0;
    while(n>0)
    {
        ans += n%10;
        n/=10;
    }
    return ans;
}
void prog()
{
	cin>>n>>s_in;
	vector<vector<ll>> dp(n+1, vector<ll>(n+1));
	vector<ll> e(n+1);
	vector<ll> tst(n+1);
	tst[0] = s_in;
	for(int i = 1; i <= n;i++)
    {
        tst[i] = tst[i-1] + (ll)(pow(sumdig(tst[i-1]),3));
        //cout<<"tst: "<<i<<": "<<tst[i];NL;
        cin>>e[i];
    }
    dp[1][0] = 0;
    for(int i = 2; i<=n; i++)
    {
        for(int t = 0; t < i;t++)
        {
            if(t==0)
                dp[i][t] = dp[i-1][t] + tst[t]*e[i-1];
            else if(i==t+1)
                dp[i][t] = dp[i-1][t-1];
            else
                dp[i][t] = max(dp[i-1][t-1], dp[i-1][t] + tst[t]*e[i-1]);

            //cout<<"DP: "<<i<<","<<t<<": "<<dp[i][t];NL;
        }
    }
    ll ans = -1;
    for(int t = 0; t < n; t++)
    {
        dp[n][t] = dp[n][t] + tst[t] * e[n];
        //cout<<"DP: "<<n<<","<<t<<": "<<dp[n][t];NL;
        ans = max(ans, dp[n][t]);
    }
    cout<<ans;NL;
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	prog();
	return 0;
}
