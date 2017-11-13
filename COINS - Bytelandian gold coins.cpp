#include<bits/stdc++.h>
#define mx 1000000005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
 
map<ll,ll>dp;
 
ll slove(ll n)
{
	if(!n)
		return 0;
	if(dp[n]!=0)
		return dp[n];
 
	ll res=slove(n/2)+slove(n/3)+slove(n/4);
	return dp[n]=max(res,n);
}
 
int main()
{
    
    ll n;
 
    while(scanf("%lld",&n)==1)
    {
    	ll ans=slove(n);
    	printf("%lld\n",ans);
    	dp.clear();
    }
 
	return 0;
} 
