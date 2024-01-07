#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
    // Sprawdź, czy macierz jest kwadratowa i ma taki sam rozmiar jak wektor b
    if (mat->r != mat->c || mat->r != b->r) {
        return 2; // Błąd nieprawidłowych rozmiarów macierzy
    }
    int n = mat->r; // Rozmiar macierzy i wektorów
    int i, j; // Zmienne indeksowe
    double sum; // Zmienna pomocnicza do przechowywania sumy iloczynów
    for (i = n - 1; i >= 0; i--) { // Pętla po wierszach macierzy od dołu
        sum = b->data[i][0]; // Przypisz wartość wektora b do sumy
        for (j = i + 1; j < n; j++) { // Pętla po kolumnach macierzy od prawej
            sum -= mat->data[i][j] * x->data[j][0]; // Odejmij iloczyn elementu macierzy i zmiennej x od sumy
        }
        // Sprawdź, czy element na diagonali jest różny od zera
        if (mat->data[i][i] != 0) {
            x->data[i][0] = sum / mat->data[i][i]; // Podziel sumę przez element na diagonali i przypisz do zmiennej x
        }
        else {
            return 1; // Błąd dzielenia przez zero
        }
    }
    return 0; // Wsteczne podstawienie zakończone sukcesem
}


