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

const int MAXN = 100010;

int i, j, ii, jj, vmax, t, ui[3], uj[3];

inline bool mesm(int a,int b){
	return ((a<=0 && b<=0) || (a>=0 && b>=0));
}

double calc(double pi, double pj, int v){
	int gas = vmax;
	ll norm = sqrt((ii-pi)*(ii-pi) + (jj-pj)*(jj-pj));
	ll ni = (norm/vmax) * (ii-pi);
	ll nj = (norm/vmax) * (jj-pj); 
	if(mesm(ii - pi, ui[v])){

	}
}

int main (){
	scanf("%d %d %d %d", &i, &j, &ii, &jj);
	scanf("%d %d", &vmax, &t);
	scanf("%d %d %d %d", &ui[0], &uj[0], &ui[1], &uj[1]);

	if(calc(i,j,0))
}