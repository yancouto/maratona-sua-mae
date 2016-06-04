
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%lld", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 5123;

#define int ll
const ll INF = 3e17;

int n, b, S, m;

ll d[MAXN], d2[MAXN];
ll dp[MAXN][MAXN], sum[MAXN];
int ind[MAXN];
int seen[MAXN];

ll mrk[MAXN];

struct ares{
	ll j;
	ll k;
	ares(){}
	ares(ll jj,ll kk){
		j = jj; k = kk;
	}

	bool operator < (ares other) const {
		return (k < other.k || (k == other.k && j < other.j));
	}
};

vector <ares> adj[MAXN], inv[MAXN];

set <ares> s;

bool cmp(ll a, ll b){
	return d[a] < d[b];
}


inline ll cus(ll i, ll j){
	return (sum[j] - sum[i-1])*(j-i);
}

void go(int i, int j, int opti, int optj, int k){
	if(i > j) return ;
	ll m = (i+j)/2ll;
	int opt = opti;
	for(ll a=(ll)opti;a<=min(m, (ll)optj);a++){
	//	printf("tenta dp[%lld][%lld] %lld + %lld\n", a-1, k-1, dp[a-1][k-1], (sum[m] - sum[a-1])*(m-a));
		if(dp[m][k] >= dp[a][k-1] + cus(a+1, m)){
			dp[m][k] = dp[a][k-1] + cus(a+1, m);
			opt = a;
		}
	}
//	printf("go %lld %lld m %lld dp[%lld][%lld] %lld\n", i, j, m, m, k, dp[m][k]);
	go(i, m-1, opti, opt, k);
	go(m+1, j, opt, optj, k);
}

main (){
	for(int a=0;a<MAXN-1;a++){
		d[a] = INF;
		d2[a] = INF;
		for(int c=0;c<MAXN-1;c++){
			dp[a][c] = INF;
		}
	}
	scanf("%lld%lld%lld%lld", &n, &b, &S, &m);
	for(int a=0;a<m;a++){
		ll i, j;
		ll kk;
		scanf("%lld%lld%lld", &i, &j, &kk);
		i--;j--;
		adj[i].pb(ares(j, kk));
		inv[j].pb(ares(i, kk));
	}
	d[b] = 0ll;
	d2[b] = 0ll;
	s.insert(ares(b, 0));

	while(!s.empty()){
		ares ar = (*s.begin());
		s.erase(ar);
		ll u = ar.j;	
		for(ares nxt: adj[u]){
			int v = nxt.j, cus = nxt.k;
			if(d[v] > d[u] + cus){
				if(d[v] != INF){ 
					s.erase(ares(v, d[v]));
				}
				d[v] = d[u] + cus;
				s.insert(ares(v, d[v]));
			}
		}
	}
	s.insert(ares(b, 0));
	while(!s.empty()){
		ares v = *s.begin();
		s.erase(v);
		for(ares nxt: inv[v.j]){
			if(d2[nxt.j] > d2[v.j] + nxt.k){
				if(d2[nxt.j] != INF) s.erase(ares(nxt.j, d2[nxt.j]));
				d2[nxt.j] = d2[v.j] + nxt.k;
				s.insert(ares(nxt.j, d2[nxt.j]));
			}
		}
	}
	
	for(int a=0;a<b;a++){
		ind[a] = a;
//		if(a == 4702) printf("cara %lld tem %lld e %lld\n", a, d[a], d2[a]); 
		d[a] += d2[a];
	}
	sort(ind, ind+b, cmp);

	for(int a=0;a<b;a++){
//		printf("na %lld-esima posicao %lld\n", a, ind[a]);
		sum[a] = 0;
		if(a != 0) sum[a] = sum[a-1];
		sum[a] += d[ind[a]];
	}
	for(ll a=0;a<b;a++){
		dp[a][1] = a*sum[a];
//		printf("dp[%lld][%lld] %lld\n", a, 1, dp[a][1]);
	}
	for(int kk = 2;kk <= S;kk++){
		go(0, b-1, 0, b-1, kk);
	}
	printf("%lld\n", dp[b-1][S]);
}
