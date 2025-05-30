#include <stdio.h>
#include <stdlib.h>

int main(){
    char *string ;
    string = (char *)malloc(sizeof(char) * 13);
    *(string +  0) = 'H';
    *(string +  1) = 'e';
    *(string +  2) = 'l';
    *(string +  3) = 'l';
    *(string +  4) = 'o';
    *(string +  5) = ' ';
    *(string +  6) = 'w';
    *(string +  7) = 'o';
    *(string +  8) = 'r';
    *(string +  9) = 'l';
    *(string + 10) = 'd';
    *(string + 11) = '!';
    *(string + 12) = '\0';
    printf(string);
    return 0;
}