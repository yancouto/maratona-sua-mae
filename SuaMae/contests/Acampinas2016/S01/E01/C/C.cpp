
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

const int DEZ = 1000000000;

int resi, resj;

inline void print(int i){
	if(resi == -1){
		printf("%d 0\n", i); 
	}
	else{
		printf("%d %d\n", resi, i);
	}
	fflush(stdout);
}

int achaPos(){
	int i=0, f=DEZ;
	while(i<f-1){
		print(i);
		int j;
		if(scanf("%d", &j) == EOF){
			exit(0);
		}
		print(f);
		if(scanf("%d", &j) == EOF){
			exit(0);
		}
		if(j){
			i = (i+f)/2;
		}
		else{
			f = (i+f+1)/2;
		}
	}
	print(i);
	int j = 0;
	if(scanf("%d", &j)== EOF)
		exit(0);
	print(f);
	if(scanf("%d", &j) == EOF)
		exit(0);
	if(j)
		return f;
	else
		return i;
}

int main (){
	resi = resj = -1;
	resi = achaPos();
	resj = achaPos();
	printf("A %d %d\n", resi, resj);
	return 0;
}
