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

const int MAXC = 100010;

int d;
char s[MAXC];

int main (){
	for_tests(t,tt){
		scanf(" %s", s);
		scanf("%d", &d);
		int tam = strlen(s);
		for(int a=d-1;a<tam;a++){
			printf("%c", s[a]);
		}
		if((tam-d+1)%2)
			for(int a=d-2;a>=0;a--)
				printf("%c", s[a]);
		else
			for(int a=0;a<d-1;a++)
				printf("%c", s[a]);
		printf("\n");
	}
	return 0;
}
