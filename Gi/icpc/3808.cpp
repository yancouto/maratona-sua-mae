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
const int MAX = 505;

char mat[5][MAX];

bool is7(int i) { return mat[0][i] == '*' && mat[0][i+1] == '*' && mat[1][i] == '*' && mat[1][i+1] == '*'; }
bool is6(int i) { return mat[0][i] == '*' && mat[0][i+1] == '*' && mat[1][i] == '*'; }
bool is8(int i) { return mat[0][i] == '*' && mat[1][i] == '*' && mat[1][i+1] == '*'; }
bool is0(int i) { return mat[0][i+1] == '*' && mat[1][i] == '*' && mat[1][i+1] == '*'; }
bool is4(int i) { return mat[0][i] == '*' && mat[0][i+1] == '*' && mat[1][i+1] == '*'; }
bool is2(int i) { return mat[0][i] == '*' && mat[1][i] == '*'; }
bool is3(int i) { return mat[0][i] == '*' && mat[0][i+1] == '*' ; }
bool is5(int i) { return mat[0][i] == '*' && mat[1][i+1] == '*'; }
bool is9(int i) { return mat[0][i+1] == '*' && mat[1][i] == '*'; }
bool is1(int i) { return mat[0][i] == '*'; }


void check(int n) {
	for(int i = 0; i < n; i += 2) {
		if(is7(i)) printf("7");
		else if(is6(i)) printf("6");
		else if(is8(i)) printf("8");
		else if(is0(i)) printf("0");
		else if(is4(i)) printf("4");
		else if(is2(i)) printf("2");
		else if(is3(i)) printf("3");
		else if(is5(i)) printf("5");
		else if(is9(i)) printf("9");
		else if(is1(i)) printf("1");
	}
	putchar('\n');
}

int main() {
	int n;
	char op;
	while(42) {
		char line[MAX];
		for(int i = 0; i < 5; i++)
			for(int j = 0; j < MAX; j++)
				mat[i][j] = '.';
		fgets(line, MAX-1, stdin);
		sscanf(line, "%d", &n);
		if(!n) return 0;
		fgets(line, MAX-1, stdin);
		sscanf(line," %c", &op);
		if(op == 'B') {
			for(int l = 0; l < 3; l++) {
				fgets(line, MAX - 1, stdin);
				int ii = 0, nn = strlen(line);
				for(int i = 0; i < nn; i++) {
					if(line[i] == ' ') continue;
					mat[l][ii++] = line[i];
				}
			}
			check(n * 2);
		}
		else {
			char s[MAX]; 
			fgets(line, MAX-1, stdin);
			sscanf(line, "%s", s);
			int sz = strlen(s);
			for(int i = 0; i < sz; i++) {
				int a = i * 2, b = i * 2 + 1;
				if(s[i] == '1')  mat[0][a] = '*'; 
				else if(s[i] == '2') mat[0][a] = mat[1][a] = '*'; 
				else if(s[i] == '3') mat[0][a] = mat[0][b] = '*'; 
				else if(s[i] == '4') mat[0][a] = mat[0][b] = mat[1][b] = '*'; 
				else if(s[i] == '5') mat[0][a] = mat[1][b] = '*'; 
				else if(s[i] == '6') mat[0][a] = mat[1][a] = mat[0][b] = '*'; 
				else if(s[i] == '7') mat[0][a] = mat[1][a] = mat[0][b] = mat[1][b] = '*'; 
				else if(s[i] == '8') mat[0][a] = mat[1][a] = mat[1][b] = '*'; 
				else if(s[i] == '9') mat[0][b] = mat[1][a] = '*'; 
				else if(s[i] == '0') mat[0][b] = mat[1][a] = mat[1][b] = '*'; 
			}
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < sz*2; j+=2) {	
					printf("%c%c", mat[i][j], mat[i][j+1]);
					if(j < sz*2 - 2) putchar(' ');
				}
				putchar('\n');
			}
		}
	}
	return 0;	
}
