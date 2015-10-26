#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

double r;
pdd v[105];

double dist(pdd a, pdd b) { return sqrt((a.fst - b.fst) * (a.fst - b.fst) + (a.snd - b.snd) * (a.snd - b.snd)); }

int main() {
	int i, n;
	double a, b;
	scanf("%d %lf", &n, &r);
	for(i = 0; i < n; i++) 
		scanf("%lf %lf", &v[i].fst, &v[i].snd);
	double ans = 0.0;
	for(i = 1; i < n; i++) 
		ans += dist(v[i], v[i-1]);
	if(n > 1) ans += dist(v[n-1], v[0]);
	printf("%.2f\n", ans + 2.0 * 3.141592 * r);
	return 0;
}
