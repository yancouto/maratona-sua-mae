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

int v[100009];
int main() {
	int i, n, S, x;
	multiset<int> s;
	scanf("%d %d", &n, &S);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		s.insert(x);
	}
	int last = 0;
	int tot = 0;
	for(i = 0; i < n; i++) {
		if(!last) { v[i] = *s.begin(); s.erase(s.begin()); last = v[i]; continue; }
		auto it = s.lower_bound(S - last + 1);
		if(it != s.end()) { v[i] = *it; s.erase(it); tot++; last = v[i]; }
		else { v[i] = *s.begin(); s.erase(s.begin()); tot++; last = 0; }
	}
	if(last) tot++;
	printf("%d\n", tot);
	for(i = 0; i < n; i++) printf("%d ", v[i]);
	putchar('\n');
}
