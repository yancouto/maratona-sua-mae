
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

const int MAXN = 60;

int n, m, mrk[MAXN][MAXN][4], l[MAXN][MAXN];

int vx[]={0,0,1,-1};
int vy[]={1,-1,0,0};
int gira[]={2,3,1,0};

struct point {
	int x,y;
} res;

bool nvalid(int x,int y){
	return (x<1 || y<1 || x>n || y>n);
}

void go(int x,int y,int d){
	if(nvalid(x,y)){
		res.x = x;
		res.y = y;
		return ;
	}
	mrk[x][y][d]=1;
	if(l[x][y]==1)d = gira[d];
	if(mrk[x+vx[d]][y+vy[d]][d]==0){
		go(x+vx[d],y+vy[d],d);
	}
}

int main (){
	for_tests(t,tt){
	scanf("%d%d", &n, &m);
	for(int a=0;a<=n+1;a++){
		for(int b=0;b<=n+1;b++){
			l[a][b]=0;
			for(int c=0;c<4;c++){
				mrk[a][b][c]=0;
			}
		}
	}
	for(int a=0;a<m;a++){
		int x, y;
		scanf("%d%d", &x, &y);
		l[x][y]=1;
	}
	int ix,iy, di;
	scanf("%d%d", &ix, &iy);
	if(ix==0)
		di=2, ix++;
	else if(ix==n+1)
		di=3, ix--;
	else if(iy==0)
		di=0, iy++;
	else
		di=1, iy--;
	
	res.x=0;
	res.y=0;
	go(ix,iy,di);
	printf("%d %d\n", res.x, res.y);
	}
}

