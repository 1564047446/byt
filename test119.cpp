#include <stdio.h>
#include <stdlib.h>
 
const int MAX_LEN = 1005;
 
void get_next(char *str, int *next) {
    int match = -1;
    next[0] = -1;
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        while (match >= 0 && str[match + 1] != str[i]) {
            match = next[match];
        }
        if (str[match + 1] == str[i]) {
            ++match;
        }
        next[i] = match;
    }
}
 
int get_next_str(char *buffer, char *str, int *repeat_num) {
    int ind = 0, stat = 0, ind2 = 0;
    repeat_num[0] = 0;
    while (1) {
        switch (stat) {
            case 0:
                if (buffer[ind] <= 'z' && buffer[ind] >= 'a') {
                    repeat_num[0] = 1;
                    str[ind2++] = buffer[ind];
                    str[ind2] = '\0';
                    stat = 6;
                } else {
                    stat = 1;
                }
                break;
            case 1:
                if (buffer[ind] <= 'z' && buffer[ind] >= 'a') {
                    str[ind2++] = buffer[ind];
                    str[ind2] = '\0';
                } else {
                    stat = 2;
                }
                break;
            case 2:
                if (isdigit(buffer[ind])) {
                    repeat_num[0] = repeat_num[0] * 10 + buffer[ind] - '0';
                    ++ind2;
                } else {
                    --ind;
                    stat = 6;
                }
                break;
            case 6:
                return ind;
        }
        ++ind;
    }
    return 0;
}
 
int match_kmp(char *buffer, char *pattern, int *next) {
    char *temp = (char *)malloc(MAX_LEN * sizeof(char));
    int rp_num = 0;
    int match = -1, len = strlen(pattern), len_temp;
    int ans = 0;
    while (*buffer) {
        buffer += get_next_str(buffer, temp, &rp_num);
        len_temp = strlen(temp);
        for (int i = 0; i < rp_num; i++) {
            for (int j = 0; j < len_temp; j++) {
                while (match >= 0 && pattern[match + 1] != temp[j]) {
                    match = next[match];
                }
                if (pattern[match + 1] == temp[j]) {
                    ++match;
                }
                if (match == len - 1) {
                    ++ans;
                    match = next[match];
                }
            }
        }
    }
    return ans;
}
 
int main() {
    char *buffer = (char *)malloc(MAX_LEN * sizeof(char));
    char *pattern = (char *)malloc(MAX_LEN * sizeof(char));
    int *next = (int *)malloc(MAX_LEN * sizeof(int));
    scanf("%s", buffer);
    scanf("%s", pattern);
    get_next(pattern, next);
    printf("%d\n", match_kmp(buffer, pattern, next));
    free(buffer);
    free(pattern);
    free(next);
    return 0;
}
