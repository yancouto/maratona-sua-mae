
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

const int MAXN = 1000010;

struct arv{
	int x, y, p;
	int l, r;
	arv(){};
	arv(int xx, int yy){
		x = xx;
		y = yy;
		l = 0;
		r = 0;
	};
} tree[MAXN];

int n, raiz;
	
int find(int v){
	int u = raiz;
	while((tree[v].x <= tree[u].x && tree[u].l != 0) || (tree[v].x > tree[u].x && tree[u].r != 0)){
		if(tree[v].x <= tree[u].x) u = tree[u].l;
		else u = tree[u].r;
	}
	return u;
}

void rotateRight(int u, int v){
	arv pai = tree[u], fil = tree[v];
	tree[u].l = fil.r;
	tree[u].p = v;
	tree[v].r = u;
	tree[v].p = pai.p;
}

void rotateLeft(int u, int v){
	arv pai = tree[u], fil = tree[v];
	tree[u].p = v;
	tree[v].p = pai.p;
	tree[u].r = fil.l;
	tree[v].l = u;
}

void balance(int u){
	while(tree[u].pai != 0 || tree[u].y < tree[tree[u].pai].y){
		int v = tree[u].pai;
		if( tree[u].l == u )
			rotateRight(v, u);
		else 
			rotateLeft(v, u);
	}
}

void insert(int v){
	if(raiz == 0){
		raiz = v;
		tree[v].p = v;
		return ;
	}
	int u = find(v);
	if( tree[v].x <= tree[u].x )
		tree[u].l = v;	
	else
		tree[u].r = v;
	tree[v].p = u;

	balance(u);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		int v;
		scanf("%d", &v);
		tree[a].x = v;
		tree[a].y = rand();
		tree[a].p = a;
		insert(a);
	}
}
