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
			sl1 = sl2 = 0;
			if(seen[i][j]) continue;
			seen[i][j] = 1;
			if(pt[j].x - pt[i].x)
				sl1 = (double) (pt[j].y - pt[i].y) / (pt[j].x - pt[i].x);
			lst = j;
			for(k = j + 1; k < n; k++) {
				//putchar('\n');	
				//puts("----------------------------------");
				if(pt[k].x - pt[i].x)
					sl2 = (double) (pt[k].y - pt[i].y) / (pt[k].x - pt[i].x);
				if(pt[k].x - pt[j].x)
					sl3 = (double) (pt[k].y - pt[j].y) / (pt[k].x - pt[j].x);
				//printf("sls %lf %lf\n", sl1, sl2);
				if(!check(sl1, sl2) || !check(sl2, sl3)) continue;
	//			printf("Pontos (%d, %d) (%d, %d) (%d, %d)\n", pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y);
	//			printf("*************Na mesma linha***************\n");
	//			printf("1Tirando distancia (%d %d) (%d %d)\n", pt[lst].x, pt[lst].y, pt[i].x, pt[i].y);
				ans -= dist(pt[lst], pt[i]);
				lst = k; seen[i][k] = 1;
				//printf("dist (%d %d) (%d %d) %lf\n", pt[k].x, pt[k].y, lst.x, lst.y, dist(pt[k], lst)); 
				//printf("2SOMANDO DISTS (%d %d) (%d %d) = %lf\n", pt[j].x, pt[j].y, pt[k].x, pt[k].y, dist(pt[k], pt[j]));
			}
			if(lst != j)
	//			printf("2Tirando distancia (%d %d) (%d %d)\n", pt[lst].x, pt[lst].y, pt[j].x, pt[j].y);
			if(lst != j) ans -= dist(pt[j], pt[lst]);
		}
	}
				//printf("Pontos (%d, %d) (%d, %d) (%d, %d)\n", pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y);
				//printf("sls %lf %lf\n", sl1, sl2);
	printf("%01.f\n", floor(ans + 0.5));	

	return 0;
}

