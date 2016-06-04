
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

int v;
double tf;
int n;
int main (){
	scanf("%d %lf", &v, &tf);
	scanf("%d", &n);
	double res = 1000000000000;
	int resi;
	for(int a=0;a<n;a++){
		int x;
		double t;
		scanf("%d %lf", &x, &t);
		if(res > (double)x+(t+tf)*((double)v))
			resi = a;
		res = min(res, (double)x+(t+tf)*((double)v));
	}
	printf("%.10f %d\n", res, resi+1);
}
