

#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000003;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 200010;

ll f[MAXN];

ll n, A, B, C, l[MAXN], c[MAXN];

ll expo(ll base, ll exp){
	if(exp == 0) return 1;
	ll ans = 0;
	ans = expo(base, exp/2);
	ans = mod(ans*ans);
	if(exp&1)
		ans = mod(ans*base);
	return ans;
}

ll bin(ll a, ll b){
	ll ans = f[a];
	ans = mod(ans*expo(f[b], modn-2));
	ans = mod(ans*expo(f[a-b], modn-2));
	return ans;
}

int main (){
	f[0] = 1;
	for(ll a=1;a<MAXN-2;a++)
		f[a] = mod(f[a-1]*a);
	

	scanf("%lld%lld%lld%lld", &n, &A, &B, &C);
	for(int a=0;a<n;a++){
		scanf("%lld", &l[a]);
	}
	for(int a=0;a<n;a++){
		scanf("%lld", &c[a]);
	}
	ll res  = 0;
	ll m, k, i, j, pA, pB;
	// linha
	i = n-1;
	m = n-1; k = 0;
	while(i > 0){
		pA = n-1; pB = n-1-i;
		printf("mul lin %lld por bin(%lld,%lld): %lld %lld %lld %lld %lld\n", i, m-1, k, bin(m-1, k), l[i], expo(A, pA), expo(B, pB), C);
		res = mod(res + mod(mod(bin(m-1, k)*l[i])*mod(expo(A,pA)*expo(B, pB))) + mod(l[i]*C));
		printf("res %lld\n", res);
		m++;k++;
		i--;
	}

	// coluna
	m = n-1;
	i = n-1;
	while(i > 0){
		pA = n-1-i; pB = n-1;
		printf("mul col %lld por bin(%lld,%lld): %lld %lld %lld %lld %lld\n", i, m-1, k-1, bin(m-1, k-1), c[i], expo(A, pA), expo(B, pB), C);
		res = mod(res + mod(mod(bin(m-1, k-1)*c[i])*mod(expo(A, pA)*expo(B, pB))) + mod(c[i]*C));
		printf("res %lld\n", res);
		m++;
		i--;
	}

	printf("%lld\n", res);
}
