
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

const int MAXN = 100010;

int n; 

int jata[MAXN], h[MAXN], pai[MAXN], subsz[MAXN], nchain, chainno[MAXN], chainind[MAXN], chainini[MAXN], s[MAXN], degs;

int res[MAXN], ind[MAXN], tree[4*MAXN];

struct ares{
	int i, j, k;
} ar[MAXN], q[MAXN];

bool cmp(ares a,ares b){
	return a.k < b.k;
}

bool cmp2(int a,int b){
	return q[a].k < q[b].k;
}

vector <int> adj[MAXN], cus[MAXN];

void go(int v,int p){
	if(p != -1) h[v] = h[p] + 1;
	pai[v] = p;
	subsz[v] = 1;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == p) continue;
		go(nxt, v);
		subsz[v] += subsz[nxt];
	}
}

void HDL(int v){
	if(chainini[nchain] == -1)
		chainini[nchain] = degs;
	chainind[v] = degs;
	s[degs] = v;
	chainno[v] = nchain;
	degs++;

	int mai = -1, imai;
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v]) continue;
		if(subsz[nxt] > mai){
			mai = subsz[nxt];
			imai = nxt;
		}
	}

	if(mai != -1)
		HDL(imai);
	
	for(int a=0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(nxt == pai[v] || nxt == imai) continue;		
		nchain++;
		HDL(nxt);
	}
}

int qry(int idx,int i, int j, int l, int r){
	if(i > r || j < l) return 0;
	if(i >= l && j<=r)
		return tree[idx];
	
	int m = (i+j)/2;
	return qry(idx*2, i, m, l, r) + qry(idx*2+1, m+1, j, l, r);
}

void upd(int idx, int i, int j, int l, int val){
	if(i > l || j < l) return ;
	if(i == j){
		tree[idx] = val;
		return ;
	}
	int m = (i+j)/2;
	upd(idx*2,i,m,l,val);
	upd(idx*2+1,m+1,j,l,val);
	tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int main(){
	freopen("union.in", "r", stdin);
	freopen("union.out", "w", stdout);


	scanf("%d", &n);
	degs = 1;
	memset(chainini, -1, sizeof(chainini));
	for(int a=0;a<=n;a++){
		pai[a] = a;
	}
	for(int a=0;a<n-1;a++){
		scanf("%d %d %d", &ar[a].i, &ar[a].j, &ar[a].k);
		adj[ar[a].i].pb(ar[a].j);
		cus[ar[a].i].pb(ar[a].k);
		adj[ar[a].j].pb(ar[a].i);
		cus[ar[a].j].pb(ar[a].k);
	}
	sort(ar,ar+n-1,cmp);
	int m;
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		ind[a] = a;
		scanf("%d %d %d", &q[a].i, &q[a].j, &q[a].k);
	}
	sort(ind,ind+m,cmp2);
	go(1,1);
	HDL(1);
	int pa=0, pq=0;

	while(pq < m){
		//printf("loop %d %d\n", pa, ind[pq]);
		while(ar[pa].k <= q[ind[pq]].k && pa < n-1){
		//	printf("loop2 %d %d\n", pa, ind[pq]);
			int i = ar[pa].i, j = ar[pa].j, k = ar[pa].k; 
			if(h[i] < h[j]) swap(i,j);
			upd(1, 1, degs-1, chainind[i], 1);
		//	printf("dei upd no v %d\n", s[chainind[i]]);
			jata[i] = 1;
			pa++;
		}
		int i = q[ind[pq]].i, j = q[ind[pq]].j;
		while(1){
		//	printf("i %d j %d\n", i, j);
			
			int cabi = s[chainini[chainno[i]]], cabj = s[chainini[chainno[j]]];
			if(chainno[i] == chainno[j]){
				res[ind[pq]] += qry(1, 1, degs-1, min(chainind[i], chainind[j]), max(chainind[i], chainind[j]));
				res[ind[pq]] -= jata[s[min(chainind[i], chainind[j])]];
		//		printf("de %d ate %d qry deu %d\n",  s[min(chainind[i], chainind[j])], s[max(chainind[i], chainind[j])],  qry(1, 1, degs-1, min(chainind[i], chainind[j]), max(chainind[i], chainind[j])));
				break;
			}
			if(h[cabi] < h[cabj]){
				swap(i,j);
				swap(cabi, cabj);
			}
			res[ind[pq]] += qry(1, 1, degs-1, chainind[cabi], chainind[i]);
//			printf("de %d ate %d qry deu %d\n", s[chainind[cabi]], s[chainind[i]],  qry(1, 1, degs-1, chainind[cabi], chainind[i]));
			i = pai[cabi];
		}
		pq++;
	}

	for(int a=0;a<m;a++){
		printf("%d\n", res[a]);
	}
}

