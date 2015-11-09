#include <bits/stdc++.h>
using namespace std;
typedef long long num;

const int MN = 2e6;
num l, r, ans;
num fact[MN], primes[MN], ps;

int main()
{
	for(num i=2;i<MN;i++)
		if(!fact[i])
		{
			primes[ps++] = i;
			for(num j=i;j<MN;j+=i)
				fact[j] = i;
		}
	scanf(" %lld%lld", &l, &r);
	ans = 0;
	for(num i=2;i<MN;i++)
	{
		int n = 0;
		num p = i;
		while(p != 1) {
			if(!(p % (fact[p] * fact[p]))) break;
			p /= fact[p], n++;
		}
		if(p != 1) continue;
		num tim = r/i - (l-1ll)/i;
		if(n == 1 && i >= l && i <= r) tim--;
		if(tim) printf("%lld[%d] appears %lld times +%d\n", i, n, tim, n&1);
		if(n&1)
			ans += tim;
		else
			ans -= tim;
	}
	printf("%lld\n", (r - l + 1ll) - ans);
}
