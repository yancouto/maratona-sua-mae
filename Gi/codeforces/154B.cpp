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

int n, m;
set<int> onn;
int divs[100005];
vector<int> f;

void fac(int k) {
	f.clear();
	for(int i = 2; i * i <= k; i++) {
		if(k % i == 0) f.pb(i);
		while(k % i == 0) k /= i;
	}
	if(k != 1) f.pb(k);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int k = 0; k < m; k++) {
		char c; int a;
		scanf(" %c %d", &c, &a);
		if(c == '+') {
			if(onn.count(a)) { puts("Already on"); continue; }
			fac(a);
			bool conf = false;
			for(int i = 0; i < f.size(); i++) 
				if(divs[f[i]]) { 
					printf("Conflict with %d\n", divs[f[i]]); 
					conf = true;
					break;
				}
			if(!conf) { 
				puts("Success");
				for(int i = 0; i < f.size(); i++)
					divs[f[i]] = a;
				onn.insert(a);
			}
		}
		else {
			if(!onn.count(a)) { puts("Already off"); continue; }
			fac(a);
			printf("Success\n");
			for(int i = 0; i < f.size(); i++)
				divs[f[i]] = 0;
			onn.erase(a);
		}
	}	
	return 0;
}
