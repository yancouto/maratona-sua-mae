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

int n;

int main (){
	int i, j;
	scanf("%d%d", &i, &j);
	scanf("%d", &n);
	double res = DBL_MAX;
	for(int a=0;a<n;a++){
		int x, y;
		double v;
		scanf("%d %d %lf", &x, &y, &v);
		res = min(res, sqrt((x - i)*(x - i) + (y - j)*(y - j))/v);
	}
	printf("%.10f\n", res);
}
