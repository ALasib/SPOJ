#include<bits/stdc++.h>
#define mx 1005

using namespace std;
typedef long long LL;
LL n,k,s,a[mx],ans;

int main()
{
    scanf("%lld%lld%lld",&n,&k,&s);
    k=k*s;
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    s=ans=0;
    for(int i=n-1;i>=0;i--)
    {
        s+=a[i];
        ans++;
        if(s>=k)
            break;
    }
    printf("%lld\n",ans);
    return 0;
}
