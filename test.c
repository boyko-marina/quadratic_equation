#include <TXLib.h>
#include <stdio.h>

int main( )
{


    //char str[] = "12345.56";
    char c;
    double d;
    while ((c = getchar()) != EOF)
    {
        sscanf(c, "%lf", &d);
        printf("%lf", d);
    }


    //double a, b, c;
    //int d;
    //while ((d = getchar()) != EOF)
    //{
    //    if (d !=
    //}
    //a = b = c = 0;
    //scanf("%lg %lg %lg", &a, &b, &c);
    //printf("%lg\n", a);
}
