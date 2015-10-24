#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
#define eps 10e-8
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

pii pt[305];
double sl1, sl2, sl3;
bool seen[305][305];

double dist(pii a, pii b) { return sqrt((double) (a.x - b.x) * (a.x - b.x) + (double) (a.y - b.y) * (a.y - b.y)); }
bool check(double a, double b) { return a - eps <= b && a + eps >= b; } 

int main() {
	int n, i, j, k, lst;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &pt[i].x, &pt[i].y);
	sort(pt, pt + n);
	double ans = 0.0;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++) 
			ans += dist(pt[i], pt[j]);
	for(i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
			sl1 = sl2 = sl3 = 0;
			if(seen[i][j]) continue;
			seen[i][j] = 1; lst = j;
			if(pt[j].x - pt[i].x)
				sl1 = (double) (pt[j].y - pt[i].y) / (pt[j].x - pt[i].x);
			for(k = j + 1; k < n; k++) {
				if(pt[k].x - pt[i].x)
					sl2 = (double) (pt[k].y - pt[i].y) / (pt[k].x - pt[i].x);
				if(pt[k].x - pt[j].x)
					sl3 = (double) (pt[k].y - pt[j].y) / (pt[k].x - pt[j].x);
				if(!check(sl1, sl2) || !check(sl2, sl3)) continue;
				ans -= dist(pt[lst], pt[i]);
				lst = k; seen[i][k] = 1;
			}
			if(lst != j) ans -= dist(pt[j], pt[lst]);
		}
	}
	printf("%01.f\n", floor(ans + 0.5));	
	return 0;
}

