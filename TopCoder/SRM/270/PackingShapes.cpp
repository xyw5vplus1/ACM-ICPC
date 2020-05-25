#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-8;
const db pi=acos(-1.0);
class PackingShapes
{
	public:
	int getNum(string s)
	{
		int x=0;
		for (int i=0;i<s.length();i++) x=x*10+s[i]-'0';
		return x;
	}
	vector <string> tryToFit(int width, int height, vector <string> shapes)
	{
		vector<string> ans; ans.clear();
		int c=min(width,height); int d=max(width,height);
		for (auto e:shapes) {
			if (e[0]=='C') {
				int r=getNum(e.substr(7,e.length()-7));
				if (2*r<=c) ans.push_back("YES");
				else ans.push_back("NO");
			}
			else {
				int pos1=e.find(" ");
				int pos2=e.find(" ",pos1+1);
				int x=getNum(e.substr(pos1+1,pos2-pos1-1));
				int y=getNum(e.substr(pos2+1,e.length()-1-pos2));
				int a=min(x,y); int b=max(x,y);
				if (a<=c&&b<=d) ans.push_back("YES");
				else {
					db l=0.0,r=pi/2;
					while (l+eps<r) {
						db mid=(l+r)/2.0;
						if (a*cos(mid)+b*sin(mid)<=c) l=mid;
						else r=mid;
					}
					if (a*sin(l)+b*cos(l)-eps<=d) ans.push_back("YES");
					else ans.push_back("NO");
				}
			}
		}
		return ans;
	}
};
