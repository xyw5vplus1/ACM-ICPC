#include<bits/stdc++.h>
using namespace std;
class CountriesRanklist
{
	public:
	map<string,int> sum;
	map<string,int> cnt;
	map<string,int> defeat;
	map<string,int> defeated;
	vector<string> findPlaces(vector<string> vs)
	{
		sum.clear(); cnt.clear();
		defeat.clear(); defeated.clear();
		int mn=600;
		int n=vs.size();
		for (int i=0;i<n;i++) {
			string ss; int grade=0;
			int pos=vs[i].find(" ");
			for (int j=0;j<pos;j++) ss+=vs[i][j];
			for (int j=pos;j<vs[i].length();j++)
			if (vs[i][j]>='0'&&vs[i][j]<='9') grade=(grade*10+vs[i][j]-'0');
			sum[ss]+=grade; cnt[ss]+=1;
			mn=min(mn,grade);
		}
		for (auto e:sum) {
			for (auto e1:sum) {
				if (e.first==e1.first) continue;
				if (e.second+(4-cnt[e.first])*(mn-1)>e1.second) {
					defeated[e1.first]++;
				}
				if (e.second+(4-cnt[e.first])*(mn-1)>=e1.second) {
					defeat[e.first]++;
				}
			}
		}
		vector<string> ans;
		for (auto e:sum) {
			string tem=e.first;
			tem+=" "; tem+=to_string(sum.size()-defeat[e.first]);
			tem+=" "; tem+=to_string(defeated[e.first]+1);
			//cout<<tem<<endl;
			ans.push_back(tem);
		}
	//	for (int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
		return ans;
	}
};
