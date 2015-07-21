#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const int MAXN=210;

int n;
int f[MAXN];
ull s[MAXN][MAXN];

ull gcd(ull x, ull y) {
	if(x==0) return y;
	return gcd(y%x, x);
}

ull lcm(ull x, ull y) {
	return (x*y)/gcd(x, y);
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &f[i]);
	ull tme=0;
	ull ans=1;
	for(int i=1; i<=n; i++) {
		int c=1, a=i;
		do {
			s[i][a]=c++;
			a=f[a];
		} while(!s[i][a]);
		tme=max(tme, s[i][a]-1);
		ans=lcm(ans,c-s[i][a]);
	}
	if(ans<tme){
		if(tme%ans)
			ans=(tme/ans+1)*ans;
		else
			ans=(tme/ans)*ans;
	}
	printf("%lld\n", ans);			
	return 0;
}
