/*#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N*2];
int p[N*2];
int len;
int del1,del2;
bool bo[N*2];
int ans1=0,ans2=0,maxlen=0;
int calc(int l,int r)
{
    int cnt1=l-1,cnt2=2*len+1-r;
    if (cnt1<=cnt2) {
        if (bo[l-1]) {
            del1=r+1; del2=2*len+1-cnt1; return 2*len+1-(del2-del1+1);
        }
        else return -1;
    }
    else {
        if (bo[r+1]) {
            del1=cnt2+1; del2=l-1; return 2*len+1-(del2-del1+1);
        }
        else return -1;
    }
}
int T;
void del()
{
    memset(bo,false,sizeof(bool)*(2*len+5));
    int l=1,r=2*len+1;
    bo[0]=bo[2*len+2]=true;
    while (l<=r) {
        if (s[l]==s[r]) bo[l]=bo[r]=true;
        else break;
        l++; r--;
        //printf("debug %d %d\n",l,r);
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        len=strlen(s);
        for(int i=len;i>=1;i--){
            s[i*2+1]='#';
            s[i*2]=s[i-1];
//          s[i*2-1]='#';   �����ƴ���ַ����ķ���ÿ����д�Ķ���Щϸ΢�Ĳ��
        }
        s[1]='#';
        s[0]='$';
//      printf("%s\n",s);
//      memset(p,0,sizeof(p));
        int maxx=1;         //����ͳ������������
        fill(p,p+2*len+5,1);
        int id=1,mx=1;      //mx=id+p[id]-1==1 ����iǰ����idΪ���ĵĻ��Ĵ����Դﵽ�����ұߵı߽�
        for(int i=2;i<=len*2+1;i++){
            if(i<mx){
                p[i]=min(p[2*id-i],mx-i+1); //i����id�ĶԳƵ�2*id-i�����Ĵ��뾶���ܳ���mx-i+1���п��ܸ���
            }
            //����if�������˻��Ĵ��ĶԳ����Լ���ƥ�����
            //��ʱ���p[2*id-i]>=mx-i+1������Ե�i�Ļ��Ĵ��뾶Ҳ���ܸ���
            //����i�������mx�����棬���޷���������if��������iΪ���ĵĻ��Ĵ���ƥ�����
            while(i-p[i]>=1&&i+p[i]<=len*2+1){
                if(s[i-p[i]]==s[i+p[i]]) p[i]++;
                else break;
            }
            //��Ҫiÿ����һ�ξ�Ҫʵʱ����id��mx�Ĵ�С
            if(p[i]+i-1>mx){
                mx=p[i]+i-1;
                id=i;
            }
            if(p[i]>maxx) maxx=p[i];
        }
        //for (int i=1;i<=2*len+1;i++) printf("%d %d\n",i,p[i]);
        del();
        //for (int i=1;i<=2*len+1;i++) printf("debug %d %d\n",i,bo[i]);
        maxlen=0; ans1=0; ans2=0;
        for (int i=1;i<=2*len+1;i++)
        {
            int t=calc(i-p[i]+1,i+p[i]-1);
            //printf("debug search %d %d\n",i,t);
            if (t!=-1) {
                if (t>maxlen) {
                    ans1=del1; ans2=del2; maxlen=t;
                }
            }
        }
        //printf("debug %d\n",maxlen);
        //printf("debug %d %d\n",ans1,ans2);
        for (int i=1;i<=2*len+1;i++)
            if (i<ans1||i>ans2)
            if (i%2==0) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}*/
/*
10
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
*/
