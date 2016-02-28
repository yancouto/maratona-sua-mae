
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

int frescura = 0;


struct arv{
	int x, y, p;
	int l, r;
	arv(){};
	arv(int xx){
		x = xx;
		y = rand();
		p = 0;
		l = 0;
		r = 0;
	};
} tree[MAXN];

int n, raiz;
	
//stress
int mrk[MAXN];
std::vector<int> res;


int find(int v){
	int u = raiz;
	while((tree[v].x <= tree[u].x && tree[u].l != 0) || (tree[v].x > tree[u].x && tree[u].r != 0)){
		if(tree[v].x <= tree[u].x) u = tree[u].l;
		else u = tree[u].r;
	}
	return u;
}

void rotateRight(int u, int v){
	//printf("rotateRight %d x %d y %d  com  %d x %d y %d\n", u, tree[u].x, tree[u].y, v, tree[v].x, tree[v].y);
	arv pai = tree[u], fil = tree[v];
	tree[fil.r].p = u;
	tree[u].l = fil.r;
	tree[u].p = v;
	tree[v].r = u;
	tree[v].p = pai.p;
	if(tree[v].p == 0)
		raiz = v;
	else if(u == tree[pai.p].l)
		tree[pai.p].l = v;
	else if(u == tree[pai.p].r)
		tree[pai.p].r = v;
}

void rotateLeft(int u, int v){
	//printf("rotateLeft %d x %d y %d  com  %d x %d y %d\n", u, tree[u].x, tree[u].y, v, tree[v].x, tree[v].y);
	arv pai = tree[u], fil = tree[v];
	tree[u].p = v;
	tree[v].p = pai.p;
	tree[fil.l].p = u;
	tree[u].r = fil.l;
	tree[v].l = u;
	if(tree[v].p == 0)
		raiz = v;
	else if(u == tree[pai.p].l)
		tree[pai.p].l = v;
	else if(u == tree[pai.p].r)
		tree[pai.p].r = v;
}

void balance(int u){
	while(tree[u].y < tree[tree[u].p].y){
		int v = tree[u].p;
		if(v == 0) break;
		if( tree[v].l == u )
			rotateRight(v, u);
		else 
			rotateLeft(v, u);
	}
}

void insert(int v){
	if(raiz == 0){
		raiz = v;
		return ;
	}
	int u = find(v);
	if( tree[v].x <= tree[u].x )
		tree[u].l = v;	
	else
		tree[u].r = v;
	tree[v].p = u;
	balance(v);
}

void print(int v){
	if(v == 0) return;
	//printf("chegay no vertice %d   v.x %d v.y %d v.l %d v.r %d v.p %d\n", v, tree[v].x, tree[v].y, tree[v].l, tree[v].r, tree[v].p);
	print(tree[v].l);
	//res.pb(tree[v].x);
	printf("%d\n", tree[v].x);
	print(tree[v].r);
}

/*vector<int> ent;

void stresstest(){
	int fudeu = 0;
	do{
		n = rand()%20;
		for(int a=1;a<=n;a++){
			int v = rand()%1000001;
			ent.pb(v);
			tree[a] = arv(v);
			insert(a);
			mrk[v]++;
		}
		print(raiz);
		int i = 0;
		for(int val: res){
			while(!mrk[i] && i<MAXN)
				i++;
			if(i != val){
				printf("FUDEU %d != %d\n", i, val);
				fudeu = 1;
				break;
			}
			mrk[i]--;
		}
		while(i < MAXN){
			if(mrk[i]){
				printf("FUDEU %d n e zero\n", i);
				fudeu = 1;
				break;
			}
			i++;
		}
		if(!fudeu){
			res.clear();
			memset(mrk, 0, sizeof(mrk));
			raiz = 0;
			ent.clear();
		}
	} while(!fudeu);
	printf("fudeu feio\n");
	for(int val: ent){
		printf("entrada %d\n", val);
	}
	sort(ent.begin(), ent.end());
	for(int v=0; v<res.size();v++){
		printf("saida %d != %d\n", res[v], ent[v]);
	}
}*/

int main (){
	srand(time(0));
	//stresstest();
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		int v;
		scanf("%d", &v);
		tree[a] = arv(v);
		insert(a);
		/*printf("\narv ate agora\n");
		print(raiz);
		printf("terminou\n\n");*/
	}
	print(raiz);
}


// 5 3 4 1 2 5
// 4 2 4 3 1

/*
7
22841
26022
30835
6383
3927
*/
16350
31499
