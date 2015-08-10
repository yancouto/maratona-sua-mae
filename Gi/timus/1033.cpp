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

int n;
int lab[35][35];
vector<int> adj[1225];
int seen[1225];
void ins(int i, int j){
	int v = i*n + j + 1;
	if(j-1 >= 0) adj[v].pb(v-1);
	if(j+1 < n) adj[v].pb(v+1);
	if(i-1 >= 0) adj[v].pb((i-1)*n + j + 1);
	if(i+1 < n) adj[v].pb((i+1)*n + j + 1);
}

int dfs(int x){
	if(adj[x].empty()) return 1;
	if(seen[x]) return 0;
	seen[x] = 1;
	int ans = 0;
	for(int i = 0; i < adj[x].size(); i++)
		ans += dfs(adj[x][i]);

	return ans;
}

int main(){
	scanf("%d", &n); n += 2;
	ins(0,0); ins(0, 1); ins(1, 0);
	ins(n-1, n-2); ins(n-1, n-1); ins(n-2, n-1);
	for(int i = 1; i <= n-2; i++){
		for(int j = 1; j <= n-2; j++){
			char c; scanf(" %c", &c);
			if(c == '.') ins(i, j);
		}
	}
	ull ans = dfs(1) + dfs(n*n);
	printf("%d\n", (ans-4)*9);
	return 0;
}
