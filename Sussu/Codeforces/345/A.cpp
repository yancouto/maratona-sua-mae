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
	
int a, b;

int main (){
	scanf("%d%d", &a, &b);
	int res = 0;
	while( (a > 0 && b > 0) &&  a+b>2){
		if(a < b) a+=3;
		else b+=3;
		a-=2;
		b-=2;
		res++;
	}
	printf("%d\n", res);
}