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

int n, s, mx[2000];

int main() {
	int f, t, i;
	scanf("%d %d", &n, &s);
	for(i = 0; i < n; i++)
		scanf("%d %d", &f, &t), mx[f] = max(mx[f], t);
	int ans = 0;
	for(i = s; i > 0; i--)
		if(ans < mx[i]) ans = mx[i] + 1;
		else ans++;
	printf("%d\n", ans);
	return 0;
}
