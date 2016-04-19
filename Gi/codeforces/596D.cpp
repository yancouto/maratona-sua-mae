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
const int N = 2010;

double memo[N][N][2][2], seen[N][N][2][2];
int n, h, x[N], we[N], wd[N];
double p;

double solve(int i, int j, int ii, int jj) {
	int xi = x[i-1], xj = x[j+1];

	if(ii) xi += h; if(!jj) xj -= h;

	if(i == j) return p * min(x[i]-xi, h) + (1.-p) * min(xj-x[j], h);

	if(seen[i][j][ii][jj]) return memo[i][j][ii][jj];

	double ie, id, je, jd;

	ie = min(x[i]-xi, h) + solve(i + 1, j, 0, jj);

	if(wd[i] >= j) id = x[j] - x[i] + min(xj-x[j], h);
	else id = x[wd[i]] - x[i] + h + solve(wd[i] + 1, j, 1, jj);

	jd = min(xj-x[j], h) + solve(i, j - 1, ii, 1);
	
	if(we[j] <= i) je = x[j] - x[i] + min(x[i]-xi, h);
	else je = x[j] - x[we[j]] + h + solve(i, we[j] - 1, ii, 0);

	ie = 1./2 * p * ie; id = 1./2 * (1. - p) * id;
	je = 1./2 * p * je; jd = 1./2 * (1. - p) * jd;
	seen[i][j][ii][jj] = 1;
	memo[i][j][ii][jj] = ie + id + je + jd;
	
	return memo[i][j][ii][jj];
}

int main() {
	int i, j, ls;
	scanf("%d %d %lf", &n, &h, &p);
	for(i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	x[0] = -3e8; x[n+1] = 3e8;
	sort(x + 1, x + n + 1);
	for(i = 1, ls = 1; i <= n; i++) {
		we[i] = ls;
		if(x[i+1]-x[i] >= h) ls = i + 1;
	}
	for(i = n, ls = n; i; i--) {
		wd[i] = ls;
		if(x[i]-x[i-1] >= h) ls = i - 1;
	}
	printf("%.7lf\n", solve(1, n, 0, 1));
	return 0;
}
