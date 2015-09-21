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


vector<int> adj[305];
map<string, int> mp;
string ump[305];
int dist[305];
int imp;

int add_edge(string name) {
	if(!mp.count(name)) mp[name] = imp++;
	return mp[name];
}

void show() {
	for(map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
		int i = it->snd;
		printf("%s ", ump[i].c_str());
		if(dist[i] == -1) printf("undefined\n");
		else printf("%d\n", dist[i]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	char x[25], y[25], z[25];
	for(int i = 0; i < n; i++) {
		scanf("%s %s %s", x, y, z);
		int i1 = add_edge(string(x));
		int i2 = add_edge(string(y));
		int i3 = add_edge(string(z));
		ump[i1] = string(x);
		ump[i2] = string(y);
		ump[i3] = string(z);
		adj[i1].pb(i2); adj[i1].pb(i3);
		adj[i2].pb(i1); adj[i2].pb(i3);
		adj[i3].pb(i1); adj[i3].pb(i2);
	}
	string st("Isenbaev");
	memset(dist, -1, sizeof dist);
	if(!mp.count(st)) { show(); return 0; }
	dist[add_edge(st)] = 0;
	deque<int> dq;
	dq.pb(add_edge(st));
	while(!dq.empty()) {
		int no = dq.front();
		dq.pop_front();
		for(int i = 0; i < adj[no].size(); i++) {
			int x = adj[no][i];
			if(dist[x] == -1 || dist[x] > dist[no] + 1) {
				dist[x] = dist[no] + 1;
				dq.pb(x);
			}
		}
	}
	show();
	return 0;
}
