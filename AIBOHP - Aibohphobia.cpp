#include<bits/stdc++.h>
#define mx 6105
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
string str;
string rev;
int dp[mx][mx];
int len;
 
int slove(int i,int j)
{
	if(str[i]=='\0' or rev[j]=='\0')
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
 
	if(str[i]==rev[j])
		return dp[i][j]=1+slove(i+1,j+1);
	else 
		return dp[i][j]=max(slove(i+1,j),slove(i,j+1));
}
 
int main()
{
	int test;
	scanf("%d",&test);
 
	while(test--)
	{
		cin>>str;
		rev=str;
		reverse(rev.begin(),rev.end());
		len=str.length();
		memset(dp,-1,sizeof(dp));
		int ans=slove(0,0);
		printf("%d\n",len-ans);
		str.clear();
		rev.clear();
	}
 
	return 0;
} 
