#include <bits/stdc++.h>
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

int mat[110][502];

int main(){
	char linha[110];
	int c = 0;
	while(scanf("%s", linha) != EOF){
		int i;
		for(i = 0; linha[i] != '\0'; i++);
		i--;
		for(int j = 500; i >= 0; j--,i--)
			mat[c][j] = linha[i]-'0';
		c++;
	}
	int resp[502];
	for(int i = 500; i >= 0; i--)
		resp[i] = mat[0][i];	
	int cast = 0;
	for(int i = 1; i <= c; i++){
		for(int j = 500; j >= 0; j--){
			int aux = resp[j];
			resp[j] = (aux+mat[i][j]+cast)%10;
			cast = (aux+mat[i][j]+cast)/10;
		}
	}
	int i;
	for(i = 0; resp[i] == 0 && i <= 500; i++);
	if(i == 501) printf("0");
	else
		for(; i <= 500; i++)
			printf("%d", resp[i]);
	printf("\n");
	return 0;
}
