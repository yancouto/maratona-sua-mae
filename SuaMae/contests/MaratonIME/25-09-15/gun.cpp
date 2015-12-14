#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, m;
vector<int> g[105];
map<string, int> mp;
string nome[105];
pii wh[105];
int dg[105];

int add(char s[100]) {
	string name = string(s);
	if(!mp.count(name)) mp[name] = mp.size() - 1;
	return mp[name];
}

ll dist(int i1, int i2) {
	return (wh[i1].fst - wh[i2].fst) * (wh[i1].fst - wh[i2].fst) + (wh[i1].snd - wh[i2].snd) * (wh[i1].snd - wh[i2].snd); 
}

int seen[105], mark[105];
vector<int> ord;

int ordtop() {
	deque<int> dq;
	for(int i = 0; i < n; i++) {
		if(!mark[i]) continue;
		if(!dg[i]) dq.pb(i);
	}
	bool unknow = false;
	while(!dq.empty()) {
		if(dq.size() > 1) unknow = true;
		int v = dq.front(); dq.pop_front();
		seen[v] = 1; ord.pb(v);
		for(int i = 0; i < g[v].size(); i++) {
			int x = g[v][i];
			dg[x]--;
			if(!dg[x]) dq.pb(x);
		}
	}
	for(int i = 0; i < n; i++) {
		if(!mark[i]) continue;
		if(!seen[i]) return 2;
	}
	return unknow;
}

map<pii, int> info[105][105];

int main() {
	int t; scanf("%d", &t);
	char s[100];
	while(t--) {
		memset(dg, 0, sizeof dg);
		memset(mark, 0, sizeof mark);
		memset(seen, 0, sizeof seen);
		ord.clear(); mp.clear();
		scanf("%d %d", &n, &m);
		for(int i = 0; i <= n; i++) g[i].clear();
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				info[i][j].clear();
		for(int i = 0; i < n; i++) {
			scanf("%s", s);
			int ind = add(s);
			scanf("%lld %lld", &wh[ind].fst, &wh[ind].snd);
			nome[ind] = string(s);
		}
		int nval = 0;
		bool impos = false;
		char s1[100], s2[100], s3[100];
		for(int i = 0; i < m; i++) {
			scanf("%s heard %s firing before %s", s1, s2, s3);
			int i1 = mp[string(s1)], i2 = mp[string(s2)], i3 = mp[string(s3)];
			mark[i2] = mark[i3] = 1;
			if(dist(i1, i3) <= dist(i1, i2)) {
				g[i2].pb(i3);
				dg[i3]++; nval++;
			}
			int won = 0;
			if(i2 > i3) { swap(i2, i3); won = 1; }
			if(info[i2][i3].count(pii(dist(i1, i2), dist(i1, i3))))
				{if(info[i2][i3][pii(dist(i1, i2), dist(i1, i3))] != won) impos = true;}
			else
				info[i2][i3][pii(dist(i1, i2), dist(i1, i3))] = won;
		}
		if(impos) { puts("IMPOSSIBLE"); continue; }
		if(!nval) { puts("UNKNOWN"); continue; }
		int resp = ordtop();
		if(resp == 2) { puts("IMPOSSIBLE"); continue; }
		if(resp) { puts("UNKNOWN"); continue; }
		for(int i = 0; i < ord.size(); i++) {
			printf("%s", nome[ord[i]].c_str());
			if(i < ord.size() - 1) putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
