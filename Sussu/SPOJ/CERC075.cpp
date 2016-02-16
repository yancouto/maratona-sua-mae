#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 100010;

int n, s[MAXN], ind[MAXN], raiz, degt;

// nfe  = tot do filho da esq + 1
/* upe = {
	se é filho da direita:
		upe do pai + nfe do pai;
	else
		upe do pai
   }
*/

struct arv{
	int x, y, pai, nfe, upe, tot;
	int l, r;
	int lz;
	arv(){};
	arv(int xx, int yy){
		x = xx; y = yy;
		nfe = 1;
		pai = l = r = 0;
		lz = 0;
		tot = 1;
		upe = 0;
	};
} tree[MAXN];

bool cmp(int a,int b){
	return s[a] < s[b];	
}

void upd(arv u){
	tree[u.x].nfe = tree[u.l].tot + 1;

	tree[u.l].upe = tree[u.x].upe;
	tree[u.r].upe = tree[u.x].nfe + tree[u.x].upe;

	tree[u.x].tot = 1 + tree[tree[u.x].l].tot + tree[tree[u.x].r].tot;
	tree[v.x].tot = 1 + tree[tree[v.x].l].tot + tree[tree[v.x].r].tot;

	if(u.lz != 0){
		tree[u.x].lz = 0;
		tree[u.l].lz = 1 - tree[u.l].lz;
		tree[u.r].lz = 1 - tree[u.r].lz;

		tree[u.x].nfe = 1 + tree[u.r].tot;
		tree[u.x].l = u.r;
		tree[u.x].r = u.l;
		
		tree[u.r].upe = tree[u.x].upe;
		tree[u.l].upe = tree[u.x].nfe + tree[u.x].upe;
		//nfe do u.r e u.l n muda
	}
}

arv find(arv v){
	arv u = tree[raiz];
	upd(u);
	u = tree[raiz];
	while(!(v.x < u.x && u.l == 0) && !(v.x > u.x && u.r == 0)){
		if(v.x < u.x) u = tree[u.l];
		else u = tree[u.r];
		upd(u);
	}
	return u;
}

void rotateRight(arv u, arv v){
	tree[u.x].pai = v.x;
	tree[v.x].pai = u.pai;

	tree[u.x].r = v.l;
	tree[v.x].l = u.x;

	upd(tree[u.x]);
	upd(tree[v.x]);
}

void rotateLeft(arv u, arv v){
	tree[u.x].pai = v.x;
	tree[v.x].pai = u.pai;

	tree[v.x].r = u.x;
	tree[u.x].l = v.r;

	upd(tree[u.x]);
	upd(tree[v.x]);
}

int balance(arv v){
	if(v.pai == 0) return;
	arv u = tree[v.pai];
	while(v.pai != 0 && u.y > v.y ){
		if( v == u.l ) rotateRight(u, v);
		else rotateLeft(u, v);
		v = tree[v.x];
		if(tree[v.x].pai != 0) u = tree[tree[v.x].pai];
	}
	return v.x;
}

void addupd(int x){
	arv v = tree[x];
	while( v.x != 0 ){
		upd(v);
		v = tree[v.x].pai;
	}
}

void insert(int x){
	arv v = tree[x] = arv(x, rand());
	if(raiz == 0){
		raiz = x;
		return ;
	}
	arv u = find(tree[x]);
	if(x > u.x){
		tree[u.x].r = x;
		tree[x].pai = u.x;
	}
	else{
		tree[u.x].l = x;
		tree[x].pai = u.x;
	}
	addupd( balance(tree[x]) );
}

void inv(int x, int i, int j, int l, int r){
	arv v = tree[x];
	if(i > r || j < l || x == 0) return ;
	upd(v);
	if( i >= l && j <= r ){
		tree[x].lz = 1 - tree[x].lz;
		return;
	}
	inv(v.l, i, i + tree[v.l].tot, )

}

int main (){
	while(scanf("%d", &n)!=EOF && n!=0){
		raiz = 0;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			ind[a] = a+1;
		}
		stable_sort(ind, ind+n, cmp);
		for(int a=0;a<n;a++){
			insert(a+1);
		}
	}
}