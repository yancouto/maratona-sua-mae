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

const int MAXN = 100010;

const double PI = acos(-1);

int n, v[MAXN], tree[MAXN*4];

struct cil{
	ll r, h, v, i;
	cil(){}
	cil(int rr, int hh, int ii){
		r = rr;
		h = hh;
		v = rr*rr*hh;
		i = ii;
	}
}  s[MAXN];

bool cmp(cil a, cil b){
	return a.v < b.v;
}

void upd(int idx,int i, int j, int l, ll val){
	if(
}	

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		int r, h;
		scanf("%d%d", &r, &h);
		s[a] = cil(r, h, a);
	}
	sort(s, s+n, cmp);
	for(int a=0;a<n;a++){
		res = max(s[a].v, qry(1, 1, n, 1, s[a].i) + s[a].v); 
		upd(1, 1, n, s[a].i, res);
	}
}
