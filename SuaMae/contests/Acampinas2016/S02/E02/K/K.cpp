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

int f[7];

int main() {
	int n, i, x;
	double med = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		f[x]++; med += x;
	}
	med /= n;
	if(f[3] > 0) puts("None");
	else if(f[5] == n) puts("Named");
	else if(med >= 4.5) puts("High");
	else puts("Common");
	return 0;
}
