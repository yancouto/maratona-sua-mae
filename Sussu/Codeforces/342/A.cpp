#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

ll n, a, b, c, res;

int main (){
	cin >> n >> a >> b >> c;
	/*if(b > n){
		cout << n/a;
		return 0;
	}*/
	res = max(res, n/a + ((n%a > c)*(n%a - c))/(b - c));
	res = max(res, (n>c)*(n-c)/(b-c) + (n>c)*(n > (b-c))*(n - (b-c)*((n-c)/(b - c)))/a);
	/* TRANSFORMADA RAPIDA DE FULVIO
	for(ull i=0ull;i < 1000000ull && a*i < n; i++){
		ull nn = n - a*i;
		res = max(res, nn/a + ((nn%a>c)*(nn%a - c))/(b - c));
		res = max(res, (nn>c)*(nn-c)/(b-c) + (nn>c)*(nn - (ull)(b-c)*((nn-c)/(b - c)))/a);

	}
	for(ull i=0ull;i < 1000000ull && (b-c)*i < n-c; i++){
		ull nn = n - (b-c)*i;
		res = max(res, nn/a + ((nn%a>c)*(nn%a - c))/(b - c));
		res = max(res, (nn>c)*(nn-c)/(b-c) + (nn>c)*(nn - (ull)(b-c)*((nn-c)/(b - c)))/a);
	}*/
	cout << res;	
}

/*
1000000000000000000
9999999999
10000000000
9999999999
*/