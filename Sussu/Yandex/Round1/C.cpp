
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

ll v[50];

ll pnt[] = {100ll, 75ll, 60ll, 50ll, 45ll, 40ll, 36ll, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main (){
	for(int a=0;a<10;a++){
		scanf("%lld", &v[a]);
	}
	for(int a=10;a<=35;a++){
		v[a] = 0ll;
	}
	int deu;
	int b = 31;
	for(b = 31;b>=0;b--){
		deu = 0;
		ll myp = 0;
		int p = 9 + 1*(b<10);
		for(int a=0;a<10;a++){
			if(p == b) p--;
			printf("verifica cara %d com %lld + %lld  < %lld\n", a, v[a], pnt[p], pnt[b]);
			if(v[a] + pnt[p] < pnt[b]){
				deu = 1;
				break;
			}
			p--;
		}
		if(deu) break;
	}
	if(!deu) puts("0");
	else{
		if(pnt[b] == 0) b=1000-1;
		printf("%d\n", b+1);
	}
}
