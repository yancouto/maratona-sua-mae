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

const int MAXN = 31234, MAXT = 5500000, MAXQ = 212345;

int n, nq;

int L[MAXT], R[MAXT], degt, degr;

int tree[MAXT], raiz[MAXT];

int build(int i, int j){
	int idx = degt++;
	tree[idx] = 0;
	if(i != j){
		int m = (i + j)/2;
		L[idx] = build(i, m);
		R[idx] = build(m+1, j);
	}
	return idx;
}

int upd(int idx, int i, int j, int x){
	int ind = degt++;
	if(i == j && i == x){
		tree[ind]++;
		return ind;
	}
	L[ind] = L[idx];
	R[ind] = R[idx];
	int m = (i+j)/2;
	if(x <= m)
		L[ind] = upd(L[idx], i, m, x);
	else
		R[ind] = upd(R[idx], m+1, j, x);

	tree[ind] = tree[L[ind]] + tree[R[ind]];
//	printf("%d a %d - tree[%d]: %d\n", i, j, ind, tree[ind]);
	return ind;
}

struct seq{
	int i, v;
	seq(int ii, int vv){
		i = ii;
		v = vv;
	}
	seq(){}
	bool const operator < (seq other) const {
		return v < other.v;
	}
} s[MAXN];

int bb(int i, int j, int v){
	while(i < j){
		int m = (i+j+1)/2;
		if(s[m].v > v)
			j = m-1;
		else
			i = m;
	}
	return i;
}

int qry(int idx, int i, int j, int l, int r){
	if(i > r || j < l)
		return 0;
	if(i >= l && j <= r)
		return tree[idx];
	int m = (i+j)/2;
	return qry(L[idx], i, m, l, r) + qry(R[idx], m+1, j, l, r);
}

int main (){
	scanf("%d", &n);
	s[0] = seq(0, INT_MIN);
	for(int a=1;a<=n;a++){
		int v;
		scanf("%d", &v);
		s[a] = seq(a, v);
	}
	sort(s, s+n+1);
	degt=2;
	raiz[0] = build(1, n);
	for(int a=1;a<=n;a++){
		raiz[a] = upd(raiz[a-1], 1, n, s[a].i);
	}

	scanf("%d", &nq);
	int ans = 0;
	for(int a=0;a<nq;a++){
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
		i ^= ans;
		j ^= ans;
		k ^= ans;
		i = max(1, i);
		j = min(j, n);
//		printf("QRY %d %d %d\n", i, j, k);
		if(i > j || k >= s[n].v){
			puts("0");
			ans = 0;
			continue;
		}
		int ir = bb(0, n, k);
//		printf("chamei a raiz %d de indice %d\n", raiz[ir], ir);
		ans = j - i + 1 - qry(raiz[ir], 1, n, i, j);
		printf("%d\n", ans);
	}
}
