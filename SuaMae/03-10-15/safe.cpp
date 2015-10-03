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
const int oo = 100000000;

int n;
int v[20];
vector<pii> pre;
int memo[100000][2];

int solve(int mask, int flag) {
	if(__builtin_popcount(mask) == n) return 0;
	int &m = memo[mask][flag];
	if(m != -1) return m;
	m = oo;
	if(flag) {
		for(int i = 0; i < n; i++) 
			if(mask & (1 << i))
				m = min(m, v[i] + solve(mask ^ (1 << i), !flag));
	}
	else {
		for(int i = 0; i < pre.size(); i++) {
			int a = pre[i].fst, b = pre[i].snd;
			if((mask & (1 << a)) || (mask & (1 << b))) continue;
			int mmask = mask;
			mmask |= (1 << a); mmask |= (1 << b);
			m = min(m, max(v[a], v[b]) + solve(mmask, !flag));
		}
	}
	return m;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			pre.pb(pii(i, j));
	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(0, 0));
	return 0;
}
