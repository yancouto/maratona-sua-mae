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

const int MAXN = 400010, INF = 0x3f3f3f3f;

int n, q, p[MAXN], ind[MAXN], degi, inv[MAXN], s[MAXN], degs, chainNo[MAXN], chainInd[MAXN], nchain, inichain[MAXN], sub[MAXN];

vector<int> adj[MAXN];

int tree[4*MAXN];

void dfs(int v,int pai){
	ind[v] = degi;
	inv[degi] = v;
	degi++;
	p[v] = pai;
	sub[v] = 1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai) continue;
		dfs(nxt,v);
		sub[v] +=  sub[nxt];
	}
}

void go(int v,int pai){
	chainNo[v] = nchain;
	chainInd[v] = degs;
	s[degs++] = v;
	if(inichain[chainNo[v]] == -1)
		inichain[chainNo[v]] = v;
	int mai=-1, ind;
	for(int a = 0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai) continue;
		if(sub[nxt] > mai){
			mai = sub[nxt];
			ind = nxt;
		}
	}
	if(mai != -1) 
		go(ind,v);

	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai || nxt == ind) continue;
		nchain++;
		go(nxt,v);
	}
}

void upd(int idx,int i,int j,int l){
	if(i > l || j < l) return;
	if(i == j){
		if(tree[idx] == INF)
			tree[idx] = ind[s[i]];
		else
			tree[idx] = INF;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l);
	upd(idx*2+1,m+1,j,l);
	tree[idx] = min(tree[idx*2],tree[idx*2+1]);
}

int qry(int idx,int i,int j,int l,int r){
	if(i > r || j < l) return INF;

	if(i>=l && j<=r)
		return tree[idx];

	int m = (i+j)/2;
	return min(qry(idx*2,i,m,l,r), qry(idx*2+1,m+1,j,l,r));
}

int main (){
	scanf("%d%d", &n, &q);
	for(int a=0;a<n-1;a++){
		int i, j;
		scanf("%d %d", &i, &j);
		adj[i].pb(j);
		adj[j].pb(i);
	}

	memset(inichain,-1,sizeof(inichain));
	memset(tree,INF,sizeof(tree));
	degs = 1;
	dfs(1,1);
	nchain = 0;
	go(1,1);

	for(int a=0;a<q;a++){
		int t, v;
		scanf("%d%d", &t, &v);
		if(!t)
			upd(1,1,degs-1,chainInd[v]);
		else{
			int ans = INF;
			while(v != 1){
				int ini = chainInd[inichain[chainNo[v]]];
				int vv = chainInd[v];
				ans = min(ans,qry(1,1,degs-1,ini,vv));
				v = inichain[chainNo[v]];
				v = p[v];
			}
			ans = min(ans,qry(1,1,degs-1,chainInd[1],chainInd[1]));
			if(ans == INF) puts("-1");
			else
				printf("%d\n", inv[ans]);
		}
	}
}