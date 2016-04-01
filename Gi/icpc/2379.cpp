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

int a[100009];

int main() {
	int n, i;
	while(scanf("%d", &n) != EOF) {
		ll x = 0;
		for(i = 0; i < n; i++)
			scanf("%d", &a[i]), x += a[i];
		if(x%2) { puts("No"); continue; }
		puts("Yes"); x /= 2;
		for(i = n-1; i >= 0; i--)
			if(a[i] > x) a[i] = -1;
			else x -= a[i], a[i] = 1;
		for(i = 0; i < n; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
	return 0;
}
