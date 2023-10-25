#include <stdio.h>
#include <string.h>

void codificareA(char mat[][51], int l, int nrlinii) {
  /// functie pentru codificareA
  /// care sorteaza cheia ce reprezinta linia 0 din matrice si
  /// interschimba coloanele matricei in functie de cheie
  int i, j, k;
  char aux;
  for (i = 0; i < l - 1; i++)
    for (j = i + 1; j < l; j++)
      if (mat[0][i] > mat[0][j]) {
        for (k = 0; k <= nrlinii; k++) {
          aux = mat[k][i];
          mat[k][i] = mat[k][j];
          mat[k][j] = aux;
        }
      }
}

void codificareB(char text[501], int cheieB) {
  /// functie pentru codificareB
  int i, j;
  char aux;
  int n = strlen(text);
  /// mut textul cu cheieB pozitii la dreapta
  for (i = 0; i < cheieB; i++) {
    aux = text[n - 1];
    for (j = n - 2; j >= 0; j--) {
      text[j + 1] = text[j];
    }
    /// modific caracterele mutate la inceputul sirului
    /// cum se precizeaza in enunt
    if (aux >= 'a' && aux <= 'z') {
      if (aux + cheieB <= 'z')
        text[0] = aux + cheieB;
      else
        text[0] = 'A' + (cheieB - ('z' - aux) - 1);
    } else if (aux >= 'A' && aux <= 'Z') {
      if (aux + cheieB <= 'Z')
        text[0] = aux + cheieB;
      else
        text[0] = 'a' + (cheieB - ('Z' - aux) - 1);
    } else {
      text[0] = aux;
    }
  }
}
void decodificareB(char text[501], int cheieB) {
  /// functie pentru decodificareB
  int i, j;
  char aux;
  int n = strlen(text);
  /// mut textul cu cheieB pozitii la stanga
  for (i = 0; i < cheieB; i++) {
    aux = text[0];
    for (j = 0; j <= n - 2; j++) {
      text[j] = text[j + 1];
    }
    /// modific caracterele mutate la sfarsitul sirului
    /// cum se precizeaza in enunt
    if (aux >= 'a' && aux <= 'z') {
      if (aux - cheieB >= 'a')
        text[n - 1] = aux - cheieB;
      else
        text[n - 1] = 'Z' - (cheieB - (aux - 'a') - 1);
    } else if (aux >= 'A' && aux <= 'Z') {
      if (aux - cheieB >= 'A')
        text[n - 1] = aux - cheieB;
      else
        text[n - 1] = 'z' - (cheieB - (aux - 'A') - 1);
    } else {
      text[n - 1] = aux;
    }
  }
}
void decodificareA(char cheie[51], int l, int v[51]) {
  /// functie pentru decodificareA
  int i, j;
  char aux1;
  int aux2;
  /// sortez cheia si in functie de ea
  /// sortez vectorul de retinere a pozitiilor, v
  for (i = 0; i < l - 1; i++)
    for (j = i + 1; j < l; j++) {
      if (cheie[i] > cheie[j]) {
        aux1 = cheie[i];
        cheie[i] = cheie[j];
        cheie[j] = aux1;
        aux2 = v[i];
        v[i] = v[j];
        v[j] = aux2;
      }
    }
}

void sortaredecodificareA(char mat[][51], int l, int nrlinii, int v[51]) {
  int i, j, k;
  char aux1;
  int aux2;
  /// sortez vectorul de pozitii
  /// si interschimb coloanele matricei in functie de v
  for (i = 0; i < l - 1; i++)
    for (j = i + 1; j < l; j++)
      if (v[i] > v[j]) {
        aux2 = v[i];
        v[i] = v[j];
        v[j] = aux2;
        for (k = 0; k <= nrlinii; k++) {
          aux1 = mat[k][i];
          mat[k][i] = mat[k][j];
          mat[k][j] = aux1;
        }
      }
}

int main() {
  char text[100], cheie[51], mat[250][51], cerinta[20];
  int cheieB, i, j, l, k, lgtext, nrlinii;

  scanf("%[^\n]s", text);
  scanf(" %s", cerinta);
  lgtext = strlen(text);

  while (strcmp(cerinta, "STOP") != 0) {
    /// daca cerinta este CodificareA
    if (cerinta[10] == 'A') {
      scanf(" %[^\n]s", cheie);
      l = strlen(cheie);
      // introduc cheia pe linia 0 din matrice
      for (i = 0; i < l; i++) {
        mat[0][i] = cheie[i];
      }
      // calculez numarul de linii din matrice
      nrlinii = lgtext / l + (lgtext % l != 0);
      k = 0;
      /// introduc textul in matrice asa cum se spune in enunt
      /// in functie de cheie
      for (i = 1; i <= nrlinii; i++) {
        for (j = 0; j < l; j++) {
          if (k < lgtext) {
            mat[i][j] = text[k];
            k++;
          }
        }
      }
      /// daca textul nu acopera toata matricea
      /// ocup casutele cu spatii
      for (j = k; j < nrlinii * l; j++) {
        mat[nrlinii][j % l] = ' ';
      }
      codificareA(mat, l, nrlinii);
      /// introduc in sirul text noul text
      /// care se obtine prin parcurgerea matricei ordonate
      k = 0;
      for (j = 0; j < l; j++) {
        for (i = 1; i <= nrlinii; i++) text[k++] = mat[i][j];
      }
      /// lungimea textului este actualizata, adaugandu-se si numarul
      /// de spatii din matrice care au fost introduse
      lgtext = k;
      text[k] = '\0';
      printf("%s\n", text);
    }
    /// daca cerinta este CodificareB
    else if (cerinta[10] == 'B') {
      scanf(" %d", &cheieB);
      codificareB(text, cheieB);
      printf("%s\n", text);
    }
    /// daca cerinta este DecodificareB
    else if (cerinta[12] == 'B') {
      scanf(" %d", &cheieB);
      decodificareB(text, cheieB);
      printf("%s\n", text);
    }
    /// daca ceinta este DecodificareA
    else if (cerinta[12] == 'A') {
      scanf(" %[^\n]s", cheie);
      l = strlen(cheie);
      lgtext = strlen(text);
      /// adaug cheia pe linia 0 din matrice
      for (i = 0; i < l; i++) {
        mat[0][i] = cheie[i];
      }
      /// calculez numarul de linii ale matricei
      nrlinii = lgtext / l + (lgtext % l != 0);
      int v[51];
      /// initializez vectorul de pozitii al cheii
      for (i = 0; i < l; i++) v[i] = i;
      decodificareA(cheie, l, v);
      k = 0;
      /// introduc in matrice textul pe coloane
      /// si aduc spatii la sfarsit daca matricea nu e completa
      for (j = 0; j < l; j++)
        for (i = 0; i < nrlinii; i++)
          if (k < lgtext)
            mat[i][j] = text[k++];
          else {
            mat[i][j] = ' ';
          }

      sortaredecodificareA(mat, l, nrlinii, v);

      k = 0;
      /// introduc in text sirul
      for (i = 0; i < nrlinii; i++)
        for (j = 0; j < l; j++) text[k++] = mat[i][j];

      /// actualizez lungimea textului cu tot cu spatiile introduse
      lgtext = k;
      text[k] = '\0';
      printf("%s\n", text);
    }

    scanf(" %s", cerinta);
  }
}