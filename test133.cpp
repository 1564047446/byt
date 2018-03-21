#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b

char s0[8][5] = {" - ", "| |", "   ", "| |", " - "};
char s1[8][8] = {"   ", "  |", "   ", "  |", "   "};
char s2[8][8] = {" - ", "  |", " - ", "|  ", " - "};
char s3[8][8] = {" - ", "  |", " - ", "  |", " - "};
char s4[8][8] = {"   ", "| |", " - ", "  |", "   "};
char s5[8][8] = {" - ", "|  ", " - ", "  |", " - "};
char s6[8][8] = {" - ", "|  ", " - ", "| |", " - "};
char s7[8][8] = {" - ", "  |", "   ", "  |", "   "};
char s8[8][8] = {" - ", "| |", " - ", "| |", " - "};
char s9[8][8] = {" - ", "| |", " - ", "  |", " - "};

void print(int x) {
	switch (x) {
		case 0: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s0[i]);
			}
			break;
		}
		case 1: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s1[i]);
			}
			break;
		}
		case 2: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s2[i]);
			}
			break;
		}
		case 3: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s3[i]);
			}
			break;
		}
		case 4: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s4[i]);
			}
			break;
		}
		case 5: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s5[i]);
			}
			break;
		}
		case 6: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s6[i]);
			}
			break;
		}
		case 7: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s7[i]);
			}
			break;
		}
		case 8: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s8[i]);
			}
			break;
		}
		case 9: {
			for (int i = 0; i < 5; i++) {
			printf("%s\n", s9[i]);
			}
			break;
		}
	}
	return ;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		print(n);
	}
}