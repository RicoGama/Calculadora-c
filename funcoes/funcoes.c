#include <gtk/gtk.h>
#include "funcoes.h"

// Variáveis globais
GtkWidget *entrada;
GtkWidget *labelResultado;
GtkWidget *labelExpressao;
double numero1 = 0.0;
double numero2 = 0.0;
const char *operacao = NULL;
char expressao[100] = "";


void calcular() {
    // Obter o número atual da entrada
    const char *entradaTexto = gtk_entry_get_text(GTK_ENTRY(entrada));
    double numeroAtual = strtod(entradaTexto, NULL);

    if (numeroAtual == 0.0 && entradaTexto[0] != '0') {
        gtk_label_set_text(GTK_LABEL(labelResultado), "Número inválido!");
        return;
    }

    // Realizar a operação
    double resultado;
    if (operacao != NULL) {
        if (strcmp(operacao, "+") == 0) {
            resultado = numero1 + numeroAtual;
        } else if (strcmp(operacao, "-") == 0) {
            resultado = numero1 - numeroAtual;
        } else if (strcmp(operacao, "*") == 0) {
            resultado = numero1 * numeroAtual;
        } else if (strcmp(operacao, "/") == 0) {
            if (numeroAtual == 0) {
                gtk_label_set_text(GTK_LABEL(labelResultado), "Erro: divisão por zero!");
                return;
            }
            resultado = numero1 / numeroAtual;
        } else {
            gtk_label_set_text(GTK_LABEL(labelResultado), "Operação inválida!");
            return;
        }

        // Atualizar o resultado na label
        char resultadoTexto[50];
        g_snprintf(resultadoTexto, sizeof(resultadoTexto), "Resultado: %.2f", resultado);
        gtk_label_set_text(GTK_LABEL(labelResultado), resultadoTexto);

        // Atualizar o número2 com o número atual
        numero2 = numeroAtual;

        // Atualizar a expressão acumulada
        char operacaoTexto[5];
        g_snprintf(operacaoTexto, sizeof(operacaoTexto), " %s ", operacao);
        strcat(expressao, operacaoTexto);
        strcat(expressao, entradaTexto);
        gtk_label_set_text(GTK_LABEL(labelExpressao), expressao);
    } else {
        // Se não houver operação, definir o número atual como número1
        numero1 = numeroAtual;
        strcpy(expressao, entradaTexto);
        gtk_label_set_text(GTK_LABEL(labelExpressao), expressao);
    }
}

// Função para lidar com o clique do botão de igual
void igual(GtkWidget *widget, gpointer data) {
    calcular();
    operacao = NULL;
}

// Função para lidar com o clique do botão de soma
void somar(GtkWidget *widget, gpointer data) {
    calcular();
    operacao = "+";
    gtk_entry_set_text(GTK_ENTRY(entrada), "");
    gtk_widget_grab_focus(entrada);
}

// Função para lidar com o clique do botão de subtração
void subtrair(GtkWidget *widget, gpointer data) {
    calcular();
    operacao = "-";
    gtk_entry_set_text(GTK_ENTRY(entrada), "");
    gtk_widget_grab_focus(entrada);
}

// Função para lidar com o clique do botão de multiplicação
void multiplicar(GtkWidget *widget, gpointer data) {
    calcular();
    operacao = "*";
    gtk_entry_set_text(GTK_ENTRY(entrada), "");
    gtk_widget_grab_focus(entrada);
}

// Função para lidar com o clique do botão de divisão
void dividir(GtkWidget *widget, gpointer data) {
    calcular();
    operacao = "/";
    gtk_entry_set_text(GTK_ENTRY(entrada), "");
    gtk_widget_grab_focus(entrada);
}

// Função para lidar com o clique do botão "C" (limpar)
void limpar(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "");
    gtk_label_set_text(GTK_LABEL(labelResultado), "");
    numero1 = 0.0;
    numero2 = 0.0;
    operacao = NULL;
    gtk_widget_grab_focus(entrada);
}

void botao1_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "1");
    gtk_widget_grab_focus(entrada);
}

void botao2_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "2");
    gtk_widget_grab_focus(entrada);
}

void botao3_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "3");
    gtk_widget_grab_focus(entrada);
}

void botao4_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "4");
    gtk_widget_grab_focus(entrada);
}

void botao5_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "5");
    gtk_widget_grab_focus(entrada);
}

void botao6_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "6");
    gtk_widget_grab_focus(entrada);
}

void botao7_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "7");
    gtk_widget_grab_focus(entrada);
}

void botao8_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "8");
    gtk_widget_grab_focus(entrada);
}

void botao9_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "9");
    gtk_widget_grab_focus(entrada);
}

void botao0_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entrada), "0");
    gtk_widget_grab_focus(entrada);
}

// Função para lidar com a tecla Enter
gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer data) {
    if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter) {
        calcular();
        operacao = NULL;
        return TRUE;
    }
    return FALSE;
}