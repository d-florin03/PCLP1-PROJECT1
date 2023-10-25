#include <stdio.h>

int evadeaza(int a[], int p) {  /// Functie pentru verificarea evadarii
  int i, ok, voie;
  /// Parcurg prizonierii
  /// verific gasirea numarului
  for (i = 0; i < p; i++) {
    ok = 0;
    int actual = a[i];  /// actual este numarul cutiei la care ne aflam
    voie = 1;
    /// verific daca fiecare detinut isi gaseste numarul in p/2 cutii deschise
    while (voie < p / 2) {
      /// a[actual-1] reprezinta numarul
      /// din cutia cu numarul actual
      if (a[actual - 1] != i + 1) {
        actual = a[actual - 1];
        voie++;  /// cresc numarul de cutii deschise la fiecare pas
      } else {   
        /// daca un prizonier si-a gasit numarul
        /// in mai putin de p/2 cutii, trecem la urmatorul prizonier
        ok = 1;
        break;
      }
    }
    /// daca un prizonier nu si-a gasit numarul,
    /// toti au pierdut si nu evadeaza
    if (!ok) {
      return 0;
    }
  }
  return 1;  /// daca toti si-au gasit numarul evadeaza
}
int main() {
  int p, i, a[501], b[501] = {0}, c[501] = {0}, ok, nr;
  scanf("%d", &p);
  for (i = 0; i < p; i++) scanf("%d", &a[i]);
  // afisez daca evadeaza sau nu
  if (evadeaza(a, p)){
    printf("Da\n");
  }
  else{
    printf("Nu\n");
  }
  /// parcurg prizonierii
  /// nr este numarul de elemente dintr-un ciclu
  /// verific gasirea ciclului
  for (i = 0; i < p; i++) {
    nr = 0;
    ok = 0;
    b[nr] = i + 1;  /// in b retin ciclurile
    c[i + 1]++;  /// in c retin numarul de cicluri in care apare fiecare element
    int actual = a[i];  /// actual este numarul cutiei la care ne aflam

    /// cat timp nu am gasit un ciclu continui cautarea
    while (!ok && nr <= p) {
      /// daca urmatorul numar din ciclu este diferit de anteriorul
      /// il adaugam in ciclu si actualizam numarul de cicluri din care face
      /// parte
      if (b[nr] != actual) {
        b[++nr] = actual;
        c[actual]++;
      }

      if (a[actual - 1] != i + 1) {
        actual = a[actual - 1];

      } else {
        ok = 1;  /// am gasit un ciclu si ne oprim
      }
    }
    /// daca am gasit un ciclu
    if (ok == 1) {
      int j;
      /// verific daca primul element al ciclului face parte
      // dintr-un singur ciclu pana la acest moment si afisez ciclul
      if (c[i + 1] == 1) {
        for (j = 0; j <= nr; j++) {
          if (j < nr)
            printf("%d ", b[j]);
          else
            printf("%d", b[j]);
        }
        printf("\n");
      }
    }
  }
}