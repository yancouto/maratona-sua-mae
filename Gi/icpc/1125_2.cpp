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
ll memo[20][26][26][2][12];


ll solve(int p, int c1, int c2, bool pre, int N) {
	if(p == N) {
		//if(N == 2) printf("%c %c\n", c1+'a', c2+'a');
		return 1ll;
	}
	ll &m = memo[p][c1][c2][pre][N];
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
	//if(N == 2)
	//printf("State %d %c %c %d e N %d = %lld\n", p, c1+'a', c2+'a', pre, N, m); 
	return m;
}

char bs(char b, char e, int i, int v, int N) {
	if(b >= e) return b;
	char mid = (b + e) / 2;
	pal[i] = mid;
	//printf("TRocnado pal[%d] para %c\n", i, mid);
	ll ans = 0;
	memset(memo, -1, sizeof memo);
	for(int j = N; j > 0; j--) 
		ans += solve(0, 0, 0, j == N, j);
	//printf("Avaliando letra %c resul %d\n", mid, ans);
	if(ans >= v)
		return bs(b, mid, i, v, N);
	//printf("Indo pra letras %c %c\n", mid+1, e);
	return bs(mid + 1, e, i, v, N);
}

int bsize(int a, int b, int v) {
	if(a >= b) return a;
	int mid = (a + b) / 2;
	ll ans = 0;
	memset(memo, -1, sizeof memo);
	for(int i = mid; i > 0; i--)
		ans += solve(0, 0, 0, 0, i);
	if(ans >= v)
		return bsize(a, mid, v);
	return bsize(mid + 1, b, v);
}

int main() {
	int t; char line[100];
	fgets(line, 100, stdin);
	sscanf(line, "%d", &t);
	while(t--) {
		int n, m, i, N; 
		ll ans;
		char s[5]; 
		fgets(line, 100, stdin);
		sscanf(line, "%d %d", &n, &m);
		memset(bad1, 0, sizeof bad1);
		memset(bad2, 0, sizeof bad2);
		memset(bad3, 0, sizeof bad3);
		for(i = 0; i < n; i++) {
			fgets(line, 100, stdin);
			sscanf(line, "%s", s);
			if(strlen(s) == 1)
				bad1[s[0]-'a'] = 1;
			else if(strlen(s) == 2)
				bad2[s[0]-'a'][s[1]-'a'] = 1;
			else if(strlen(s) == 3)
				bad3[s[0]-'a'][s[1]-'a'][s[2]-'a'] = 1;
		}
		while(m--) {
			fgets(line, 100, stdin);
			if(line[0] >= '0' && line[0] <= '9') {
				ll pos; sscanf(line, "%lld", &pos);
				N = bsize(0, 10, pos);
				for(i = 0; i < N; i++) pal[i] = 'z';
				for(i = 0; i < N; i++) 
					pal[i] = bs('a', 'z', i, pos, N);
				for(i = 0; i < N; i++) putchar(pal[i]);
				putchar('\n');
			}
			else {
				sscanf(line, "%s", pal);
				N = strlen(pal); ans = 0;
				memset(memo, -1, sizeof memo);
				for(i = N; i > 0; i--) {
					printf("respota (%d) = %lld\n", i, solve(0, 0, 0, N == i, i));
					ans += solve(0, 0, 0, N == i, i);
				}
				printf("%lld\n", ans);
			}
		}
	}
	return 0;
}
