#include<bits/stdc++.h>
#define mx 200000
#define mod 100000000

using namespace std;
typedef long long LL;
LL n,cnt[mx][2];
vector<LL>v;
vector<LL>::iterator it;

struct info
{
    LL s,e;
}arr[mx];

bool cmp(info n1,info n2)
{
    return n1.e<n2.e;
}

void call()
{
      cnt[0][1]=1;
      v.push_back(arr[0].e);

      for(int i=1;i<n;i++)
      {
          cnt[i][0]=(cnt[i-1][0]+cnt[i-1][1])%mod;
          if(arr[i].s<v[0])
             cnt[i][1]=1;
          else
          {
              it=upper_bound(v.begin(),v.end(),arr[i].s);
              int ind=it-v.begin();
              --ind;
              cnt[i][1]=(cnt[ind][0]+cnt[ind][1]+1)%mod;
          }
          v.push_back(arr[i].e);
      }
}

int main()
{
    while(scanf("%lld",&n)==1 && n!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%lld%lld",&arr[i].s,&arr[i].e);
        sort(arr,arr+n,cmp);
        memset(cnt,0,sizeof(cnt));

        call();
        int ans=(cnt[n-1][0]+cnt[n-1][1])%mod;
        printf("%0.8d\n",ans);
        v.clear();

    }
    return 0;
}
