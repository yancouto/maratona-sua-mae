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

const int MAXN = 31234;

int n, q;

int s[MAXN];

vector <int> v[MAXN*4];

void build(int idx, int i, int j){
	if(i == j){
		v[idx].pb(s[i]);
		return ;
	}

	int m = (i+j)/2;

	build(idx*2, i, m);
	build(idx*2+1, m+1, j);

	int i1, i2;
	int t1 = v[idx*2].size();
	int t2 = v[idx*2+1].size();
	i1 = i2 = 0;
	while(i1 < t1 && i2 < t2){
		if(v[idx*2][i1] < v[idx*2+1][i2])
			v[idx].pb(v[idx*2][i1]), i1++;
		else
			v[idx].pb(v[idx*2+1][i2]), i2++;
	}
	while(i1 < t1)
		v[idx].pb(v[idx*2][i1]), i1++;
	while(i2 < t2)
		v[idx].pb(v[idx*2+1][i2]), i2++;
}

int qry(int idx, int i, int j, int l, int r, int k){
	if(l > r) return 0;
	if(i > r || j < l) return 0;
	if(i >= l && j <= r){
		return v[idx].end() - upper_bound(v[idx].begin(), v[idx].end(), k);
	}
	int m  = (i+j)/2;
	return qry(idx*2, i, m, l, r, k) +	qry(idx*2+1, m+1, j, l, r, k);
}

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	build(1, 1, n);
	scanf("%d", &q);
	int ans = 0;
	for(int a=0;a<q;a++){
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
		i ^= ans;
		j ^= ans;
		k ^= ans;
		i = max(1, i);
		j = min(j, n);
		ans = qry(1, 1, n, i, j, k);
		printf("%d\n", ans);
	}
}
