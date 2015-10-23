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

int n, k;
char w[1005][20], pal[20];
bool bad3[26][26][26], bad2[26][26], bad1[26];
int memo[20][26][26][2][12];


int solve(int p, int c1, int c2, bool pre, int N) {
//	printf("Satate %d %c %c %d %d\n", p, c1+'a', c2+'a', pre, N);
	if(p == N) return 1;
	int &m = memo[p][c1][c2][pre][N];
	if(m != -1) return m; m = 0;
	for(int c = 0; c < 26; c++) {
		if(pre && c > pal[p] - 'a') continue;
		if(bad1[c]) continue;
		if(p == 1 && bad2[c1][c]) continue;
		if(p > 1 && (bad3[c1][c2][c] || bad2[c2][c])) continue;
		if(p == 0) c1 = c;
		if(p == 1) c2 = c;
		if(p > 1) { c1 = c2; c2 = c; }
		m += solve(p + 1, c1, c2, pre && c == pal[p] -'a', N);
	}
	return m;
}

int main() {
	for_tests(t, tt) {
		int n, m, i, N, Q, ans;
		char s[5];
		scanf("%d %d", &n, &m);
		memset(bad1, 0, sizeof bad1);
		memset(bad2, 0, sizeof bad2);
		memset(bad3, 0, sizeof bad3);
		for(i = 0; i < n; i++) {
			scanf("%s", s);
			if(strlen(s) == 1)
				bad1[s[0]-'a'] = 1;
			else if(strlen(s) == 2)
				bad2[s[0]-'a'][s[1]-'a'] = 1;
			if(strlen(s) == 3)
				bad3[s[0]-'a'][s[1]-'a'][s[2]-'a'] = 1;
		}
		while(m--) {
			memset(memo, -1, sizeof memo);
			scanf("%s", pal);
			Q = N = strlen(pal); ans = 0;
			while(Q--) ans += solve(0, 0, 0, Q+1 == N, Q+1);
			printf("%d\n", ans);
		}
	}
	return 0;
}
