#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 200010;

int n;
int a[N];
pii d1[N], d2[N];
int w1[N], w2[N];

pii solve2(ll x);	
pii solve1(ll x) {
	if(x <= 0 || x > n) return pii(0, 1);
	if(x == 1) return pii(-1, 0);
	if(w1[x]) return d1[x];
	w1[x] = 1; d1[x].fst--; 
	pii ret = solve2(x+a[x]);
	if(ret.snd) ret.fst += a[x];
	return d1[x] = ret;
}

pii solve2(ll x) {
	if(x <= 0 || x > n) return pii(0, 1);
	if(x == 1) return pii(-1, 0);
	if(w2[x]) return d2[x];
	w2[x] = 1; d2[x].fst--;
	pii ret = solve1(x-a[x]);
	if(ret.snd) ret.fst += a[x];
	return d2[x] = ret;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 2; i <= n; i++) scanf("%d", &a[i]);
	for(i = 1; i < n; i++) {
		pii ans = solve2(i + 1);
		if(ans.snd) ans.fst += i;
		cout << ans.fst << '\n';
	}
	return 0;	
}
