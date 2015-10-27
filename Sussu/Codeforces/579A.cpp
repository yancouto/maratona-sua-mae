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

int t, n, m;

int main (){
	scanf("%d%d", &n, &t);
	if(t==10 && n==1){
		printf("-1\n"); 
		return 0;
	}
	else if(t==10)n--;
		printf("%d", t);

		for(int a=0;a<n-1;a++)
		printf("0");
	return 0;
}