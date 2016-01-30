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
const int N = 1700000;
int dv[N+1], mx[N+1], nx[N+1];

int main() {
	int i, j;
	for(i = 2; i <= N; i++)
		if(!dv[i])
			for(j = i; j <= N; j += i)
				dv[j] = i;
	for(i = N; i >= 2; i--) {
		int d = 1, x = i;
		while(x != 1) {
			int p = dv[x], k = 0;
			while(!(x % p)) x /= p, k++;
			d *= (k + 1);
		}
		mx[i] = max(mx[i], 1);
		if(d <= 300 && mx[i - d] < mx[i] + 1)
			mx[i - d] = mx[i] + 1, nx[i - d] = i;
	}
	int st = max_element(mx+1, mx + 301) - mx, n;
	scanf("%d", &n);
	printf("%d", st);
	for(i = 1; i < n; i++) {
		printf(" %d", nx[st] - st);
		st = nx[st];
	}
	putchar('\n');
}
