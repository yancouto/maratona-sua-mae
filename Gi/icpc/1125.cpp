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

int n, k, flag;
char w[1005][25], pal[25];
bool bad3[30][30][30], bad2[30][30], bad1[30];
ll memo[30][30][30][2], seen[30][30][30][2], resp[25];
ll tmp;


ll solve(int p, int c1, int c2, bool pre, int N) {
	if(p == N) return 1ll;
	ll &m = memo[p][c1][c2][pre];
	if(seen[p][c1][c2][pre] == tmp) return m;
	seen[p][c1][c2][pre] = tmp; m = 0;
	for(int c = 0; c < 26; c++) {
		if(pre && c > pal[p] - 'a') continue;
		if(bad1[c+1] || bad2[c2][c+1] || bad3[c1][c2][c+1]) continue;
		m += solve(p + 1, c2, c+1, pre && c == pal[p] -'a', N);
	}
	return m;
}

int main() {
	int t; char line[100];
	fgets(line, 100, stdin);
	sscanf(line, "%d", &t);
	while(t--) {
		int n, m, i, N, lst; 
		ll ans;
		char c1, c2, c;
		char s[5]; 
		fgets(line, 100, stdin); flag = 0;
		sscanf(line, "%d %d", &n, &m);
		memset(bad1, 0, sizeof bad1);
		memset(bad2, 0, sizeof bad2);
		memset(bad3, 0, sizeof bad3);
		memset(seen, 0, sizeof seen);
		tmp = 0;
		for(i = 0; i < n; i++) {
			fgets(line, 100, stdin);
			sscanf(line, "%s", s);
			if(strlen(s) == 1)
				bad1[s[0]-'a'+1] = 1;
			else if(strlen(s) == 2)
				bad2[s[0]-'a'+1][s[1]-'a'+1] = 1;
			else if(strlen(s) == 3)
				bad3[s[0]-'a'+1][s[1]-'a'+1][s[2]-'a'+1] = 1;
		}
		for(i = 1; i <= 20; i++) 
			tmp++, resp[i] = solve(0, 0, 0, 0, i);

		while(m--) {
			fgets(line, 100, stdin);
			if(line[0] >= '0' && line[0] <= '9') {
				ll pos; sscanf(line, "%lld", &pos);
				for(N = 1; N <= 20 && pos > 0; N++)
					pos -= resp[N];
				pos += resp[--N];
				c1 = c2 = 0;
				for(i = 0; i < N; i++) pal[i] = 'z';
				tmp++;
				for(i = 0; i < N; i++) {
					for(c = 0; c < 26; c++) {
						if(bad1[c+1] || bad2[c2][c+1] || bad3[c1][c2][c+1]) continue;
						if(solve(i + 1, c2, c + 1, 0, N) >= pos) break; 
						else pos -= solve(i + 1, c2, c + 1, 0, N);
					}
					c1 = c2;
					c2 = c + 1;
					pal[i] = c + 'a';
				}
				for(i = 0; i < N; i++)
					putchar(pal[i]);
				putchar('\n');
			}
			else {
				sscanf(line, "%s", pal);
				N = strlen(pal); tmp++;
				ans = solve(0, 0, 0, 1, N); 
				for(i = 1; i < N; i++) 
					ans += resp[i];
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
