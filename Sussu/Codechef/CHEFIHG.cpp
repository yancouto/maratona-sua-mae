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

const int MAXN = 22;

int n, m;

char M[MAXN][MAXN];
int d[MAXN][MAXN];

string ans = "";

queue <pii> q;

int vi[] = {-1, 0, 0, 1};
int vj[] = {0, 1, -1, 0};

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m && M[i][j] != '*');
}

char let[] = {'U', 'R', 'L', 'D'};

void go(int i, int j){
	if(M[i][j] == 'C')
		return ;
	for(int a=0;a<4;a++){
		int ii = i + vi[a];
		int jj = j + vj[a];
		if(valid(ii, jj) && d[ii][jj] == d[i][j] -1){
			ans += let[a];
			printf("%c", let[a]);
			go(ii, jj);
			return ;
		}
	}
}

int rev[500];

pii move(int i, int j){
	int tam = ans.size();
	for(int c=0;c<tam;c++){
		int dir = rev[ans[c]];
		if(valid(i + vi[dir], j + vj[dir])){
			i = i+vi[dir];
			j = j+vj[dir];
		}
	}
	return pii(i, j);
}

int main (){
	rev['U'] = 0;
	rev['R'] = 1;
	rev['L'] = 2;
	rev['D'] = 3;
	scanf("%d%d", &n, &m);
	int ci, cj;
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			d[a][b] = -1;
			scanf(" %c", &M[a][b]);
			if(M[a][b] == 'C'){
				ci = a;
				cj = b;
			}
		}
	}
	q.push(pii(ci, cj));
	d[ci][cj] = 0;
	while(!q.empty()){
		pii t = q.front();
		q.pop();
		for(int a=0;a<4;a++){
			int ii = t.fst + vi[a];
			int jj = t.snd + vj[a];
			if(valid(ii,jj) && d[ii][jj] == -1){
				d[ii][jj] = d[t.fst][t.snd] + 1;
				q.push(pii(ii, jj));
			}
		}
	}
	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			if(M[a][b] == '.'){
				pii nw = move(a, b);
				go(nw.fst, nw.snd);
			}
		}
	}

}
