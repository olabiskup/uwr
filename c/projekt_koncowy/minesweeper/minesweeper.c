#include "minesweeper.h"

void easy_mode(GtkWidget *widget, gpointer user_data){
    arguments *s=user_data;
    s->n=8;
    s->bombs=10;
    game_window(widget, s);
}

void normal_mode(GtkWidget *widget, gpointer user_data){
    arguments *s=user_data;
    s->n=16;
    s->bombs=40;
    game_window(widget, s);
}

void hard_mode(GtkWidget *widget, gpointer user_data){
    arguments *s=user_data;
    s->n=20;
    s->bombs=64;
    game_window(widget, s);
}

gboolean btn_press_callback(GtkWidget *button, GdkEventButton *event, gpointer user_data){
    arguments *s=user_data;
    int r,c;
    for(r=0; r<s->n; r++){
        for(c=0; c<s->n; c++){
            if (s->buttons[r][c]==button){
                goto Next;
            }
        }
    }
    Next:
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3){ 
        if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(button))){ 
            if(!s->is_randomized){
                randomize_bombs(button, s);
                s->is_randomized=true;
            }
            if(s->is_bomb[r][c]) loss(button, user_data);
            else hint(button, user_data);
        }
    }

    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 1){
       gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON(button));
    }
    return FALSE;
}

void quit_if_user_action(GtkWidget *window, gpointer user_data) {
    (void)window;
    arguments *s=user_data;
    if (s->n == 0) gtk_main_quit();
}

void quit_if_user_action_game(GtkWidget *window, gpointer user_data) {
    (void)window;
    arguments *s=user_data;
    if (s->n != 0) gtk_main_quit();
}

void first_window(gpointer user_data){
    arguments *s=user_data;
    s->fst_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);    
    gtk_window_set_title(GTK_WINDOW(s->fst_window), "Saper");
    gtk_window_set_default_size(GTK_WINDOW(s->fst_window), 500, 500);

    gtk_container_set_border_width(GTK_CONTAINER(s->fst_window), 50);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(s->fst_window), box1);

    GtkWidget *title=gtk_label_new("Witaj! Wybierz poziom trudności: ");
    GtkWidget *easy = gtk_button_new_with_label("Łatwy");
    GtkWidget *normal = gtk_button_new_with_label("Normalny");
    GtkWidget *hard = gtk_button_new_with_label("Ekspert");
    GtkWidget *empty, *empty1;
    empty=gtk_label_new(" ");
    empty1=gtk_label_new(" ");

    gtk_box_pack_start(GTK_BOX(box1), title, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), easy, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), empty, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), normal, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), empty1, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box1), hard, TRUE, TRUE, 0);

    g_signal_connect(G_OBJECT(easy), "clicked", G_CALLBACK(easy_mode), s);
    g_signal_connect(G_OBJECT(normal), "clicked", G_CALLBACK(normal_mode), s);
    g_signal_connect(G_OBJECT(hard), "clicked", G_CALLBACK(hard_mode), s);

    gtk_widget_show_all(s->fst_window);
    g_signal_connect(G_OBJECT(s->fst_window), "destroy", G_CALLBACK(quit_if_user_action), s);
}

void play_again(arguments *s) {
    s->n = 0;
    gtk_widget_destroy(s->game_window);
    memset(s, 0, sizeof(arguments));
    first_window(s);
}

void game_window(GtkWidget *widget, gpointer user_data){
    (void)widget;
    arguments *s=user_data;
    int n=s->n;

    s->buttons=malloc(sizeof(GtkWidget **) *n);
    for(int i=0; i<n; i++){
        s->buttons[i]=malloc(sizeof(GtkWidget *) *n);
    }

    s->is_bomb=malloc(sizeof(bool*)*n);
    for(int i=0; i<n; i++){
        s->is_bomb[i]=calloc(n, sizeof(bool));
    }

    s->value=malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        s->value[i]=calloc(n, sizeof(int));
    }

    s->visited=malloc(sizeof(bool*)*n);
    for(int i=0; i<n; i++){
        s->visited[i]=calloc(n, sizeof(bool));
    }

    s->game_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(s->game_window), "Saper");
    gtk_window_set_default_size(GTK_WINDOW(s->game_window), s->n * 60, s->n * 60);

    gtk_container_set_border_width(GTK_CONTAINER(s->game_window), 20);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(s->game_window), box1);

    GtkWidget *grid;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);

    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            GtkWidget *butt;
            butt=gtk_toggle_button_new();
            s->buttons[r][c]=butt;
            g_signal_connect(G_OBJECT(s->buttons[r][c]), "button-press-event", G_CALLBACK(btn_press_callback), s);
            gtk_grid_attach(GTK_GRID(grid),butt, c,r,1,1);
        }
    }

    gtk_widget_show_all(s->game_window);
    gtk_window_close(GTK_WINDOW(s->fst_window));
    g_signal_connect(G_OBJECT(s->game_window), "destroy", G_CALLBACK(quit_if_user_action_game), s);
}
