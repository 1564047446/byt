/*************************************************************************
	> File Name: 编译原理大作业.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年12月18日 星期一 12时14分37秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;


char origin[20][100];
char FIRSTVT[300][100];
char LASTVT[300][100];
char equal[300][100];
int num[1000] = {0};
int num_tail[1000] = {0};
int f[1000] = {0};
char get_final[300];
char table[300][300];

int get_first(int n) {
    for (int i = n - 1; i >= 0; i--) {
        int flag = 0;
        for (int j = 3; j < strlen(origin[i]); j++) {
            if (origin[i][j] >= 'A' && origin[i][j] <= 'Z') {
                flag = 1;
                continue;
            }
            FIRSTVT[origin[i][0] - '0'][num[origin[i][0] - '0'] ++] = origin[i][j];
            FIRSTVT[origin[i][0] - '0'][num[origin[i][0] - '0']] = '\0';
            flag = 0;
            break;
        }
        if (i <= n - 2 && origin[i + 1][0] != origin[i][0] && origin[i + 1][0] == origin[i][3] && flag) {
            strcpy(FIRSTVT[origin[i][0] - '0'], FIRSTVT[origin[i + 1][0] - '0']);
            num[origin[i][0] - '0'] = strlen(FIRSTVT[origin[i][0] - '0']);
        }
    
    }
    return 1;
}

int get_last(int n) {
    
    for (int i = n - 1; i >= 0; i--) {
        int flag = 0;
        for (int j = strlen(origin[i]) - 1; j >= 3; j --) {
            if (origin[i][j] >= 'A' && origin[i][j] <= 'Z') {
                flag = 1;
                continue;
            }
            LASTVT[origin[i][0] - '0'][num_tail[origin[i][0] - '0'] ++] = origin[i][j];
            LASTVT[origin[i][0] - '0'][num_tail[origin[i][0] - '0']] = '\0';
            flag = 0;
            break;
        }
        if (i <= n - 2 && origin[i + 1][0] != origin[i][0] && origin[i + 1][0] == origin[i][3] && flag) {
            strcpy(LASTVT[origin[i][0] - '0'], LASTVT[origin[i + 1][0] - '0']);
            num_tail[origin[i][0] - '0'] = strlen(LASTVT[origin[i][0] - '0']);
        }
    }
    
    return 1;
}

int get_equal() {
    
    table[2][3] = '=';
    
    return 1;
}

int search_first(char *first, int x) {
    
    for (int i = 0; i < strlen(first); i++) {
        int num = 0;
        for (int j = 0; j < strlen(get_final); j++) {
            if (first[i] == get_final[j] && table[x][j] == '0') {
                table[x][j] = '<';
                num++;
            } else {
                num++;
            }
        }
    }
    
    return 1;
}

int search_last(char *last, int x) {
    
    for (int i = 0; i < strlen(last); i++) {
        for (int j = 0; j < strlen(get_final); j++) {
            if (last[i] == get_final[j] && table[j][x] == '0') {
                table[j][x] = '>';
            } else {
                continue;
            }
        }
    }

    return 1;
}

int get_ans(char *s) {
    int flag = 1;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] == '#') {
            flag = 1;
        } else flag = 0;
    }
    if (flag) printf("%s :是正确的输入串\n", s);
    else printf("%s :是错误的输入串\n", s);
}



int main() {
    
    int n;
    memset(table, '0', sizeof(table));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", origin[i]);
    }
    //memset(FIRSTVT, '0', sizeof(FIRSTVT));
    //for (int i = 0; i < 10; i++) printf("%s\n", FIRSTVT[i]);
    get_first(n);
    get_last(n);
    /*for (int i = 0; i <= 300; i += 2) {
        if (num[origin[i][0] - '0'] != 0) {
        
            printf("FIRSTVT[%c] = {%s}\n", origin[i][0], FIRSTVT[origin[i][0] - '0']);
        }
    }*/
    for (int i = 0; i <= 300; i++) {
        if (num[i] != 0) {
            printf("FIRSTVT[%c] = { %s }\n", i + '0', FIRSTVT[i]);
        }
    }
    for (int i = 0; i <= 300; i++) {
        if (num_tail[i] != 0) {
            printf("LASTVT[%c] = { %s }\n", i + '0', LASTVT[i]);
        }
    }
    /*for (int i = 0; i <= 300; i += 2) {
        if (num_tail[origin[i][0] - '0'] != 0) {
            printf("LASTVT[%c] = {%s}\n", origin[i][0], LASTVT[origin[i][0] - '0']);
        }
    }*/
    
    int num = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 3; j < strlen(origin[i]); j++) {
            if (origin[i][j] >= 'A' && origin[i][j] <= 'Z') {
                continue;
            } else {
                if (f[origin[i][j] - '0'] == 0)
                    get_final[num++] = origin[i][j];
                f[origin[i][j] - '0'] = 1;   
                
            }
        } 
        //printf("\n");
    }
    printf("\n");
    
    //for (int i = 0; i < num; i++) printf("%4c ", get_final[i]);
    memset(f, 1, sizeof(f));
    num = 0;
    for (int i = 0; i < strlen(get_final); i++) {
        if (i == 0) printf(" ");
        printf("%3c", get_final[i]);
    }
    printf("\n");
    printf("\n");
    for (int i = 0; i < strlen(get_final); i++) {
        for (int j = 0; j < n; j++) {
            int tar = 0;
            for (int k = 3; k < strlen(origin[j]); k++) {
                if (get_final[i] == origin[j][k]) {
                    if (origin[j][k + 1] >= 'A' && origin[j][k + 1] <= 'Z') {
                        search_first(FIRSTVT[origin[j][k + 1] - '0'], i);
                        tar = 1;
                    }
                    if (origin[j][k - 1] >= 'A' && origin[j][k - 1] <= 'Z') {
                        search_last(LASTVT[origin[j][k - 1] - '0'], i);
                        tar = 1;
                    }
                    /*if (get_final[i] == '#') {
                        printf("# : origin = %s, FIRSTVT = %s\n", origin[j], FIRSTVT[origin[j][k + 1] - '0']);
                    }*/
                }
            }
        }
    }
    //printf("num = %d\n", num);
    get_equal();
    for (int i = 0; i < strlen(get_final); i++) {
        printf("%c", get_final[i]);
        for (int j = 0; j < strlen(get_final); j++) {
            printf("%3c", table[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    char target[100];
    scanf("%s", target);
    get_ans(target);
    return 0;
}
