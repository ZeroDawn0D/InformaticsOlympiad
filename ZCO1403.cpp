//link: https://www.codechef.com/ZCOPRAC/problems/ZCO14003
// Sort 0-indexed array in ascending
// i-th object is bought by (n-i) people
// maximise

#include <bits/stdc++.h>
#define ll long long
#define NL cout<<'\n';
#define fast_io cin.tie(0);cout.tie(0); ios_base::sync_with_stdio(0)
#define INF 100000000
#define unordered_map umap
#define unordered_set uset
#define debug(x) cout<<x<<' '
#define debugNL(x) cout<<x<<'\n'

using namespace std;

void prog()
{
    ll n;
    cin>>n;
    ll* a = new ll[n];
    for(int i = 0; i < n;i++)
        cin>>a[i];
    sort(a,a+n);
    ll max_ans=-1;
    for(int i = 0; i < n;i++)
        max_ans = max(max_ans, a[i] * (n-i));
    cout<<max_ans;NL;
}

int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    //cin>>t;
    while(t>0)
    {
        prog();
        t--;
    }
    return 0;
}
