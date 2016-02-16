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

const int MAXN = 100010;

char s[MAXN], nd[50];

vector <int> app;

int main (){
	scanf(" %s", s);
	scanf(" %s", nd);
	int tam = strlen(s);
	int t2 = strlen(nd);
	for(int a=0;a<tam;a++){
		int aa = a;
		for(int b=0;b<=t2;b++, aa++){
			if(b == t2){
				app.pb(a);
				break;
			}
			if(s[aa] != nd[b]) break;
		}
	}
	int ans = 0;
	int ult = -1;
	for(int a: app){
		if(ult >= a) continue;
		ans++;
		ult = a+t2-1;
	}
	printf("%d\n", ans);
}