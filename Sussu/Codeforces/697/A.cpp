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

int t, s, x;

int main (){
	int i, j;
	scanf("%d%d%d", &t, &s, &x);
	if(x < t || (x > t && x < t+s)){
		puts("NO");
		return 0;
	}
	if(x == t){
		puts("YES");
		return 0;
	}
	x -= t+s;
	if(x%s <= 1){
		puts("YES");
		return 0;
	}
	else
		puts("NO");

}
