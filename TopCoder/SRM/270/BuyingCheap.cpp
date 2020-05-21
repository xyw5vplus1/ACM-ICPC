#include<bits/stdc++.h>
using namespace std;
class BuyingCheap
{
	public:
	int thirdBestPrice(vector<int> v)
	{
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		if (v.size()<3) return -1;
		return v[2];
	}
};
