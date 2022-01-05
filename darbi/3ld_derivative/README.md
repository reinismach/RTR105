#include <stdio.h>

#include <math.h>

double af(double x)
{
    
    return sin(x/2);
}

double af1(double x)
{
    
    return cos(x/2)/2;
}

double af2(double x)
{
    
    return -sin(x/2)/4;
}

int main()
{
    
    double a, b, delta_x;
    
    int el;

    printf("Lūdzu, ievadiet minimuma robežas vērtību: ");
    fflush(stdout);
    scanf("%lf", &a);

    printf("Lūdzu, ievadiet maksimuma robežas vērtību: ");
    fflush(stdout);
    scanf("%lf", &b);

    printf("Lūdzu, ievadiet precizitātes vērtību: ");
    fflush(stdout);
    scanf("%lf", &delta_x);

    el = (b-a)/delta_x;

    printf("el vērtība = %d\n", el);

    double arg[el], f[el], df1[el-1], df2[el-2], x;
    int n;

    for(n=0 ; n<el ; n++)
    {
        arg[n] = a + n*delta_x;
        f[n] = af(arg[n]);
    }

    for(n=0 ; n<el-1 ; n++)
    {
        df1[n] = (af(arg[n+1])-af(arg[n]))/delta_x;
    }
    
    for(n=0 ; n<el-2 ; n++)
    {
        df2[n] = (df1[n+1]-df1[n])/delta_x;
    }
    
    printf("|%13s||%13s||%13s|%13s|%13s|%13s|\n" "x", "f", "f\'", "f\'", "f\'\'", "f\'\'");
    printf("|%13s||%13s||%13s|%13s|%13s|%13s|\n", " ", " ", "analītiskais", "diferencēšana", "analītiskais", "diferencēšana");
    for(n=0; n<el-2 ; n++)
    {
        printf("|%13.3lf||%13.3lf||%13.3lf|%13.3lf|%13.3lf|%13.3lf|\n", arg[n], f[n], af1(arg[n]), df1[n], af2(arg[n]), df2[n]);
    }
    printf("|%13.3lf||%13.3lf||%13.3lf|%13.3lf|%13.3lf|%13s|\n", arg[n], f[n], af1(arg[n]), df1[n], af2(arg[n]), "nav");
    n++;
    printf("|%13.3lf||%13.3lf||%13.3lf|%13s|%13.3lf|%13s|\n", arg[n], f[n], af1(arg[n]), "nav", af2(arg[n]), "nav");

    return 0;
}