#include<bits/stdc++.h>
#define mx 8005
 
using namespace std;
int dp[mx][mx][4];
int h,a;
 
int slove(int cur_h,int cur_a,int op)
{
	if(cur_h<=0 or cur_a<=0)
		return 0;
	if(dp[cur_h][cur_a][op]!=-1)
		return dp[cur_h][cur_a][op];
 
	int res=0;
	if(op==0)
		res=1+max(slove(cur_h+3,cur_a+2,1),slove(cur_h+3,cur_a+2,2));
	else if(op==1)
		res=1+max(slove(cur_h-5,cur_a-10,0),slove(cur_h-5,cur_a-10,2));
	else if(op==2)
		res=1+max(slove(cur_h-20,cur_a+5,0),slove(cur_h-20,cur_a+5,1));
 
	return dp[cur_h][cur_a][op]=res;
 
}
 
int main()
{
	int test;
	scanf("%d",&test);
 
	while(test--)
	{
		scanf("%d%d",&h,&a);
		memset(dp,-1,sizeof(dp));
		int ans=max(slove(h,a,0),max(slove(h,a,1),slove(h,a,2)));
		printf("%d\n",ans-1);
	}
 
	return 0;
} 
