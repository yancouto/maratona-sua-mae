#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

vector<int> prime;
int seen[1000000];
void prec(){
	prime.pb(2);	
	for(int i = 3; i < 1000000; i+=2){
		if(seen[i]) continue;
		prime.pb(i); 
		if(prime.size() >= 15000) break;
		for(int j = 1; j < 1000000; j++){
			if(j*i >= 1000000) break;
			seen[j*i] = 1;
		}
	}
			
}

int main(){
	int k; scanf("%d", &k);
	prec();
	for(int i = 0; i < k; i++){
		int x; scanf("%d", &x);
		printf("%d\n", prime[x-1]);
	}
	return 0;
}
