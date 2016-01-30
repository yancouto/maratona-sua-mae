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
int base;

char s[2003];
unordered_map<int, int> h[2002];
int main() {
	base = 263 + (rand() % 40);
	while(fgets(s, sizeof s, stdin)) {
		if(s[0] == '0' && !s[2]) return 0;
		int j = 0, i;
		for(i = 0; s[i]; i++)
			if(s[i] != ' ')
				s[j++] = s[i];
		int n = j;
		s[n - 1] = 0; n--;
		for(i = 0; i < n; i++) {
			ll hs = 0;
			for(j = i; j < n; j++) {
				hs = mod(hs * base + s[j]);
				h[j - i + 1][hs]++;
			}
		}
		for(i = 1; i <= n; i++) {
			int mx = 0;
			for(pii p : h[i])
				mx = max(mx, p.snd);
			printf("%d\n", mx);
			if(mx == 1) break;
		}
		for(i = 0; i <= n; i++)
			h[i].clear();
	}
}
