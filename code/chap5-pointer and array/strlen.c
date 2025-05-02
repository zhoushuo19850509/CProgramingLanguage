#include <stdio.h>

int strlen(char *s);
int main(){
    char *s = "hello\0";
    int n = strlen(s);
    printf("%d \n", n);
}

int strlen(char *s){
    int n;

    for(n = 0; *s != '\0'; s++){
        n++;
    }
    return n;

}