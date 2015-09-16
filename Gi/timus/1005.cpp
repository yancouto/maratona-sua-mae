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

int n;
int p[30];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) 
		scanf("%d", &p[i]);
	int ans = 10000000;
	for(int i = 0; i < (1 << n); i++) {
		pii cur = pii(0, 0);
		for(int j = 0; j < n; j++) {
			int k = 1 << j;
			if(i & k) cur.fst += p[j];
			else cur.snd += p[j];
		}
		ans = min(ans, abs(cur.fst - cur.snd));
	}
	printf("%d\n", ans);
	return 0;
}
