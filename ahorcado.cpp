#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void Base(int x, int y, int largo) {
    for(int i = 0; i < largo; i++) {
        gotoxy(x + i, y);
        printf("%c", (char)196);
    }
}

void linea_horizontal(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)179);
    }
}

void BaseSuperior(int x, int y, int largo) {
    for(int i = 0; i < largo; i++) {
        gotoxy(x + i, y);
        printf("%c", (char)196);
    }
}

void linea(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)179);
    }
}

void Cara(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)79);
    }
}

void linea2(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)179);
    }
}

void Manoderecha(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)47);
    }
}

void ManoIzquierda(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)92);
    }
}

void PieDerecho(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)47);
    }
}

void PieIzquierdo(int x, int y, int alto) {
    for(int i = 0; i < alto; i++) {
        gotoxy(x, y + i);
        printf("%c", (char)92);
    }
}

char Palabras[10][15] = {"Colombia", "Ecuador", "Venezuela", "Bolivia", "Argentina", "Brasil", "Chile", "Uruguay", "Paraguay", "Peru"};
char Cad1[15];
char Cad2[15];

int Aleatorio(int n) {
    return(rand() % n);
}

void SeleccionarPalabra() {
    int n, t;
    n = Aleatorio(10);
    strcpy(Cad1, Palabras[n]);
    t = strlen(Cad1);
    for(int i = 0; i < t; i++) {
        Cad2[i] = '-';
    }
    printf("%s\n", Cad2);
}

int AdivinarLetra() {
    char letra;
    printf("Ingrese una letra: ");
    scanf(" %c", &letra); // Espacio antes de %c para ignorar el carácter de nueva línea
    int aciertos = 0;
    for(int i = 0; i < strlen(Cad1); i++) {
        if (letra == Cad1[i]) {
            Cad2[i] = letra;
            aciertos++;
        }
    }
    printf("%s\n", Cad2);
    return aciertos;
}

int main() {
    srand(time(NULL));
    SeleccionarPalabra();
    int intentos = 6;
    while (intentos > 0) {
        int aciertos = AdivinarLetra();
        if (strcmp(Cad1, Cad2) == 0) {
            printf(" Has adivinado la palabra: %s\n", Cad1);
            break;
        }
        if (aciertos == 0) {
            intentos--;
            printf("Te quedan %d intentos.\n", intentos);
            
            switch(intentos) {
                case 5:
                    Manoderecha(21, 8, 1);
                    break;
                case 4:
                    ManoIzquierda(23, 8, 1);
                    break;
                case 3:
                    PieDerecho(21, 7, 1);
                    break;
                case 2:
                    PieIzquierdo(23, 7, 1);
                    break;
                case 1:
                    linea2(22, 7, 1);
                    break;
                case 0:
                    Cara(22, 6, 1);
                    break;
            }
        }
    }
    linea(22,5,1);
    BaseSuperior(14,4,8);
    linea_horizontal(13,5,5);
	Base(8,9,10);
    return 0;
}
