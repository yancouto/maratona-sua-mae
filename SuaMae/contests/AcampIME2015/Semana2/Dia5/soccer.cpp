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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
int n, h;

vector<int> adj[10003];
int seen[10004], deg[10004];
int tempo, tempo2;
int top[10004], inv[10004];

bool dfs(int u) {
	//printf("u%d %d\n", u, seen[u]);
	if(seen[u] == tempo) return true;
	seen[u] = tempo;
	for(int v : adj[u])
		if(!dfs(v))
			return false;
	tempo2++;
	top[n - tempo2] = u;
	inv[u] = n - tempo2;
	//printf("%d t%d\n", u, n - tempo2);
	return true;
}

int main() {
	int i, j, a, b;
	tempo = 0;
	for_tests(t, tt) {
		scanf("%d %d", &n, &h);
		for(i = 0; i < h; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			adj[a].pb(b);

		}
		tempo++; tempo2 = 0;
		for(i = 0; i < n; i++)
			if(seen[i] < tempo)
				dfs(i);

		//for(i = 0; i < n; i++)
		//	printf("%d ", top[i] + 1);
		//putchar('\n');
		bool flag = false, flag2 = false;
		for(i = 0; i < n; i++) {
			bool has = false, left = false;
			for(int v : adj[top[i]]) {
				if(i < n - 1 && v == top[i + 1]) {
//					printf("%d to %d\n", top[i], top[i + 1]);
					has = true;
				}
				//printf("%d to %d (%d)\n", top[i], v, inv[v]);
				if(inv[v] < i)
					left = true;
			}
			if(left) { puts("recheck hints"); flag = true; break; }
			if((i < n - 1) && !has) flag2 = true;		
		}
		for(j = 0; j < n; j++) adj[j].clear();
		if(flag) continue;
		if(!flag2) {
			for(i = 0; i < n; i++)
				printf("%d ", top[i] + 1);
			putchar('\n');
		} else puts("missing hints");
	}
	return 0;
}
