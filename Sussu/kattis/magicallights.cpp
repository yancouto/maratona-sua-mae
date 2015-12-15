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

const int MAXN = 300010;

int n, m, pai[MAXN], sub[MAXN];

int chainNo[MAXN], ind[MAXN], degs, nchain, inichain[MAXN];

ull bm1[MAXN], bm2[MAXN], c[MAXN];

int res;

vector<int> adj[MAXN];

struct arv{
	ull v1, v2;
	ull lz1, lz2;
} tree[MAXN*8], s[MAXN];

void dfs(int v){
	sub[v] = 1;
	if(c[v] <= 63)
		bm1[v] = (1ull << ull(c[v]));
	else
		bm2[v] = (1ull << ull(c[v]-63));

	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v]) continue;
		dfs(nxt);
		sub[v] += sub[nxt];
		bm1[v] ^= bm1[nxt];
		bm2[v] ^= bm2[nxt];
	}
	//printf("%d ", v);
	//cout << bm1[v] << "  " << bm2[v] << "\n";

}

void HDL(int v){
	if(inichain[nchain] == -1)
		inichain[nchain] = v;
	chainNo[v] = nchain;
	ind[v] = degs;
	s[degs].v1 = bm1[v];
	s[degs++].v2 = bm2[v];

	int mai=-1, ind2;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v]) continue;
		if(sub[nxt] > mai){
			mai = sub[nxt];
			ind2 = nxt;
		}
	}
	if(mai!=-1)
		HDL(ind2);
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == ind2 || nxt == pai[v]) continue;
		nchain++;
		HDL(nxt);
	}
}

void build(int idx,int i,int j){
	if(i==j){
		tree[idx] = s[i];
		tree[idx].lz1 = 0;
		tree[idx].lz2 = 0;
		return ;
	}
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
	tree[idx].v1 = tree[idx*2].v1 ^ tree[idx*2+1].v1;
	tree[idx].v2 = tree[idx*2].v2 ^ tree[idx*2+1].v2;
}

void upd(int idx,int i,int j,int l, int r, ull val1, ull val2){
	if(i > r || j < l) return;
	if(tree[idx].lz1 || tree[idx].lz2){
		ull l1 = tree[idx].lz1, l2 = tree[idx].lz2;
		tree[idx].lz1 = 0;
		tree[idx].lz2 = 0;
		if(i!=j){
			tree[idx*2].v1 ^= l1;
			tree[idx*2].v2 ^= l2;
			tree[idx*2].lz1 ^= l1;
			tree[idx*2].lz2 ^= l2;

			tree[idx*2+1].v1 ^= l1;
			tree[idx*2+1].v2 ^= l2;
			tree[idx*2+1].lz1 ^= l1;
			tree[idx*2+1].lz2 ^= l2;
		}
	}
	if(i>=l && j<=r){
		tree[idx].v1 ^= val1;
		tree[idx].lz1 ^= val1;
		tree[idx].v2 ^= val2;
		tree[idx].lz2 ^= val2;
		return ;
	}
	int m = (i+j)/2;

	upd(idx*2,i,m,l,r,val1,val2);
	upd(idx*2+1,m+1,j,l,r,val1,val2);

	tree[idx].v1 = tree[idx*2].v1 ^ tree[idx*2+1].v1;
	tree[idx].v2 = tree[idx*2].v2 ^ tree[idx*2+1].v2;
}

void upd_up(int i, int j, int val){
	ull v1 = 0, v2 = 0;
	if(val <= 63)
		v1 = (1ull << ull(val));
	else
		v2 = (1ull << ull(val-63));

	if(c[i] <= 63)
		v1 ^= (1ull << ull(c[i]));
	else
		v2 ^= (1ull << ull(c[i]-63));
	c[i] = val;

	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int jj = ind[j2];
		int ii = ind[i];
		//printf("upd %d - %d\n", jj, ii);
		upd(1,1,degs-1,jj,ii,v1,v2);
		i = pai[j2];
	}
	//	printf("upd %d %d -  %d %d\n", j, ind[j], i, ind[i]);
	upd(1,1,degs-1,ind[j],ind[i],v1,v2);
}

void qry(int idx,int i,int j, int l){
	if(i>l || j<l) return ;
	if(tree[idx].lz1 || tree[idx].lz2){
		ull l1 = tree[idx].lz1, l2 = tree[idx].lz2;
		tree[idx].lz1 = 0;
		tree[idx].lz2 = 0;
		if(i!=j){
			tree[idx*2].v1 ^= l1;
			tree[idx*2].v2 ^= l2;
			tree[idx*2].lz1 ^= l1;
			tree[idx*2].lz2 ^= l2;

			tree[idx*2+1].v1 ^= l1;
			tree[idx*2+1].v2 ^= l2;
			tree[idx*2+1].lz1 ^= l1;
			tree[idx*2+1].lz2 ^= l2;
		}
	}
	if(i==j){
		res = __builtin_popcountll(tree[idx].v1) + __builtin_popcountll(tree[idx].v2);
		return ;
	}

	int m = (i+j)/2;
	qry(idx*2,i,m,l);
	qry(idx*2+1,m+1,j,l);

	tree[idx].v1 = tree[idx*2].v1 ^ tree[idx*2+1].v1;
	tree[idx].v2 = tree[idx*2].v2 ^ tree[idx*2+1].v2;
}

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<=n;a++){
		inichain[a] = -1;
	}
	for(int a=1;a<=n;a++){
		scanf("%llu",  &c[a]);
	}
	for(int a=2;a<=n;a++){
		scanf("%d", &pai[a]);
		adj[pai[a]].pb(a);
		adj[a].pb(pai[a]);
	}
	dfs(1);
	nchain = 0;
	degs=1;
	HDL(1);
	build(1,1,degs-1);
	for(int a=0;a<m;a++){
		int tip, v;
		scanf("%d%d", &tip, &v);
		if(tip)
			upd_up(v, 1, tip);
		else{
			res = 0;
			qry(1,1,degs-1,ind[v]);
			printf("%d", res);
			printf("\n");
		}
	}
	return 0;
}