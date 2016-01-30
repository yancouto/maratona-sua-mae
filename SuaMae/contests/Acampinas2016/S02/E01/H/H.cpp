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

struct ed {
	int l, r, nx, us;
};
ed tr[40009][30]; int ls[40009], tn;

int dfs(int u) {
	int &f = ls[u];
	for(int i = 0; i < 30; i++)
		if(tr[u][i].nx)
			f += dfs(tr[u][i].nx);
	if(!f) f = 1;
	return f;
}

char s1[10009], s2[10009];
int main() {
	freopen("strings.in", "r", stdin);
	freopen("strings.out", "w", stdout);
	int i, j, k;
	scanf("%s %s %d", s1, s2, &k);
	int n1 = strlen(s1), n2 = strlen(s2);
	s2[n2++] = 'z' + 1;
	for(i = 0; i < n1; i++) s1[i] -= 'a';
	for(i = 0; i < n2; i++) s2[i] -= 'a';
	for(i = 0; i < n2; i++) {
		int r = INT_MAX; ed *e = &tr[40008][0];
		for(j = i; j < n2; j++) {
			if(r > e->r && tr[e->nx][s2[j]].nx) { e = &tr[e->nx][s2[j]]; r = e->l; }
			if(r > e->r) { tr[e->nx][s2[j]] = ed{j, n2 - 1, ++tn, -1}; break; }
			if(s2[j] != s2[r]) {
				int v = e->nx;
				tr[tn+1][s2[r]] = ed{r, e->r, e->nx, -1};
				tr[tn+1][s2[j]] = ed{j, n2 - 1, tn + 2, -1};
				e->nx = ++tn; e->r = r - 1; ++tn;
				break;
			}
			else r++;
		}
	}
	dfs(0);
	int tot = 0;
	for(i = 0; i < n1; i++) {
		int r = INT_MAX; ed *e = &tr[40008][0];
		for(j = i; j < n1; j++) {
			if(r > e->r && tr[e->nx][s1[j]].nx) { e = &tr[e->nx][s1[j]]; r = e->l; }
			if(r > e->r || s1[j] != s2[r] || ls[e->nx] < k) break;
			if(ls[e->nx] == k && e->us < r) tot++, e->us = r;
			r++;
		}
	}
	printf("%d\n", tot);
}
