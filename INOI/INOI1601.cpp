#include <bits/stdc++.h>
#define ll long long
using std::cin;
using std::cout;
using std::unordered_map;
using std::string;
using std::set;
using std::vector;
int max_dif;
vector<vector<int>> tree;
vector<int> A;
int min_dfs(int u)
{
 //   if(tree[u].size()==0)
    //    return A[u];
    //cout<<"At node: "<<u<<'\n';
    int min_subtree = A[u];
    for(int v = 0; v < tree[u].size();v++)
    {
        min_subtree = std::min(min_subtree, min_dfs(tree[u][v]));
    }
    max_dif = std::max(max_dif, A[u] - min_subtree);
    return min_subtree;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int root;
    vector<int> x(0,0);
    for(int i = 0; i< n;i++)
    {
        tree.push_back(x);
    }
    for(int i = 0; i < n;i++)
    {
        int x;
        cin>>x;
        A.push_back(x);
    }
    for(int j = 0; j < n;j++)
    {
        int x;
        cin>>x;
        x--;
        if(x==-2)
        {
            root = j;
            continue;
        }
        tree[x].push_back(j);
    }

    max_dif = 0;
    int z = min_dfs(root);
    cout<<max_dif<<'\n';
}
