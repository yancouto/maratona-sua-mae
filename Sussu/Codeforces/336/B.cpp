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

const int MAXN = 200010;

int qz[MAXN], qu[MAXN];

char s1[MAXN], s2[MAXN];

int main (){
	scanf(" %s", s1);
	scanf(" %s", s2);
	int tam = strlen(s2);

	for(int a=0;a<tam;a++){
		if(a!=0){
			qu[a] = qu[a-1];
			qz[a] = qz[a-1];
		}
		if(s2[a] == '1')
			qu[a]++;
		else
			qz[a]++;
	}
	ll res = 0;
	int tam2 = strlen(s1);
	for(int a=0;a<tam2;a++){
		if(s1[a] == '1'){
			int ant = 0;
			if(a != 0)
				ant = qz[a-1];
			res += qz[tam-1 - (tam2-1-a)] - ant;
		}
		else{
			int ant = 0;
			if(a != 0)
				ant = qu[a-1];
			res += qu[tam-1 - (tam2-1-a)] - ant;
		}
	}
	cout << res;
	return 0;
}	