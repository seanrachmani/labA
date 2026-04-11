#include <stdlib.h>
#include <stdio.h>
#include <string.h>
FILE* output=stdout;
FILE* input=stdin;
FILE* errors=stderr;

int encode(int c){
    return c;
}

unsigned char password[] = "1234";
int main(int argc,char **argv){
    int debug=1; //default is on
    for(int i=0;i<argc;i++){
        if(debug){
            fprintf(errors,"%s \n",argv[i]);
        }
        if(strcmp(argv[i],"-D")==0){
            debug=0;
        }
        //strncmp for +D comparsion only
        if(strncmp(argv[i],"+D",2)==0 && strcmp(argv[i]+2,password)==0){
            debug=1;
        }
    }

    //second part
    while(feof(input)==0){//we have more input
        int c = fgetc(input);
        c = encode(c);
        fputc(c,output);
    }
    fclose(output);
    return 0;
}