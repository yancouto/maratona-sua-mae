
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

bool f(int v){
	return (v >= 1 && v <= n);
}

int main (){
	int a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	ll res = 0;
	int x1, x2, x3, x4;
	for(int i=1;i<=n;i++){
		x1 = i;
		x2 = x1 + b -c;
		x4 = x2 + a - d;
		x3 = x4 + c - b;
		if(!f(x1) || !f(x2) || !f(x3) || !f(x4))
			continue;
		else
			res++;
	}
	if(res != 0)
		res *= (ll)n;
	cout << res;
}
