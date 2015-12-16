
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

const int MAXN = 51*51;

int n, m;

struct result{
	int i , j;
} res1[MAXN], res2[MAXN];

int main (){
	freopen("alter.in", "r", stdin);
	freopen("alter.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n==1 && m ==1){
		printf("0\n");
		return 0;
	}
	int cnt = 0;

	for(int i=2;i<=n;i+=2)
		cnt++;
	for(int j=2;j<=m;j+=2)
		cnt++;

	printf("%d\n", cnt);
	for(int i = 2;i<=n;i+=2){
		printf("%d 1 %d %d\n", i, i, m);
	}
	for(int j =2;j<=m;j+=2){
		printf("1 %d %d %d\n", j, n, j);
	}
		
}
