#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define NL cout<<std::endl
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
vector<set<ll>> id;
vector<bool> visited;
vector<vector<ll>> graph;
ll n,k;
bool isRel(ll a, ll b)
{
    ll c = 0;
   // cout<<"entered";NL;
    for(auto it = id[a].begin(); it != id[a].end() ;it++)
    {
       // cout<<"entered loop";NL;
        //cout<<*it;NL;
        if(id[b].find(*it) == id[b].end())
        {
            //cout<<"NOT FOUND";NL;
        }
        else
        {
            //cout<<"FOUND";NL;
            c++;
            if(c==k)
            {
                //cout<<"TRUE";NL;
                return true;
            }
        }
    }
    //cout<<"FALSE";NL;
    return false;
}
ll dfs(ll u)
{
    //cout<<"NODE: "<<u;NL;
    visited[u] = true;
    ll sum = 1;
    for(int i = 0; i < graph[u].size();i++)
    {
        if(!visited[graph[u][i]])
        {
            visited[graph[u][i]] = true;
            sum += dfs(graph[u][i]);
        }
    }
    return sum;
}
void prog()
{
    //cout<<"HERE";NL;
    ll p;
    cin>>n>>k;
    id = vector<set<ll>>(n+1);
    //cout<<"HERE@";NL;
    for(int i = 1;i<=n;i++)
    {
        cin>>p;
        for(int j = 0; j < p;j++)
        {
            ll x;
            cin>>x;
            id[i].insert(x);
        }
    }
    graph = vector<vector<ll>>(n+1);
    //cout<<"HERE1";NL;
    for(int i = 1; i<n;i++)
    {
        for(int j = i+1;j<=n;j++)
        {
            //cout<<"isrel "<<i<<" "<<j;NL;
            if(isRel(i,j))
            {
                //cout<<"here again";NL;
                graph[i].PB(j);
                graph[j].PB(i);
            }
        }
    }
    //cout<<"HERE2";NL;
    visited = vector<bool>(n+1);
    cout<<dfs(1);NL;
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
