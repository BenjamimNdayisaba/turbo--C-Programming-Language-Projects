#include <stdio.h>
#include <stdlib.h>

int main()
{
   float SecretNumber = 007;
   int guess;
   while (guess != SecretNumber) {

    printf ("Enter the number: ");
    scanf("%d", &guess);

   }
   return 0;
}
