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
const ll oo = 1000000000000;
const int N = 5005;

int n, m;
int op[N], l[N], r[N];
ll v[N], acc[N], mmin[N], aux[N];

ll mini(ll a, ll b) { if(a < b) return a; return b; }
ll maxi(ll a, ll b) { if(a > b) return a; return b; }

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i <= n; i++) mmin[i] = oo;
	for(i = 0; i < m; i++) {
		scanf("%d %d %d %lld", &op[i], &l[i], &r[i], &v[i]);
		if(op[i] == 1) 
			for(j = l[i]; j <= r[i]; j++) acc[j] += v[i];
		else 
			for(j = l[i]; j <= r[i]; j++)
				mmin[j] = mini(mmin[j], v[i] - acc[j]);
	}
	for(i = 0; i <= n; i++) aux[i] = mmin[i];
	bool bad = false;
	for(i = 0; i < m && !bad; i++) {
		if(op[i] == 1) {
			for(j = l[i]; j <= r[i]; j++)
				aux[j] += v[i];
		}
		else {
			ll m = -oo;
			for(j = l[i]; j <= r[i]; j++)
				m = maxi(m, aux[j]);
			if(m != v[i]) bad = true;
		}
	}
	if(bad) puts("NO");
	else {  
		puts("YES");
		for(i = 1; i <= n; i++)
			printf("%d ", mmin[i]);
		putchar('\n');
	}
	return 0;
}
