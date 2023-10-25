#include <stdio.h>
#include <string.h>

void adunare(char a[], char b[], int n) {
  int t = 0;
  int i, j;
  /// adun partile reale de acelasi semn
  if (a[0] == b[0]) {
    for (i = (n - 1) / 2 - 1; i >= 1; i--) {
      t += (int)(a[i] - '0') + (int)(b[i] - '0');
      a[i] = t % 10 + '0';
      t /= 10;
    }
  }
  t = 0;  /// adun partile imaginare de acelasi semn
  if (a[(n - 1) / 2] == b[(n - 1) / 2]) {
    for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
      t += (int)(a[i] - '0') + (int)(b[i] - '0');
      a[i] = t % 10 + '0';
      t /= 10;
    }
  }
  /// adun partile reale de semne diferite
  if (a[0] != b[0]) {
    int k = 1;  /// verific care dintre numere este mai mare
    while (a[k] == b[k] && k < (n - 1) / 2 - 1) {
      k++;
    }
    /// daca primul numar este mai mare
    /// calculez diferenta in primul vector
    if (a[k] >= b[k]) {
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (a[i] >= b[i])
          a[i] = ((int)(a[i] - '0') - (int)(b[i] - '0')) + '0';
        else {
          j = i - 1;
          while (a[j] == '0') {
            a[j--] = '9';
          }
          a[j] = ((a[j] - '0') - 1) + '0';
          a[i] = (10 + (a[i] - '0') - (b[i] - '0')) + '0';
        }
      }
    }
    /// daca al doilea este mai mare calculez
    /// in al doilea si copiez dupa in primul
    else {
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (b[i] >= a[i])
          b[i] = ((int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        else {
          j = i - 1;
          while (b[j] == '0') b[j--] = '9';
          b[j] = ((int)(b[j] - '0') - 1) + '0';
          b[i] = (10 + (int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        }
      }
      /// copiez rezultatul din al doilea vector in primul
      /// cu tot cu semn
      for (i = 0; i <= (n - 1) / 2 - 1; i++) {
        a[i] = b[i];
      }
    }
    int ok = 0;  /// verific cazul in care toate cifrele sunt 0
    /// ca sa pun semnul "+"
    for (i = 1; i <= (n - 1) / 2 - 1 && ok == 0; i++)
      if (a[i] != 0) ok = 1;
    if (!ok) {
      if (a[0] == '1') a[0] = '0';
    }
  }
  /// adun partile imaginare de semne diferite
  if (a[(n - 1) / 2] != b[(n - 1) / 2]) {
    int k = (n - 1) / 2 + 1;
    /// verific care dintre numere este mai mare
    while (a[k] == b[k] && k < n - 2) {
      k++;
    }
    /// daca primul numar este mai mare
    /// calculez diferenta in primul vector
    if (a[k] >= b[k]) {
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (a[i] >= b[i])
          a[i] = ((int)(a[i] - '0') - (int)(b[i] - '0')) + '0';
        else {
          j = i - 1;
          while (a[j] == '0') a[j--] = '9';
          a[j] = ((a[j] - '0') - 1) + '0';
          a[i] = (10 + (a[i] - '0') - (b[i] - '0')) + '0';
        }
      }
    }
    /// daca al doilea este mai mare calculez
    /// in al doilea si copiez dupa in primul
    else {
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (b[i] >= a[i])
          b[i] = ((int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        else {
          j = i - 1;
          while (b[j] == '0') b[j--] = '9';
          b[j] = ((int)(b[j] - '0') - 1) + '0';
          b[i] = (10 + (int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        }
      }
      /// copiez rezultatul din al doilea vector in primul
      /// cu tot cu semn
      for (i = (n - 1) / 2; i <= n - 2; i++) a[i] = b[i];
    }
    int ok = 0;
    /// verific cazul in care toate cifrele sunt 0
    ///  ca sa pun semnul "+"
    for (i = (n - 1) / 2 + 1; i <= n - 2 && ok == 0; i++)
      if (a[i] != '0') ok = 1;
    if (!ok) {
      if (a[(n - 1) / 2] == '1') a[(n - 1) / 2] = '0';
    }
  }
}

void scadere(char a[], char b[], int n) {
  int i, j;
  if (a[0] == b[0])  /// scad partile reale de acelasi semn
  {
    int k = 1;
    /// verific care dintre numere este mai mare
    while (a[k] == b[k] && k < (n - 1) / 2 - 1) {
      k++;
    }
    /// daca primul este mai mare calculez in primul vector
    if (a[k] >= b[k]) {
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (a[i] >= b[i])
          a[i] = ((int)(a[i] - '0') - (int)(b[i] - '0')) + '0';
        else {
          j = i - 1;
          while (a[j] == '0') a[j--] = '9';
          a[j] = ((a[j] - '0') - 1) + '0';
          a[i] = (10 + (a[i] - '0') - (b[i] - '0')) + '0';
        }
      }
    } else {  /// daca al doilea este mai mare calculez in al doilea
      /// si copiez dupa in primul cu semn schimbat
      for (i = (n - 1) / 2 - 1; i >= 1; i--) {
        if (b[i] >= a[i])
          b[i] = ((int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        else {
          j = i - 1;
          while (b[j] == '0') b[j--] = '9';
          b[j] = ((int)(b[j] - '0') - 1) + '0';
          b[i] = (10 + (int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        }
      }
      /// schimb semnul
      if (b[0] == '0')
        a[0] = '1';
      else
        a[0] = '0';
      /// copiez in primul vector
      for (i = 1; i <= (n - 1) / 2 - 1; i++) a[i] = b[i];
    }
  } else {  /// scad partile reale de semne diferite
    /// care inseamna adunarea fara semn
    /// si pastrarea semnului initial
    int t = 0;
    for (i = (n - 1) / 2 - 1; i >= 1; i--) {
      t += (int)(a[i] - '0') + (int)(b[i] - '0');
      a[i] = t % 10 + '0';
      t /= 10;
    }
  }

  /// scad partile imaginare de semne diferite
  /// care inseamna adunarea fara semn
  /// si pastrarea semnului initial
  if (a[(n - 1) / 2] != b[(n - 1) / 2]) {
    int t = 0;
    for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
      t += (int)(a[i] - '0') + (int)(b[i] - '0');
      a[i] = t % 10 + '0';
      t /= 10;
    }
  } else {  /// scad partile imaginare de acelasi semn
    int k = (n - 1) / 2 + 1;
    /// verific care numar e mai mare
    while (a[k] == b[k] && k < n - 2) {
      k++;
    }
    // daca primul numar e mai mare calculez in primul vector
    if (a[k] >= b[k]) {
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (a[i] >= b[i])
          a[i] = ((int)(a[i] - '0') - (int)(b[i] - '0')) + '0';
        else {
          j = i - 1;
          while (a[j] == '0') a[j--] = '9';
          a[j] = ((a[j] - '0') - 1) + '0';
          a[i] = (10 + (a[i] - '0') - (b[i] - '0')) + '0';
        }
      }
    } else {  /// daca al doliea numar e mai mare
      /// calculez in al doilea vector si copiez
      /// in primul cu semn schimbat
      for (i = n - 2; i >= (n - 1) / 2 + 1; i--) {
        if (b[i] >= a[i])
          b[i] = ((int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        else {
          j = i - 1;
          while (b[j] == '0') b[j--] = '9';
          b[j] = ((int)(b[j] - '0') - 1) + '0';
          b[i] = (10 + (int)(b[i] - '0') - (int)(a[i] - '0')) + '0';
        }
      }
      /// schimb semnul
      if (b[(n - 1) / 2] == '0'){
        a[(n - 1) / 2] = '1';
      }
      else{
        a[(n - 1) / 2] = '0';
      }
      /// copiez in primul vector
      for (i = (n - 1) / 2 + 1; i <= n - 2; i++) {
        a[i] = b[i];
      }
    }
  }
}

int main() {
  int n;
  char a[1001], b[1001], c;
  scanf("%d", &n);
  scanf("%s", a);
  scanf(" %c", &c);
  /// citesc pana cand intalnesc numarul 0
  while (c != '0') {
    scanf(" %s", b);
    /// daca semnul e + atunci adun numerele
    if (c == '+') {
      adunare(a, b, n);
    } else {  /// daca semnul e minus atunci scad numerele
      scadere(a, b, n);
    }
    scanf(" %c", &c);
    printf("%s\n", a);
  }
}