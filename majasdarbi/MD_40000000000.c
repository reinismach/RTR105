
    #include <stdio.h>

    int main()

    {

    int a;

    long long int c, b;


    printf("Lietotāj, ievadiet skaitli četri simti tūkstoši: ");

    scanf("%d", &a);

    printf("Lietotāj, ievadiet skaitli simts tūkstoši: ");

    scanf("%lli", &b);

    c = a*b;

    printf("Rezultāts pēc ievadīto skaitļu reizināšanas: %lli \n", c);

    return 0;

    }
