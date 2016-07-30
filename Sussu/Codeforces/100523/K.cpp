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

const int MAXN = 112345;

struct pti{
	ll x, y, z;
	pti(ll xx, ll yy, ll zz){
		x = xx;
		y = yy;
		z = zz;
	}
	pti(){};
	pti operator - (pti o){
		return pti(x - o.x, y - o.y, z - o.z);
	}
	bool operator == (pti o){
		return (x == o.x && y == o.y && z == o.z);
	}
	bool operator != (pti o){
		return !(x == o.x && y == o.y && z == o.z);
	}

} s[MAXN], z;

int n;

pti cross(pti a, pti b){
	return pti(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

void printp(pti p){
	printf("print: %lld %lld %lld\n", p.x, p.y, p.z);
}

int main (){
	z = pti(0ll, 0ll, 0ll);
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%lld%lld%lld", &s[a].x, &s[a].y, &s[a].z);
	}
	if(n <= 3){
		puts("TAK");
		return 0;
	}
	pti pa, pb, pc;
	pa = s[0];
	pb = s[1];
	int i = 2;
	while(i < n){
		if(cross(pb - pa, s[i] - pa) != z)
			break;	
		i++;
	}
	if( i == n ) i--;
	pc = s[i];
	pti perp = cross(pb - pa, pc - pa);
	//printp(perp);
	int fod = 0;
	for(int a=0;a<n;a++){
		if(cross(perp, cross(pb - pa, s[a] - pa)) != z){
			fod = 1;
			break;
		}
	}
	if(fod)
		puts("NIE");
	else
		puts("TAK");

}
