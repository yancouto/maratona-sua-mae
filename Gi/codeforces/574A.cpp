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

int main() {
	int n; scanf("%d", &n);
	int v[105];
	for(int i = 0; i < n; i++) scanf("%d", &v[i]); 
	int ans = 0;
	while(42) {
		int m = 0;
		for(int i = 1; i < n; i++) if(v[i] >= v[m]) m = i;
		if(!m) break;
		ans++;
		v[m]--;
		v[0]++;
	}
	printf("%d\n", ans);
	return 0;
}
