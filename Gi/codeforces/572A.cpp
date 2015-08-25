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
	int na, nb, k, m;
	int a[100005], b[100005];
	scanf("%d %d %d %d", &na, &nb, &k, &m);
	for(int i = 0; i < na; i++) scanf("%d", &a[i]);
	for(int i = 0; i < nb; i++) scanf("%d", &b[i]);
	if(na < k || nb < m) { puts("NO"); return 0; }
	int i;
	for(i = 0; b[i] <= a[k-1] && i < nb; i++); 
	if(i == nb) { puts("NO"); return 0; }
	if(nb - i >= m) puts("YES");
	else puts("NO");
	return 0;
}
