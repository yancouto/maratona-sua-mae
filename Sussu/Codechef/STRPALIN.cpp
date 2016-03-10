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

int mrk[1000];

char s[1010];

int main (){
	for_tests(t, tt){
		scanf(" %s", s);
		int tam = strlen(s);
		for(int a=0;a<tam;a++){
			mrk[s[a]]++;
		}
		scanf(" %s", s);
		tam = strlen(s);
		int ver = 0;
		for(int a=0;a<tam;a++){
			if(mrk[s[a]]){
				ver = 1;
				break;
			}
		}
		if(ver)
			puts("Yes");
		else
			puts("No");
		memset(mrk, 0, sizeof(mrk));
	}
}