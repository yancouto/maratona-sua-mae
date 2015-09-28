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
const int MAX = 10005;

int n, m, lst;
vector<int> g[MAX];
list<int> ans;
void dfs(int no, list<int>::iterator it) {
	list<int>::iterator aux = it;
	if(it != ans.end()) ++aux;
	it = ans.insert(aux, no);
	printf("No %d\n", no);
	while(!g[no].empty()) {
		int x = g[no].back();
		g[no].pop_back();
		dfs(x, it);
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &m, &lst);
		while(m--) {
			int a; scanf("%d", &a);
			g[lst].pb(a); lst = a;
		}
	}
	dfs(1, ans.begin());
	list<int>::iterator it;
	printf("%ld\n", ans.size());
	for(it = ans.begin(); it != ans.end(); ++it)
		printf("%d ", *it);
	putchar('\n');
	return 0;
}
