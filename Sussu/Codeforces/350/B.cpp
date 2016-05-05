
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


int s[100010];
ll ind[100010];


int n, k;
int main (){

	scanf("%d%d", &n, &k);
	ind[1] = 1;
	ll i = -1;
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		if(a != 1) ind[a] = ind[a-1] + a-1;
		if(i == -1 && ind[a] > k){
			i = ind[a-1];
		}
	}
	if(i == -1) i = ind[n];
	printf("%d\n", s[k - i+1]);
	
}
