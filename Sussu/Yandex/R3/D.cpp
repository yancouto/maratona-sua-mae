

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
	bool find = 0;
	ll k, kmax, res = 0;
	kmax = 1e17;
	ll i = 1e17+1;
	printf("? %d\n", i); 
	char ci, cj;
	scanf(" %c", &ci);
	ll j = i + kmax;
	while(!find){
		printf("? %d\n", j);
		scanf(" %c", &cj);
		if(cj != ci){
			
		}

	}
	printf("I %d\n", res);
}
