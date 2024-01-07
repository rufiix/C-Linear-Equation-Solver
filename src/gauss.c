#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    // Sprawdź, czy macierz jest kwadratowa i ma taki sam rozmiar jak wektor b
    if (mat->r != mat->c || mat->r != b->r) {
        return 2; // Błąd nieprawidłowych rozmiarów macierzy
    }
    int n = mat->r; // Rozmiar macierzy i wektorów
    int i, j, k; // Zmienne indeksowe
    float c; // Zmienna pomocnicza do przechowywania współczynnika
    for (j = 0; j < n - 1; j++) { // Pętla po kolumnach macierzy
        // Sprawdź, czy element na diagonali jest różny od zera
        if (mat->data[j][j] != 0) {
            for (i = j + 1; i < n; i++) { // Pętla po wierszach macierzy poniżej diagonali
                c = mat->data[i][j] / mat->data[j][j]; // Oblicz współczynnik
                for (k = j; k < n + 1; k++) { // Pętla po kolumnach macierzy od lewej
                    // Odejmij wielokrotność wiersza j od wiersza i
                    if (k < n) {
                        mat->data[i][k] = mat->data[i][k] - c * mat->data[j][k];
                    }
                    else {
                        b->data[i][0] = b->data[i][0] - c * b->data[j][0];
                    }
                }
            }
        }
        else {
            return 1; // Błąd macierzy osobliwej - dzielenie przez zero
        }
    }
    return 0; // Eliminacja zakończona sukcesem
}
