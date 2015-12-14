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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif

int main() {
	int imax, cmax;
	char frase[10010];
	for_tests(t, tt) {
		int freq[30];
		memset(freq, 0, sizeof(freq));
		scanf(" ");
		fgets(frase, 1010, stdin);
		int n=strlen(frase);
		for(int i=0; i<n; i++) {
			char c=frase[i];
			if(c>='A' && c<='Z')
				freq[c-'A']++;
		}
		cmax=imax=0;
		for(int i=0; i<26; i++)
			if(cmax<freq[i]){
				cmax=freq[i];
				imax=i;
			}
		int count=0;
		for(int i=0; i<26; i++)
			if(freq[i]==freq[imax])
				count++;
		if(count>1)
			printf("NOT POSSIBLE\n");
		else {
			int d=(imax-4+26)%26;
			printf("%d ", d);
			for(int i=0; i<n; i++)
				if(frase[i]>='A' && frase[i]<='Z') {
					int c=(frase[i]-'A'-d+26)%26;
				
					//printf("letra=%c-%d\n", frase[i], frase[i]-'A');
					printf("%c", c+'A');
				}
				else
					printf("%c", frase[i]);
		}		
	}	
	return 0;
}
