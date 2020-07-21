#include <bits/stdc++.h>
#define ll long long
#define INF 100000000
#define PB push_back
#define NL cout<<'\n'
#define debug1(n) cout<<"Reached: "<<n
#define debug2(n) cout<<"Reached: "<<n
using std::cout;
using std::cin;
using std::vector;
using std::map;
using std::unordered_map;
using std::string;
using std::priority_queue;
using std::set;
using std::unordered_set;
using std::deque;
ll n,k;
vector<ll> a, fdp, bdp;
ll maxi = 0;
ll backw(ll k)
{
    if(k==1)
        return bdp[1];
    if(k==2)
        return bdp[2];
    bdp[k] = std::min(a[k-1] + bdp[k-1],a[k-2] + bdp[k-2]);
    return bdp[k];
}
void prog()
{
	cin>>n>>k;
	a = vector<ll> (n+5,0);
	for(int i = 1; i<=n;i++)
        cin>>a[i];
    fdp = vector<ll> (n+5,-INF);
    bdp = vector<ll> (n+5, -INF);
    bdp[1] = 0;
    bdp[2] = a[1];
    //for(int i = 1; i<=n;i++)
        //cout<<a[i]<<" ";
    //NL;
    for(int i = 3; i<=n;i++)
    {
        //cout<<a[i-1] + bdp[i-1]<<","<<a[i-2] + bdp[i-2];
        //NL;
        bdp[i] = std::max(a[i-1] + bdp[i-1], a[i-2] + bdp[i-2]);
    }
    fdp[k] = 0;
    ll ans = fdp[k] + bdp[k];
    fdp[k+1] = a[k+1];
    ans = std::max(ans,fdp[k+1] + bdp[k+1]);
    //for(int i = 1; i<=n;i++)
   // {
   //     cout<<bdp[i]<<" ";
   // }
    //NL;

    for(int i = k+2; i<=n;i++)
    {
        fdp[i] = a[i] + std::max(fdp[i-1], fdp[i-2]);
        ans = std::max(ans, fdp[i] + bdp[i]);
    }
    //for(int i = 1; i<=n;i++)
   // {
   //     cout<<fdp[i]<<" ";
   // }
    //NL;
    cout<<ans;
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
