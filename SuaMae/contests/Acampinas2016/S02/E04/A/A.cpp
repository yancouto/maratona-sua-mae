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
const int N = 300007;

pii v[N];
multiset<ll> st;

int main() {
	ll n, m;
	int i;
	scanf("%lld %lld", &n, &m);
	for(i = 0; i < n; i++) 
		scanf("%lld %lld", &v[i].fst, &v[i].snd);
	sort(v, v + n);
	ll ans = 0;
	for(i = 0; i < n; i++) {
		while(!st.empty() && v[i].fst - *(st.begin()) > m) 
			st.erase(st.begin());
		if(!st.empty()) 
			if(*st.begin() <= v[i].fst)
				st.erase(st.begin()), ans++;
		st.insert(v[i].fst+v[i].snd);
	}
	printf("%lld\n", ans);
	return 0;
}
