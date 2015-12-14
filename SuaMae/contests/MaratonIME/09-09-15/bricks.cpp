#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

int n, t, nw, nb, res;

struct seq{
	int n;
	char c;
} s[MAXN];

int mdc(int a,int b){
	if(b==0) return a;
	return mdc(b,a%b);
}

int main (){
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		scanf("%d", &n);
		nw=nb=0;
		for(int a=0;a<n;a++){
			scanf("%d", &s[a].n);
			scanf(" %c", &s[a].c);
			if(s[a].c=='W')
				nw+=s[a].n;
			else
				nb+=s[a].n;
		}
		if(nb==0){
			printf("%d\n", nw);
			continue;
		}
		if(nw==0){
			printf("%d\n", nb);
			continue;
		}
		res=0;
		int div = mdc(nw,nb);
		nw=(int)nw/div;
		nb=(int)nb/div;
		int cw=0, cb=0;
		for(int a=0;a<n;a++){
			if(s[a].c=='W'){
				if(cb!=0 && mdc(cb,nb)==nb){
					int mul = (int)cb/nb;
					int querow = mul*nw;
					printf("W %d %d %d %d %d %d\n", nw, nb, cw, cb, mul, querow);
					if(cw+s[a].n>=querow){
						res++;
						cw = cw+s[a].n-querow;
						cb=0;
					}
					else
						cw+=s[a].n;
				}
				else
					cw+=s[a].n;
			}
			else{
				if(cw!=0 && mdc(cw,nw)==nw){
					int mul = (int)cw/nw;
					int querob = mul*nb;
					printf("B %d %d %d %d %d %d\n", nw, nb, cw, cb, mul, querob);
					if(cb+s[a].n>=querob){
						res++;
						cb = cb+s[a].n-querob;
						cw=0;
					}
					else
						cb+=s[a].n;
				}
				else
					cb+=s[a].n;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
