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
vector<vector<ll>> psum;
vector<vector<ll>> a;
vector<vector<vector<ll>>> maxdp;
vector<vector<vector<ll>>> mindp;
ll n,m,k;
void prog()
{
	cin>>n>>m>>k;
	psum = vector<vector<ll>>(n+1,vector<ll>(m+1,0) );
	a = vector<vector<ll>>(n+1,vector<ll>(m+1,0) );
	maxdp = vector<vector<vector<ll>>>(n+1, vector<vector<ll>>(m+1, vector<ll>(k+1)));
	mindp = vector<vector<vector<ll>>>(n+1, vector<vector<ll>>(m+1, vector<ll>(k+1)));
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            cin>>a[i][j];
            psum[i][j] = psum[i][j-1] + a[i][j];
        }
    }
    for(int i = 1; i<= n;i++)
    {
        for(int j = 1; j<=m;j++)
        {
            for(int z = 0; z <= (n-i);z++)
            {
                if(z>k)
                    break;
                if(i==1)
                {
                    mindp[1][j][z] = psum[1][j-1];
                    maxdp[1][j][z] = psum[1][j];
                    continue;
                }
                if(z==k)
                {
                    mindp[i][j][z] = psum[i][j-1] + mindp[i-1][j][z];
                    maxdp[i][j][z] = psum[i][j] + maxdp[i-1][j][z];
                    continue;
                }
                if(j==1)
                {
                    mindp[i][j][z] = psum[i][j-1] + mindp[i-1][j][z];
                    maxdp[i][j][z] = psum[i][j] + maxdp[i-1][j][z];
                    continue;

                }

                mindp[i][j][z] = psum[i][j-1] + min(mindp[i-1][j][z] , mindp[i-1][j-1][z+1]);
                maxdp[i][j][z] = psum[i][j] + max(maxdp[i-1][j][z] , maxdp[i-1][j-1][z+1]);
            }
        }
    }
    ll ans =-INF;

    for(int i = 1; i<=m-k-1;i++)
    {
        for(int j = i + k + 1; j<=m;j++)
        {

            ans =  max(ans, maxdp[n][j][0] - mindp[n][i][0]);
        }
    }
    cout<<ans;NL;
}
int main()
{

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--)
		prog();
	return 0;
}
