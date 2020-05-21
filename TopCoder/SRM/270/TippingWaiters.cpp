#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class TippingWaiters
{
	public:
	int possiblePayments(int bill,int cash)
	{
		ll l=0,r=cash-bill;
		while (l<r) {
			ll mid=(l+r+1)>>1LL;
			if (mid*9<=bill) l=mid;
			else r=mid-1;
		}
		int ans1=l+bill;
		l=0,r=cash-bill;
		while (l<r) {
			ll mid=(l+r)>>1LL;
			if (mid*19>=bill) r=mid;
			else l=mid+1;
		}
		int ans2=l+bill;
		return ans1/5-(ans2-1)/5;
	}
};
