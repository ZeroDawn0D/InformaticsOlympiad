#include <bits/stdc++.h>
#define ll long long
#define INF 100000000
#define PB push_back
#define umap unordered_map
#define uset unordered_set
#define MP make_pair
#define NL cout<<endl
#define debug1(n) cout<<"Reached: "<<n
#define debug(n) cout<<"Reached: "<<n
#define ff first
#define ss second
using namespace std;
set<pair<ll,ll>> cult;
set<pair<ll,ll>> constcult;
int fences(pair<ll,ll> p)
{
    ll x = p.ff , y = p.ss;
    pair<ll,ll> up = {x-1,y};
    pair<ll,ll> down = {x+1,y};
    pair<ll,ll> left = {x,y-1};
    pair<ll,ll> right = {x,y+1};
    ll temp = 4;
    if(constcult.find(up) != constcult.end())
        temp--;
    if(constcult.find(down) != constcult.end())
        temp--;
    if(constcult.find(left) != constcult.end())
        temp--;
    if(constcult.find(right) != constcult.end())
        temp--;
    return temp;
}
vector<pair<ll,ll>> adj(pair<ll,ll> p)
{
    ll x = p.ff , y = p.ss;
    pair<ll,ll> up = {x-1,y};
    pair<ll,ll> down = {x+1,y};
    pair<ll,ll> left = {x,y-1};
    pair<ll,ll> right = {x,y+1};
    vector<pair<ll,ll>> ans;
    if(cult.find(up) != cult.end())
        ans.PB(up);
    if(cult.find(down) != cult.end())
        ans.PB(down);
    if(cult.find(left) != cult.end())
        ans.PB(left);
    if(cult.find(right) != cult.end())
        ans.PB(right);
    return ans;
}
ll dfs(pair<ll,ll> u)
{
    //cout<<"NODE: "<<u.ff<<" "<<u.ss;
    cult.erase(u);
    ll ans = fences(u);
    //cout<<" FENCES: "<<ans;NL;
    auto alist = adj(u);
    for(auto i = alist.begin(); i !=alist.end();i++)
    {
        if(cult.find(*i)!=cult.end())
            ans += dfs(*i);
    }
    return ans;
}
void prog()
{
	ll r,c,n;
	cin>>r>>c>>n;
	for(int i = 1; i<= n;i++)
    {
        ll x,y;
        cin>>x>>y;
        cult.insert({x,y});
    }
    constcult = cult;
    ll maxn = -1;
    while(cult.size()>0)
    {
        pair<ll,ll> x = *(cult.begin());
        ll temp = dfs(x);
        //cout<<temp;NL;
        maxn = max(temp, maxn);
    }
    cout<<maxn;NL;
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
