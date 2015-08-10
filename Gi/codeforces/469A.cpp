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

int seen[105];

int main(){
	int n, p, q;
	scanf("%d %d", &n, &p);
	bool yes = true;
	for(int i = 0; i < p; i++){
		int a; scanf("%d", &a);
		seen[a] = 1;
	}
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int a; scanf("%d", &a);
		seen[a] = 1;
	}
	for(int i = 1; i <= n; i++)
		if(!seen[i]) yes = false;
	if(yes)
		puts("I become the guy.");
	else
		puts("Oh, my keyboard!");
	return 0;
}
