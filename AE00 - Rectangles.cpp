#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
LL n,ans;

int main()
{
    scanf("%d",&n);
    int loop=sqrt(n);
    ans=n;
    for(int i=2;i<=loop;i++)
    {
        int j=i;
        while((i*j)<=n)
        {
            ans++;
            j++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
