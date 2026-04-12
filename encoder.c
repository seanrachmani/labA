#include <stdlib.h>
#include <stdio.h>
#include <string.h>
FILE* output;
FILE* input;
FILE* errors;
unsigned char password[] = "1234";
char** encstr; //encoder string
int add,subtract;
int shiftA=0;


int encode(int c,int index){
    if(add){
        int addition = encstr[index]-shiftA;
        c = c+addition;
    }
    if(subtract){
        int subtraction = encstr[index]-shiftA;
        c = c - subtraction;
    }
    return c;
}


int main(int argc,char **argv){
    add=0;
    subtract=0;
    output=stdout;
    input=stdin;
    errors=stderr;
    int debug=1; //default is on
    for(int i=0;i<argc;i++){
        //part1-debug
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
        //end of part1-debug

        //part2-encode
        if(strncmp(argv[i],"+V",2)==0){
            encstr = argv[i]+2; //key argument
            add=1;
        }
        if(strncmp(argv[i]+2,"-V",2)==0){
            encstr = argv[i]+2;
            subtract=1;
        }
    }
}

    
    int index=-1; //indicate where are we in the enc string
    while(feof(input)==0){//we have more input
        int c = fgetc(input);
        index++;
        if(c=='\0'){//cyclic
            index=0;
        }
        c = encode(c,index);
        if(c!=EOF){ //handle last garbage char
            fputc(c,output);
        }
    }
    fclose(output);
    return 0;
}