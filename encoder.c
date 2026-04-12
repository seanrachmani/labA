#include <stdlib.h>
#include <stdio.h>
#include <string.h>
FILE* output;
FILE* input;
FILE* errors;
unsigned char password[] = "my_password1";
char* encstr="A"; //encoder string
int add,subtract;
int idx; //indicate where are we in the enc string


int encode(int c){
    if((c>='a'&&c<='z') || (c>='A'&&c<='Z')){
        if(add){
            int addition = encstr[idx]-'A';
            if(c>='a'&&c<='z' && c+addition>'z'){ 
                addition=addition-26; //Z-A cyclic
            }
            if(c>='A'&&c<='Z' && c+addition>'Z'){
                addition=addition-26;
            }
            c = c+addition; 
        }
        if(subtract){
            int subtraction = encstr[idx]-'A';
            if(c>='a'&&c<='z' && c-subtraction<'a'){
                subtraction=subtraction-26;//A-Z cyclic
            }
            if(c>='A'&&c<='Z' && c-subtraction<'A'){
                subtraction=subtraction-26;
            }
            c = c-subtraction;    
        }
        idx++; //only when we encoded relevant lettters(not for all stding)
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
        if(strncmp(argv[i],"-V",2)==0){
            encstr = argv[i]+2;
            subtract=1;
        }
    }

    
    idx=0; 
    while(feof(input)==0){//we have more input
        int c = fgetc(input);
        if(encstr[idx]=='\0'){//cyclic
            idx=0;
        }
        c = encode(c);
        if(c!=EOF){ //handle last garbage char
            fputc(c,output);
        }
    }
    fclose(output);
    return 0;
}