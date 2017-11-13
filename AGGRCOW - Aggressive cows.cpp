#include<bits/stdc++.h>
#define mx 100005
 
using namespace std;
typedef long long ll;
ll x[mx],n,ans,c;
 
bool check(ll val)
{
      int cnt=1;
      ll prev=x[0];
 
      for(int i=1;i<n;i++)
          if(x[i]-prev>=val)
            {
                 cnt++;
                 if(cnt==c)
                    return 1;
                 prev=x[i];
            }
 
 
      return 0;
}
 
void bs()
{
      ll low=0;
      ll high=x[n-1];
     // cout<<"ok"<<endl;
      while(low<=high)
      {
           ll mid=low+((high-low)/2);
           if(check(mid)==1)
               low=mid+1;
           else
               high=mid-1;
          //  cout<<"loop"<<endl;
      }
      //cout<<"finish"<<endl;
      ans=high;
}
 
int main()
{
       int test;
       scanf("%d",&test);
 
       while(test--)
       {
            scanf("%lld%lld",&n,&c);
            for(int i=0;i<n;i++)
                scanf("%lld",&x[i]);
 
            sort(x,x+n);
            bs();
            printf("%lld\n",ans);
       }
 
       return 0;
}
 
