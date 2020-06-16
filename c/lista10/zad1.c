//Aleksandra Biskup 317424 zadanie 1 lista 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <stdbool.h>

typedef struct
{
    int n;
    int *p;
    GtkWidget ***tab;
} arguments;

bool next_perm(int n, int p[n])
{
    int tmp;
    int pom[n];

    if (n == 1)
        return false;
    if (!(next_perm(n - 1, p + 1)))
    {
        if (p[0] > p[1])
            return false;
        else
        {
            for (int i = n - 1; i > 0; i--)
            {
                if (p[i] > p[0])
                {
                    tmp = p[i];
                    p[i] = p[0];
                    p[0] = tmp;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                pom[i] = p[i];
            }
            for (int i = 1; i < n; i++)
            {
                p[i] = pom[n - i];
            }
        }
    }
    return true;
}

void button_clicked(GtkWidget *widget, gpointer user_data)
{
    arguments *s = user_data;
    gtk_button_set_label(GTK_BUTTON(widget), "Następna permutacja");
    for (int i = 0; i < s->n; i++)
    {
        for (int j = 0; j < s->n; j++)
        {
            gtk_label_set_text(GTK_LABEL(s->tab[i][j]), "");
        }
    }

    for (int i = 0; i < s->n; i++)
    {
        int l = s->p[i];
        gtk_label_set_text(GTK_LABEL(s->tab[i][l - 1]), "X");
    }
    next_perm(s->n, s->p);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("za malo argumentow!\n");
        exit(1);
    }

    arguments a;
    int n = atoi(argv[1]);
    int l;
    a.n = n;
    a.p = malloc(sizeof(int) * n);
    a.tab = malloc(sizeof(GtkWidget **) * n);

    for (int i = 0; i < n; i++)
    {
        a.p[i] = i + 1;
        a.tab[i] = malloc(sizeof(GtkWidget *) * n);
    }

    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Szachownica");

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box1);
    GtkWidget *grid;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_box_pack_start(GTK_BOX(box1), grid, TRUE, TRUE, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            GtkWidget *lab;
            lab = gtk_label_new("");
            a.tab[i][j] = lab;
            GtkWidget *frame = gtk_frame_new(NULL);
            gtk_grid_attach(GTK_GRID(grid), frame, i, j, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), lab, i, j, 1, 1);
        }
    }

    GtkWidget *button = gtk_button_new_with_label("Start");
    //gtk_grid_attach(GTK_GRID(grid), button, n/2, n, 1, 1);
    gtk_box_pack_end(GTK_BOX(box1), button, TRUE, TRUE, 0);

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), &a);

    gtk_widget_show_all(window);
    gtk_main();
}
