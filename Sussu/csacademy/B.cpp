
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
	for(int a=0;a<n;a++){
		ll res = 0;
		int i, j;
		scanf("%d%d", &i, &j);
		while(i <= j && i + j != 0){
			ll ii = i;
			ll jj = j;
			if(!(ii&1))
				ii++;
			
			if(!(jj&1))
				jj--;
			res += ((jj+ii)*(jj-ii+2))/4;
			i = i/2 + (i%2);
			j = j/2;
		}
		printf("%lld\n", res);
	}
}
