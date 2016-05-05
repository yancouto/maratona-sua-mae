
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
	scanf("%d", &n);
	int res1 = min(2, n), res2;
	res1 += 2*((n-res1)/7) + ((n-res1)%7>5);
	res2 = (n/7)*2 + (n%7 > 5);
	printf("%d %d\n", res2, res1); 
}
