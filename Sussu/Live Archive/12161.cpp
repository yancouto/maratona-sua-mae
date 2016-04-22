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

const int MAXN = 31234;

int n, m, deg[MAXN], sz[MAXN], proi[MAXN], nv;

struct ares{
	int v, d, c;
	ares(int Av, int Ad, int Ac){
		v = Av; d = Ad;	c = Ac;
	}
	ares(){}

};

vector<ares> adj[MAXN];

int dfs(int v, int p){
	sz[v] = 1;
	for(ares nxt: adj[v]){
		if(nxt.v == p) continue;
		sz[v] += dfs(nxt.v, v);
	}
	return sz[v];
}

int divi(int v, int p){
	int mai = -1, imai;
	for(ares nxt: adj[v]){
		if(nxt.v == p || proi[nxt.v]) continue;
		if(sz[nxt.v] > mai){
			mai = sz[nxt.v];
			imai = nxt.v;
		}
	}
	if(mai < nv/2)
		return v;
	return divi(imai, v);
}

struct track{
	int v, v2, d, c;
	track(int Av, int Av2, int Ad, int Ac){
		v = Av;
		v2 = Av2;
		d = Ad;
		c = Ac;
	}
	track(){}

	bool operator<(const track other) const { 
		return c < other.c;
	}
	bool operator==(const track other) const {
		return (v == other.v && v2 == other.v2 && d == other.d && c == other.c);
	}
} md, smd;

vector<track> cam, esc;

int go(int v, int p, int v2, int d, int c){
	//printf("chegay %d %d %d %d %d\n", v, p, v2, d, c);
	sz[v] = 1;
	if(c <= m)
		cam.pb(track(v, v2, d, c));
	//printf("boto em cam v %d pai %d v2 %d d %d c%d\n", v, p, v2, d, c);
	for(ares nxt: adj[v]){
		if(nxt.v == p || proi[nxt.v]) continue;
		sz[v] += go(nxt.v, v, v2, d + nxt.d, c + nxt.c);
	}
	return sz[v];
}

inline int bb(int i, int j, int val){
	while(i < j){
		int m = (i+j+1)/2;
		if(esc[m].c + val <= ::m)
			i = m;
		else
			j = m-1;
	}
	return i;
}

queue<int> s;

int main (){
	for_tests(t, tt){
		int res = 0;
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n;a++){
			adj[a].clear();
			proi[a] = 0;
		}
		for(int a=0;a<n-1;a++){
			int i, j, l, c;
			scanf("%d%d%d%d", &i, &j, &c, &l);
			adj[i].pb(ares(j, l, c));
			adj[j].pb(ares(i, l, c));
		}
		dfs(1, 0);
		s.push(1);
		while(!s.empty()){
			int r = s.front();
			s.pop();
			nv = sz[r];
			int v = divi(r, 0);
			//printf("divido em %d\n", v);
			//se o caminho otimo passar por v
			sz[v] = 1;
			for(ares nxt: adj[v]){
				if(proi[nxt.v]) continue;
				sz[v] += go(nxt.v, v, nxt.v, nxt.d, nxt.c);
			}

			cam.pb(track(v, v, 0, 0));
			sort(cam.begin(), cam.end());
			int j = cam.size()-1;
			for(int a = 0;a<=j;a++){
				if(esc.empty() || esc[esc.size()-1].d < cam[a].d){
					esc.pb(cam[a]);
					//printf("esc bota %d\n", cam[a].v);
				}
			}

			for(int a=0;a<cam.size();a++){
				int i = bb(0, esc.size()-1, cam[a].c);
				if(esc[i].v2 != cam[a].v2){
					//printf("res v %d %d  e v %d %d\n", esc[i].v, esc[i].d, cam[a].v, cam[a].d);
					res = max(res, esc[i].d + cam[a].d);
				}
			}
			cam.clear();
			esc.clear();
			//se o caminho nao passar por v
			proi[v] = 1;
			for(ares nxt: adj[v]){
				if(proi[nxt.v]) continue;
				s.push(nxt.v);
			}
		}
		printf("Case %d: %d\n", tt, res);
	}
	return 0;
}
