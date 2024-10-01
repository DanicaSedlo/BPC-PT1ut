// Project2.cpp: Definuje vstupní bod pro aplikaci.
//

#include "Project2.h"

using namespace std;

int main()
{
    int rychlostzvuk = 340;
    int cas;
    printf("Cas v sekundach: ");
    cin >> cas;
    int vzdalenost = rychlostzvuk * cas;
    printf("Blesk je ");
    printf("%d", vzdalenost);
    printf(" metru daleko");
    return 0;
}