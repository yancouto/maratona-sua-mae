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

int p[10], M[10], s[10];

int main() {
	int i, L, lo, hi, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &s[i]);
	L = 0;
	for(i = 0; i < n; i++) {
		lo = 1; hi = L;
		while(lo <= hi) {
			int m = (lo+hi+1) / 2;
			if(s[M[m]] < s[i]) lo = m + 1;
			else hi = m - 1;
		}
		p[i] = M[lo-1];
		M[lo] = i;
		L = max(L, lo);
	}
	printf("%d\n", L);
	return 0;
}
