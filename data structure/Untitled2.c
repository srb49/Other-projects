#include<stdio.h>
#include<stdlib.h>
int main() {
    char *a[10];
    int i;
    printf("enter--->");
    for(i=0;i<3;++i) {
        scanf("%s",a+i);
    }   
    printf("\nentered elements\n");
    for(i=0;i<3;++i) {
        printf("%s\n",a+i);
    }   
}
