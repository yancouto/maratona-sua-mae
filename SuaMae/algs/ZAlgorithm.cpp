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

const int MAXS = 6543210;

int L, R, Z[MAXS];

char seq[MAXS];

inline void ZAlgorithm(char s[]){
	int tam = strlen(s);
	L = R = 0;
	for(int i=1;i<tam;i++){
		if(i > R){
			L = R = i;
			while(R < tam && s[R] == s[R-L])
				R++;
			Z[i] = R-L; 
			R--;
		}
		else{
			if(Z[i-L] >= R-i+1){
				L = i;
				while(R < tam && s[R] == s[R-L])
					R++;
				Z[i] = R-L;
				R--;
			}
			else
				Z[i] = Z[i-L];
		}
	}
}

int main (){
	scanf("%s", seq);
	ZAlgorithm(seq);
	return 0;
}	