/*************************************************************************
	> File Name: test31.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月07日 星期四 23时20分06秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int prime[1000] = {0};

void is_prime() {
    for(int i = 2; i < 1000; i++) {
        prime[++prime[0]] = i;
        for(int j = 1; j <= prime[0]; j++) {
            if(i * prime[j] > 1000) break;
            prime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}


int main(int argc, char *argv[], char *envp[]) {
    if (strcmp(argv[0], "./dd") == 0) printf("RIGHT\n");
    else return 0;
    int flag = 0;
    for (int i = 0; envp[i] != NULL; i++) {
        //printf("%s\n", envp[i]);
        if (strcmp(envp[i], "USER=byt") == 0) flag = 1;
    }
    if (!flag) return 0;
    is_prime();
    for (int i = 1; i <= 10; i++) printf("%d\n", prime[i]);
}
