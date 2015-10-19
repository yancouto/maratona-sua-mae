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
const int MAX = 55;

int id[2 * MAX];
vector<int> v[2 * MAX];
int n, m;

int main() {
	int a, b;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		v[a].pb(b); v[b].pb(a);
	}
	vector<int> c1, c2, c3;
	for(int i = 1; i <= 2 * n; i++) {	
		bool um = false, dois = false;
		if(v[i].empty()) { c3.pb(i); continue; }
		for(int j = 0; j < v[i].size(); j++) {
			if(id[v[i][j]] == 1) um = true;
			else if(id[v[i][j]] == 2) dois = true;
		}
		if(um && dois) { puts("IMPOSSIBLE"); return 0; }
		if((um && id[i] == 1) || (dois && id[i] == 2)) { puts("IMPOSSIBLE"); return 0; }
		if(um) {
			if(id[i] != 2) { id[i] = 2; c2.pb(i); }
			for(int j = 0; j < v[i].size(); j++) {
				if(id[v[i][j]] == 1) continue;
				id[v[i][j]] = 1; c1.pb(v[i][j]); 
			}
		}
		else {
			if(id[i] != 1) { id[i] = 1; c1.pb(i); }
			for(int j = 0; j < v[i].size(); j++) { 
				if(id[v[i][j]] == 2) continue;
				id[v[i][j]] = 2; c2.pb(v[i][j]);
			}
		}
	}
	if(c1.size() > n || c2.size() > n) { puts("IMPOSSIBLE"); return 0; }
	while(c1.size() != n) {
		c1.pb(c3[c3.size() - 1]);
		c3.pop_back();
	}
	while(c2.size() != n) {
		c2.pb(c3[c3.size() - 1]);
		c3.pop_back();
	}
	for(int i = 0; i < n; i++) printf("%d ", c1[i]);
	putchar('\n');
	for(int i = 0; i < n; i++) printf("%d ", c2[i]);
	putchar('\n');
	return 0;
}
