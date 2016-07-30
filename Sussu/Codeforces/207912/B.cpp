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

int n;

struct ct{
	int x, y, c;
	ct(int xx, int yy, int cc){
		x =xx;
		y = yy;
		c =cc;
	}
	ct(){}
} s[52];

set <pii> ans;

int dm(int xx, int yy, int x, int y){
	return abs(xx -x) + abs(yy - y);
}

bool tem(int xx, int yy, int x, int y, int c){
	int d = dm(xx, yy, x, y);
	return (d < c+2 || (d == c+2 && (xx != x || yy != y)));
}

void go(int x, int y, int c){
	for(int xx = x-(c+3);xx <= x + (c+3);xx++){
		for(int yy = y - (c+3); yy <= y + (c+3); yy++){
			if(tem(xx, yy, x, y, c)){
				printf("%d %d\n", xx, yy);
				ans.insert(pii(xx, yy));
			}
		}
	}
}

int vx[][4] = {{-1, -1, 0, 0},
				{0, 0, 1, 1},
				{-1, -1, 0, 0},
				{0, 0, 1, 1}};

int vy[][4] = {{-1, 0, -1, 0},
				{-1, 0, -1, 0},
				{0, 1, 0, 1},
				{0, 1, 0, 1}};


void go2(int x, int y, int c){
	for(int xx = x-(c+3);xx <= x + (c+3);xx++){
		for(int yy = y - (c+3); yy <= y + (c+3); yy++){
			if(ans.find(pii(xx, yy)) != ans.end())
				continue;
			int hang = 1;
			for(int p = 0;p < 4;p++){
				int tem = 0; 
				for(int i=0;i<4;i++){
					if(ans.find(pii(xx+vx[p][i], yy+vy[p][i])) != ans.end())
						tem = 1;
				}
				if(tem == 0){
					hang = 0;
					break;
				}
			}
			if(hang)
				ans.insert(pii(xx, yy));
		}
	}
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		go(x, y, c);
	printf("%d\n", (int)ans.size());
		go2(x, y, c);
	printf("%d\n", (int)ans.size());
	}
}
