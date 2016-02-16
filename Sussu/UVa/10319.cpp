#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 120*4;

int n, m, q, c[MAXN], mrk[MAXN];

stack <int> s;

inline int sim(int v){
	return v*2;
}

inline int nao(int v){
	return sim(v)+1;
}

vector<int> adj[MAXN], inv[MAXN];

void addedge(int u, int v){
	adj[u].pb(v);
	inv[v].pb(u);
}

void dfs(int v){
	mrk[v] = 1;
	for(int nxt: adj[v]){
		if(mrk[nxt]) continue;
		dfs(nxt);
	}
	s.push(v);
}

int nchain;

void go(int v){
	//printf("V %d\n", v);
	c[v] = nchain;
	//if(v&1) printf("nao ");
	//else printf("sim ");
	//printf("do ");
	//if( v/2 > n ) printf("y %d ", (v/2)-n);
	//else printf("x %d ", v/2);
	//printf(" recebe cor %d\n", nchain);
	for(int nxt: inv[v]){
		if( c[nxt] != -1 ) continue;
		go(nxt);
	}
}

int main(){
	for_tests(t,tt){
		nchain = 0;
		memset(c, -1, sizeof(c));
		memset(mrk, 0, sizeof(mrk));
		scanf("%d%d%d", &n, &m, &q);
		for(int a=sim(1);a<=nao(n+m);a++){
			adj[a].clear();
			inv[a].clear();
		}
		for(int a=0;a<q;a++){
			int x, y, xx, yy;
			scanf("%d%d%d%d", &x, &y, &xx, &yy);
			if( x != xx && y != yy ){
				if( x < xx && y < yy){
					addedge(nao(y+n), sim(yy+n));
					addedge(nao(y+n), sim(x));
					addedge(nao(yy+n), sim(y+n));
					addedge(nao(yy+n), sim(xx));
					addedge(nao(x), sim(y+n));
					addedge(nao(x), sim(xx));
					addedge(nao(xx), sim(yy+n));
					addedge(nao(xx), sim(x));
				}
				else if( x < xx && y > yy){
					addedge(nao(y+n), sim(yy+n));
					addedge(nao(y+n), nao(x));
					addedge(nao(yy+n), sim(y+n));
					addedge(nao(yy+n), nao(xx));
					addedge(sim(x), sim(y+n));
					addedge(sim(x), nao(xx));
					addedge(sim(xx), nao(yy+n));
					addedge(sim(xx), sim(x));
				}
				else if( x > xx && y < yy ){
					addedge(nao(x), sim(xx));
					addedge(nao(x), nao(y+n));
					addedge(nao(xx), sim(x));
					addedge(nao(xx), nao(yy+n));
					addedge(sim(y+n), sim(x));
					addedge(sim(y+n), nao(yy+n));
					addedge(sim(yy+n), sim(xx));
					addedge(sim(yy+n), nao(y+n));
				}
				else{
					addedge(sim(x), nao(xx));
					addedge(sim(x), nao(y+n));
					addedge(sim(xx), nao(x));
					addedge(sim(xx), nao(yy+n));
					addedge(sim(y+n), nao(x));
					addedge(sim(y+n), nao(yy+n));
					addedge(sim(yy+n), nao(y+n));
					addedge(sim(yy+n), nao(xx));
				}
			}
			else if( x == xx && y != yy ){
				int v;
				if( y < yy ) v = sim(x);
				else v = nao(x);
				for(int b=sim(1);b<=nao(n+m);b++){
					addedge(b, v);
				}
			}
			else if( x != xx && y == yy ){
				int u;
				if( x < xx ) u = sim(y+n);
				else u = nao(y+n);
				for(int b=sim(1);b<=nao(n+m);b++){
					addedge(b, u);	
				}
			}
		}
		for(int a=sim(1);a<=nao(n+m);a++){
			if(!mrk[a])
				dfs(a);
		}
		while(!s.empty()){
			int v = s.top();
			s.pop();
			if(c[v] == -1){
				nchain++;
				go(v);
			}
		}
		int ver = 0;
		for(int a=1;a<=n+m;a++){
			if(c[sim(a)] == c[nao(a)]){
				puts("No");
				ver = 1;
				break;
			}
		}
		if(!ver)
			puts("Yes");
	}
}