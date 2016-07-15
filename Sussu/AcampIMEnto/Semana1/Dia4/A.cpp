#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef pair<double, double> pto;

double sq(double x) { return x * x; }

const double EPS = 1e-10;

int main() {
	int n;
	while(scanf("%d", &n) && n) {
		vector<pto> v;
		for(int i = 0; i < n; i++) {
			double x, y;
			scanf("%lf%lf", &x, &y);
			v.pb(mp(x, y));
		}
		double l = 0, h = 1e8, x1, x2;
		int iter = 0;
		while(iter++ < 250) {
			double m = (l + h) / 2;
			double diff = sq(m) - sq(v[0].ss); 
			if(diff < -EPS) {
				l = m;
				continue;
			} else if(diff < EPS) {
				diff = 0;
			}
			x1 = -sqrt(diff) + v[0].ff, x2 = sqrt(diff) + v[0].ff;
			for(int i = 1; i < n; i++) {
				diff = sq(m) - sq(v[i].ss); 
				if(diff < -EPS) {
					l = m;
					goto next;
				} else if(diff < EPS) {
					diff = 0;
				}
				double xl = -sqrt(diff) + v[i].ff;
				double xr = sqrt(diff) + v[i].ff;
				x1 = max(x1, xl);
				x2 = min(x2, xr);
			}
			if(x2 - x1 < -EPS) {
				l = m;
			} else {
				h = m;
			}
			next:;
		}
		printf("%.9f %.9f\n", x1 + EPS, l + EPS);
	}
	return 0;
}
