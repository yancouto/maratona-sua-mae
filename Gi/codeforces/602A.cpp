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
	int nx, bx, ny, by, i;
	int x[15], y[15];
	scanf("%d %d", &nx, &bx);
	for(i = 0; i < nx; i++) scanf("%d", &x[i]);
	scanf("%d %d", &ny, &by);
	for(i = 0; i < ny; i++) scanf("%d", &y[i]);
	ll pot = 1;
	ll xa = 0, ya = 0;
	for(i = nx-1; i >= 0; i--) {
		xa += pot * x[i];
		pot *= bx;
	}
	pot = 1;
	for(i = ny-1; i >= 0; i--) {
		ya += pot * y[i];
		pot *= by;
	}
	if(xa > ya) puts(">");
	else if(xa < ya) puts("<");
	else puts("=");
	return 0;
}
