#include<bits/stdc++.h>
#define mx 2005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef unsigned int ui;
int len1,len2;
string s1,s2;
int dp[mx][mx];
 
int slove(int i,int j)
{
      if(i==0)
         return j;
      if(j==0)
          return i;
      if(dp[i][j]!=-1)
          return dp[i][j];
 
      if(s1[i-1]==s2[j-1])
          return dp[i][j]=slove(i-1,j-1);
      else
          return dp[i][j]=1+min(slove(i-1,j-1),min(slove(i-1,j),slove(i,j-1)));
}
 
int main()
{
      int test;
      scanf("%d",&test);
      while(test--)
      {
           cin>>s1>>s2;
           len1=s1.size();
           len2=s2.size();
           memset(dp,-1,sizeof(dp));
           int ans=slove(len1,len2);
           printf("%d\n",ans);
      }
      return 0;
}
 
