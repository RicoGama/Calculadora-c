#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes/funcoes.h"

GtkWidget *entrada;
GtkWidget *labelResultado;
GtkWidget *labelExpressao;

int main(int argc, char *argv[]) {
    // Inicializar o GTK
    gtk_init(&argc, &argv);

    // Criar a janela
    GtkWidget *janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(janela), "Calculadora by Rico");
    gtk_container_set_border_width(GTK_CONTAINER(janela), 10);
    gtk_widget_set_size_request(janela, 250, 300);
    g_signal_connect(janela, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Criar um grid para organizar os elementos
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(janela), grid);

    // Criar a entrada para os números
    entrada = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entrada, 0, 0, 4, 1);
    g_signal_connect(entrada, "key-press-event", G_CALLBACK(on_key_press), entrada);

    // Criar o botão "C" (limpar)
    GtkWidget *botaoLimpar = gtk_button_new_with_label("C");
    g_signal_connect(botaoLimpar, "clicked", G_CALLBACK(limpar), NULL);
    gtk_grid_attach(GTK_GRID(grid), botaoLimpar, 0, 1, 4, 1);

    GtkWidget *botao1 = gtk_button_new_with_label("1");
    g_signal_connect(botao1, "clicked", G_CALLBACK(botao1_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao1, 0, 2, 1, 1);

    GtkWidget *botao2 = gtk_button_new_with_label("2");
    g_signal_connect(botao2, "clicked", G_CALLBACK(botao2_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao2, 1, 2, 1, 1);

    GtkWidget *botao3 = gtk_button_new_with_label("3");
    g_signal_connect(botao3, "clicked", G_CALLBACK(botao3_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao3, 2, 2, 1, 1);

    GtkWidget *botao4 = gtk_button_new_with_label("4");
    g_signal_connect(botao4, "clicked", G_CALLBACK(botao4_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao4, 0, 3, 1, 1);

    GtkWidget *botao5 = gtk_button_new_with_label("5");
    g_signal_connect(botao5, "clicked", G_CALLBACK(botao5_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao5, 1, 3, 1, 1);

    GtkWidget *botao6 = gtk_button_new_with_label("6");
    g_signal_connect(botao6, "clicked", G_CALLBACK(botao6_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao6, 2, 3, 1, 1);

    GtkWidget *botao7 = gtk_button_new_with_label("7");
    g_signal_connect(botao7, "clicked", G_CALLBACK(botao7_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao7, 0, 4, 1, 1);

    GtkWidget *botao8 = gtk_button_new_with_label("8");
    g_signal_connect(botao8, "clicked", G_CALLBACK(botao8_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao8, 1, 4, 1, 1);

    GtkWidget *botao9 = gtk_button_new_with_label("9");
    g_signal_connect(botao9, "clicked", G_CALLBACK(botao9_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao9, 2, 4, 1, 1);

    GtkWidget *botao0 = gtk_button_new_with_label("0");
    g_signal_connect(botao0, "clicked", G_CALLBACK(botao0_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), botao0, 0, 5, 2, 1);

    // Criar o botão de igual
    GtkWidget *botaoIgual = gtk_button_new_with_label("=");
    g_signal_connect(botaoIgual, "clicked", G_CALLBACK(igual), NULL);
    gtk_grid_attach(GTK_GRID(grid), botaoIgual, 2, 5, 1, 1);

    // Criar os botões de operação
    GtkWidget *botaoSoma = gtk_button_new_with_label("+");
    g_signal_connect(botaoSoma, "clicked", G_CALLBACK(somar), NULL);
    gtk_grid_attach(GTK_GRID(grid), botaoSoma, 3, 2, 1, 1);

    GtkWidget *botaoSubtracao = gtk_button_new_with_label("-");
    g_signal_connect(botaoSubtracao, "clicked", G_CALLBACK(subtrair), NULL);
    gtk_grid_attach(GTK_GRID(grid), botaoSubtracao, 3, 3, 1, 1);

    GtkWidget *botaoMultiplicacao = gtk_button_new_with_label("*");
    g_signal_connect(botaoMultiplicacao, "clicked", G_CALLBACK(multiplicar), NULL);
    gtk_grid_attach(GTK_GRID(grid), botaoMultiplicacao, 3, 4, 1, 1);

    GtkWidget *botaoDivisao = gtk_button_new_with_label("/");
    g_signal_connect(botaoDivisao, "clicked", G_CALLBACK(dividir), NULL);
    gtk_grid_attach(GTK_GRID(grid), botaoDivisao, 3, 5, 1, 1);

    // Criar a label para exibir o resultado
    labelResultado = gtk_label_new(NULL);
    gtk_label_set_justify(GTK_LABEL(labelResultado), GTK_JUSTIFY_CENTER);
    gtk_grid_attach(GTK_GRID(grid), labelResultado, 0, 6, 4, 1);

    labelExpressao = gtk_label_new("");
    gtk_label_set_justify(GTK_LABEL(labelExpressao), GTK_JUSTIFY_CENTER);
    gtk_grid_attach(GTK_GRID(grid), labelExpressao, 0, 7, 4, 1);

    // Exibir a janela
    gtk_widget_show_all(janela);

    // Executar o loop principal do GTK
    gtk_main();

    return 0;
}