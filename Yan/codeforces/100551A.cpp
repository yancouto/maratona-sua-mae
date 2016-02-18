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
const int N = 601009;
int S[N], sz[N], st[N], sn, qt[N], qa[N], qn, o[N], comp;
pii qe[N];
enum {ADD, REM, COMP};

inline int find(int i) {
	while(S[i] != i) i = S[i];
	return i;
}

inline void query(int t, pii e=pii(0,0)) {
	qt[qn] = t; qe[qn++] = e;
}

void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
	st[sn++] = b;
	comp--;
}

void rollback() {
	int u = st[--sn];
	sz[S[u]] -= sz[u];
	S[u] = u;
	comp++;
}

void process(int l, int r) {
	if(l == r) return (void) (qa[l] = comp);
	int P = sn, m = (l + r) / 2, i;
	for(i = l; i <= m; i++)
		if(qt[i] == ADD && o[i] > r)
			join(qe[i].fst, qe[i].snd);
	process(m + 1, r);
	while(P != sn) rollback();
	for(i = m + 1; i <= r; i++)
		if(qt[i] == REM && o[i] < l)
			join(qe[i].fst, qe[i].snd);
	process(l, m);
	while(P != sn) rollback();
}

int main() {
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);
	int i, n, k; char op; pii e;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) S[i] = i, sz[i] = 1;
	comp = n;
	map<pii, int> mp;
	for(i = 0; i < k; i++) {
		scanf(" %c", &op);
		if(op != '?') { scanf("%d %d", &e.fst, &e.snd); e.fst--; e.snd--; if(e.fst > e.snd) swap(e.fst, e.snd); }
		if(op == '+') {
			mp[e] = i;
			query(ADD, e);
		} else if(op == '-') {
			o[i] = mp[e];
			o[mp[e]] = i;
			query(REM, e);
			mp.erase(e);
		} else {
			query(COMP);
		}
	}
	while(!mp.empty()) {
		o[k] = mp.begin()->snd;
		o[mp.begin()->snd] = k++;
		query(REM, mp.begin()->fst);
		mp.erase(mp.begin());
	}
	process(0, qn - 1);
	for(i = 0; i < qn; i++)
		if(qt[i] == COMP)
			printf("%d\n", qa[i]);
}
