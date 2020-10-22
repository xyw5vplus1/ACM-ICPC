#include<bits/stdc++.h>
#define ull long long
using namespace std;
ull st[21][21];
char s[21];
ull f[21];
int main()
{
    int T;
    scanf("%d",&T);
    for (int I=1;I<=T;I++)
    {
        scanf("%s",s+1);
        int n=strlen(s+1);

       // for (int i=1;i<=n;i++)
          //      for (int j=i;j<=n;j++)
           //     {
              //      int len=j-i+1;
               // }
         ull cur=0;
        f[n]=s[n]-'0';
        for (int i=n-1,j=10;i>=1;i--,j*=10)
            f[i]=(ull)(s[i]-'0')*j+f[i+1];
       // for (int i=n;i>=1;i--)
           //     cout<<f[i]<<endl;
        ull ans=-(0x3f3f3f3f);
        for (int i=1;i<=n-4;i++)
        {

            cur=cur*10+s[i]-'0';
            ull C=0;
            for (int j=i+1;j<=n-3;j++)
                {
                    C=C*10+s[j]-'0';
                    ull X=s[j+1]-'0';
                    ull Y=s[j+2]-'0';
                    ull Q=f[j+3];
                    ull Cur=(ull)X*Y/Q;
                    ull temp=cur+C-Cur;
                    if (temp>ans)
                    {
//cout<<i<<" "<<j<<endl;
                       // cout<<cur<<" "<<C<<" "<<Cur<<endl;
                       //// cout<<temp<<"t"<<endl;
                        ans=temp;
                    }
                   // ans=max(ans,temp);
                }
        }
         cout<<"Case #"<<I<<": "<<ans<<endl;
    }

}
