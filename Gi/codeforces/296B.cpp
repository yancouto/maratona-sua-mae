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
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100005;

int n;
char s[N], t[N];

int main () {
	int i;
	scanf("%d", &n);
	scanf("%s %s", s, t);
	ll r1, r2, r3, tot;
	r1 = r2 = r3 = tot = 1;
	for(i = 0; i < n; i++) {
		if(s[i] == '?' && t[i] == '?') r2 *= 10ll;
		else if(s[i] != '?' && t[i] != '?' && s[i] != t[i]) r2 = 0;
		r2 = mod(r2);
	}
	for(i = 0; i < n; i++) {
		if(s[i] == '?' && t[i] == '?') { r1 *= 55ll; r3 *= 55ll; }
		else if(s[i] != '?' && t[i] != '?') { 
			if(s[i] > t[i]) r1 = 0;
			else if(s[i] < t[i]) r3 = 0;
		}
		else {
			if(s[i] == '?') { r1 *= (t[i] - '0' + 1); r3 *= (10 - (t[i] - '0')); }
			else { r3 *= (s[i] - '0' + 1); r1 *= (10 - (s[i] - '0')); }
		}
		if(s[i] == '?') tot = mod(tot * 10ll);
		if(t[i] == '?') tot = mod(tot * 10ll);
		r1 = mod(r1); r3 = mod(r3);
	}
	ll ans = mod(r1 + r3 - r2 + modn);
	printf("%lld\n", mod(tot - ans + modn));
	return 0;
}
