#include <cstdio>
#include <algorithm>
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

double p, p1;
int N;

double solve(int i, int n) {
	if(n == 0) return 0;
	if(n == N) return 1;
	if(i == 0) return 0;
	int x = min(n, N - n);
	return p * solve(i - 1, n + x) + p1 * solve(i - 1, n - x);
}

int main() {
	freopen("betting.in", "r", stdin);
	freopen("betting.out", "w", stdout);
	int i, n, s, t, p;
	while(scanf("%d %d %d %d", &n, &s, &p, &t) && n) {
		N = n;
		::p = double(p) / 100;
		p1 = ((double)1.) - ::p;
		printf("%.11f\n", solve(t, s));
	}
	
}
