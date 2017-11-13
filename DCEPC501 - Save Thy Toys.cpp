#include<bits/stdc++.h>
#define mx 100005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
ll dp[mx][4];
int price[mx];
int n;
 
ll slove(int pos,int op)
{
	if(pos>=n)
		return 0;
 
	if(dp[pos][op]!=-1)
		return dp[pos][op];
 
    ll res=0;
	if(pos+op-1<n)
	{
		if(op==1)
		    res=price[pos]+max(slove(pos+2,1),max(slove(pos+2,2),slove(pos+2,3)));
	    else if(op==2)
		    res=price[pos]+price[pos+1]+max(slove(pos+4,1),max(slove(pos+4,2),slove(pos+4,3)));
	    else if(op==3)
		    res=price[pos]+price[pos+1]+price[pos+2]+max(slove(pos+6,1),max(slove(pos+6,2),slove(pos+6,3)));
 
	}
	else 
	{
		int rem=n-pos;
		if(rem==1)
			res=price[pos];
		else if(rem==2)
			res=price[pos]+price[pos+1];
		//
		//else if(rem==3)
 
	}
 
	return dp[pos][op]=res;
 
}
 
int main()
{
	int test;
	scanf("%d",&test);
 
	while(test--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&price[i]);
 
		memset(dp,-1,sizeof(dp));
		ll ans=max(slove(0,1),max(slove(0,2),slove(0,3)));
		printf("%lld\n",ans);
	}
 
	return 0;
} 
