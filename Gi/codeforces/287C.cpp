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
	int n, i, p[100005];
	scanf("%d", &n);
	if(n == 1) { puts("1"); return 0; }
	if(n % 4 == 2 || n % 4 == 3) { puts("-1"); return 0; }
	for(i = 1; i <= n/2; i++)
		if(i%2) p[i] = i + 1, p[n-i+1] = n - i;
		else p[i] = n - i + 2, p[n-i+1] = i - 1;
	if(n % 4) p[n/2 + 1] = n/2 + 1;
	for(i = 1; i <= n; i++) printf("%d ", p[i]);
	putchar('\n');
	return 0;
}
