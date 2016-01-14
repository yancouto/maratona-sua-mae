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

const int MAXN = 1000010;

char n[MAXN], m[MAXN];
int zn, zm;

int main(){
	scanf(" %s", n);
	scanf(" %s", m);
	int t1 = strlen(n);
	int t2 = strlen(m);
	for(int a = 0;a<t1;a++){
		if(n[a]!='0') break;
		zn++;
	}
	for(int a = 0;a<t2;a++){
		if(m[a]!='0') break;
		zm++;
	}
	if(t1-zn > t2-zm){
		puts(">");
	}
	else if(t1-zn < t2-zm){
		puts("<");
	}
	else{
		for(int a = 0;a<t1-zn;a++){
			int an = a+zn;
			int am = a+zm;
			if(n[an]!=m[am]){
				if(n[an] > m[am])
					puts(">");
				else
					puts("<");
				return 0;
			}
		}
		puts("=");
	}
	return 0;
}