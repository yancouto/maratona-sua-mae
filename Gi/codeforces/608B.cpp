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
const int N = 200010;

int ub, zb, ua, za;

int main() {
	int i;
	char a[N], b[N];
	int na = strlen(a);
	int nb = strlen(b);
	for(i = 0; i < na; i++) {
		ans += abs(a[i] - b[i]);
	}
	return 0;
}
