
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

const int INF = 1000000001;

struct pti{
	int x, y;
} s[5];

bool igx(int i,int j){
	return (s[i].x == s[j].x);
}

bool igy(int i, int j){
	return (s[i].y == s[j].y);
}

map <int,int> mrkx, mrky;

int main (){
	for(int a=0;a<3;a++){
		scanf("%d%d", &s[a].x, &s[a].y);
		mrkx[s[a].x]++;
		mrky[s[a].y]++;
	}
	if(mrkx[s[0].x] == 3 || mrky[s[0].y] == 3){
		puts("1");
		return 0;
	}
	int vx = 0, vy = 0;
	for(int a=0;a<3;a++){
		if(mrkx[s[a].x] == 2)
			vx = 1;
		if(mrky[s[a].y] == 2)
			vy = 1;
	}
	if(vx + vy == 2){
		puts("2");
		return 0;
	}
	if(vx == 1){
		int mx, mxy = -INF, mn, mny = INF;
		for(int a=0;a<3;a++){
			if(mxy < s[a].y){
				mx = a;
				mxy = s[a].y;
			}
			if(mny > s[a].y){
				mn = a;
				mny = s[a].y;
			}
		}
		if(mrkx[s[mn].x] + mrkx[s[mx].x] == 4)
			puts("3");
		else
			puts("2");
		return 0;
	}
	if(vy == 1){
		int mx, mxx = -INF, mn, mnx = INF;
		for(int a=0;a<3;a++){
			if(mxx < s[a].x){
				mx = a;
				mxx = s[a].x;
			}
			if(mnx > s[a].x){
				mn = a;
				mnx = s[a].x;
			}
		}
		if(mrky[s[mn].y] + mrky[s[mx].y] == 4)
			puts("3");
		else
			puts("2");
		return 0;
	}
	puts("3");
}

