#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

#define MINI 0
#define MAXI 1


int r[MAXN], l[MAXN], pai[MAXN], x[MAXN], y[MAXN];

void add(int )

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		char t;
		int k, i, j;
		scanf(" %c %d", &t, &k);
		if( t == 'I' )
			add(k, rand());
		else if( t == 'D' )
			del(k);
		else{
			i = k;
			scanf("%d", &j);
			if( t == 'X' ) separa(i, j, MAXI);
			else separa(i, j, MINI);
		}
	}
}