#include <stdio.h>
#include <string.h>

#define MAXC 100010

char s[MAXC], inv[MAXC];

int ff[MAXC]; /*funcao de falha do KMP */ 

int main(){
	while(scanf(" %s", s)!=EOF){ /* lê a entrada até o final do arquivo de entrada */
		int tam = strlen(s);
		int i = tam-1;
		for(i = tam-1;i >= 0;i--){
			inv[tam-i] = s[i]; 
		}
		inv[tam+1]='\0';

		memset(ff,0,sizeof(ff)); /* zera todas as casas da função de falha do KMP - necessaria devido aos varios casos de teste */

		ff[0] = 0;
		ff[1] = 0;
		for(i = 2;i <= tam;i++){ /* calcula a função de falha */
			int ii = ff[i-1];
			while(ii!=0 && inv[ii+1] != inv[i])
				ii = ff[ii];

			if(inv[ii+1] == inv[i])
				ff[i]=ii+1;
		}

		int deg=0;
		for(i=0;i<tam;i++){
			if(s[i] == inv[deg+1]){
				deg++;
			}
			else{
				while(deg != 0 && inv[deg+1] != s[i])
					deg = ff[deg];
				deg++;
			}
		}
		printf("%s", s);
		for(i=deg+1;i <= tam;i++){
			printf("%c", inv[i]);
		}
		printf("\n");
	}
	return 0;
}