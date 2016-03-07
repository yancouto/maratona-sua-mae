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

int l[MAXN], vl[MAXN], c[MAXN], vc[MAXN], sz[MAXN], pai[MAXN], maxv[MAXN], n, m;

map <pii, int> mrkl, mrkc;

struct mt{
	int i, j, v, ind;
	mt(){}
	mt(int ii, int jj, int vv){
		i = ii; j = jj; v = vv;
		ind = ii*n + jj;
	}
	bool operator < (mt other) const{
		return v < other.v;
	}
};

vector<mt> v, res;

int raiz(int a){
	if(a == pai[a]) return a;
	return pai[a] = raiz(pai[a]);
}

void join(int a,int b){
	a = raiz(a);
	b = raiz(b);
	if( a == b ) return;
	if(sz[a] < sz[b]) swap(a, b);
	pai[b] = a;
	sz[a] += sz[b];
}

bool cmp(mt a, mt b){
	return ((a.i != b.i && a.i < b.i) || (a.i == b.i && a.j < b.j));
}

int main (){
	scanf("%d %d", &n, &m);
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			pai[a*n+b] = a*n+b; sz[a*n+b] = 1;
			mt cel;
			scanf("%d", &cel.v);
			cel = mt(a, b, cel.v);
			v.pb(cel);
			if(mrkl.find(pii(cel.v, cel.i)) != mrkl.end()){
				join(mrkl[pii(cel.v, cel.i)], cel.ind);
			}
			mrkl[pii(cel.v, cel.i)] = cel.ind;

			if(mrkc.find(pii(cel.v, cel.j)) != mrkc.end()){
				join(mrkc[pii(cel.v, cel.j)], cel.ind);
			}
			mrkc[pii(cel.v, cel.j)] = cel.ind;
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int a=0;a < v.size();a++){
		int cor = v[a].v;
		for(int b=a;b<v.size() && v[b].v == cor;b++){
			int r = raiz(v[b].ind);
			maxv[r] = max(maxv[r], l[v[b].i]+1);
			maxv[r] = max(maxv[r], c[v[b].j]+1);
		}
		l[v[a].i] = maxv[raiz(v[a].ind)];
		c[v[a].j] = maxv[raiz(v[a].ind)];
		res.pb(mt(v[a].i, v[a].j, l[v[a].i]));
	}
	sort(res.begin(), res.end(), cmp);
	int cnt = 0;
	for(int a=0;a<res.size();a++){
		if(a%(n-1)==0) printf("\n");
		printf("%d ", res[a].v);
	}
}