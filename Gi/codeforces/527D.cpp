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

bool myfunction(pii a, pii b) {
	if(a.fst + a.snd == b.fst + b.snd) 
		return a.fst < b.fst;
	return a.fst + a.snd < b.fst + b.snd;
}

int main() {
	int n; scanf("%d", &n);
	vector<pii> v;
	for(int i = 0; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v.pb(make_pair(a, b));
	}
	sort(v.begin(), v.end(), myfunction);
	int ans, lst;
	ans = lst = 0;
	for(int i = 0; i < n; i++) {
		if(v[i].fst - v[i].snd >= v[lst].fst + v[lst].snd) {
			lst = i;
			ans++;
		}
	}
	printf("%d\n", ans + 1);
	return 0;
}
