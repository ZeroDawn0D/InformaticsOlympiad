#include <bits/stdc++.h>
#define ll long long
using std::cin;
using std::cout;
using std::unordered_map;
using std::string;
using std::set;
using std::vector;
struct data
{
    int cobol;
    int other;
};
bool structComp(data a1, data a2)
{
    return (a1.other>a2.other);
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<data> arr;
    for(int i = 0; i < n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        data w;
        w.cobol = x;
        w.other = y+z;
        arr.push_back(w);
    }
    int prefix = 0;
    int max = 0;
    std::sort(arr.begin(),arr.end(),structComp);
    for(int i = 0; i < arr.size();i++)
    {
        prefix+=arr[i].cobol;
        max = std::max(max, prefix + arr[i].other);
    }
    cout<<max;
}
