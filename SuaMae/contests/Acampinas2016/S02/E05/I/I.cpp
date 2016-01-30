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


int n, m, all;
int tr[107][26], f[107], mt[107], leaf[107];
ll memo[27][107][1026];
ll solve(int i, int t, int bm) {
	if(i == n) return bm == all;
	ll &r = memo[i][t][bm];
	if(r != -1) return r;
	r = 0;
	for(int c = 0; c < 26; c++) {
		int v = t;
		while(v && !tr[v][c]) v = f[v];
		v = tr[v][c];
		int bm2 = bm;
		if(leaf[v]) bm2 |= (1 << (leaf[v] - 1));
		for(int v2 = v; mt[v2]; v2 = mt[v2])
			bm2 |= (1 << (leaf[mt[v2]] - 1));
		r += solve(i + 1, v, bm2);
	}
	return r;
}

char q[30];
void build(int i, int t, int bm) {
	if(i == n) {
		puts(q);
		return;
	}
	for(int c = 0; c < 26; c++) {
		int v = t;
		while(v && !tr[v][c]) v = f[v];
		v = tr[v][c];
		int bm2 = bm;
		if(leaf[v]) bm2 |= (1 << (leaf[v] - 1));
		for(int v2 = v; mt[v2]; v2 = mt[v2])
			bm2 |= (1 << (leaf[mt[v2]] - 1));
		if(solve(i + 1, v, bm2)) {
			q[i] = c + 'a';
			build(i + 1, v, bm2);
		}
	}
}


char s[20];
int main() {
	int i, j, k, tt = 0;
	while(scanf("%d %d", &n, &m) && (n || m)) {
		memset(tr, 0, sizeof tr);
		memset(f, 0, sizeof f);
		memset(mt, 0, sizeof mt);
		memset(leaf, 0, sizeof leaf);
		int tn = 0;
		for(i = 0; i < m; i++) {
			scanf("%s", s);
			int v = 0;
			for(j = 0; s[j]; j++) {
				if(!tr[v][s[j] - 'a']) tr[v][s[j] - 'a'] = ++tn;
				v = tr[v][s[j] - 'a'];
			}
			leaf[v] = i + 1;
		}
		queue<int> q;
		for(i = 0; i < 26; i++)
			if(tr[0][i])
				q.push(tr[0][i]), f[tr[0][i]] = 0;
		while(!q.empty()) {
			int v = q.front(); q.pop();
			if(leaf[f[v]]) mt[v] = f[v];
			else mt[v] = mt[f[v]];
			for(i = 0; i < 26; i++) {
				if(!tr[v][i]) continue;
				int &x = f[tr[v][i]];
				x = f[v];
				while(x && !tr[x][i]) x = f[x];
				x = tr[x][i];
				q.push(tr[v][i]);
			}
		}
		all = 0;
		for(i = 0; i <= tn; i++)
			if(leaf[i])
				all |= (1 << (leaf[i] - 1));
		memset(memo, -1, sizeof memo);
		printf("Case %d: %lld suspects\n", ++tt, solve(0, 0, 0));
		memset(::q, 0, sizeof ::q);
		if(solve(0, 0, 0) <= 42) build(0, 0, 0);
	}
}
