
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

const int MAXN = 100010, MAXC = 100010;


int n;

map<ll, int> ind;

int deg;

char pal[MAXC];

int main (){
	int res = 0;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf(" %s", pal);
		int tam = strlen(pal);
		sort(pal, pal+tam);
		ll h = 0;
		for(int b=0;b<tam;b++){
			h = mod(mod(h*26) + pal[b] - 'a');
		}
		ind[h]++;
		res = max(res, ind[h]);
	}
	printf("%d\n", res);
}
