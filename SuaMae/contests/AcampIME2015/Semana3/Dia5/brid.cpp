#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<long long, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
int n, m;
map<string, int> mp;
ll cu[1003], cd[1003];
int tpu[1003], tpd[1003];

pii memo[1003][1003];
pii solve(int up, int dw) {
	if(up == n || dw == m) return pii(0, 0);
	pii &ret = memo[up][dw];
	if(ret.fst != -1) return ret;
	ret = max(solve(up + 1, dw), solve(up, dw + 1));
	if(tpu[up] == tpd[dw]) {
		pii aux = solve(up + 1, dw + 1);
		ret = max(ret, pii(aux.fst + cu[up] + cd[dw], aux.snd - 1));
	}
	return ret;
}

int main() {
	char name[200];
	int i;
	for_tests(t, tt) {
		mp.clear();
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%*s %s %lld", name, &cu[i]);
			string ss(name);
			if(!mp.count(ss)) mp[ss] = mp.size();
			tpu[i] = mp[ss];
		}
		scanf("%d", &m);
		for(i = 0; i < m; i++) {
			scanf("%*s %s %lld", name, &cd[i]);
			string ss(name);
			if(!mp.count(ss)) mp[ss] = mp.size();
			tpd[i] = mp[ss];
		}
		memset(memo, -1, sizeof memo);
		pii p = solve(0, 0);
		printf("%lld %d\n", p.fst, -p.snd);
	}
	return 0;
}
