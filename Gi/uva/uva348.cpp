#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define N 50
int l[N], c[N];
int pd[N][N];
int esq[N], dir[N];
int n;
int solve (int e, int d){
	if (e == d) return 0;
	int& ret = pd[e][d];
	if (ret != -1) return ret;
	ret = 2000000000;
	for (int i = e; i < d; i++){
		ret = min(ret, solve(e,i) + solve(i+1,d) + l[e]*c[d]*c[i]);
	}
	return ret;
}

void build (int e, int d){
	if (e == d){
		printf("A%d", e+1);
		return;
	}
	printf("(");
	int ret = solve(e,d);
	for (int i = e; i < d; i++){
		if (ret == solve(e,i) + solve(i+1,d) + l[e]*c[d]*c[i]){
			build(e,i);
			printf(" x ");	
			build(i+1,d); break;
		}
	}
	printf(")");
}

int main(){
	int t = 1;
	while (1){
		cin >> n;
		if (!n) break;
		f (i, 0, n) cin >> l[i] >> c[i];
		clr (pd, -1);
		printf("Case %d: ", t++);
		build(0, n-1); cout << endl;
			
	}
	return 0;
}
