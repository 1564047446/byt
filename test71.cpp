#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int a;
	char b;
	double c;
} Node;

int main() {
	//int *p;
	char *s;
	//printf("sizeof(p) = %d, sizeof(s) = %d\n", sizeof(p), sizeof(s));
	Node p;
	printf("sizeof(int) = %d, sizoef(char) = %d, sizeof(double) = %d, sizeof(Node) = %d\n", sizeof(p.a), sizeof(p.b), sizeof(p.c), sizeof(p));
}