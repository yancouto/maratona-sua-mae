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

ll memo[100009][3];
const int N = 100009;
int a[N], b[3*N], bn;
int val[3*N][3];
int get(int x) {
	return lower_bound(b, b + bn, x) - b;
}

int main() {
	int i, n, d;
	for_tests(t, tt) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b[3*i] = a[i];
			b[3*i+1] = a[i]+1;
			b[3*i+2] = a[i]-1;
		}
		sort(b, b + 3*n);
		bn = unique(b, b + 3*n) - b;
		for(i = 0; i < bn; i++)
			for(d = 0; d < 3; d++)
				val[i][d] = 0;
		for(i = n - 1; i >= 0; i--) {
			for(d = -1; d <= 1; d++) {
				ll &r = memo[i][d+1];
				r = (d == 0);
				if(d == 0)
					r += val[get(a[i]+1)][2] + val[get(a[i]-1)][0];
				else
					r += val[get(a[i]-d)][1];
				r %= modn;
			}
			for(d = -1; d <= 1; d++)
				val[get(a[i])][d+1] = mod(val[get(a[i])][d+1] + memo[i][d+1]);
			
		}
		ll tot = 0;
		for(i = 0; i < n; i++)
			tot += memo[i][1];
		printf("%d\n", (int) mod(tot));
	}
}
