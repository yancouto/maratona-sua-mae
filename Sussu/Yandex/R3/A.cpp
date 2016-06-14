

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

int main (){
	int n;
	scanf("%d", &n);
	int mine = INT_MAX;
	int maxd = INT_MIN;
	for(int a=0;a<n;a++){
		int x; char d;
		scanf("%d %c", &x, &d);
		if( d == '-')
			mine = min(mine, x);
		else
			maxd = max(maxd, x);
	}
	if(mine >= maxd)
		puts("1");
	else
		puts("2");
}
