//link: https://www.codechef.com/ZCOPRAC/problems/ZCO14001
// literally no algo

#include <bits/stdc++.h>
#define ll long long
#define INF 100000000
#define PB push_back
#define NL cout<<'\n'
#define debug1(n) cout<<"Reached: "<<n
#define debug2(n) cout<<"Reached: "<<n
using namespace std;
void prog()
{
	ll n,h;
	cin>>n>>h;
	ll* a = new ll[n];
	for(int i = 0; i<n;i++)
	{
	    cin>>a[i];
	}
	ll p = 0;
	bool hasbox = false;
	ll x;
	while(true)
	{
	    cin>>x;
	    if(x==0)
	        break;
	    else if(x==1)
	    {
	        if(p>0)
	            p--;
	    }
	    else if(x==2)
	    {
	        if(p<n-1)
	            p++;
	    }
	    else if(x==3)
	    {
	        if(!hasbox && a[p] > 0)
	        {
	            hasbox = !hasbox;
	            a[p]--;
	        }
	    }
	    else if(x==4)
	    {
	        if(hasbox && a[p]<h)
	        {
	            hasbox = !hasbox;
	            a[p]++;
	        }
	    }
	}
	
	for(int i = 0; i < n;i++)
	{
	    cout<<a[i]<<" ";
	}
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
