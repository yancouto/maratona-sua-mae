#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

char s1[200005], s2[200005];
vector<int> conf, a1[30], a2[30];
int f1[30], f2[30];

int l(char c) { return c - 'a'; }

int main() {
	int n; scanf("%d", &n);
	scanf("%s %s", s1, s2);
	for(int i = 0; i < n; i++) {
		if(s1[i] == s2[i]) continue;
		conf.pb(i); 
		a1[l(s1[i])].pb(i);
		a2[l(s2[i])].pb(i);
		f1[l(s1[i])]++;
		f2[l(s2[i])]++;
	}
	int ini, fim; ini = fim = -1;
	for(int i = 0; i < conf.size(); i++) {
		int um = l(s1[conf[i]]);
		int dois = l(s2[conf[i]]);
		if(f2[um] && f1[dois]) {
			for(int j = 0; j < a2[um].size(); j++) {
				int k = a2[um][j];
				if(s1[k] == s2[conf[i]]) { printf("%d\n%d %d\n", conf.size() - 2, conf[i] + 1, k + 1); return 0; }
			}
		}
		if(f2[um]) { ini = conf[i]; fim = a2[um][0]; }
		else if(f1[dois]) { ini = conf[i]; fim = a1[dois][0]; }
	}
	if(ini == -1) printf("%d\n-1 -1\n", conf.size());
	else printf("%d\n%d %d\n", conf.size() - 1, ini + 1, fim + 1);
	return 0;
}
