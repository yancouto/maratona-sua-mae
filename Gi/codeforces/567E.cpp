//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <priority_queue>
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

int n, m, s, t;
int seen[100005], pai[100005], used[100005], rps[100005], dist[10005];
vector<int> g[100005], w[100005];
set<pii> st;

struct No{
	int u, w, pai, rep;
	No() {}
	No(int u, int w, int pai, int rep) : u(u), w(w), pai(pai), rep(rep) {}
	bool operator<(const No &e) const{
		if(w == e.w) return rep > e.rep;
		return w > e.w;
	}
};

int simple_dik(int o, int f){
	priority_queue<No> pq;
	pq.push(No(o, 0, o, 0));
	while(!pq.empty()){
		No no = pq.top();
		pq.pop();
		int u = no.u;
		if(seen[u]) continue;
		if(u == f) return no.w;
		seen[u] = 1;
		for(int x = 0; x < g[u].size(); x++)
			pq.push(g[u][x], no.w + w[u][x], u, 0);
	}
}

int repairs, cost;
void dik_repair(int o, int f){
	priority_queue<No> pq;
	pq.push(No(o, 0, o, 0));
	while(!pq.empty()){
		No no = pq.top();
		pq.pop();
		int u = no.u;
		if(seen[u]) continue;
		seen[u] = 1;
		pai[u] = no.pai;
		dist[u] = no.w;
		if(u == f) {
			memset(seen, 0, sizeof seen);
			while(pai[u] != o){
				used[u] = 1;
				u = pai[u];
			}
			repairs = no.rep;
			cost = no.w;
			return;
		}
		for(int x = 0; x < g[u].size(); x++)
			pq.push(g[u][x], no.w + 1, u, no.rep + (w[u][x] == 1));
	}
}

void dik_final(int o, int f){
	memset(seen, 0, sizeof seen);
	priority_queue<No> pq;
	pq.push(No(o, 0, o, 0));
	while(!pq.empty()){
		No no = pq.top();
		pq.pop();
		int u = no.u;
		if(seen[u] && !used[u]) continue;
		if(seen[u]) {
			if(rps[u] != no.rep || dist[u] != no.w) continue;
			pai[u] = no.pai;
			while(pai[u] != o){
				st.insert(make_pair(pai[u], u));
				u = pai[u];
			}
			continue;
		}
		seen[u] = 1; 
		dist[u] = no.w;
		pai[u] = no.pai;
		if(u == f) {
			while(pai[u] != o){
				st.insert(make_pair(pai[u], u));
				used[u] = 1;
				u = pai[u];
			}
			repairs = no.rep;
			cost = no.w;
		}
		for(int x = 0; x < g[u].size(); x++)
			pq.push(g[u][x], no.w + 1, u, no.rep + (w[u][x]==1));
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &s, &t);
	queue<pii> edge;
	for(int i = 0; i < m; i++){
		int u, v, c; 
		scanf("%d %d %d", &u, &v, &c);
		edge.push(make_pair(u, v));
		g[u].pb(v);	w[u].pb(c);
	}
	int d = simple_dik(s, t);
	int dmin = dik_repair(s, t);
		
	return 0;
}
