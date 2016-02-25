#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int MAX = 26;

int N, np, np2;
ll v[MAX], cura[MAX], curb[MAX];
vector<ll> prec[1100000][2];

inline int half(int n) { return n/2 + (n%2); }

void show() {
	int i, j;
	for(i = 0; i < np; i++) {
		if(i == np2) puts("Segunda parte--------------");
		for(j = 0; j < prec[i][0].size(); j++)
			printf("%lld ", prec[i][0][j]);
		printf("-----");
		for(j = 0; j < prec[i][1].size(); j++)
			printf("%lld ", prec[i][1][j]);
		putchar('\n');
	}
}

void add_c(int a, int b, int took) {
	for(int i = 0; i < a; i++)
		prec[np][0].pb(cura[i]);
	for(int i = 0; i < b; i++)
		prec[np][1].pb(curb[i]);
	np++;
}

void solve(int i, int a, int b, int took, int lim) {
	if(i == lim) { add_c(a, b, took); return; }
	cura[a] = v[i];
	solve(i + 1, a + 1, b, took + 1, lim);
	curb[b] = v[i];
	solve(i + 1, a, b + 1, took + 1, lim);
	solve(i + 1, a, b, took, lim);
}

pii give(int i) {
	int j; ll suma, sumb;
	suma = sumb = 0;
	for(j = 0; j < prec[i][0].size(); j++) 
		suma += prec[i][0][j];
	for(j = 0; j < prec[i][1].size(); j++)
		sumb += prec[i][1][j];
	return pii(suma, sumb);
}


int main() {
	int i, j;
	while(42) {
		scanf("%d", &N);
		if(!N) break;
		ll tot = 0;
		for(i = 0; i < N; i++) 
			scanf("%lld", &v[i]),	tot += v[i];
		solve(0, 0, 0, 0, half(N)); 
		np2 = np;
		solve(half(N), 0, 0, 0, N); 
		map<ll, pii> mp;
		printf("NP %d\n", np);
		for(i = 0; i < np2; i++) {
			pii cur = give(i);
			ll a = cur.fst, b = cur.snd;
			if(mp.count(a-b)) mp[a-b] = max(mp[a-b], pii(a, b));
			else mp[a-b] = pii(a, b);
		}
		ll ans = mp[0].fst;
		for(i = np2; i < np; i++) {
			pii cur = give(i);
			ll a = cur.fst, b = cur.snd;
			if(mp.count(a-b)) { 
				ans = max(ans, a + mp[a-b].snd);
				if(2*ans == tot)
					printf("aCHEI (%lld) (%lld, %lld) (%lld, %lld)\n", a-b, a, b, mp[a-b].fst, mp[a-b].snd);
			}
		}
		printf("%lld\n", tot - ans*2);
	}
	return 0;
}
