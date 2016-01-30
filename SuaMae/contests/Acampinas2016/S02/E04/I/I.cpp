
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

const int MAXN = 50;

char s[MAXN];

int main(){
	scanf(" %s", s);
	long long tam = strlen(s);
	ll len = (1ll << tam);
	ll x, y;
	x = y = 0;
	for(int a=0;a<tam;a++){
		if(s[a] == '1')
			x += len/2;
		else if(s[a] == '2')
			y += len/2;
		else if(s[a] == '3'){
			x += len/2;
			y += len/2;
		}
		len /= 2;
	}
	printf("%lld %lld %lld\n", tam, x, y);

}
