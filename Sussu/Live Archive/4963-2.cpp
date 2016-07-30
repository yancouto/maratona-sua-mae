
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

struct pti{
	int x, y;
	pti(){}
	pti(int a, int b){
		x = a;
		y = b;
	}
	bool operator == (pti o){
		return (x == o.x && y == o.y);
	}
	pti operator - (pti o) {
		return pti(x - o.x, y - o.y);
	}

	int cross(pti o){
		return x*o.y - y*o.x;
	}
};

struct poi{
	int x, y, z;
	poi(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}
	poi(){}
} s[5];

int main (){
	while(1){
		for(int a=0;a<4;a++){
			if(scanf("%d%d%d", &s[a].x, &s[a].y, &s[a].z) == EOF || (a == 0 && s[a].x + s[a].z + s[a].y == 0))
				return 0;
		}
		int fodeu = 0;
		pti l1 = 
		double ar =  
		if(fodeu)
			puts("NO");
		else
			puts("YES");
	}
}
