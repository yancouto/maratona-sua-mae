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

char op[2000];
int val[2000], sn;
int ot[2000];

pii memo[2000][15];
pii solve(int i, int v) {
	pii &r = memo[i][v];
	if(r.fst != -1) return r;
	ll a = 0;
	for(int j = i + 1; j != ot[i]; ) {
		if(op[j] == 'V') a += (v != val[j]), v = val[j], j++;
		else {
			assert(op[j] == 'R');
			pii k = solve(j, v);
			a += k.fst;
			a += ll(val[j] - 1) * solve(j, k.snd).fst;
			j = ot[j] + 1;
			v = k.snd;
		}
	}
	return r = pii(a, v);
}

int main() {
	int b, s, i; char c;
	while(scanf("%d %d", &b, &s) != EOF) {
		memset(memo, -1, sizeof memo);
		sn = 0;
		ll num = 1;
		ll tot = 0;
		op[sn] = 'R'; val[sn] = 1; sn++;
		vector<int> S;
		while(true) {
			if(scanf(" %c", &c) == EOF) break;
			if(isdigit(c)) {
				ungetc(c, stdin);
				break;
			}
			op[sn] = c;
			if(c != 'E') scanf("%d", &val[sn]);
			if(c == 'V') val[sn] = (val[sn] - 1) / s;
			sn++;
			if(c == 'E' && op[sn - 2] == 'R') sn -= 2;
		}
		int j = 0;
		for(i = 0; i < sn; i++) {
			if(op[i] == 'R') num *= val[i], S.pb(val[i]);
			if(op[i] == 'E') num /= S.back(), S.pop_back();
			if(op[i] == 'V') tot += num;
			if(op[i] == 'V' && val[i] == 0) continue;
			op[j] = op[i];
			val[j++] = val[i];
			if(op[j - 1] == 'E' && op[j - 2] == 'R') j -= 2;
		}
		S.pop_back();
		assert(S.empty());
		sn = j;
		op[sn++] = 'E';
		for(i = 0; i < sn; i++) {
			if(op[i] == 'R')
				S.pb(i);
			else if(op[i] == 'E')
				ot[S.back()] = i, ot[i] = S.back(), S.pop_back();
		}
		tot += solve(0, 13).fst;
		printf("%lld\n", tot);
	}
}
