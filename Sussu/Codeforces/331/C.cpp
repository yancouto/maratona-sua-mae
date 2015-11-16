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


#define temp template<typename num>
#define ptn point<num>

temp struct point {
	num x, y;
	ptn() {}
	ptn(num a, num b) : x(a), y(b) {}
	ptn operator + (ptn o) const { return ptn(x + o.x, y + o.y); }
	ptn operator - (ptn o) const { return ptn(x - o.x, y - o.y); }
	num operator * (ptn o) const { return x * o.x + y * o.y; }
	num operator ^ (ptn o) const { return x * o.y - y * o.x; }
	ptn operator * (num i) const { return ptn(x * i, y * i); }
	ptn operator / (num i) const { return ptn(x / i, y / i); }
	point<double> rotate(double deg) {
		double cs = cos(deg), sn = sin(deg);
		return point<double>(x*cs - y*sn, x*sn + y*cs);
	}
	num distSqr(ptn o) const { return (*this - o) * (*this - o); }
	bool operator < (ptn o) const { return x < o.x || (x == o.x && y < o.y); }
};


typedef point<int> pti;

const int MAXN = 100010;

vector <int> pos[MAXN*2];	

int n, w[MAXN], bit[MAXN], v[MAXN], mrk[MAXN];
pti p[MAXN]; 

inline int qry(int i){
	int ans = 0;
	while(i>0){
		ans += bit[i];
		i -= (i&-i);
	}
	return ans;
}

inline void upd(int i,int x){
	while(i<MAXN-2){
		bit[i] += x;
		i += (i&-i);
	}
}

int main (){
	int res = 0;
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &p[a].x, &p[a].y);
		p[a].x++;
		p[a].y++;
	}
	for(int a=0;a<n;a++){
		scanf("%d", &w[a]);
		pos[w[a]+MAXN].pb(a);
	}
	sort(p,p+n);
	memset(mrk,-1,sizeof(mrk));
	for(int a=0;a<n;a++){
		int val = qry(p[a].y);
		upd(p[a].y,1);
		int foi =0, i = p[a].y-p[a].x+MAXN;
		for(int b=0;b<pos[i].size();b++){
			if(pos[i][b]>=val && mrk[pos[i][b]]==-1){
				mrk[pos[i][b]] = a;
				foi = 1;
				break;
			}
		}
		if(foi == 0)
			res=1;
	}
	if(res==0){
		printf("YES\n");
		for(int a=0;a<n;a++){
			p[mrk[a]].x--;
			p[mrk[a]].y--;
			printf("%d %d\n", p[mrk[a]].x, p[mrk[a]].y);
		}
	}
	else
		printf("NO\n");
	return 0;
}