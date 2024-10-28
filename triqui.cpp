#include <stdio.h>
#include <windows.h>

void mostrarMatriz(int matriz[3][3]);
void jugar(int matriz[3][3], int jugador);
int verificarGanador(int matriz[3][3]);
void gotoxy(int x,int y);
void linea_horizontal(int x, int y, int l, int tipo);
void linea_vertical(int x, int y, int l, int tipo);
void cuadrado(int x, int y, int alto, int ancho, int tipo);
void tabla(int x, int y, int filas, int columnas, int borde);

int main() {
    int matriz[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int jugador = 1;
    int ganador = 0;
    int jugadas = 0;

    while (ganador == 0 && jugadas < 9) {
        jugar(matriz, jugador);
        mostrarMatriz(matriz);
        ganador = verificarGanador(matriz);
        jugadas++;

        if (ganador == 0) {
            jugador = (jugador == 1) ? 2 : 1;
        }
    }

    if (ganador == 1) {
        printf("¡El jugador 1 ha ganado!\n");
    } else if (ganador == 2) {
        printf("¡El jugador 2 ha ganado!\n");
    } else {
        printf("Empate.\n");
    }

    return 0;
}

void jugar(int matriz[3][3], int jugador) {
    int fila, columna;

    do {
        printf("Jugador %d, ingrese la posicion donde desea jugar (fila, columna): ", jugador);
        scanf("%d %d", &fila, &columna);
    } while (fila < 0 || fila > 2 || columna < 0 || columna > 2 || matriz[fila][columna] != 0);

    matriz[fila][columna] = jugador;
}

void mostrarMatriz(int matriz[3][3]) {
system("cls");
tabla(0,0,3,3,1);
    int posx = 4;
    int posy = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {    
            int x = posx + j * 5;
            int y = posy + i * 3;
            gotoxy(x, y);
            printf("%d", matriz[i][j]);
        }
    }
    printf("\n\n\n\n");
}

int verificarGanador(int matriz[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2] && matriz[i][0] != 0) {
            return matriz[i][0];
        }
    }


    for (int i = 0; i < 3; i++) {
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i] && matriz[0][i] != 0) {
            return matriz[0][i];
        }
    }


    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2] && matriz[0][0] != 0) {
        return matriz[0][0];
    }


    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0] && matriz[0][2] != 0) {
        return matriz[0][2];
    }

    return 0;
}

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

void linea_horizontal(int x, int y, int l, int tipo){
    if (tipo==1){
        for(int i=0; i<=l; i++){
            gotoxy(x,y);
            printf("%c",(char)196);
            x++;
        }
    }
    else{
        for(int i=0; i<=l; i++){
            gotoxy(x,y);
            printf("%c",(char)205);
            x++;
        }
    }
}

void linea_vertical(int x, int y, int l, int tipo){
    if(tipo==1){
        for(int i=0; i<=l; i++){
            gotoxy(x,y);
            printf("%c",(char)179);
            y++;
        }
    }
    else{
        for(int i=0; i<=l; i++){
            gotoxy(x,y);
            printf("%c",(char)186);
            y++;
        }
    }
}

void cuadrado(int x, int y, int alto, int ancho, int tipo){
    if (tipo==1){
        linea_horizontal(x, y, ancho, tipo);
        linea_horizontal(x, y + alto, ancho, tipo);
        linea_vertical(x, y, alto, tipo);
        linea_vertical(x + ancho, y, alto, tipo);
        gotoxy(x, y);
        printf("%c", (char)218);
        gotoxy(x + ancho, y);
        printf("%c", (char)191);
        gotoxy(x, y + alto);
        printf("%c", (char)192);
        gotoxy(x + ancho, y + alto);
        printf("%c", (char)217);
    }
    else{
        linea_horizontal(x, y, ancho, tipo);
        linea_horizontal(x, y + alto, ancho, tipo);
        linea_vertical(x, y, alto, tipo);
        linea_vertical(x + ancho, y, alto, tipo);
        gotoxy(x, y);
        printf("%c", (char)201);
        gotoxy(x + ancho, y);
        printf("%c", (char)187);
        gotoxy(x, y + alto);
        printf("%c", (char)200);
        gotoxy(x + ancho, y + alto);
        printf("%c", (char)188);
    }
}

void tabla(int x, int y, int filas, int columnas, int borde){
    cuadrado(x, y, filas*3, columnas*5, borde);
    for(int i = 1; i < filas; i++){
        linea_horizontal(x, y + i*3, columnas*5, borde);
    }
    for(int i = 1; i < columnas; i++){
        linea_vertical(x + i*5, y, filas*3, borde);
    }
    if (borde==1){
        gotoxy(x, y);
        printf("%c", (char)218);
        gotoxy(x + columnas*5, y);
        printf("%c", (char)191);
        gotoxy(x, y + filas*3);
        printf("%c", (char)192);
        gotoxy(x + columnas*5, y + filas*3);
        printf("%c", (char)217);
        for(int i = 1; i < filas; i++){
            for(int j = 1; j < columnas; j++){
                gotoxy(x + j*5, y + i*3);
                printf("%c", (char)197);
            }
        }
        for(int i = 1; i < filas; i++){
            gotoxy(x, y + i*3);
            printf("%c", (char)195);
            gotoxy(x + columnas*5, y + i*3);
            printf("%c", (char)180);
        }
        for(int i = 1; i < columnas; i++){
            gotoxy(x + i*5, y);
            printf("%c", (char)194);
            gotoxy(x + i*5, y + filas*3);
            printf("%c", (char)193);
        }
    }
    else{
        gotoxy(x, y);
        printf("%c", (char)201);
        gotoxy(x + columnas*5, y);
        printf("%c", (char)187);
        gotoxy(x, y + filas*3);
        printf("%c", (char)200);
        gotoxy(x + columnas*5, y + filas*3);
        printf("%c", (char)188);
        for(int i = 1; i < filas; i++){
            for(int j = 1; j < columnas; j++){
                gotoxy(x + j*5, y + i*3);
                printf("%c", (char)206);
            }
        }
        for(int i = 1; i < filas; i++){
            gotoxy(x, y + i*3);
            printf("%c", (char)204);
            gotoxy(x + columnas*5, y + i*3);
            printf("%c", (char)185);
        }
        for(int i = 1; i < columnas; i++){
            gotoxy(x + i*5, y);
            printf("%c", (char)203);
            gotoxy(x + i*5, y + filas*3);
            printf("%c", (char)202);
        }
    }
}
