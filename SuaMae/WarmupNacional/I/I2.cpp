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
				fact[j]++;
		}
	scanf(" %lld%lld", &l, &r);
	ans = r - l + 1;
	for(num i=2;i<MN;i++)
	{
		if(fact[i]&1)
			ans -= r/i + (l-1ll)/i;
		else
			ans += r/i + (l-1ll)/i;
	}
	printf("%lld\n", ans);
}
