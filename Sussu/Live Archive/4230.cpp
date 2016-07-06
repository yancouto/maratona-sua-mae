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

const int MAXN = 210;

int n, m;

char M[MAXN][MAXN];

ll sum[MAXN], sum2[MAXN];

int d[MAXN][MAXN];

queue<pii> q;

vector<pii> v;

bool cmp(pii a, pii b){
	return (d[a.fst][a.snd] < d[b.fst][b.snd]);
}

ll dis(pii i){
	return d[i.fst][i.snd];
}

int vi[] = {1,-1,0,0};
int vj[] = {0, 0, 1, -1};


bool valid(int i, int j){
	return (i >= 0 && j>=0 && i < n && j < m && M[i][j] != 'X');
}

int main (){
	while(scanf("%d%d", &n, &m) != EOF && n+m != 0){
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				scanf(" %c", &M[a][b]);
				if(M[a][b] == 'E'){
					q.push(pii(a, b));
					d[a][b] = 0;
				}
				else{
					d[a][b] = INT_MAX - 10;
				}
			}
		}
		while(!q.empty()){
			pii t = q.front();
			q.pop();
			for(int a=0;a<4;a++){
				int ii = t.fst + vi[a];
				int jj = t.snd + vj[a];
				if(valid(ii, jj) && d[ii][jj] > d[t.fst][t.snd] + 1){
					d[ii][jj] = d[t.fst][t.snd] + 1;
					q.push(pii(ii, jj));
				}
			}
		}
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				if(M[a][b] != 'X'){
					v.pb(pii(a, b));
				}
			}
		}
		sort(v.begin(), v.end(), cmp);
		sum[0] = 0;
		sum2[0] = 0;
		for(int a=0;a<v.size();a++){
			if(a != 0){
				sum[a] = sum[a-1];
				sum2[a] = sum2[a-1];
			}
			sum[a] += dis(v[a]);
			sum2[a] += dis(v[a])*dis(v[a]);
		}

		double res = DBL_MAX;
		for(int a=0;a<v.size();a++){
			while(a != v.size()-1 && dis(v[a+1]) == dis(v[a]))
				a++;
			res = min(res, 1.0/(a+1.0) + double(sum[a]*sum[a] - sum2[a])/2.0);
		}
		printf("%.10f\n", res);
	}	
}
