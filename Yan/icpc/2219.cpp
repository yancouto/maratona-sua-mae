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
vector<int> cit[502], adj[502];

int S[502], sz[502];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}

int main() {
	int n, c, i, k, j, x;
	while(true) {
		scanf("%d %d", &n, &c);
		for(i = 0; i < n; i++)
			cit[i].clear();
		int rc = c;
		for(i = 0; i < c; i++) {
			scanf("%d", &k);
			S[i] = i; sz[i] = 1;
			adj[i].clear();
			if(!k) rc--;
			for(j = 0; j < k; j++) {
				scanf("%d", &x);
				cit[x].pb(i);
			}
		}
		for(i = 0; i < n; i++)  {
			join(cit[i].front(), cit[i].back());
			adj[cit[i].front()].pb(cit[i].back());
			if(cit[i].size() > 1) adj[cit[i].back()].pb(cit[i].front());
		}
		int odd = 0;
		for(i = 0; i < c; i++)
			odd += adj[i].size() & 1;
		if((odd != 0 && odd != 2) || sz[find(cit[0].back())] != rc) {
			puts("-1");
			continue;
		}
		if(odd == 0) {
			puts("0");
			continue;
		}
		for(i = 0; i < n; i++)
			if((adj[cit[i].front()].size() & 1) || (adj[cit[i].back()].size() & 1))
				break;
		printf("%d\n", i);
	}
}
