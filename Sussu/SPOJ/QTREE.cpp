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

#define mp make_pair

const int MAXN = 10010, LOGN = 20;

int n, pai[MAXN][LOGN], chainNo[MAXN], chainInd[MAXN], s[MAXN*2], subsize[MAXN], nchain, degs, inichain[MAXN];

vector <int> adj[MAXN], pes[MAXN];
vector <pair<pii,int> > ares;

int tree[8*MAXN];

int h[MAXN], custopai[MAXN];

int res;

void dfs(int v,int ant){
	pai[v][0] = ant;
	h[v] = h[ant]+1;
	for(int a=1;a<LOGN;a++){
		pai[v][a] = pai[pai[v][a-1]][a-1];
	}
	subsize[v] = 1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt != ant){
			custopai[nxt] = pes[v][a];
			dfs(nxt,v);
			subsize[v] += subsize[nxt];
		}
	}
}

void HLD(int v){
	chainInd[v] = degs;
	chainNo[v] = nchain;
	int mai=-1, ind=-1, maip = -1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		int cus = pes[v][a];
		if(nxt == pai[v][0]) continue;
		if(mai < subsize[nxt]){
			mai = subsize[nxt];
			maip = cus;
			ind = nxt;
		}
	}
	if(mai != -1){
		if(inichain[nchain] == -1){
			inichain[nchain] = v;
		}
		s[degs++] = maip;
		HLD(ind);
	}
	else{
		// eh uma folha
		if(inichain[nchain] == -1){
			inichain[nchain] = v;
		}
		s[degs++] = 0; //para que todo no tenha uma valor na seg
	}
	for(int a =0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		int cus = pes[v][a];
		if(nxt == pai[v][0] || nxt == ind) continue;
		nchain++;
		HLD(nxt);
	}
}

//segtree
void build(int idx,int i,int j){
	if(i==j){
		tree[idx] = s[i];
		return;
	}
	int m = (i+j)/2;
	build(idx*2,i,m);
	build(idx*2+1,m+1,j);
	tree[idx] = max(tree[idx*2],tree[idx*2+1]);
}

int LCA(int i,int j){
	if(h[j] > h[i]) swap(i,j);

	if(h[i] > h[j]){
		for(int a = LOGN-1;a>=0;a--){
			if(h[pai[i][a]] > h[j]){
				i = pai[i][a];
			}
		}
		i = pai[i][0];
	}

	if(i==j) return i;

	for(int a=LOGN-1;a>=0;a--){
		if(pai[i][a] != pai[j][a]){
			i = pai[i][a];
			j = pai[j][a];
		}
	}
	return pai[i][0];
}

void qry(int idx,int i,int j,int l, int r){
	if(i > r || j < l) return ;
	if(i>=l && j<=r){
		res = max(res,tree[idx]);
		return;
	}
	int m = (i+j)/2;
	qry(idx*2,i,m,l,r);
	qry(idx*2+1,m+1,j,l,r);
}

void qryup(int i,int j){
//	printf("qryup %d chain %d   %d chain %d\n", i, chainNo[i], j, chainNo[j]);

	while(chainNo[i] != chainNo[j]){
		int j2 = inichain[chainNo[i]];
		int ii = chainInd[i], jj = chainInd[j2];
		if(ii!=jj)
			qry(1,1,degs-1,jj,ii-1);
		res = max(res, custopai[j2]);
//		printf("res recebe max entre res e custopai[%d] %d\n", j2, custopai[j2]);
		i = pai[j2][0];
	}
//	printf("agora tao na mesma chain %d %d\n", i, j);
	// mesma chain
	int ii = chainInd[i], jj = chainInd[j];
	if(ii==jj) return;
	qry(1,1,degs-1,jj,ii-1);
}

void upd(int idx,int i, int j, int l, int val){
	if(i>l || j<l) return ;
	if(i == j){
		tree[idx] = val;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,val);
	upd(idx*2+1,m+1,j,l,val);
	tree[idx] = max(tree[idx*2],tree[idx*2+1]);
}

int main (){
	for_tests(t,tt){
		degs=1;
		nchain = 0;
		memset(inichain,-1,sizeof(inichain));
		memset(tree,0,sizeof(tree));
		ares.clear();
		scanf("%d", &n);
		for(int a=0;a<=n;a++){
			adj[a].clear();
			pes[a].clear();
		}
		int pri = -1;
		for(int a=0;a<n-1;a++){
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);
			if(pri == -1) pri = i;
			ares.pb(mp(mp(i,adj[i].size()),adj[j].size()));
			adj[i].pb(j);
			adj[j].pb(i);

			pes[i].pb(k);
			pes[j].pb(k);
		}
		h[pri] = -1;
		dfs(pri,pri);
		nchain = 0;
		HLD(pri);
		build(1,1,degs-1);

		char ins;
		scanf(" %c", &ins);
		scanf("%*s");
		while(ins != 'D'){
			int i, j;
			scanf("%d %d", &i, &j);
			if(ins == 'Q'){
				res = 0;
				int lca = LCA(i,j);
//				printf("qryup %d %d e %d %d\n", i, lca, j, lca);
				qryup(i,lca);
				qryup(j,lca);
				printf("%d\n", res);
			}
			else{
				i--;
				int v = ares[i].fst.fst;
				int a = ares[i].fst.snd;
				int a2 = ares[i].snd;
				pes[v][a] = j;
				pes[adj[v][a]][a2] = j;
				if(pai[v][0] == adj[v][a]){
					custopai[v] = j;
					if(chainNo[v] == chainNo[adj[v][a]]){
						//printf("chain %d = chain %d\n", chainNo[v], chainNo[adj[v][a]]);
						//break;
						upd(1, 1, degs-1, chainInd[adj[v][a]], j);
					}
				}
				else{
					custopai[adj[v][a]] = j;
					//printf("upd pos %d valor %d entre os caras %d e %d\n", chainInd[v], j, v, adj[v][a]);
					if(chainNo[v] == chainNo[adj[v][a]]){
						//printf("chain %d = chain %d\n", chainNo[v], chainNo[adj[v][a]]);
						//break;
						upd(1, 1, degs-1, chainInd[v], j);
					}
				}
			}

			scanf(" %c", &ins);
			scanf("%*s");
		}
	}
	return 0;
}