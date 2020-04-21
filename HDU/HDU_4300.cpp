#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
char s[maxn+5],t[maxn+5];
int z[maxn+5],extend[maxn+5];
char mp[100];
int T;
vector<int> v[26];
void pre_EKMP(char s[],int m)
{
    z[1]=m;
    int j=0;
    while (j+2<=m&&s[j+1]==s[j+2]) j++;
    z[2]=j;
    int k=2;
    for(int i=3;i<=m;i++) {
        int p=z[k]+k-1;
        int L=z[i-k+1];
        if (i+L<p+1) z[i]=L;
        else {
            j=max(0,p-i+1);
            while (i+j<=m&&s[i+j]==s[j+1]) j++;
            z[i]=j;
            k=i;
        }
    }
}
void EKMP(char s[],int m,char t[],int n)
{
    int j=0;
    while (j+1<=n&&j+1<=m&&s[j+1]==t[j+1]) j++;
    extend[1]=j;
    int k=1;
    for(int i=2;i<=n;i++) {
        int p=extend[k]+k-1;
        int L=z[i-k+1];
        if (i+L<p+1) extend[i]=L;
        else {
            j=max(0,p-i+1);
            while (j+1<=m&&i+j<=n&&t[i+j]==s[j+1]) j++;
            extend[i]=j;
            k=i;
        }
    }
}
int main()
{
    scanf("%d",&T);
    while (T--) {
        scanf("%s",mp);
        scanf("%s",s+1);
        int len=strlen(s+1);
        for (int i=1;i<=len;i++) t[i]=mp[s[i]-'a'];
        for (int i=0;i<26;i++) v[i].clear();
        for (int i=0;i<26;i++)
            v[mp[i]-'a'].push_back(i);
        //printf("%s\n",t+1);
        t[len+1]='\0';
        pre_EKMP(s,len);
        EKMP(s,len,t,len);
        int pos=len+1;
        for (int i=(len+1)/2+1;i<=len;i++)
            if (extend[i]+i-1==len) pos=min(pos,i);
        //printf("pos=%d\n",pos);
        for (int i=1;i<=pos-1;i++) printf("%c",s[i]);
        for (int i=1;i<=pos-1;i++) printf("%c",v[s[i]-'a'][0]+'a');
        printf("\n");
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
aaaaa
*/
