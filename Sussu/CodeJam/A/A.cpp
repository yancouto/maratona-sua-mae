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

char s[5010], res[5010];

int main (){
	for_tests(t, tt){
		scanf(" %s", s);
		int i = 2000, f = 2001;
		int tam = strlen(s);
		res[i--] = s[0];
		for(int a=1;a<tam;a++){
			if(s[a] >= res[i+1]){
				res[i--] = s[a];
			}
			else{
				res[f++] = s[a];
			}
		}
		printf("Case #%d: ", tt);
		for(int a=i+1;a<f;a++){
			printf("%c", res[a]);
		}
		printf("\n");
	}
}