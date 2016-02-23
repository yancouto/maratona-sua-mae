
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

const int MAXN = 2000010;

int raiz[5];

struct arv{
	int x, y;
	int l, r, p;
	int mn, mx;
	int rmn;
	arv(){};
	arv(int xx){
		x = xx;
		y = rand();
		p = 0;
		l = 0;
		r = 0;
	};
} tree[MAXN];

int find(int vx,int ind){
	int u = raiz[ind];
	while((vx <= tree[u].x && tree[u].l != 0) || (vx > tree[u].x && tree[u].r)){
		if(vx <= tree[u].x) u = tree[u].l;
		else u = tree[u].r;
	}
	return u;
}

void insert(int v, int ind){
	if(raiz[ind] == 0){
		raiz[ind] = v;
		return;
	}
	int u = find(tree[v].x, ind);
}

int main (){
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