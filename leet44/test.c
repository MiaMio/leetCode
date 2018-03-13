#include <stdio.h>

int isMatch(const char *s, const char *p) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
       
    const char* star=NULL;  
    const char* ss=s;   
    while (*s){  
        if ((*p=='?')||(*p==*s)){s++;p++;continue;}  
        if (*p=='*'){star=p++; ss=s;continue;}  
        if (star){ p = star+1; s=++ss;continue;}  
        return 0;  
    }  
    while (*p=='*'){p++;}  
    return !*p;  
}

int main(){
    char* s="zacabz";
    char* p="*a?b*";
    printf("%d\n", isMatch(s, p));
}