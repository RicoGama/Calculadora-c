#ifndef FUNCOES_H
#define FUNCOES_H

#include <gtk/gtk.h>

void botao1_clicked(GtkWidget *widget, gpointer data);
void botao2_clicked(GtkWidget *widget, gpointer data);
void botao3_clicked(GtkWidget *widget, gpointer data);
void botao4_clicked(GtkWidget *widget, gpointer data);
void botao5_clicked(GtkWidget *widget, gpointer data);
void botao6_clicked(GtkWidget *widget, gpointer data);
void botao7_clicked(GtkWidget *widget, gpointer data);
void botao8_clicked(GtkWidget *widget, gpointer data);
void botao9_clicked(GtkWidget *widget, gpointer data);
void botao0_clicked(GtkWidget *widget, gpointer data);
void somar(GtkWidget *widget, gpointer data);
void subtrair(GtkWidget *widget, gpointer data);
void multiplicar(GtkWidget *widget, gpointer data);
void dividir(GtkWidget *widget, gpointer data);
void limpar(GtkWidget *widget, gpointer data);
void igual(GtkWidget *widget, gpointer data);
void calcular();
gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data);
// Declare as demais funções aqui

#endif