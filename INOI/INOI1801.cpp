#include <bits/stdc++.h>
#define ll long long
using std::cin;
using std::cout;
using std::vector;
using std::queue;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int z = 0; z < t;z++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> x (0,0);
        vector<vector<int>> roads(n,x);
        vector<int> mus;
        vector<bool> visited(n,false);
        vector<int> graphs;
        for(int i = 0; i < m;i++)
        {
            int u,v;
            cin>>u>>v;
            u--;v--;
            roads[u].push_back(v);
            roads[v].push_back(u);
        }
        for(int i = 0 ; i < n;i++)
        {
            int y;
            cin>>y;
            mus.push_back(y);
        }
        for(int i = 0; i < n;i++)
        {
            if(!visited[i])
            {
                int sum = 0;
                queue<int> bfs;
                bfs.push(i);
                visited[i] = true;
                while(!bfs.empty())
                {
                    int y = bfs.front();
                    sum+= mus[y];
                    for(int j = 0; j < roads[y].size();j++)
                    {
                        if(!visited[roads[y][j]])
                        {
                            bfs.push(roads[y][j]);
                            visited[roads[y][j]] = true; 
                        }
                    }
                    bfs.pop();
                }
                graphs.push_back(sum);
            }
        }
        int ans = 0;
        if(graphs.size() < k)
            ans = -1;
        else
        {
            std::sort(graphs.begin(), graphs.end());
            int n_p = 0;
            int l_p = graphs.size() -1;
            for(int i = 0; i < k ;i++)
            {
                
                if(i%2 == 0) // lav turn
                {
                    ans+=graphs[l_p];
                    l_p--;
                }
                else //nik turn
                {
                    ans+=graphs[n_p];
                    n_p++;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
