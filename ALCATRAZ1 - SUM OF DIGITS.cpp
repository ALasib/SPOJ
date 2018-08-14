#include<bits/stdc++.h>

using namespace std;
int ans,test;
string s;

int main()
{
    scanf("%d",&test);
    while(test--)
    {
        ans=0;
        cin>>s;
        int len=s.size();
        for(int i=0;i<len;i++)
            ans+=(s[i]-'0');
        printf("%d\n",ans);
        s.clear();
    }
    return 0;
}
