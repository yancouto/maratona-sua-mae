
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

char s[30];

int main (){
	for_tests(t,tt){
		scanf("%d",&n);
		for(int a=0;a<n;a++){
			scanf(" %[^\n]", s);
			int tam = strlen(s);
			for(int a=0;a<tam;a++){
				pal[deg++] = s[a];
				if(a == tam-1 || s[a] == ' '){
					pal[
				}
			}
		}
	}
}
