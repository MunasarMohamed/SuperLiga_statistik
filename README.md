# Superliga-statistik

Et lille C-program, der læser alle kampe fra en Superliga-sæson i en tekstfil og laver en stilling for de 12 hold.

For hvert hold tæller programmet:

- **Point**: 3 for en sejr, 1 for uafgjort, 0 for et nederlag
- **M-a-h** (mål af hold): mål, holdet selv har scoret
- **M-m-h** (mål mod hold): mål, holdet har lukket ind

## Input

Inputtet er en tekstfil med én kamp pr. linje i formatet:

```
<ugedag> <dag>/<måned> <tt>.<mm> <hjemmehold> - <udehold> <hjemmemål> - <udemål> <tilskuere>
```

Eksempel fra `kampe-2024-2025.txt`:

```
Fre     19/07 18.00     AGF - FCM     1 - 1     12456
Fre     19/07 20.00     FCN - AaB     3 - 0      3934
Son     21/07 14.00     SIF - SJF     1 - 0      4394
```

Første linje betyder: fredag den 19/7 kl. 18.00 spillede AGF hjemme mod FCM. Kampen endte 1-1 foran 12.456 tilskuere.

Repoet indeholder to datafiler:

| Fil | Sæson |
|---|---|
| `kampe-2024-2025.txt` | 2024/2025 (grundspillet, 90 kampe) |
| `kampe-2023-2024.txt` | 2023/2024 |

## Output

Når programmet kører på `kampe-2024-2025.txt`, udskriver det:

```
Klub 1  - AGF   Point: 27    M-a-h: 29    M-m-h: 15
Klub 2  - FCK   Point: 27    M-a-h: 27    M-m-h: 17
Klub 3  - FCM   Point: 27    M-a-h: 27    M-m-h: 22
Klub 4  - SIF   Point: 25    M-a-h: 28    M-m-h: 21
Klub 5  - RFC   Point: 24    M-a-h: 27    M-m-h: 18
Klub 6  - BIF   Point: 23    M-a-h: 28    M-m-h: 20
Klub 7  - FCN   Point: 23    M-a-h: 28    M-m-h: 26
Klub 8  - VFF   Point: 20    M-a-h: 28    M-m-h: 25
Klub 9  - AaB   Point: 16    M-a-h: 18    M-m-h: 30
Klub 10 - SJF   Point: 12    M-a-h: 17    M-m-h: 35
Klub 11 - LBK   Point: 10    M-a-h: 11    M-m-h: 20
Klub 12 - VB    Point: 6     M-a-h: 16    M-m-h: 35
```

AGF har altså 27 point og en målscore på 29-15.

## Kørsel

Programmet er skrevet i C og kan bygges med CMake (fx i CLion) eller direkte med gcc:

```sh
gcc main.c -o superliga
./superliga
```

Stien til datafilen står i `main.c` i kaldet til `fopen`. Ret den, så den peger på den fil, du vil læse.
