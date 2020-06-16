#include "minesweeper.h"

GtkCssProvider *css_provider;

void readstyle(){
    css_provider = (GtkCssProvider *)malloc(sizeof(GtkCssProvider));
    css_provider = gtk_css_provider_new();
            gtk_css_provider_load_from_path(css_provider, "style.css", NULL);
        gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                        GTK_STYLE_PROVIDER(css_provider),
                                        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
} 

void win(gpointer user_data){
    arguments *s=user_data;
    GtkWidget *dialog = gtk_dialog_new();
    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(s->game_window));
    gtk_window_set_title(GTK_WINDOW(dialog), "Saper");
    gtk_dialog_add_buttons(GTK_DIALOG(dialog), "Jeszcze raz", GTK_RESPONSE_OK, "Wyjście", GTK_RESPONSE_CANCEL, NULL);
    gtk_window_set_default_size(GTK_WINDOW(dialog), 200, 100);
    
    GtkWidget *area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *label = gtk_label_new("\nWygrywasz!");
    gtk_container_add(GTK_CONTAINER(area), label);
    gtk_widget_show_all(dialog);
    int button = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    if (button == GTK_RESPONSE_OK) {
        play_again(s);
    } else {
        gtk_main_quit();
    }
}

void loss(GtkWidget *widget, gpointer user_data){
    show_bombs(widget, user_data);
    arguments *s=user_data;
    GtkWidget *dialog = gtk_dialog_new();
    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(s->game_window));
    gtk_window_set_title(GTK_WINDOW(dialog), "Saper");
    gtk_dialog_add_buttons(GTK_DIALOG(dialog), "Jeszcze raz", GTK_RESPONSE_OK, "Wyjście", GTK_RESPONSE_CANCEL, NULL);
    gtk_window_set_default_size(GTK_WINDOW(dialog), 200, 100);
    
    GtkWidget *area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *label = gtk_label_new("\nPrzegrywasz!");
    gtk_container_add(GTK_CONTAINER(area), label);
    gtk_widget_show_all(dialog);
    int button = gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    if (button == GTK_RESPONSE_OK) {
        play_again(s);
    } else {
        gtk_main_quit();
    }
}

void show_bombs(GtkWidget *widget, gpointer user_data){
    (void)widget;
    arguments *s=user_data;
    for(int r=0; r<s->n; r++){
        for(int c=0; c<s->n; c++){
            if(s->is_bomb[r][c]){
                gtk_widget_set_name(s->buttons[r][c], "bomb");
            }
        }
    }
    gtk_widget_show_all(s->game_window);
}

void hint(GtkWidget *widget, gpointer user_data){
    arguments *s=user_data;
    int to_click=(s->n*s->n)-s->bombs;
    int k=0, l=0;
    for(int r=0; r<s->n; r++){
        for(int c=0; c<s->n; c++){
            if (s->buttons[r][c]==widget){
                k=r, l=c;
                break;
            }
        }
        if(k>0) break;
    }

    char str[2], name[6]="butt";
    if(s->visited[k][l]) return;
    s->visited[k][l]=true;
    s->uncovered++;
    
    gtk_widget_set_name(s->buttons[k][l], "uncovered");
    if(s->value[k][l]>0&&!s->is_bomb[k][l]){
        sprintf(str, "%d", s->value[k][l]);
        name[4]=str[0];
        gtk_widget_set_name(s->buttons[k][l], name);
        gtk_button_set_label(GTK_BUTTON(s->buttons[k][l]), str);
        if(s->uncovered==to_click) win(s);
        return;
    }

    if(!(s->is_bomb[k][l])){
        if(l>0) hint(s->buttons[k][l-1], s);
        if(k>0) hint(s->buttons[k-1][l], s);
        if(l>0&&k>0) hint(s->buttons[k-1][l-1], s);
        if(l>0&&k<s->n-1) hint(s->buttons[k+1][l-1], s);
        if(k>0&&l<s->n-1) hint(s->buttons[k-1][l+1], s);
        if(l<s->n-1&&k<s->n-1) hint(s->buttons[k+1][l+1], s);
        if(l<s->n-1) hint(s->buttons[k][l+1], s);
        if(k<s->n-1) hint(s->buttons[k+1][l], s);
    }   
}

void randomize_bombs(GtkWidget *widget, gpointer user_data){
    arguments *s=user_data;
    int r,c;
    for(r=0; r<s->n; r++){
        for(c=0; c<s->n; c++){
            if (s->buttons[r][c]==widget){
                goto Next;
            }
        }
    }
    Next:
    srand(time(NULL));
    int tmpR,tmpC;  
    for(int i=0; i<s->bombs; i++){
        while(true){
            tmpR=(rand()%s->n);
            tmpC=(rand()%s->n);
            if (tmpC == c && tmpR == r) continue;
            if (tmpC == c - 1 && tmpR == r) continue;
            if (tmpC == c + 1 && tmpR == r) continue;
            if (tmpC == c && tmpR == r - 1) continue;
            if (tmpC == c && tmpR == r + 1) continue;
            if (tmpC == c - 1 && tmpR == r + 1) continue;
            if (tmpC == c - 1 && tmpR == r - 1) continue;
            if (tmpC == c + 1 && tmpR == r + 1) continue;
            if (tmpC == c + 1 && tmpR == r - 1) continue;
            if (s->is_bomb[tmpR][tmpC]) continue;
            break;
        }
        s->is_bomb[tmpR][tmpC]=true;
    }

    set_value(s);
  //  show_bombs(widget, user_data);
}

void set_value(gpointer user_data){
    arguments *s=user_data;
    int n=s->n;
    int tmpR,tmpC; 
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            if(s->is_bomb[r][c]){
                if(r==0&&c==0){
                    tmpR=r;
                    tmpC=c+1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpR=r+1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpC=c;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                }
                else if(r==0&&c==n-1){
                    tmpR=r+1;
                    tmpC=c;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpC=c-1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpR=r;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                }
                else if(c==0&&r==n-1){
                    tmpC=c;
                    tmpR=r-1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpC=c+1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpR=r;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                }
                else if(c==n-1&&r==n-1){
                    tmpC=c;
                    tmpR=r-1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpC=c-1;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                    tmpR=r;
                    if(!(s->is_bomb[tmpR][tmpC])){
                        s->value[tmpR][tmpC]++;
                    }
                }
                else if(c==0){
                    for(tmpR=r-1; tmpR<=r+1; tmpR++){
                        tmpC=c;
                        if(!(tmpC==c&&tmpR==r)){
                            if(!(s->is_bomb[tmpR][tmpC])){
                                s->value[tmpR][tmpC]++;
                            }
                        }     
                        tmpC=c+1;
                        if(!s->is_bomb[tmpR][tmpC]){
                            s->value[tmpR][tmpC]++;
                        }
                    }
                }
                else if(r==0){
                    for(tmpC=c-1; tmpC<=c+1; tmpC++){
                        tmpR=r;
                        if(!(tmpC==c&&tmpR==r)){
                            if(!(s->is_bomb[tmpR][tmpC])){
                                s->value[tmpR][tmpC]++;
                            }
                        }     
                        tmpR=r+1;
                        if(!s->is_bomb[tmpR][tmpC]){
                            s->value[tmpR][tmpC]++;
                        }
                    }
                }
                else if(c==n-1){
                    for(tmpR=r-1; tmpR<=r+1; tmpR++){
                        tmpC=c;
                        if(!(tmpC==c&&tmpR==r)){
                            if(!s->is_bomb[tmpR][tmpC]){
                                s->value[tmpR][tmpC]++;
                            }
                        }     
                        tmpC=c-1;
                        if(!s->is_bomb[tmpR][tmpC]){
                            s->value[tmpR][tmpC]++;
                        }
                    }
                }
                else if(r==n-1){
                    for(tmpC=c-1; tmpC<=c+1; tmpC++){
                        tmpR=r;
                        if(!(tmpC==c&&tmpR==r)){
                            if(!s->is_bomb[tmpR][tmpC]){
                                s->value[tmpR][tmpC]++;
                            }
                        }     
                        tmpR=r-1;
                        if(!s->is_bomb[tmpR][tmpC]){
                            s->value[tmpR][tmpC]++;
                        }
                    }
                }
                else{
                    for(tmpR=r-1; tmpR<=r+1; tmpR++){
                        for(tmpC=c-1; tmpC<=c+1; tmpC++){
                            if(!(tmpC==c&&tmpR==r)){
                                if(!s->is_bomb[tmpR][tmpC]){
                                    s->value[tmpR][tmpC]=s->value[tmpR][tmpC]+1;
                                }
                            }
                        }
                    }
                } 
            }
        }
    }
}


 