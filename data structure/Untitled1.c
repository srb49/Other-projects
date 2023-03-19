#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main() {
    char a[10];
    int i,l;
    for(i=0;i<3;++i) {
        scanf("%s",&a[i]);
    }   
    l=strlen(a);
    printf("%d\n",l);
    for(i=0;i<3;++i) {
        printf("%s",a[i]);
    } 
}
