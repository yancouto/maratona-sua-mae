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


double t[6], s[6], hs, hu;
double maxs[] = {500, 1000, 1500, 2000, 2500};

int main (){
	for(int a=0;a<5;a++){
		cin >> t[a];
	}
	for(int a=0;a<5;a++){
		cin >> s[a];
	}
	double res=0;
	for(int a=0;a<5;a++){
		res+=max((0.3*(maxs[a])),(1 - (t[a]/250))*(maxs[a]) - 50*s[a]);
	}
	cin >> hs;
	cin >> hu;
	res+= 100*hs - 50*hu;
	long long ans = res;
	cout << ans;
	return 0;
}