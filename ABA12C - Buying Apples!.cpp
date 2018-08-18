#include<bits/stdc++.h>
#define mx 105
#define inf 60000000

using namespace std;
int Dp[mx][mx][mx],n,k,price[mx];

int solve(int pos,int nn,int kk)
{
    if(kk>=k or pos>k)
    {
        if( pos<=k+1 && kk==k && nn<=n)
            return 0;
        else
            return inf;

    }

    int &ret=Dp[pos][nn][kk];
    if(ret!=-1)return ret;
    int r1,r2,r3;
    r1=r2=r3=inf;
    if(price[pos]!=-1)
    {
        r1=price[pos]+solve(pos,nn+1,kk+pos);
        r2=price[pos]+solve(pos+1,nn+1,kk+pos);
    }
    r3=solve(pos+1,nn,kk);
   // cout<<"r1:"<<r1<<" r2:"<<r2<<" r3:"<<r3<<endl;
    ret=min(r1,min(r2,r3));
    return ret;
}

int main()
{
    int test;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d",&n,&k);
        memset(Dp,-1,sizeof(Dp));
        for(int i=1;i<=k;i++)
            scanf("%d",&price[i]);
        int ans=solve(1,0,0);
        if(ans>=inf)
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
