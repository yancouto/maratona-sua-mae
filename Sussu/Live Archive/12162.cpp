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
		if(nxt.v == p) continue;
		if(sz[nxt.v] > mai){
			mai = sz[nxt.v];
			imai = nxt.v;
		}
	}
	if(mai == -1 || sz[imai] < nv/2)
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

vector<track> cam[MAXN], esc[MAXN];

int go(int v, int p, int v2, int d, int c){
	sz[v] = 1;
	if(c <= m)
		cam[v2].pb(track(v, v2, d, c));
	//printf("boto em cam v %d pai %d v2 %d d %d c%d\n", v, p, v2, d, c);
	for(ares nxt: adj[v]){
		if(nxt.v == p || proi[nxt.v]) continue;
		sz[v] += go(nxt.v, v, v2, d + nxt.d, c + nxt.c);
	}
	return sz[v];
}

int main (){
	for_tests(t, tt){
		int res = 0;
		scanf("%d%d", &n, &m);
		for(int a=1;a<=n;a++){
			sz[a] = 0;
			adj[a].clear();
			proi[a] = 0;
		}
		for(int a=0;a<n-1;a++){
			int i, j, l, c;
			scanf("%d %d%d%d", &i, &j, &c, &l);
			adj[i].pb(ares(j, l, c));
			adj[j].pb(ares(i, l, c));
		}
		dfs(1, 0);
		queue<int> s;
		s.push(1);
		while(!s.empty()){
			int r = s.front();
			s.pop();
			nv = sz[r];
			int v = divi(r, 0);
			//printf("divido em %d\n", v);
			//se o caminho otimo passar por v
			sz[v] = 0;
			for(ares nxt: adj[v]){
				if(proi[nxt.v]) continue;
				sz[v] += go(nxt.v, v, nxt.v, nxt.d, nxt.c);
			}
			for(ares nxt: adj[v]){
				if(proi[nxt.v]) continue;
				sort(cam[nxt.v].begin(), cam[nxt.v].end());
				for(int i=1;i<acm[nxt.v].size();i++){
					
				}
			}
			for(int j=0;j<cam.size();j++){
				for(int i=0;i<j;i++){
					if(cam[i].c + cam[j].c > m) break;
					if(cam[i].v2 == cam[j].v2) continue;
					res = max(res, cam[i].d + cam[j].d);
			//		printf("res max= %d + %d cmp %d %d\n", cam[i].d, cam[j].d, i, j);
				}
			}
			cam.clear();

			//se o caminho nao passar por v
			proi[v] = 1;
			for(ares nxt: adj[v]){
				if(proi[nxt.v]) continue;
				s.push(nxt.v);
			}
		}
		printf("%d\n", res);
	}
}
