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

int n, m;
int b[100005], a[100005];
vector<int> f[100005];

int main() {
	int i, x;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) scanf("%d", &x), f[x].pb(i+1);
	for(i = 0; i < m; i++) scanf("%d", &b[i]);
	bool amb = false;
	for(i = 0; i < m; i++) {
		if(f[b[i]].empty()) { puts("Impossible"); return 0; }
		else if(f[b[i]].size() > 1) amb = true;
		else a[i] = f[b[i]][0];
	}
	if(amb) puts("Ambiguity");
	else {
		puts("Possible");
		for(i = 0; i < m; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	return 0;
}
