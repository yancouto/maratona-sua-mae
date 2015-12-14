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
const int N = 5003;
int a[2][N], b[2][N];
double memo[N][N];
const double eps = 1e-8;
double mx(double a, double b) { return max(a, b); }
double mn(double a, double b) { return min(a, b); }
double (*fun)(double, double);
double st;

double mm[N]; int n;
double solve(int i) {
	if(i == n) return 0;
	double &r = mm[i];
	if(r >= -.5) return r;
	r = st;
	for(int j = i; j < n; j++)
		r = fun(r, solve(j + 1) + memo[i][j]);
	return r;
}

int main() {
	freopen("braess.in", "r", stdin);
	freopen("braess.out", "w", stdout);
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[0][i], &b[0][i], &a[1][i], &b[1][i]);
		//printf("[%d] %d %d %d %d\n", i, a[0][i], b[0][i], a[1][i], b[1][i]);
	}
	//printf("read\n");
	for(i = 0; i < n; i++) {
		int a0 = 0, b0 = 0, a1 = 0, b1 = 0;
		for(j = i; j < n; j++) {
			a0 += a[0][j]; b0 += b[0][j];
			a1 += a[1][j]; b1 += b[1][j];

			double k = -1, cur;
			if(a0 != 0 || a1 != 0) {
				k = double(a1 + b1 - b0) / (a0 + a1);
				cur = a0 * k + b0;
			}
			if(k < 0 || k > 1) k = -1;
			if(k < 0 || cur > a0 + b0) k = 1, cur = a0 + b0;
			if(k < 0 || cur > a1 + b1) k = 0, cur = a1 + b1;
			memo[i][j] = cur;
		}
	}
	double all = 0;
	for(i = 0; i < n; i++)
		all += memo[i][i];
	printf("%.15f\n%.15f\n", memo[0][n - 1], all);
	fun = mn; st = 1/0.; fill(mm, mm + n + 1, -1.);
	printf("%.15f\n", solve(0));
	fun = mx; st = 0; fill(mm, mm + n + 1, -1.);
	printf("%.15f\n", solve(0));
}
