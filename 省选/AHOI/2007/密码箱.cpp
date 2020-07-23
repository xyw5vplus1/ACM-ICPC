//题目大意，给定一个n(1<=n<=2e9)。从小到大输出每个x，满足x^2==1(mod n)。
//主要思路:移项可得(x-1)*(x+1)==0(mod n)。
//(x-1)*(x+1)==k*n
//那么我们可以这么思考，相当于(x-1)承担了一部分n的因子,(x+1)又承担了一部分n的因子。
//我们记n=a*b，分别记他们承担的因子为a和b，也就是a|x-1，b|x+1.
//那么我们思考目前计算的复杂度，首先肯定需要枚举因子，这样需要O(sqrt(N))的复杂度。
//得到当前的a和b后，我们又需要去得到这个具体的x是多少，一种想法是我们用扩展中国剩余定理，把它看成一个线性同余方程组，因为只有两条式子，我们可以认为能在常数时间内求出一个
//落在[0,lcm(a,b)]范围内的解x。此时，我们每增加一个lcm(a,b)，就可以得到一个新的解。往上增加的复杂度是O(N/lcm(a,b))=O(N/max(a,b))
//但是题解大部分不是这么做的，因为这里两个线性方程构成的方程组，直接枚举就OK了。
//我们沿着之前的思路，为了使复杂度正确，我们不能枚举每一个a之后往上增长，我们只能枚举a和b中较小的那个，这样复杂度就限制在O(sqrt(N))。并且有一个关键性的trick在于
//假设我们当前外层枚举的是1,如果我们往上增长的时候，也是1个1个往上跳，那么复杂度就变成了O(N/1+N/2+……+N/(sqrt(N))),就爆炸了……
//我们往上跳的时候应该按照b，也就是n/a往上跳，这样复杂度就变成了O(N/N+N/(N/2)+……+N/(N/sqrt(N))),虽然这样复杂度看起来是O(N)的，但实际上会远远小于这个上界。
//加上外层枚举，我们可以近似看成一个调和级数求和，因此总复杂度应当是O(sqrt(N)*logN)的。
//这样这道题基本就完成了。
//回顾一下来说，为了控制枚举因子的复杂度，我们一般会枚举较小的那个因子，为了控制内部复杂度正确，我们利用调和级数的思想，去枚举另一侧较大的那个因子向上跳保证复杂度正确。
//前期推导的核心是将等式转化为等价的同余式，将n分拆为a*b是前期推导的关键。
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define per(i,a,b) for (int i=a;i>b;i--)
using namespace std;
typedef long long ll;
typedef double db;
set<int> s;
int n;
int main()
{
	scanf("%d",&n);
	if (n==1) {
		printf("None\n");
		return 0;
	}
	for (ll i=1;i*i<=n;i++) 
		if (n%i==0) {
			for (ll j=(n/i)-1;j<n;j+=(n/i)) 
				if ((j-1)%i==0) s.insert(j);
		}
	for (ll i=1;1LL*i*i<=n;i++) 
		if (n%i==0) {
			for (ll j=1;j<n;j+=(n/i)) 
				if ((j+1)%i==0) s.insert(j);
		}
	if (!s.size()) printf("None\n");
	else for (set<int>::iterator iter=s.begin();iter!=s.end();iter++) printf("%d\n",(*iter)); 
	return 0;
}
