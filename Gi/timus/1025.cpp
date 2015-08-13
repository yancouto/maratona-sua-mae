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

int main(){
	int k; scanf("%d", &k);
	int ks[110];
	for(int i = 0; i < k; i++)
		scanf("%d", &ks[i]);
	sort(ks, ks+k);
	int ans = 0;
	for(int i = 0; i < k/2+1; i++)
		ans += ks[i]/2 + 1; 
	printf("%d\n", ans);
	return 0;
}
