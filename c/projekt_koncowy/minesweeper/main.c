#include "minesweeper.h"

int main(int argc, char *argv[]){
    arguments a;
    a.uncovered=0;
    a.n=0;
    a.is_randomized=false;
    gtk_init(&argc,&argv);
    readstyle ();
    first_window(&a);
    gtk_main();
    return 0;
}