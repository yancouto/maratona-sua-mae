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

int main() {
	int a, b, c, x, y, z;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &x, &y, &z);
	int l = max(0, a-x)/2 + max(0, b-y)/2 + max(0, c-z)/2 + min(0, a-x) + min(0, b-y) + min(0, c-z);
	if(l >= 0) puts("YES");
	else puts("NO");
	return 0;
}
