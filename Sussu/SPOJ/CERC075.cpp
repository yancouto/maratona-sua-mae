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

int n, s[MAXN], ind[MAXN], raiz, degt, raiz[5];

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
	arv(int xx){
		x = xx; 
		y = rand();
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

arv find(arv v, int ind){
	arv u = tree[raiz[ind]];
	upd(u);
	u = tree[raiz[ind]];
	while(!(v.x < u.x && u.l == 0) && !(v.x > u.x && u.r == 0)){
		if(v.x < u.x) u = tree[u.l];
		else u = tree[u.r];
		upd(u);
	}
	return u;
}

void rotateRight(arv u, arv v, int ind){
	tree[u.x].pai = v.x;
	tree[v.x].pai = u.pai;

	tree[v.l].pai = u.x;
	if(u.pai == 0)
		raiz[ind] = v.x; 
	else if(tree[u.pai].l == u.x)
		tree[u.pai].l = v.x;
	else if(tree[u.pai].r == u.x)
		tree[u.pai].r = v.x;

	tree[u.x].r = v.l;
	tree[v.l].pai = u.x;
	tree[v.x].l = u.x;

	upd(tree[u.x]);
	upd(tree[v.x]);
	upd(tree[v.l]);
}

void rotateLeft(arv u, arv v, int ind){
	tree[u.x].pai = v.x;
	tree[v.x].pai = u.pai;

	tree[v.l].pai = u.x;
	if(u.pai == 0)
		raiz[ind] = v.x; 
	else if(tree[u.pai].l == u.x)
		tree[u.pai].l = v.x;
	else if(tree[u.pai].r == u.x)
		tree[u.pai].r = v.x;

	tree[v.x].r = u.x;
	tree[v.l].pai = u.x;
	tree[u.x].l = v.r;

	upd(tree[u.x]);
	upd(tree[v.x]);
	upd(tree[v.l]);
}

int balance(arv v, int ind){
	if(v.pai == 0) return;
	arv u = tree[v.pai];
	while(v.pai != 0 && u.y > v.y ){
		if( v == u.l ) rotateRight(u, v, ind);
		else rotateLeft(u, v, ind);
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

void insert(int x, int ind){
	arv v = tree[x] = arv(x);
	if(raiz[ind] == 0){
		raiz[ind] = x;
		return ;
	}
	arv u = find(tree[x], ind);
	if(x > u.x){
		tree[u.x].r = x;
		tree[x].pai = u.x;
	}
	else{
		tree[u.x].l = x;
		tree[x].pai = u.x;
	}
	addupd( balance(tree[x], ind) );
}

void split(int x)

int main (){
	while(scanf("%d", &n)!=EOF && n!=0){
		raiz[0] = raiz[1] = raiz[2] = 0;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a]);
			ind[a] = a+1;
		}
		stable_sort(ind, ind+n, cmp);
		for(int a=0;a<n;a++){
			insert(a+1, 0);
		}
	}
}