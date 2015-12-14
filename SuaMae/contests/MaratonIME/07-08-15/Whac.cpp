#include <cstdio>
#include <algorithm>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

#include <cmath>
template<typename num> struct point {
	num x, y;
	point() {}
	point(num a, num b) : x(a), y(b) {}
	point operator + (point o) const { return point(x + o.x, y + o.y); }
	point operator - (point o) const { return point(x - o.x, y - o.y); }
	num operator * (point o) const { return x * o.x + y * o.y; }
	num operator ^ (point o) const { return x * o.y - y * o.x; }
	point operator * (num i) const { return point(x * i, y * i); }
	point operator / (num i) const { return point(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(point o) const { return (*this - o) * (*this - o); }
	bool operator < (point o) const { return x < o.x || (x == o.x && y < o.y); }
};
typedef point<int> pointi;


const int MAXX = 30;

int M[MAXX][MAXX][15], dp[MAXX][MAXX][15], n, m, d;

int wmole(int i,int j,int ii,int jj,int tem){
	pointi pi(i,j), pf(ii,jj);
	int ans =0;
	for(int a=min(i,ii);a<=max(i,ii);a++){
		for(int b=min(j,jj);b<=max(j,jj);b++){
			if((a<0 || b<0) || (a>=n || b>=n)) continue;
			pointi pm(a,b);
			if(((pf-pi)^(pm-pi))==0 && M[a][b][tem]==1)
				ans++;
			
		}
	}
	return ans;
}
				
			
			
	


int go(int i,int j,int tem){
	if(tem==11) return 0;
	if(dp[i][j][tem]==-1){
		for(int a=i-d;a<=i+d;a++){
			for(int b=j-d;b<=j+d;b++){
				pointi mo(a,b), wh(i,j);
				if(mo.distSqr(wh)<=d*d){
					dp[i][j][tem]=max(go(a,b,tem+1)+wmole(i,j,a,b,tem),dp[i][j][tem]);
				}
			}
		}
	}
	return dp[i][j][tem];
}
		
	


int main (){
	while(scanf("%d%d%d", &n, &d, &m) && n+m+d!=0){
		for(int a=0;a<MAXX;a++){
			for(int b=0;b<MAXX;b++){
				for(int c=0;c<15;c++){
					M[a][b][c]=0;
					dp[a][b][c]=-1;
				}
			}
		}		
		for(int a=0;a<m;a++){
			int x,y,t;
			scanf("%d%d%d", &x, &y, &t);
			M[x][y][t]=1;
		}
		int res=-1;
		for(int a=0;a<n;a++){
			for(int b=0;b<n;b++){
				res=max(res,go(a,b,1));
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
		
			
		
	
	

