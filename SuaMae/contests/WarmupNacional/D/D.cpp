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
	int i, n, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n - k + 1; i++)
		printf("0 ");
	for(i = n - k + 1; i < n; i++) {
		if(!((i - (n - k + 1)) & 1)) putchar('-');
		printf("%d ", (i - (n - k + 1) + 2) / 2);
	}
	putchar('\n');
}
