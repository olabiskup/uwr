#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int n;  //rozmiary tablicy
    int bombs; //ilosc bomb
    GtkWidget ***buttons; //przyciski
    bool **is_bomb; //true jesli przycisk jest bombą
    bool **visited;
    int uncovered;
    int **value; //ile bomb znajduje się przy danym przycisku
    GtkWidget *game_window;
    GtkWidget *fst_window;
    bool is_randomized;
} arguments;

gboolean btn_press_callback(GtkWidget *button, GdkEventButton *event, gpointer user_data);
void game_window(GtkWidget *widget, gpointer user_data);
void first_window(gpointer user_data);
void easy_mode(GtkWidget *widget, gpointer user_data);
void normal_mode(GtkWidget *widget, gpointer user_data);
void hard_mode(GtkWidget *widget, gpointer user_data);
void play_again(arguments *s);

//play.c
void readstyle();
void win(gpointer user_data);
void loss(GtkWidget *widget, gpointer user_data);
void show_bombs(GtkWidget *widget, gpointer user_data);
void hint(GtkWidget *widget, gpointer user_data);
void randomize_bombs(GtkWidget *widget, gpointer user_data);
void set_value(gpointer user_data);

