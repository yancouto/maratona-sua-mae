#include <cstdio>
#include <cstring>

#define alpha(c) ((c)>='A'&&(c)<='Z')

const char LESS[] = 	"........||.../\\...\n"
				   		"........||../..\\..\n"
				   		".../\\...||./....\\.\n"
				   		"../..\\..||/", 
			EQUAL[] =	"........||........\n"
						".../\\...||.../\\...\n"
						"../..\\..||../..\\..\n"
						"./....\\.||./....\\.\n"
						"/",
			GRTR[] = 	".../\\...||........\n"
						"../..\\..||........\n"
						"./....\\.||.../\\...\n"
						"/";
char pre[100], trash[200];
char left[10], right[10];
int rt, lt;
int i, n;
char c;

inline void f(char init) {
	scanf(" %c", &c);
	int index=0;
	left[index++]=init;
	lt=0;
	int j=0;
	while (init>0) {
		lt+=250+(init%2)*250;
		init>>=1;
		++j;
	}
	lt += (7-j)*250;
	while (c>='A'&&c<='Z') {
		j=0;
		left[index++]=c;
		while (c>0) {
			++j;
			lt+=250+(c%2)*250;
			c>>=1;
		}
		lt+=(7-j)*250;
		scanf(" %c", &c);
	}
	while (c<'A'||c>'Z') scanf(" %c", &c);
	rt=index=0;
	while (c>='A'&&c<='Z') {
		j = 0;
		right[index++]=c;
		while (c>0) {
			rt+=250+(c%2)*250;
			c>>=1;
			++j;
		}
		rt+=(7-j)*250;
		scanf(" %c", &c);
	}
}

inline void _f(char init) {
	scanf(" %c", &c);
	int index=0;
	int j=0;
	rt=0;
	right[index++]=init;
	while (init>0) {
		rt+=250+(init%2)*250;
		init>>=1;
		++j;
	}
	rt+=(7-j)*250;
	while (c>='A'&&c<='Z') {
		j=0;
		right[index++]=c;
		while (c>0) {
			rt+=250+(c%2)*250;
			c>>=1;
			++j;
		}
		rt+=(7-j)*250;
		scanf(" %c", &c);
	}
	while (c<'A'||c>'Z') scanf(" %c", &c);
	lt=index=0;
	while (c>='A'&&c<='Z') {
		j=0;
		left[index++]=c;
		while (c>0) {
			lt+=250+(c%2)*250;
			c>>=1;
			++j;
		}
		rt+=(7-j)*250;
		scanf(" %c", &c);
	}	
}

int main() {
	char a;
	scanf("%d", &n);

	for (int what=0;what<n;++what) {
		i=rt=lt=0;
		scanf(" ");
		do {
			scanf("%c", &a);
			pre[i++] = a;
		} while (a<'A' || a>'Z');
		pre[i-1] = '\0';
		printf("Case %d:\n", what+1);
		if (!strcmp(LESS, pre)) {
			_f(a);
			if (lt > rt) puts("The figure is correct.");
			else if (lt == rt) {
				printf("%s", EQUAL);
				for (int j=0;j<6;++j)
					putchar(alpha(left[j])?left[j]:'.');
				printf("\\||/");
				for (int j=0;j<6;++j)
					putchar(alpha(right[j])?right[j]:'.');
				puts("\\\n\\______/||\\______/\n........||........");
			} else {
				printf("%s", GRTR);
				for (int j=0;j<6;++j)
					putchar(alpha(left[j])?left[j]:'.');
				printf("\\||../..\\..\n\\______/||./....\\.\n........||/");
				for (int j=0;j<6;++j)
					putchar(alpha(right[j])?right[j]:'.');
				puts("\\\n........||\\______/");
			}
		} else if (!strcmp(EQUAL, pre)) {
			f(a);
			if (lt == rt) puts("The figure is correct.");
			else if (lt > rt) {
				printf("%s", GRTR);
				for (int j=0;j<6;++j)
					putchar(alpha(left[j])?left[j]:'.');
				printf(".\\||../..\\..\n\\______/||./....\\.\n........||/");
				for (int j=0;j<6;++j)
					putchar(alpha(right[j])?right[j]:'.');
				puts("\\\n........||\\______/");
			} else {
				printf("%s", LESS);
				for (int j=0;j<6;++j)
					putchar(alpha(right[j])?right[j]:'.');
				printf("\\\n./....\\.||\\______/\n/");
				for (int j=0;j<6;++j)
					putchar(alpha(left[j])?left[j]:'.');
				puts("\\||........\n\\______/||........");
			}
		} else {
			f(a);
			if (lt < rt) puts("The figure is correct.");
			else if (lt == rt) {
				printf("%s", EQUAL);
				for (int j=0;j<6;++j)
					putchar(alpha(left[j])?left[j]:'.');
				printf("\\||/");
				for (int j=0;j<6;++j)
					putchar(alpha(right[j])?right[j]:'.');
				puts("\\\n\\______/||\\______/\n........||........");
			} else {
				printf("%s", LESS);
				for (int j=0;j<6;++j)
					putchar(alpha(right[j])?right[j]:'.');
				printf("\\\n./....\\.||\\______/\n/");
				for (int j=0;j<6;++j)
					putchar(alpha(left[j])?left[j]:'.');
				puts("\\||........\n\\______/||........");
			}
		}
		do {
			if(scanf(" %s", trash) == EOF) return 0;
		} while(trash[0] != '-');
		memset(left, 0, 10);
		memset(right, 0, 10);
		memset(pre, 0, 100);
	}

	return 0;
}