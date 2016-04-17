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

ll n;

#define lld I64d

vector <int> p, t;

map<int,int > ind;

int sinal;

int s[MAXN], res[MAXN], mrk[150010];

int ans = 0;

int go(int i, int cnt, int ults, int ver){
	if(i == p.size() && cnt%2 != sinal) return 0;
	if(i == p.size()){
		if(ver == 0) ans++;
		else{
			for(int a=0;a<p.size();a++){
				if(res[a] < 0)
					printf("%d ", res[a]);
			}
			for(int a=p.size()-1;a>=0;a--){
				if(res[a] > 0)
					printf("%d ", res[a]);
			}
			printf("\n");
		}
		return 0;
	}
	if(ults == 1){
		res[i] = -p[i];
		go(i+1, cnt+1, 1, ver);
		res[i] = p[i];
		go(i+1, cnt, (i == p.size()-1 || p[i+1]!=p[i]), ver);
	}
	return 0;
}

bool cmp(int a,int b){
	return a>b;
}

int main (){
	freopen("product.in", "r", stdin);
	freopen("product.out", "w", stdout);
	scanf("%lld", &n);
	sinal = (n<0);
	n = abs(n);
	for(int a=2;a<=sqrt(n);a++){
		if(!mrk[a]){
			for(int b=a;a*b <= sqrt(n);b++){
				mrk[a*b] = 1;
			}
			int one = 0;
			while(n%a == 0){
				if(one == 0){
					t.pb(a);
				}
				one = 1;
				p.pb(a);
				//printf("%d ", a);
				n/=a;
			}
		}
	}
	if(n != 1){
		p.pb(n);
		//printf("%d", n);
		t.pb(n);
	}
	sort(p.begin(), p.end(), cmp);
	//printf("\n");
	go(0, 0, 1, 0);
	printf("%d\n", ans);
	go(0, 0, 1, 1);
	return 0;
}