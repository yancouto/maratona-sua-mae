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

bool in(char *s1, char *s2) {
	while(*s1 && *s2 && *s1 == *s2) s1++, s2++;
	return !(*s1) && (*s2);
}

char s[12][20];
int m, all, n;
ll memo[30][12][12][1025];
ll solve(int i, int mi, int p, int bm) {
	if(mi != -1 && !s[mi][p]) return solve(i, -1, 0, bm);
	if(i == n) return bm == all && mi == -1;
	ll &r = memo[i][mi + 1][p][bm];
	if(r != -1) return r;
	if(mi == -1) {
		r = 26ll * solve(i + 1, -1, 0, bm);
		for(int j = 0; j < m; j++)
			if(!((1 << j) & bm))
				r += solve(i + 1, j, 1, bm | (1 << j));
	}
	else {
		r = solve(i + 1, mi, p + 1, bm);
		for(int j = 0; j < m; j++)
			if(!((1 << j) & bm) && in(s[mi] + p, s[j]))
				r += solve(i + 1, j, 1, bm | (1 << j));
	}
	return r;
}

int bad[20];
int main() {
	int i, j, k;
	while(scanf("%d %d", &n, &m) && (n || m)) {
		for(i = 0; i < m; i++)
			scanf("%s", s[i]), bad[i] = 0;
		for(i = 0; i < m; i++) {
			for(j = 0; j < m; j++)
				if(i != j && !bad[j]) {
					if(strcmp(s[i], s[j]) == 0) { bad[i] = true; break; }
					for(k = 0; s[j][k] && !in(s[i], s[j] + k); k++);
					if(s[j][k]) { bad[i] = true; break; }
				}
		}
		for(i = j = 0; i < m; i++)
			if(!bad[i]) {
				if(i != j) strcpy(s[j], s[i]);
				j++;
			}
		m = j; all = (1 << m) - 1;
		printf("m %d all %d\n", m, all);
		memset(memo, -1, sizeof memo);
		printf("%lld\n", solve(0, -1, 0, 0));



	}
}
