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
			for(num j=i+i;j<MN;j+=i)
				fact[j] = i;
		}
	scanf(" %lld%lld", &l, &r);
	ans = 0;
	for(int i = 0; i < ps; i++)
		for(num j = primes[i] * primes[i], ct = 3; j <= r; j *= primes[i], ct++) {
			if(j >= l && fact[ct] == 0)
				ans++;
		}
	printf("%lld\n", (r - l + 1ll) - ans);
}
