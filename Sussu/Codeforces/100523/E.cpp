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

const int MAXN = 512345;

int n, m, d, l;

vector <int> dis, rad;

struct arv{
	int mn, cnt;
	int lz;

} tree[4*MAXN];

void build(int idx, int i, int j){
	if(i == j){
		tree[idx].mn = 0;
		tree[idx].cnt = 1;
		tree[idx].lz = 0;
		return ;
	}
	int m = (i+j)/2;
	build(idx*2, i, m);
	build(idx*2+1, m+1, j);
	if(tree[idx*2].mn < tree[idx*2+1].mn){
		tree[idx].mn = tree[idx*2].mn;
		tree[idx].cnt = tree[idx*2].cnt;
	}
	else if(tree[idx*2].mn > tree[idx*2+1].mn){
		tree[idx].mn = tree[idx*2+1].mn;
		tree[idx].cnt = tree[idx*2+1].cnt;
	}
	else{
		tree[idx].mn = tree[idx*2].mn;
		tree[idx].cnt = tree[idx*2].cnt + tree[idx*2+1].cnt;
	}

}

void upd(int idx, int i, int j, int l, int r, int val){
	if(l > r) return;
	if(i > r || j < l) return ;
	if(tree[idx].lz != 0){
		int aux = tree[idx].lz;
		tree[idx].lz = 0;
		if(i != j){
			tree[idx*2].lz += aux;
			tree[idx*2].mn += aux;
			tree[idx*2+1].lz += aux;
			tree[idx*2+1].mn += aux;
		}
	}
	if(i >= l && j <= r){
		tree[idx].mn += val;
		tree[idx].lz += val;
		return;
	}

	int m = (i+j)/2;

	upd(idx*2, i, m, l, r, val);
	upd(idx*2+1, m+1, j, l, r, val);

	if(tree[idx*2].mn < tree[idx*2+1].mn){
		tree[idx].mn = tree[idx*2].mn;
		tree[idx].cnt = tree[idx*2].cnt;
	}
	else if(tree[idx*2].mn > tree[idx*2+1].mn){
		tree[idx].mn = tree[idx*2+1].mn;
		tree[idx].cnt = tree[idx*2+1].cnt;
	}
	else{
		tree[idx].mn = tree[idx*2].mn;
		tree[idx].cnt = tree[idx*2].cnt + tree[idx*2+1].cnt;
	}
}

int main (){
	scanf("%d%d%d%d", &n, &m, &d, &l);
	dis.pb(0);
	for(int a=1;a<n;a++){
		int di;
		scanf("%d", &di);
		dis.pb(di);
	}
	build(1, 0, n-1);
	for(int a=0;a<m;a++){
		int di;
		scanf("%d", &di);
		rad.pb(di);
		int i = lower_bound(dis.begin(), dis.end(), di-l) - dis.begin();
		int j = (--upper_bound(dis.begin(), dis.end(), di+l)) - dis.begin();
		upd(1, 0, n-1, i, j, 1);
	}
	
	printf("%d\n", n-((tree[1].mn==0) ? tree[1].cnt : 0));
	//printf("%d %d\n", tree[1].mn, tree[1].cnt);
	for(int a=0;a<d;a++){
		int bef, aft;
		scanf("%d %d", &bef, &aft);
		int i = lower_bound(dis.begin(), dis.end(), bef-l) - dis.begin();
		int j = (--upper_bound(dis.begin(), dis.end(), bef+l)) - dis.begin();

	//	printf("atualiza bef %d  %d %d\n", bef, i, j);
		upd(1, 0, n-1, i, j, -1);

		i = lower_bound(dis.begin(), dis.end(), aft-l) - dis.begin();
		j = (--upper_bound(dis.begin(), dis.end(), aft+l)) - dis.begin();
		upd(1, 0, n-1, i, j, 1);
	//	printf("atualiza aft %d  %d %d\n", aft, i, j);
		
		printf("%d\n", n - (!tree[1].mn ? tree[1].cnt : 0));
	//	printf("%d %d\n", tree[1].mn, tree[1].cnt);
	}
}
