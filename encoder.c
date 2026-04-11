#include <stdlib.h>
#include <stdio.h>
#include <string.h>
FILE* output;
FILE* input;
FILE* errors;
unsigned char password[] = "1234";

int encode(int c){
    return c;
}


int main(int argc,char **argv){
    output=stdout;
    input=stdin;
    errors=stderr;
    int debug=1; //default is on
    for(int i=0;i<argc;i++){
        if(debug){
            fprintf(errors,"%s \n",argv[i]);
        }
        if(strcmp(argv[i],"-D")==0){
            debug=0;
        }
        //strncmp for +D comparsion only
        //(char*) casting from unsigned char to string in order to use strncmp
        if(strncmp(argv[i],"+D",2)==0 && strcmp(argv[i]+2,(char*)password)==0){
            debug=1;
        }
    }

    //second part
    while(feof(input)==0){//we have more input
        int c = fgetc(input);
        c = encode(c);
        if(c!=EOF){ //handle last garbage char
            fputc(c,output);
        }
    }
    fclose(output);
    return 0;
}