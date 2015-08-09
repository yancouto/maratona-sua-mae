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

int n, m;
int seen[105];
char mat[105][105];

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		for(j = 1; j <= m; j++)
			scanf(" %c", &mat[i][j]);
		mat[i][0] = 'a';
	}
	int took = 0;
	for(int k = 0; k < m; k++){
		int col = 200;
		for(i = 1; i < n; i++){
			for(j = 1; j <= m; j++){
				if(seen[j]) continue;
				if(mat[i][j] < mat[i-1][j])
					col = min(col, j);
				else if(mat[i][j] > mat[i-1][j])
					break;
			}
		}
		if(col == 200) break;
		seen[col] = 1;
		took++;
	}
	printf("%d\n", took);
	return 0;
}
