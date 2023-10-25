#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// folosesc o structura in care retin proprietatile unei masini
typedef struct {
  char *brand, *numar, *combustibil;
  double consum;
  int km;
} masina;

void calculnrmasini(masina* v, int nr[4], int n) {
  /// functie pentru calcularea numarului de masini in functie de
  /// combustibilul cu care functioneaza
  int i;
  for (i = 0; i < n; i++) {
    if (strcmp((v + i)->combustibil, "benzina") == 0)
      nr[0]++;
    else if (strcmp((v + i)->combustibil, "motorina") == 0)
      nr[1]++;
    else if (strcmp((v + i)->combustibil, "hibrid") == 0)
      nr[2]++;
    else if (strcmp((v + i)->combustibil, "electric") == 0)
      nr[3]++;
  }
}

void calculconsum(masina* v, double consumt[21], int n) {
  /// functie pentru calculul numarului de litri de combustibil consumati
  /// de fiecare producator
  int i, j, ok;
  int nrmasinidif = 0;
  /// in consumt calculez consumul fiecarui brand
  for (i = 0; i < n; i++) {
    /// daca intalnesc un nou brand cresc numarul de masini diferite
    /// si adun consumul masinii curente
    if (strcmp((v + i)->brand, "1") != 0) {
      consumt[++nrmasinidif] = (double)(((v + i)->consum * (v + i)->km) / 100);
      ok = 1;
    } else
      ok = 0;
    /// daca brandul era nou cautam acelasi brand si adunam consumul
    /// si schimbam numele brandului pentru a nu il accesa din nou
    for (j = i + 1; j < n && ok == 1; j++) {
      if (strcmp((v + i)->brand, (v + j)->brand) == 0) {
        consumt[nrmasinidif] = consumt[nrmasinidif] +
                               (double)(((v + j)->consum * (v + j)->km) / 100);
        (v + j)->brand = "1";
      }
    }
  }
}

int verificarenrcorect(masina* v, int n) {
  /// functie pentru a verifica daca masinile au numarul de inmatriculare corect
  int i, j, ok, l, nr1 = 0, nr2 = 0, nrcif = 0, oktot = 1;
  /// parcurg toate numerele
  for (i = 0; i < n; i++) {
    nr1 = 0;
    nrcif = 0;
    nr2 = 0;
    l = strlen((v + i)->numar);
    j = 0;
    /// nr1 reprezinta numarul de litere de la inceputul numarului de
    /// inmatriculare nrcif reprezinta numarul de cifre din interior nr2
    /// reprezinta numarul de litere de la sfarsit
    while (j < l && (v + i)->numar[j] >= 'A' && (v + i)->numar[j] <= 'Z') {
      nr1++;
      j++;
    }
    while (j < l && (v + i)->numar[j] >= '0' && (v + i)->numar[j] <= '9') {
      nrcif++;
      j++;
    }
    while (j < l && (v + i)->numar[j] >= 'A' && (v + i)->numar[j] <= 'Z') {
      nr2++;
      j++;
    }

    /// verific daca caracteristicile corespund unui numar corect
    if (nr1 == 1 || nr1 == 2) {
      if (nrcif == 2 || nrcif == 3) {
        if (nr2 == 3)
          ok = 1;
        else {
          ok = 0;
        }
      } else {
        ok = 0;
      }
    } else {
      ok = 0;
    }

    /// daca un singur numar nu este corect atunci nu toate sunt corecte
    if (oktot == 1 && ok == 0) {
      oktot = ok;
    }
    /// daca o masina nu avea numarul ii schimbam combustibilul pentru a putea
    /// sa afisez corect la final
    if (ok == 0) {
      (v + i)->combustibil = "1";
    }
  }

  return oktot;
}
int main() {
  char cer;
  int i, n, nr[4] = {0};
  double consumt[101] = {0.0};
  scanf("%d", &n);

  masina* v;
  /// aloc memorie pentru v
  v = (masina*)malloc(n * sizeof(masina));
  /// aloc memorie si citesc valorile la adresa respectiva
  for (i = 0; i < n; i++) {
    (v + i)->brand = (char*)malloc(21 * sizeof(char));
    (v + i)->numar = (char*)malloc(8 * sizeof(char));
    (v + i)->combustibil = (char*)malloc(8 * sizeof(char));
    scanf("%s", (v + i)->brand);
    scanf(" %s", (v + i)->numar);
    scanf(" %s", (v + i)->combustibil);
    scanf("%lf %d", &(v + i)->consum, &(v + i)->km);
  }

  scanf(" %c", &cer);
  if (cer == 'a') {
    calculnrmasini(v, nr, n);
    printf("benzina - %d\n", nr[0]);
    printf("motorina - %d\n", nr[1]);
    printf("hibrid - %d\n", nr[2]);
    printf("electric - %d\n", nr[3]);
  } else if (cer == 'b') {
    int nrmasinidif = 0;
    calculconsum(v, consumt, n);
    /// afisez consumul si costul pentru fiecare brand separat
    /// in functie de combustibil
    for (i = 0; i < n; i++) {
      if (strcmp((v + i)->brand, "1") != 0) {
        if (strcmp((v + i)->combustibil, "benzina") == 0) {
          ++nrmasinidif;
          printf("%s a consumat %.2lf - %.2lf lei\n", (v + i)->brand, consumt[nrmasinidif], consumt[nrmasinidif] * 8.02);
        } else if (strcmp((v + i)->combustibil, "motorina") == 0) {
          ++nrmasinidif;
          printf("%s a consumat %.2lf - %.2lf lei\n", (v + i)->brand, consumt[nrmasinidif], consumt[nrmasinidif] * 9.29);
        } else if (strcmp((v + i)->combustibil, "hibrid") == 0) {
          ++nrmasinidif;
          printf("%s a consumat %.2lf - %.2lf lei\n", (v + i)->brand, consumt[nrmasinidif], consumt[nrmasinidif] * 8.02);
        } else if (strcmp((v + i)->combustibil, "electric") == 0) {
          ++nrmasinidif;
          printf("%s a consumat %.2lf - %.2lf lei\n", (v + i)->brand, consumt[nrmasinidif], consumt[nrmasinidif]);
        }
      }
    }
  } else {  // cerinta c
    /// daca toate masinile au numere corecte afisez mesajul cerut
    if (verificarenrcorect(v, n) == 1) {
      printf("Numere corecte!\n");
    } else {  /// daca nu toate au numere corecte afisez mesajul pentru fiecare
      /// care are numar gresit
      for (i = 0; i < n; i++) {
        if (strcmp((v + i)->combustibil, "1") == 0) {
          printf("%s cu numarul %s: numar invalid\n", (v + i)->brand, (v + i)->numar);
        }
      }
    }
  }
}