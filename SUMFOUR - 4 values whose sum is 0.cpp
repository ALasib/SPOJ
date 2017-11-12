#include<bits/stdc++.h>
#define mx 2505

using namespace std;
typedef long long LL;

int A[mx],B[mx],C[mx],D[mx],n;
unordered_map<int,int>AA;

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);

    AA.reserve(20000000);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        int sum=A[i]+B[j];
        AA[sum]++;
    }

    LL ans=0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        int sum=C[i]+D[j];
        ans+=AA[-sum];
    }

    printf("%lld\n",ans);
    return 0;
}

/*unordered_map: http://codeforces.com/blog/entry/21853*/
/*Technique:meet in the middle*/
