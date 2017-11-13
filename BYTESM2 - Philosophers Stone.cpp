#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#define mx 105
#define inf 1<<31
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
int arr[mx][mx];
int dp[mx][mx];
int h,w;
 
int rock(int i,int j)
{
	if(i>=0 and i<h and j>=0 and j<w)
	{
		if(dp[i][j]!=-1)
			return dp[i][j];
 
		int res=-inf;
		res=arr[i][j]+max(rock(i+1,j),max(rock(i+1,j-1),rock(i+1,j+1)));
		//res=max(res,arr[i][j]+rock(i+1,j));
		//res=max(res,arr[i][j]+rock(i+1,j+1));
		//res=max(res,arr[i][j]+rock(i+1,j-1));
		//cout<<res<<endl;
		return dp[i][j]=res;
	}
	else 
		return 0;
}
 
int main()
{
	int test,i,j,ans;
	scanf("%d",&test);
 
	while(test--)
	{
		scanf("%d%d",&h,&w);
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
 
		memset(dp,-1,sizeof(dp));
		ans=-inf;
		for(i=0;i<w;i++)
		    ans=max(ans,rock(0,i));
		printf("%d\n",ans);
	}
	return 0;
} 
