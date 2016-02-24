
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

const int MAXN = 2000010, INF = 0x3f3f3f3f;

int raiz[5];

struct arv{
	int x, y;
	int l, r, p;
	int mn, mx;
	int rmn;
	int t;
	arv(){};
	arv(int xx){
		x = xx;
		y = rand();
		p = l = r = 0;
		mn = mx = xx;
		rmn = INF;
		t = 1;
	};
	arv(int xx, int yy){
		x = xx;
		y = yy;
		p = l = r = 0;
		mn = mx = xx;
		rmn = INF;
		t = 1;
	};
} tree[MAXN];

int find(int vx, int ind){
	int u = raiz[ind];
	upd(u);
	upd(tree[u].l);
	upd(tree[u].r);
	while((vx <= tree[u].x && tree[u].l != 0) || (vx > tree[u].x && tree[u].r)){
		if(vx <= tree[u].x) u = tree[u].l;
		else u = tree[u].r;
		upd(u)
		upd(tree[u].l);
		upd(tree[u].r);
	}
	return u;
}

void upd(int v){
	if(v == 0) return;
	tree[v].t = tree[tree[v].l].t + tree[tree[v].r].t + 1;

	tree[v].mn = min(tree[v].mn, tree[tree[v].l].mn);
	tree[v].mx = max(tree[v].mx, tree[tree[v].r].mx);

	tree[v].rmn = min(tree[v].rmn, tree[tree[v].r].mn - tree[tree[v].l].mx);
	tree[v].rmn = min(tree[v].rmn, tree[tree[v].l].rmn);
	tree[v].rmn = min(tree[v].rmn, tree[tree[v].r].rmn);
}

void updup(int v){
	while(v != 0){
		upd(v);
		v = tree[v].p;
	}
}	

void rotateRight(int u, int v, int idx){
	arv pai = tree[u], fil = tree[v];
	tree[u].p = v;
	tree[fil.r].p = u;
	tree[v].p = pai.p;

	tree[v].r = u;
	tree[u].l = fil.r;

	if(pai.p == 0)
		raiz[idx] = v;
	else if(u == tree[pai.p].l)
		tree[pai.p].l = v;
	else if(u == tree[pai.p].r)
		tree[pai.p].r = v;
}

void rotateLeft(int u, int v, int idx){
	arv pai = tree[u], fil = tree[v];
	tree[u].p = v;
	tree[fil.l].p = u;
	tree[v].p = pai.p;

	tree[v].r = u;
	tree[u].r = fil.l;

	if(pai.p == 0)
		raiz[idx] = v;
	else if(u == tree[pai.p].l)
		tree[pai.p].l = v;
	else if(u == tree[pai.p].r)
		tree[pai.p].r = v;
}

void balance(int v){
	while(tree[v].p != 0 && tree[v].y < tree[tree[v].p].y){
		int u = tree[v].p;
		if(v == tree[u].l)
			rotateRight(u, v);
		else
			rotateLeft(u, v);
	}
}

void insert(int v, int ind){
	if(raiz[ind] == 0){
		raiz[ind] = v;
		return;
	}
	int u = find(tree[v].x, ind);
	if(tree[v].x <= tree[u].x)
		tree[u].l = v;
	else
		tree[u].r = v;
	tree[v].p = u;
	updup(v);
	balance(v);
}

void split(int i, int idx){
	int cnt = 0;
	if(idx != 0) cnt += tree[raiz[idx-1]].t;
	int v = raiz[idx];
	while(tree[tree[v].l].t + 1 != cnt){
		
	}
}

void qry(int i, int j, char t){
	split(i, 0);
	split(j, 1);

	if(tree[raiz[1]].t != 1){
		if(t == 'N')
			printf("%d\n", abs(tree[raiz[1]].rmn));
		else
			printf("%d\n", abs(tree[raiz[1]].mx - tree[raiz[1]].mn));
	}
	else
		puts("-1");

	merge(1, 2);
	merge(0, 1);
}

int main (){
	srand(time(0));
	tree[0].mn = tree[0].rmn = INF;
	tree[0].mx = -INF;
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		char tip;
		int k, i, j;
		scanf("%c", tip);
		if(tip == 'I'){
			scanf("%d", &k);
			tree[a] = arv(k);
			insert(a);
		}
		else if(tip == 'D'){
			scanf("%d", &k);
			remove(k);
		}
		else{
			scanf("%d%d", &i, &j);
			qry(i, j, tip);
		}
	}
}