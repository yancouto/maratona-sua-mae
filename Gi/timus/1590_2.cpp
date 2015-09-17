//TLE
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#define MAX 5005

char str[MAX];
int n;
ll hsh[MAX], pot[2 * MAX];
set<ll> st;

void make_pot() {
	pot[0] = 1;
	for(int i = 1; i <= n + 2; i++) pot[i] = mod(pot[i-1] * 257);
}

void make_hsh() {
	hsh[0] = str[0];
	for(int i = 1; i < n; i++) 
		hsh[i] = mod(hsh[i-1] + mod(str[i] * pot[i]));
}

ll get_hsh(int l, int r) {
	ll a = ((l) ? hsh[l-1] : 0);
	ll b = hsh[r];
	return mod(mod(b - a + modn) * pot[n - l]);
}

void show(int i, int j, ll hh) { printf("Bateu %d %d %lld\n", i, j, hh); }

int main() {
	scanf("%s", str);
	n = strlen(str);
	make_pot();
	make_hsh();
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			ll hh = get_hsh(i, j);
			if(st.empty()) { st.insert(hh); ans++; continue; }
			set<ll> :: iterator it = st.lower_bound(hh);
			if(it == st.end() || (*it) != hh) { st.insert(hh); ans++; }
		}
	}
	printf("%lld\n", ans);	
	return 0;
}
