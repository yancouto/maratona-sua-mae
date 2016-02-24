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

int n, deg;

struct bolo{
	ll r, h, res, v, i;
	bolo(){}
	bolo(int rr, int hh, int ii){
		r = rr;
		i = ii;
		h = hh;
		v = rr*rr*hh;
		res = rr*rr*hh;
	}
} s[MAXN], fil[MAXN];

bool cmp(bolo a, bolo b){
	return ((a.v != b.v && a.v > b.v) || ( a.v == b.v && a.i<b.i)); 
}

ll dp[MAXN];

ll go(int i){
	if(i == n) return 0;
	if(dp[i] != -1) return dp[i];
}

int main (){
	scanf("%d", &n);
	deg = 0;
	for(int a=0;a<n;a++){
		scanf("%lld%lld", &s[a].r, &s[a].h);
		s[a] = bolo(s[a].r, s[a].h, a);
	}
	sort(s[a], s[a]+n, cmp);
	go(0);
}