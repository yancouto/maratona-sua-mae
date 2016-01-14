#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 1010;

int n, m, mrk[MAXN][MAXN], qtd[MAXN*MAXN], cnt;

int vi[]={0,0,1,-1};
int vj[]={1,-1,0,0};

char c[MAXN][MAXN], res[MAXN][MAXN];

set <int> s;

bool valid(int i,int j){
	return (i<n && j<m && i>=0 && j>=0 && c[i][j]!='*');
}

void go(int i,int j){
	mrk[i][j] = cnt;
	qtd[cnt]++;
	for(int a=0;a<4;a++){
		int ii = i+vi[a], jj = j+vj[a];
		if(valid(ii,jj) && !mrk[ii][jj]){
			go(ii,jj);
		}
	}
}

int main (){
	scanf("%d%d", &n, &m);
	cnt = 1;
	for(int a=0;a<n;a++){
		scanf(" %s", c[a]);
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(c[a][b] == '.')
				res[a][b] = c[a][b];
			else{
				int ans = 1;
				s.clear();
				for(int i=0;i<4;i++){
					int aa = a+vi[i];
					int bb = b+vj[i];
					if(valid(aa,bb)){
						if(!mrk[aa][bb]){
							go(aa,bb);
							cnt++;
						}
						s.insert(mrk[aa][bb]);
					}
				}
				while(!s.empty()){
					int cor = *s.begin();
					s.erase(cor);
					ans+=qtd[cor];
				}
				res[a][b] = '0'+(ans%10);
			}
		}
	}
	for(int a=0;a<n;a++){
		printf("%s\n", res[a]);
	}
}