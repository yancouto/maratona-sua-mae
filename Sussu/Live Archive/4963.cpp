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

int sinal(int x){
	if(x>0)
		return 1;
	else if(x == 0)
		return 0;
	else
		return -1;
}


int main (){
	while(1){
		for(int a=0;a<4;a++){
			if(scanf("%d%d%d", &s[a].x, &s[a].y, &s[a].z) == EOF || (a == 0 && s[a].x + s[a].z + s[a].y == 0))
				return 0;
		}
		double area, ar;
		int fodeu = 0;
		int sin = -1;
		pti p1 = pti(s[0].x, s[0].y);
		pti p2 = pti(s[1].x, s[1].y);
		pti p3 = pti(s[2].x, s[2].y);
		area = (p3 - p1).cross(p2 - p1)/2.;
		ar = 0;
		for(int a=0;a<3;a++){
			pti p = pti(s[3].x, s[3].y);
			pti pc = pti(s[a].x, s[a].y);
			pti pl = pti(s[(a+1)%3].x, s[(a+1)%3].y);
			pti la = pl - pc;
			pti lp = p - pc;
			ar += la.cross(lp)/2.;
		}
		printf("%.2f %.2f\n", area, ar);
		if(abs(ar) != abs(area))
			fodeu = 1;
		printf("1 %d\n", fodeu);
		if((p3-p1).cross(p2-p1) < EPS && (p3-p1).cross(p2-p1) > -EPS){
			if(s[3] != s[1] && s[3] != s[0] && s[3] != s[2])
				puts("YES");
		}

		p1 = pti(s[0].z, s[0].y);
		p2 = pti(s[1].z, s[1].y);
		p3 = pti(s[2].z, s[2].y);
		area = (p3 - p1).cross(p2 - p1)/2.;
		ar = 0;

		for(int a=0;a<3;a++){
			pti p = pti(s[3].z, s[3].y);
			pti pc = pti(s[a].z, s[a].y);
			pti pl = pti(s[(a+1)%3].z, s[(a+1)%3].y);
			pti la = pl - pc;
			pti lp = p - pc;
			ar += la.cross(lp)/2.;
		}
		printf("%.2f %.2f\n", area, ar);
		if(abs(ar) != abs(area))
			fodeu = 1;
		printf("2 %d\n", fodeu);

		p1 = pti(s[0].x, s[0].z);
		p2 = pti(s[1].x, s[1].z);
		p3 = pti(s[2].x, s[2].z);
		area = (p3 - p1).cross(p2 - p1)/2.;
		ar = 0;
		for(int a=0;a<3;a++){
			pti p = pti(s[3].x, s[3].z);
			pti pc = pti(s[a].x, s[a].z);
			pti pl = pti(s[(a+1)%3].x, s[(a+1)%3].z);
			pti la = pl - pc;
			pti lp = p - pc;
			ar += la.cross(lp)/2.;
		}
		printf("%.2f %.2f\n", area, ar);
		if(abs(ar) != abs(area))
			fodeu = 1;
		printf("3 %d\n", fodeu);
		if(fodeu)
			puts("NO");
		else
			puts("YES");
	}
}
