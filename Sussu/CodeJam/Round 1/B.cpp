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

char s[110];

char inv(char c){
	if(c == '-') return '+';
	return '-';
}

int main (){
	for_tests(t, tt){
		int ans = 0;
		scanf(" %s", s);
		int tam = strlen(s);
		s[tam] = '+';
		for(int a=0;a<tam;a++){
			if(s[a] != s[a+1]){
				for(int b=0;b<=a;b++){
					s[b] = inv(s[b]);
				}
				ans++;
			}
		}
		printf("Case #%d: %d\n", tt, ans);
	}
}