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
const int N = 100005;

int sm[N], f[N];
vector<pii> st;

ll xcont(int j, int k) {

}



int main() {
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		if(i) sm[i] = sm[i-1];
		sm[i] += x;
	}
	for(j = 1; j <= m; j++) scanf("%d", &f[j]);
	st.pb(pii(oo, 0));
	for(j = 1; j <= m-1; j++) {
		while(!st.empty() && xcont(st.back().snd, j) <= st.back().fst)
			st.pop_back();
		st.pb(pii(xcont(st.back().snd, j), j));
	}

	

		

	

	return 0;
}
