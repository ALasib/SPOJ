#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#define mx 5005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
ll dp[mx];
string str;
int len;
 
ll slove(int pos)
{
	if(pos<=0)
		return 1;
	if(dp[pos]!=0)
		return dp[pos];
 
	int num=((str[pos-1]-'0')*10)+(str[pos]-'0');
 
	if((str[pos]-'0') and (num>9 and num<27))
	{
		if(pos-2>0)
			return dp[pos]=slove(pos-1)+slove(pos-2);
		else 
			return dp[pos]=slove(pos-1)+1;
	}
 
	else if((str[pos]-'0') and !(num>9 and num<27))
		return dp[pos]=slove(pos-1);
 
	else if((str[pos]-'0'==0) and (num>9 and num<27))
	{
		if(pos-2>0)
			return dp[pos]=slove(pos-2);
		else
			return dp[pos]=1;
	}
 
	else if((str[pos]-'0'==0) and !(num>9 and num<27))
		return dp[pos]=0;
 
}
 
int main()
{
	ll res;
 
	while(cin>>str)
	{
		if(str[0]=='0')
			break;
		len=str.size();
 
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		res=slove(len-1);
		printf("%lld\n",res);
		str.clear();
	}
	return 0;
} 
