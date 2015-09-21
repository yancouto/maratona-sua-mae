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

vector<int> adj[105];
int dg[105];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		while(42) {
			int no; scanf("%d", &no);
			if(!no) break; no--;
			adj[i].pb(no);
			dg[no]++;
		}
	}
	deque<int> dq;
	for(int st = 0; st < n; st++)
		if(!dg[st]) dq.pb(st);
	vector<int> ans;
	while(!dq.empty()) {
		int no = dq.front();
		dq.pop_front();
		ans.pb(no);
		for(int i = 0; i < adj[no].size(); i++) {
			int x = adj[no][i]; dg[x]--;
			if(!dg[x]) dq.pb(x);
		}
	}
	for(int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i] + 1);
	putchar('\n');
	return 0;
}
