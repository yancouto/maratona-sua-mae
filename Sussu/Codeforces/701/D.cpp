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

int n, k;

double l, vb, vs;

int go(double ini){
	double t = 0;
	t += ini/vb;
	double est = ini;
	for(int a=k;a<n;a+=k){
		double busca = (est - vs*t)/(vb+vs);
		t += busca;
		est = est + vs*busca;
		double leva = (est - vs*t)/(vb-vs);
		t += leva;
		est = est + vs*leva;
	}
	if((t-ini/vb) > (l - ini)/vs)
		return 0;
	return 1;
}

void pgo(double ini){
	double t = 0;
	t += ini/vb;
	double est = ini;
	for(int a=k;a<n;a+=k){
		double busca = (est - vs*t)/(vb+vs);
		t += busca;
		est = est + vs*busca;
		double leva = (est - vs*t)/(vb-vs);
		t += leva;
		est = est + vs*leva;
	}
	printf("%.10f\n", t);
}

int main (){
	clock_t t = clock(); 
	scanf("%d %lf %lf %lf %d", &n, &l, &vs, &vb, &k);
	double i = 0., j = l;
	while((float)(clock() - t)/CLOCKS_PER_SEC < 0.7 && i < j){
		double m = (i + j)/2.;
		if(go(m))
			i = m;
		else
			j = m;
	}
	pgo(i);
}
