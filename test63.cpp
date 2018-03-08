/*************************************************************************
	> File Name: test63.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年01月17日 星期三 21时16分36秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

const char *next_token(const char *s){
   while(*s!='\0'&&*s!='['&&*s!=']'&&*s!='('&&*s!=')'&&*s!='{'&&*s!='}')s++;
   return s;
}
const char *IsRecurMatch(const char *string){
    char cur_char = -1;    
    const char *next;
    string = next_token(string);
    switch(*string){
    case ')':
    case ']':
    case '}':
        cur_char = *string;
        next = IsRecurMatch(string+1); 
        if(next == NULL)return NULL;
        if(*next!=cur_char)return NULL;
        next++;
        next = next_token(next);
        break;
    case '{':
    case '[':
    case '(':
        return string;
    }
    return NULL;
}

bool Is_Match(const char *string){
    return IsRecurMatch(string)!=NULL;
} 

int main() {
    char s[100];
    scanf("%s", s);
    printf("%d\n", Is_Match(s));
}
