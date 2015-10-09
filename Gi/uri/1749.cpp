#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 50005;

int n;
int mark[MAX];
vector<int> g[MAX];
map<pii, int> mp;
set<int> p[MAX*10];

bool check(ll x, ll y, ll x2, ll y2) {
	return (ll)(x-x2)*(x-x2) + (ll)(y-y2)*(y-y2) <= 25ll;
}

bool dif(int x, int y, int x2, int y2) {
	return x != x2 || y != y2;
}

void dfs(int o, int c, int v[2]) {
	v[c]++; mark[o] = 1;
	for(int i = 0; i < g[o].size(); i++) {
		if(mark[g[o][i]]) continue;
		dfs(g[o][i], !c, v);	
	}
}

int main() {
	int x, y; int i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		mp[pii(x, y)] = i;
		p[y].insert(x);
	}
	map<pii, int>::iterator it;
	set<int>::iterator it2, it3;
	for(it = mp.begin(); it != mp.end(); ++it) {
		x = (it->x).x; y = (it->x).y;
		for(int yy = max(y - 5, 1); yy <= min(y + 5, 500000); yy++) {
			it2 = p[yy].lower_bound(x-5);
			it3 = p[yy].upper_bound(x+5);
			for(; it2 != it3; ++it2) {
				if(check(x, y, *it2, yy) && dif(x, y, *it2, yy)) 
					g[mp[pii(x, y)]].pb(mp[pii(*it2, yy)]);
			}
		}
	}
	int ans = 0, v[2];
	int count = 0;
	for(int i = 0; i < n; i++)
		if(!mark[i]) {  
			v[0] = v[1] = 0;
			dfs(i, 0, v);
			ans += min(v[0], v[1]);
		}
	printf("%d\n", ans);
	return 0;
}
