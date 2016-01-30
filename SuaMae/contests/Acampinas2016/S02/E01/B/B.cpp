
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

#define ZERA 1
#define UMZA 2

const int MAXN = 100010, MAXT = 4*MAXN;

int degs, subsz[MAXN], h[MAXN], hmax[MAXN], chainno[MAXN], ult[MAXN], inichain[MAXN], indchain[MAXN], s[MAXN], nchain, pai[MAXN];

vector <int> adj[MAXN];

struct arv{
	int lz, s;
}	tree[4*MAXN];

void go(int v){
	subsz[v] = 1;
	if(pai[v] != -1)
		h[v] = h[pai[v]]+1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		go(nxt);
		subsz[v] += subsz[nxt];
	}
}

void HDL(int v){
	s[degs] = v;
	if(inichain[nchain] == -1) inichain[nchain] = degs;	
	indchain[v] = degs++;
	chainno[v] = nchain;

	int mai = -1, imai;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mai <= subsz[nxt]){
			mai = subsz[nxt];
			imai = nxt;
		}
	}
	if(mai != -1)
		HDL(imai);
	
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == imai) continue;
		nchain++;
		HDL(nxt);
	}
}

int qry(int idx,int i,int f, int l, int r){
	if(i > r || f < l) return 0;
	if(tree[idx].lz != 0){
		if(i != f){
			int op = tree[idx].lz; // 1 se for pra zera e 2 se for pra umza
			tree[idx*2].lz = op;
			tree[idx*2+1].lz = op;
			int m = (i+f)/2;
			tree[idx*2].s = (m-i+1)*(op-1);
			tree[idx*2+1].s = (f-m)*(op-1);
		}
		tree[idx].lz = 0;
	}
	if(i >= l && f <= r){
//		printf("encontrou %d %d %d %d retornou %d\n", i, f, l, r, tree[idx].s);
		return tree[idx].s;
	}
	int m = (i+f)/2;
//	printf("qry %d %d %d %d %d = %d + %d\n", idx, i, f, l, r, qry(idx*2,i,m,l,r), qry(idx*2+1,m+1,f,l,r));
	return qry(idx*2,i,m,l,r) + qry(idx*2+1,m+1,f,l,r);
}


void upd(int idx, int i, int f,int l,int r,int op){
	if(i > r || f < l) return ;
	if(tree[idx].lz != 0){
		if(i != f){
			int op = tree[idx].lz; // 1 se for pra zera e 2 se for pra umza
			int m = (i+f)/2;
			tree[idx*2].s = (m-i+1)*(op-1);
			tree[idx*2+1].s = (f-m)*(op-1);
			tree[idx*2].lz = op;
			tree[idx*2+1].lz = op;
		}
		tree[idx].lz = 0;
	}
	if(i >= l && f <= r){
		tree[idx].s = (f-i+1)*(op-1);
		tree[idx].lz = op;
		return ;
	}
	int m = (i+f)/2;
	upd(idx*2,i,m,l,r,op);
	upd(idx*2+1,m+1,f,l,r,op);
	tree[idx].s = tree[idx*2].s + tree[idx*2+1].s;
}

int main (){
	freopen("genealogy.in", "r", stdin);
	freopen("genealogy.out", "w", stdout);
	int n;
	scanf("%d", &n);
	memset(inichain, -1, sizeof(inichain));
	int raiz = 0;
	for(int a=1;a<=n;a++){
		scanf("%d", &pai[a]);
		if(pai[a] == -1) 
			raiz = a;
		else
			adj[pai[a]].pb(a);
	}
	memset(ult,-1,sizeof(ult));
	degs = 1;
	go(raiz);
	HDL(raiz);
	upd(1,1,degs-1,1,degs-1,UMZA);
	int m;
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int res = 0;
		for_tests(t,tt){
			int v;
			scanf("%d", &v);
			while(v != -1){

//				printf("v %d\n", v);
				int cab = s[inichain[chainno[v]]];
				if(ult[cab] < a)
					hmax[cab] = h[cab];
				ult[cab] = a;
				res += max(0, h[v] - hmax[cab] + 1);	
				hmax[cab] = max(hmax[cab], h[v] + 1);
				//res += qry(1, 1, degs-1, inichain[chainno[v]], indchain[v]);
		//		printf("qry 1 1 %d %d %d  valeu %d\n", degs-1, inichain[chainno[v]], indchain[v], qry(1, 1, degs-1, inichain[chainno[v]], indchain[v]));
				//upd(1, 1, degs-1, inichain[chainno[v]], indchain[v], ZERA);
		//		printf("v: %d chainno %d inichain %d s[inichain] %d pai[s[ini..]] %d\n", v, chainno[v], inichain[chainno[v]], s[inichain[chainno[v]]], pai[s[inichain[chainno[v]]]]);
				v = pai[cab];
			}
		}
		printf("%d\n", res);
		//upd(1,1,degs-1,1,degs-1, UMZA);
	}
}
