#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INTERPRET_SIZE 100
#define NAZEV_SIZE 100

struct t_album {
    char interpret[INTERPRET_SIZE];
    char nazev[NAZEV_SIZE];
    int rok;
    struct t_album* dalsi;
};

struct t_album* prvni = NULL;

void add(char* interpret, char* nazev, int rok, struct t_album** uk_prvni)
{
    struct t_album* noveAlbum;
    struct t_album* aktAlbum;

    noveAlbum = (struct t_album*)malloc(sizeof(struct t_album));
    if (noveAlbum == NULL) {
        printf("Chyba: Nepodarilo se alokovat pamet pro nove album.\n");
        return;
    }

    strcpy(noveAlbum->interpret, interpret);
    strcpy(noveAlbum->nazev, nazev);
    noveAlbum->rok = rok;
    noveAlbum->dalsi = NULL;

    if (*uk_prvni == NULL)
    {
        *uk_prvni = noveAlbum;
        return;
    }
    else if (strcmp(noveAlbum->interpret, (*uk_prvni)->interpret) < 0)
    {
        noveAlbum->dalsi = *uk_prvni;
        *uk_prvni = noveAlbum;
        return;
    }

    aktAlbum = *uk_prvni;
    while (aktAlbum)
    {
        if (aktAlbum->dalsi == NULL)
        {
            aktAlbum->dalsi = noveAlbum;
            return;
        }
        else if (strcmp(noveAlbum->interpret, aktAlbum->dalsi->interpret) < 0)
        {
            noveAlbum->dalsi = aktAlbum->dalsi;
            aktAlbum->dalsi = noveAlbum;
            return;
        }
        aktAlbum = aktAlbum->dalsi;
    }
}

void del(char* interpret, char* nazev, struct t_album** uk_prvni)
{
    struct t_album* aktAlbum;
    struct t_album* predchozi = NULL;

    aktAlbum = *uk_prvni;

    while (aktAlbum != NULL)
    {
        if (strcmp(aktAlbum->interpret, interpret) == 0 && strcmp(aktAlbum->nazev, nazev) == 0)
        {
            if (predchozi == NULL)
            {
                *uk_prvni = aktAlbum->dalsi;
            }
            else
            {
                predchozi->dalsi = aktAlbum->dalsi;
            }
            free(aktAlbum);
            printf("Album bylo uspesne smazano.\n");
            return;
        }
        predchozi = aktAlbum;
        aktAlbum = aktAlbum->dalsi;
    }

    printf("Album nebylo nalezeno.\n");
}

void ShowAlbums(struct t_album* uk_prvni)
{
    char zacatek;
    printf("\nZadejte pocatecni pismeno interpreta: ");
    scanf(" %c", &zacatek);
    while (getchar() != '\n');

    struct t_album* aktAlbum = uk_prvni;
    printf("\n\n");
    while (aktAlbum)
    {
        if (tolower(aktAlbum->interpret[0]) == tolower(zacatek))
        {
            printf("%s - %s (%d)\n", aktAlbum->interpret, aktAlbum->nazev, aktAlbum->rok);
        }
        aktAlbum = aktAlbum->dalsi;
    }
    printf("\nStisknete libovolnou klavesu pro pokracovani...\n");
    getchar();
}

void ShowAllAlbums(struct t_album* uk_prvni)
{
    struct t_album* aktAlbum = uk_prvni;
    printf("\nSeznam vsech alb:\n\n");
    while (aktAlbum)
    {
        printf("%s - %s (%d)\n", aktAlbum->interpret, aktAlbum->nazev, aktAlbum->rok);
        aktAlbum = aktAlbum->dalsi;
    }
    printf("\nStisknete libovolnou klavesu pro pokracovani...\n");
    getchar();
}

int main()
{
    char  cmd;

    do
    {
        system("cls");
        printf("A: Pridat     ");
        printf("D: Smazat     ");
        printf("F: Hledat     ");
        printf("S: Vsechna alba     ");
        printf("Q: Konec\n\n");

        cmd = tolower(getchar());
        while (getchar() != '\n');

        switch (cmd)
        {
        case 'a':
        {
            char interpret[INTERPRET_SIZE];
            char nazev[NAZEV_SIZE];
            int rok;

            printf("\nNazev interpreta : ");
            fgets(interpret, INTERPRET_SIZE, stdin);
            interpret[strcspn(interpret, "\n")] = 0;
            printf("\nNazev alba : ");
            fgets(nazev, NAZEV_SIZE, stdin);
            nazev[strcspn(nazev, "\n")] = 0;
            printf("\nRok vydani : ");
            if (scanf("%d", &rok) != 1) {
                printf("Chyba: Neplatny vstup pro rok. Zadejte cele cislo.\n");
                while (getchar() != '\n');
                break;
            }
            while (getchar() != '\n');

            add(interpret, nazev, rok, &prvni);
        }
        break;
        case 'd':
        {
            char interpret[INTERPRET_SIZE];
            char nazev[NAZEV_SIZE];
            printf("\nInterpret : ");
            fgets(interpret, INTERPRET_SIZE, stdin);
            interpret[strcspn(interpret, "\n")] = 0;
            printf("\nNazev alba : ");
            fgets(nazev, NAZEV_SIZE, stdin);
            nazev[strcspn(nazev, "\n")] = 0;
            del(interpret, nazev, &prvni);
        }
        break;
        case 'f':
            ShowAlbums(prvni);
            break;
        case 's':
            ShowAllAlbums(prvni);
            break;
        }
    } while (cmd != 'q');
    return 0;
}