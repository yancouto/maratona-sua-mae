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

int n, s[1000], m;

char logo[200010];

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<n;a++){
		scanf(" %c", &logo[a]);
	}
	int fila[500], deg=0;
	for(int a='a';a<='z';a++){
		s[a] = a;
	}
	for(int a=0;a<m;a++){
		char i, j;
		scanf(" %c %c", &i, &j);
		deg=0;
		for(int c='a';c<='z';c++){
			if(s[c] == i){
				fila[deg++] = c;
			}
		}
		for(int c='a';c<='z';c++){
			if(s[c] == j){
				s[c] = i;
			}
		}
		for(int b=0;b<deg;b++)
			s[fila[b]] = j;
	}
	for(int a=0;a<n;a++){
		if(s[logo[a]] != 0)
			printf("%c", s[logo[a]]);
		else
			printf("%c", logo[a]);
	}

}