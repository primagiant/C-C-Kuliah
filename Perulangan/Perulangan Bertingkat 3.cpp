#include <cstdio>

int main()
{
    int X, Y;
     
     for( Y = 0; Y < 10; Y++)
     {
          for(X=0;X <= Y; X++)
           {
                  printf("%i ", X);
            }
            printf("\n");
    }
     return 0;
}
