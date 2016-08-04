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

const int MAXN = 112345, MAXT = 1123456, DEZ = 1000010;

int n, p[MAXN], sz[MAXN];

struct pti{
	int x, y;
	pti(int xx, int yy){
		x = xx;
		y = yy;
	}
	pti(){}
} s[MAXN];

struct arv{
	int mn, mx;
	int ne, nc;
	int lze, lzc;
	/*arv operator = (arv o){
		mn = o.mn;
		mx = o.mx;
		ne = o.ne;
		nc = o.nc;
		lze = o.lze;
		lzc = o.lzc;
	}*/
} tree[4*MAXT], es[MAXN];

int raiz(int i){
	if(p[i] == i) return i;
	return p[i] = raiz(p[i]);
}

arv junta(arv a, arv b){
	arv ans;
	ans.mn = min(a.mn, b.mn);
	ans.mx = max(a.mx, b.mx);
	return ans;
}

void upd(int idx, int i, int j, int l, int r, int v1, int v2){
	if(l > r) return;
	if(l > j || r < i) return;
	if(tree[idx].lze != 0 || tree[idx].lzc != 0){
		int a1 = tree[idx].lze;
		int a2 = tree[idx].lzc;
		tree[idx].lze = 0;
		tree[idx].lzc = 0;
		if( i != j ){
			int l = idx*2;
			int r = idx*2+1;
			tree[l].lze += a1;
			tree[l].ne += a1;
			tree[l].lzc += a2;
			tree[l].nc += a2;

			tree[r].lze += a1;
			tree[r].ne += a1;
			tree[r].lzc += a2;
			tree[r].nc += a2;
		}
		return ;
	}
	if(i >= l && j <= r){
		tree[idx].lze += v1;
		tree[idx].ne += v1;
		tree[idx].lzc += v2;
		tree[idx].nc += v2;
		return ;
	}

	int m = (i+j)/2;
	upd(idx*2, i, m, l, r, v1, v2);
	upd(idx*2+1, m+1, j, l, r, v1, v2);
}

void join(int i, int j){
	i = raiz(i);
	j = raiz(j);
	if(i == j)
		return ;
	if(sz[i] > sz[j])
		swap(i, j);
	p[i] = j;
	upd(1, 0, DEZ, es[i].mn, es[i].mx-1, -1, -sz[i]);
	upd(1, 0, DEZ, es[j].mn, es[j].mx-1, -1, -sz[j]);
	sz[j] += sz[i];
	es[j] = junta(es[i], es[j]);
	upd(1, 0, DEZ, es[j].mn, es[j].mx-1, 1, sz[j]);
}

void qry(int idx, int i, int j, int l){
	if(l > j || l < i) return ;
	if(tree[idx].lze != 0 || tree[idx].lzc != 0){
		int a1 = tree[idx].lze;
		int a2 = tree[idx].lzc;
		tree[idx].lze = 0;
		tree[idx].lzc = 0;
		if( i != j ){
			int l = idx*2;
			int r = idx*2+1;
			tree[l].lze += a1;
			tree[l].ne += a1;
			tree[l].lzc += a2;
			tree[l].nc += a2;

			tree[r].lze += a1;
			tree[r].ne += a1;
			tree[r].lzc += a2;
			tree[r].nc += a2;
		}
	}
	if(i == j && i == l){
		printf("%d %d\n", tree[idx].ne, tree[idx].nc);
		return ;
	}
	int m = (i+j)/2;
	qry(idx*2, i, m, l);
	qry(idx*2+1, m+1, j, l);
}

void build(int idx, int i, int j){
	tree[idx].ne = tree[idx].nc = tree[idx].lze = tree[idx].lzc = 0;
	if(i == j)
		return;
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
}

int main (){
	for_tests(t, tt){
		build(1, 0, DEZ);
		scanf("%d", &n);
		for(int a=0;a<n;a++){
			int x;
			scanf("%d %d", &x, &es[a].mn);
			es[a].mx = es[a].mn;
			p[a] = a;
			sz[a] = 1;
		}
		int m;
		scanf("%d", &m);
		for(int a=0;a<m;a++){
			char com[10];
			scanf(" %s", com);
			if(com[0] == 'r'){
				int i, j;
				scanf("%d %d", &i, &j);
				printf("road com %d %d\n", i, j);
				join(i, j);
			}
			else{
				int i, j;
				printf("detecta line\n");
				scanf("%d.%d", &i, &j);
				printf("line com %d.5\n", i);
				qry(1, 0, DEZ, i);
				printf("passei do qry\n");
			}
		}
	}
}
