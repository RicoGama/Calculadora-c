# estudos-c

Calculadora montada usando gtk. Rode o seguinte comando pra compilar
gcc -o calculadora calculadora.c funcoes/funcoes.c -Ifuncoes `pkg-config --cflags --libs gtk+-3.0`