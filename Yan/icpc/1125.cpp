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

int tr[3100][26], tn, bad[3100], pr[3100];

char s[23];
ull memo[22][3100][2];
int seen[22][3100][2], tempo;
ull solve(int i, int v, bool pre) {
	if(bad[v]) return 0;
	if(!s[i]) return 1;
	ull &r = memo[i][v][pre];
	if(seen[i][v][pre] == tempo) return r;
	seen[i][v][pre] = tempo;
	r = 0;
	for(int d = 'a'; d <= 'z'; d++) {
		if(pre && d > s[i]) break;
		int x = v;
		while(x && !tr[x][d - 'a'])
			x = pr[x];
		r += solve(i + 1, tr[x][d - 'a'], pre && d == s[i]);
	}
	return r;
}

ll sz[22];
int main() {
	int n, m, i, j, p, x;
	for_tests(t, tt) {
		scanf("%d %d", &n, &m);
		tn = 1;
		memset(tr, 0, sizeof tr);
		memset(bad, 0, sizeof bad);
		for(i = 0; i < n; i++) {
			scanf("%s", s);
			int p = 0;
			for(j = 0; s[j]; j++) {
				if(!tr[p][s[j] - 'a'])
					tr[p][s[j] - 'a'] = tn++;
				p = tr[p][s[j] - 'a'];
			}
			bad[p] = 1;
		}
		queue<int> q;
		for(i = 0; i < 26; i++)
			if(tr[0][i])
				q.push(tr[0][i]), pr[tr[0][i]] = 0;
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(i = 0; i < 26; i++) {
				if(!tr[x][i]) continue;
				int &p = pr[tr[x][i]];
				p = pr[x];
				while(p && !tr[p][i])
					p = pr[p];
				p = tr[p][i];
				if(bad[p]) bad[tr[x][i]] = 1;
			}
		}
		for(i = 1; i <= 20; i++) {
			s[i - 1] = 'z';
			s[i] = 0;
			tempo++;
			sz[i] = solve(0, 0, true);
		}
		for(i = 0; i < m; i++) {
			if(scanf("%d", &x)) {
				int q;
				for(q = 0; x > sz[q]; q++)
					x -= sz[q];
				for(j = 0; j < q; j++)
					s[j] = 'z';
				s[q] = 0;
				for(j = 0; j < q; j++) {
					int l = 'a', r = 'z';
					while(l < r) {
						int m = (l + r) / 2;
						s[j] = m;
						tempo++;
						if(solve(0, 0, true) >= x) r = m;
						else l = m + 1;
					}
					s[j] = l;
				}
				puts(s);
			} else {
				scanf("%s", s);
				int k = strlen(s); ull v = 0;
				for(j = 0; j < k; j++)
					v += sz[j];
				tempo++;
				printf("%llu\n", solve(0, 0, true) + v);
			}
		}
	}
}
