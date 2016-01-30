
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

int n, t, s;

int main (){
	scanf("%d%d%d", &n, &t, &s);
	for(int a=0;a<n;a++){
		int s2;
		scanf("%d", &s2);
		int p = s2;
		int p2 = s+t;
		printf("%.15f\n", (double)(p+p2)/2.);
	}
}
