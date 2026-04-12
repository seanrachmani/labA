#include <stdio.h>
int main(int argc, char **argv){
    //for each input string except filename
    for(int i=1;i<argc;i++){
        printf("%s ", argv[i]);
    }
    printf("\n");
}