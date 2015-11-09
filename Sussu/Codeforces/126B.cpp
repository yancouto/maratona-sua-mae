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
	int tam = strlen(seq);
	int tamt=0, ifim=0;
	int meio=0, imeio=MAXS;
	for(int a=1;a<tam;a++){
		//printf("%d %d\n", a, Z[a]);
		if(a + Z[a] == tam){
			if(Z[a] <= meio){
				for(int j=0;j<Z[a];j++)
					printf("%c", seq[j]);
				return 0;
			}
		}
		meio = max(meio, Z[a]);
	}
	printf("Just a legend\n");
	return 0;
}