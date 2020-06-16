//Aleksandra Biskup 317424 zadanie 1 lista 9
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int l=0, n;
    int c;
    FILE *infile, *outfile;

    if(argc<4){
        printf("za malo agrumentow!");
        exit(1);
    }

    n=atoi(argv[2]);
    outfile=fopen(argv[1], "w");

    for(int i=3; i<argc; i++){
        infile=fopen(argv[i], "r");

        if(infile==NULL){
            fprintf(outfile, "nie udalo sie otworzyc pliku");
        }

        while(((c=getc(infile))!=EOF)){
            if(c=='\n') l++;
        }

        rewind(infile);
        fprintf(outfile, "%s (%d)\n",argv[i], l);

        if(l>n) l=n;
        for(int j=0; j<l; j++){
            while((c=getc(infile))!='\n'){
                putc(c, outfile);
            }
            putc(c, outfile);
        }
        fprintf(outfile, "\n");

        fclose(infile);
    }

    fclose(outfile);

    return 0;
}
