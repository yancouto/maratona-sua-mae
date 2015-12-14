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

const int N = 100009;
double x[N], y[N], z[N], r[N];
const double pi = acos(-1);
double calc(int i, double x) {
	double xx = x - ::x[i] + r[i];
	if(xx > 2 * r[i]) return 4. / 3. * pi * r[i] * r[i] * r[i];
	if(xx < 0) return 0;
	return pi * (xx * xx * r[i] - xx * xx * xx / 3.);
}

int n;
double ar(double x) {
	double a = 10000 * x;
	for(int i = 0; i < n; i++)
		a -= calc(i, x);
	return a;
}

int main() {
	int i, s;
	while(scanf("%d %d", &n, &s) != EOF) {
		double a = 1000000;
		for(i = 0; i < n; i++) {
			scanf("%lf %lf %lf %lf", &r[i], &x[i], &y[i], &z[i]);
			x[i] /= 1000; y[i] /= 1000; z[i] /= 1000; r[i] /= 1000;
			swap(x[i], z[i]);
			a -= 4. / 3. * pi * r[i] * r[i] * r[i];
		}
		double ant = 0;
		for(i = 1; i < s; i++) {
			double l = 0, r = 100;
			while(r - l >= 1e-10) {
				double m = (l + r) / 2;
				if(ar(m) >= a * i / double(s)) r = m;
				else l = m;
			}
			printf("%.15f\n", (l + r) / 2 - ant);
			ant = (l + r) / 2;
		}
		printf("%.15f\n", 100 - ant);
	}
}
