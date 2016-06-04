
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


int n, m, na;

struct ares{
	int i, j, k;
	ares(){}
	ares(int ii, int jj, int kk){
		i=ii; j = jj; k = kk;
	}
	bool operator (const qry other) const{
		return k < other.k;
	}
} ar[MAXN];

pii q[MAXN], res[MAXN];

int qdeg[MAXN];

//Union-Find
int pai[MAXN], sz[MAXN];
int mx[MAXN], deg[MAXN];

int cnt;

int paizao(int v){
	if(pai[v] == v) return v;
	return pai[v] = paizao(pai[v]);
}

void join(int a,int b){
	int pb = paizao(b);
	int pa = paizao(a);
	
	if(pa == pb) return;
	
	qdeg[deg[a]]--;
	qdeg[deg[b]]--;
	deg[a]++;
	deg[b]++;
	q[deg[a]]++;
	q[deg[b]]++;

	a = pa;
	b = pb;
	if(sz[a] < sz[b])
		swap(a, b);
	pai[b] = a;
	sz[a] += sz[b];
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=1;a<=n;a++){
		pai[a] = a;
		mx[a] = deg[a] = 0;
	}
	qdeg[0] = n;
	for(int a=0;a<m;a++){
		scanf("%d%d%d", &ar[a].i, &ar[a].j, &ar[a].k);
	}
	sort(ar, ar+n);
	scanf("%d", &nq);
	for(int a=0;a<nq;a++){
		scanf("%d", &q[a].fst);
		q[a].snd = a;
	}
	sort(q, q+nq);
	int i=0;
	for(int a=0;a<n;a++){
		while(i < nq && ar[a].k < q[i].fst){
			join(ar[a].i, ar[a].j);
			i++;
		}
		printf("%d %d\n", 
	}
}
