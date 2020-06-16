//Aleksandra Biskup 317424 lista 2 zad 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h.>

int main(int argc, char *argv[])
{
    if(argc<=1){
        printf("Brak argumentow \n");
        return 1;
    }
    int twin[18]={0xA5, 0xC6,0xCA,0xA3,0xD1,0xD3,0x8C,0x8F,0xAF,0xB9,0xE6,0xEA,	0xB3,0xF1,0xF3,0x9C,0x9F,0xBF};
    int tutf1[18]={0xC4,0xC4,0xC4,0xC5,0xC5,0xC3,0xC5,0xC5,0xC5,0xC4,0xC4,0xC4,0xC5,0xC5,0xC3,0xC5,0xC5,0xC5};
    int tutf2[18]={0x84,0x86,0x98,0x81,0x83,0x93,0x9A,0xB9,0xBB,0x85,0x87,0x99,0x82,0x84,0xB3,0x9B,0xBA,0xBC};
    _Bool test=1;
    int c;
    int c1;
    //win2utf
    if (strcmp(argv[1],"win2utf")==0){
        while ((c=getchar())!=EOF){
            for(int i=0;i<18;i++){
                if(c==twin[i]){
                    putchar(tutf1[i]);
                    putchar(tutf2[i]);
                    test=0;
                    break;
                }
            }
            if (test) putchar(c);
            else test=1;
        }
    }
    //utf2win
    if (strcmp(argv[1],"utf2win")==0){
     while ((c=getchar())!=EOF){
           if(c==0xC3||c==0xC4||c==0xC5){
                c1=getchar();
        for(int i=0;i<18;i++){
            {
            if(c==tutf1[i]&&c1==tutf2[i]){
                putchar(twin[i]);
                test=0;
                break;
            }
            }
            }

        if (test){
            putchar(c);
            putchar(c1);
        }
        else test=1;
        }
        else putchar(c);
    }
    }
    return 0;
}
