Šī programma atrod izvēlētās x vērtības funkcijas vērtību funkcijas definīcijas apgabalā. Šajā metodē tiek salīdzināts rezultāts no Teilora rindām un parastās funkcijas. Grafikā var redzēt, ka palielinoties Teilora rindas kārtas skaitlim, funkcija arvien garāku gabalu ir vienāda ar pētāmo funkciju. Manā gadījumā pētāmā funkcija bija sin(x/2).

Kods:
```
#include <stdio.h>
#include <math.h>
int main()
{
    long double a499, a500;
    double x, a0, S0, S499, S500;
    int k=0;

    printf("Lūdzu, ievadiet x vērtību: ");
    fflush(stdin);
    scanf("%lf", &x);

    printf("\nSummas izteiksme: \n\n");
    printf("               500\n");
    printf("              _____\n");
    printf("              %c           k     2*k+1     -2*k-1\n",92);
    printf("               %c      (-1)  *  x      *  2\n",92);
    printf("sin(%.2lf/2) =   >    ___________________________\n", x);
    printf("               /\n");
    printf("              /____             (2*k+1)!\n");
    printf("               k=0\n\n");
    
    printf("Rekurences funkcionālā reizinātāja izteiksme: \n\n");
    printf("            2     -2\n");
    printf("    (-1) * x  *  2\n");
    printf("  ____________________\n");
    printf(" \n");
    printf("    (2*k) * (2*k+1)\n\n");

    printf("funkcijas definīcijas apgabals: x∈ R \n\n");

    a0 = pow(-1,0)*pow(x,2*0+1)*pow(2,-2*0-1)/(1.);
    S0 = a0;
    printf("a0   = %.2lf\t\tS0   = %.2lf\n", a0,S0);

    a499 = a0;
    S499 = S0;
    while(k<499)
    {
        k++;
        a499 *= (-1) *x*x * pow(2,-2) / ((2*k)*(2*k+1));
        S499 += a499;
    }
    printf("a499 = %Le\tS499 = %lf\n", a499, S499);

    a500 = a499 * (-1) *x*x * pow(2,-2) / ((2*500)*(2*500+1));
    S500 = S499 + a500;
    printf("a500 = %Le\tS500 = %lf\n", a500, S500);

    printf("Funkcijas vērtība izmantojot Teilora rindas izteiksmi = %lf\n", S500);
    
    double f1 = sin(x/2);
    printf("Funkcijas vērtība, izmantojot funkcijas izteiksmi = %lf\n", f1);

    return 0;
}
```
Rezultāts:

<img width="786" alt="Screenshot 2022-01-11 at 11 24 02" src="https://user-images.githubusercontent.com/90239563/148916450-2c7be853-fad3-4fda-a252-2ca70389d194.png">
https://user-images.githubusercontent.com/90239563/148916450-2c7be853-fad3-4fda-a252-2ca70389d194.png

Grafiks:

![LD1_grafiks](https://user-images.githubusercontent.com/90239563/148989394-49f98dfc-4391-4a6f-ac59-55aa41ec4616.png)
https://user-images.githubusercontent.com/90239563/148989394-49f98dfc-4391-4a6f-ac59-55aa41ec4616.png

Gnuplot script:
```
# Scale font and line width (dpi) by changing the size! It will always display stretched.
set terminal svg size 600,400 enhanced fname 'arial'  fsize 10 butt solid
set output 'out.svg'

# Key means label...
set key inside bottom right
set xlabel 'x'
set ylabel 'y'
set title 'sin(x/2) un teilora rindas'
set grid
plot [-8:8] [-1.1:1.1] sin(x/2), x/2, x/2-x**3/48, x/2-x**3/48+x**5/3840, '-' w p ls 1
3 0.997495
```
md faila skats iekšpusē: https://raw.githubusercontent.com/reinismach/RTR105/main/darbi/1ld_series/README.md
