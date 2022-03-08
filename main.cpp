#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <Windows.h>
#include <string.h>
#include <math.h>

int cntPareri, cntHoteluri, NumarDePersoane;


struct datelocatii {
    char numeLocatie[151];
    char numeHotel[101];
    int id;
    float pret;
    int locuriRamase;
    int evaluare;
    float mediePareri;
    int numarPareri;
    int disponibilitate;
}locatie[100];


struct parereClienti {
    char Locatie[151];
    char Hotel[101];
    char numePrenume[55];
    char txt[401];
    float nota;
}parere[100];


struct persoana
{
    char nume[55];
    struct persoana* next;
};

struct persoana* head = NULL;


void utility_ReviewMenu()
{
    system("cls");
    printf("Multumim ca doriti sa ajutati comunitatea !\n\n");
    printf("Pregatim pagina de adaugat pareri...");
    Sleep(4500);
}


void utility_exit()
{
    system("cls");

    FILE* ptr = fopen("raport.txt", "w");

    fprintf(ptr, "  ");

    fclose(ptr);

    exit(0);
}


void adauga_parere()
{
    system("cls");
    fflush(stdin);

    printf("*********************************************************************** MENIUL DE ADAUGAT PARERI ****************************************************************************\n\n");
    ++cntPareri;

    char var[150], text[401];
    float mark;
    int poz;

    printf("ID-ul hotelului: ");
    int ID = utility_receiveIDForReview();

    printf("\n");

    int ok = utility_checkIDExistanceForReview(ID);

    if (ok == 2)
    {
        printf("ID-ul nu exista, verificati inca odata\n\n");
        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n\n");

        int option = utility_readUserOption();

        if (option == 1)
        {
            system("cls");
            return;
        }

        utility_exit();

    }

    else
    {
        printf("Hotelul s-a gasit! \n\n");
        printf("\n");
        poz = utility_findHotelByID(ID);
    }

    printf("Redirectionam catre pagina de adaugat pareri...");
    Sleep(4500);
    utility_ReviewMenu(poz);
    system("cls");
    printf("Puteti inncepe: \n\n");

    printf("Numele locatiei: ");
    strcpy(parere[cntPareri].Locatie, locatie[poz].numeLocatie);
    printf("%s\n", parere[cntPareri].Locatie);

    printf("Numele Hotelului: ");
    strcpy(parere[cntPareri].Hotel, locatie[poz].numeHotel);
    printf("%s\n", parere[cntPareri].Hotel);

    printf("Numele tau: ");
    scanf("%s", var);
    var[strlen(var) + 1] = '\0';
    strcpy(parere[cntPareri].numePrenume, var);
    printf("\n");
    while ((getchar()) != '\n');

    printf("Parerea ta: ");
    fgets(text, 400, stdin);
    strcpy(parere[cntPareri].txt, text);
    printf("\n");


    printf("Nota: ");
    scanf("%f", &mark);
    parere[cntPareri].nota = mark;
    printf("\n\n");


    printf("Review-ul dumneavoastra a fost adaugat. Multumim !\n\n");
    printf("[1] Adaugati alt review\n");
    printf("[2] Reveniti la meniul principal\n\n");

    int option = utility_readUserOption();

    if (option == 1) adauga_parere();

    else
    {
        printf("Redirectionam catre meniul principal...");
        Sleep(4500);
    }
}


void utility_printLocations()
{
    for (int i = 0; i < cntHoteluri; ++i)
    {
        if (locatie[i].locuriRamase > 0)
        {
            Sleep(2500);
            printf("                           -----------------------------------------------------------------\n\n");
            printf("                                        Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("                                        Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("                                        ID: ");
            printf("%i\n", locatie[i].id);

            printf("                                        Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("                                        Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("                                        Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);
                
            printf("                                        Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("                                        Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("                                        Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("                           -----------------------------------------------------------------\n\n");
        }

    }

    //if ((n+1) % 2) 

}


void utility_printLocationsByLocationName(char arg[])
{
    for (int i = 0; i < cntHoteluri; i++)
    {
        int ok = 1;

        for (int j = 0; j < strlen(arg); j++)
        {
            if (tolower(arg[j]) != tolower(locatie[i].numeLocatie[j])) {
                ok = 0;
                break;
            }
        }

        if (ok == 1)
        {
            printf("---------------------------------------\n\n");
            printf("Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("ID: ");
            printf("%i\n", locatie[i].id);

            printf("Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("---------------------------------------\n\n");
        }
    }

}


void utility_printLocationsByReviewsNumber(int num)
{
    for (int i = 0; i < cntHoteluri; i++)
    {
        if (locatie[i].numarPareri >= num)
        {
            printf("---------------------------------------\n\n");
            printf("Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("ID: ");
            printf("%i\n", locatie[i].id);

            printf("Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("---------------------------------------\n\n");
        }
    }

}


void utility_printLocationsByMean(int num)
{
    for (int i = 0; i < cntHoteluri; i++)
    {
        if ((int)((locatie[i].mediePareri)) >= num)
        {
            printf("---------------------------------------\n\n");
            printf("Locatie: ");
            printf("%s", locatie[i].numeLocatie);

            printf("Nume Hotel: ");
            printf("%s", locatie[i].numeHotel);

            printf("ID: ");
            printf("%i\n", locatie[i].id);

            printf("Pret: ");
            printf("%f\n", locatie[i].pret);

            printf("Locuri Ramase: ");
            printf("%i\n", locatie[i].locuriRamase);

            printf("Numar de stele: ");
            printf("%i\n", locatie[i].evaluare);

            printf("Medie Review-uri: ");
            printf("%f\n", locatie[i].mediePareri);

            printf("Numar de Review-uri: ");
            printf("%i\n", locatie[i].numarPareri);

            printf("Disponibilitate: ");
            printf(locatie[i].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

            printf("---------------------------------------\n\n");
        }
    }

}


void utility_printReviews(int n)
{
    printf("************************************************************************** PARERI FOSTI CLIENTI *****************************************************************************\n\n");

    for (int i = 0; i <= n; ++i)
    {
        Sleep(2000);
        printf("                                            -------------------------------------------------------------------------\n\n");
        printf("                                                            Loc: ");
        printf("%s\n", parere[i].Locatie);

        printf("                                                            Nume Hotel: ");
        printf("%s\n", parere[i].Hotel);

        printf("                                                            Nume si Prenume: ");
        printf("%s\n", parere[i].numePrenume);

        printf("                          Parere: ");
        for (int j = 0; j < strlen(parere[i].txt); j++)
            if (parere[i].txt[j] != '\\')
                printf("%c", parere[i].txt[j]);
            else
            {
                printf(" ");
                parere[i].txt[j + 1] = ' ';
                strcpy(parere[i].txt + j, parere[i].txt + j + 1);
            }

        printf("\n");

        printf("                                                            Nota: ");
        printf("%f\n\n", parere[i].nota);

        printf("                                            ----------------------------------------------------------------------------\n\n");

    }   

    printf("*****************************************************************************************************************************************************************************\n\n");


    //if ((n + 1) % 2) 
}


void utility_storeLocationsData()
{
    FILE* locatii = fopen("locuri.txt", "r");
    char var[151];

    while (fgets(var, 150, locatii))
    {
        if (var[0] == '-') cntHoteluri++;

        else
        {
            strcpy(locatie[cntHoteluri].numeLocatie, var);

            fgets(var, 150, locatii);
            strcpy(locatie[cntHoteluri].numeHotel, var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].id = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].pret = atof(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].locuriRamase = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].evaluare = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].mediePareri = atof(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].numarPareri = atoi(var);

            fgets(var, 150, locatii);
            locatie[cntHoteluri].disponibilitate = atoi(var);
        }
    }

    // utility_printData(cnt);

}


int utility_readUserOption()
{
    int option;
    printf("Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}


void utility_mainMenus()
{
    printf("                                                                            [1] Optiuni\n");
    printf("                                                                            [2] Pareri Fosti Clienti\n");
    printf("                                                                            [3] Rezerva loc\n");
    printf("                                                                            [4] Anuleaza Rezervarea\n");
    printf("                                                                            [5] Filtreaza optiuni\n");
    printf("                                                                            [6] Adauga un review\n");
    printf("                                                                            [7] Vezi cazarile mele\n");
    printf("                                                                            [8] Oprire Program\n\n");
}


void utility_storeReviews()
{
    FILE* opinii = fopen("pareri.txt", "r");
    char store[255];


    while (fgets(store, 255, opinii))
    {
        if (store[0] == '-') cntPareri++;

        else
        {
            strcpy(parere[cntPareri].Locatie, store);

            fgets(store, 255, opinii);
            strcpy(parere[cntPareri].Hotel, store);

            fgets(store, 255, opinii);
            strcpy(parere[cntPareri].numePrenume, store);

            fgets(store, 255, opinii);
            strcpy(parere[cntPareri].txt, store);

            fgets(store, 255, opinii);
            parere[cntPareri].nota = atof(store);

        }
    }

}

void optiuniLocatii()
{
    system("clS");
    fflush(stdin);
    printf("*************************************************************************** LOCATIILE DISPONIBILE **********************************************************************\n\n\n");

    utility_printLocations();

    printf("*********************************************************************************************************************************************************************\n\n\n");
    
    printf("\n\n");
    printf("                                              [1] Revino la meniul principal\n");
    printf("                                              [2] Opreste Programul\n\n");
    
    printf("                                              "); getchar(); int option = utility_readUserOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    else if (option == 2)  utility_exit();


    // arata optiunile complete
}


void utility_SitemDePlata()
{
    system("cls");
    fflush(stdin);

    printf("**************************************************************************** MENIUL DE PLATA ********************************************************************************\n\n");

    printf("[1] Anularea procesului de plata\n");
    printf("[2] Continua Plata\n\n");

    int option = utility_readUserOption();

    if (option == 1)  utility_exit();

    char IBAN[40], cvv[40];

    printf("Pentru confirmarea cazarii trebuie sa platiti online cu cardul si sa generati raportul de cazare\n");
    printf("Neindeplinirea celor 2 pasi va duce la nealocarea cazarii si restituirea banilor \n\n");
    printf("Introduceti IBAN: "); getchar();    fgets(IBAN, 38, stdin);

    printf("\n");


    printf("Introduceti codul de securitate(CVV): "); scanf("%s", cvv);
    printf("\n");

    printf("Plata se proceseaza...\n\n");
    Sleep(3500);
    printf("Plata efectuata cu succes\n\n");

}


void pareri_fosti_clienti()
{
    system("clS");

    fflush(stdin);

    utility_printReviews(cntPareri);

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n\n");

    int option = utility_readUserOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    if (option == 2) utility_exit();
}


void utility_generare_raport(int i)
{
    system("clS");

    printf("**************************************************** MENIUL DE GENERARE RAPORT DE CAZARE IN FORMAT TEXT *************************************************\n\n");

    printf("[1] Genereaza raport de cazare\n");
    printf("[2] Revino la meniul principal\n");
    printf("[3] Opreste Programul\n\n");

    int option = utility_readUserOption();

    if (option == 1)
    {
        printf("Se incepe generarea raportului de cazare...\n\n");
        Sleep(4500);

        FILE* cazare = fopen("raport.txt", "w");
        fprintf(cazare, "Persoane\n");

        struct persoana* temp = head;


        while (temp != NULL)
        {
            fprintf(cazare, "%s\n", (*temp).nume);
            temp = (*temp).next;
        }

        fprintf(cazare, "*****************************\n");
        fprintf(cazare, "Locatie: %s", locatie[i].numeLocatie);
        fprintf(cazare, "Nume Hotel: %s", locatie[i].numeHotel);
        fprintf(cazare, "ID: %i\n", locatie[i].id);
        fprintf(cazare, "Pret: %f\n", locatie[i].pret);
        fprintf(cazare, "Locuri Ramase: %i\n", locatie[i].locuriRamase);
        fprintf(cazare, "Stele: %i\n", locatie[i].evaluare);
        fprintf(cazare, "Medie Review-uri: %f\n", locatie[i].mediePareri);
        fprintf(cazare, "Numar Review-uri%i\n", locatie[i].numarPareri);
        fprintf(cazare, "Disponibilitate: %s\n\n", locatie[i].disponibilitate == 0 ? "Nu este disponibil" : "Este disponibil");
        fprintf(cazare, "*****************************\n\n");

        fclose(cazare);

        locatie[i].locuriRamase -= NumarDePersoane;

    }

    else if (option == 2)
    {
        system("cls");
        return;
    }

    else if (option == 3)  utility_exit();

    printf("Raportul a fost generat, se poate gasi in format text, cazarea a fost facuta, vom redirectiona catre meniul principal. Multumim!");
    Sleep(4500);
    fflush(stdin);
    system("cls");

}


int utility_checkLocuriRamase(int persoane, int i)
{
    return ((locatie[i].locuriRamase - persoane) >= 0);
}


void utility_vizualizare_raport_cazare(int poz, int persoane)
{
    system("clS");

    printf("**************************************************************************** RAPORT DE CAZARE ONLINE ************************************************************************\n\n");

    printf("Ati ales:\n\n");

    printf("----------------------------------------------------------------------\n\n");
    printf("Locatie: ");
    printf("%s", locatie[poz].numeLocatie);

    printf("Nume Hotel: ");
    printf("%s", locatie[poz].numeHotel);

    printf("ID: ");
    printf("%i\n", locatie[poz].id);

    printf("Pret: ");
    printf("%f\n", persoane * locatie[poz].pret);

    printf("Locuri Ramase: ");
    printf("%i\n", locatie[poz].locuriRamase);

    printf("Numar de stele: ");
    printf("%i\n", locatie[poz].evaluare);

    printf("Medie Review-uri: ");
    printf("%f\n", locatie[poz].mediePareri);

    printf("Numar de Review-uri: ");
    printf("%i\n", locatie[poz].numarPareri);

    printf("Disponibilitate: ");
    printf(locatie[poz].disponibilitate == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

    printf("----------------------------------------------------------------------\n\n");

    printf("***************************************************************************************************************************************************************************\n\n");


    printf("[1] Confirmati\n");
    printf("[2] Revino la meniul principal\n");
    printf("[3] Opreste Programul\n\n");

    int option = utility_readUserOption();

    if (option == 1)
    {
        printf("Vom redirectiona catre zona de plata\n");
        printf("Daca va razganditi in timpul platii, din motive de securitate a banilor, singura posibilitate este de a opri programul\n");
        Sleep(20000);
        utility_SitemDePlata();
        printf("Vom redirectiona catre generarea formularului de cazare...");
        Sleep(4500);
        utility_generare_raport(poz);
    }

    else if (option == 2)
    {
        system("cls");
        return;
    }

    else if (option == 3)  utility_exit();

}


void utility_adaugaPersoana()
{
    struct persoana* om = (struct persoana*)malloc(sizeof(struct persoana));
    char var[55];

    printf("Nume Persoana: ");
    scanf("%s", var);
    var[strlen(var) + 1] = '\0';

    getchar();
    printf("\n");

    strcpy((*om).nume, var);
    (*om).next = NULL;

    if (head == NULL) head = om;

    else
    {
        struct persoana* ptr = head;
        while ((*ptr).next != NULL)
        {
            ptr = (*ptr).next;
        }

        (*ptr).next = om;
    }
}

int utility_findHotelByID(int ID)
{
    int i = 0;

    while (locatie[i].id != ID) i++;

    return i;
}


void rezerva_loc()
{
    system("clS");

    printf("************************************************************************** MENIU DE REZERVARE A LOCULUI *********************************************************************\n\n");

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n");
    printf("[3] Continuati\n\n");

    printf("*****************************************************************************************************************************************************************************\n\n");


    int option = utility_readUserOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    else if (option == 2) utility_exit();

    int poz, check;

    printf("\n");
    int ID = utility_getIDForBooking();
    printf("\n");
    printf("Se verifica daca ID-ul corespunde unui hotel si disponibilitatea hotelului...\n\n");
    Sleep(3500);


    int ok = utility_checkAvailabilityAndExistanceForBookingByID(ID);

    if (ok == 3)
    {
        printf("ID-ul nu exista, verificati inca odata\n\n");
        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n\n");

        int option = utility_readUserOption();

        if (option == 1)
        {
            system("cls");
            return;
        }

        else if (option == 2) utility_exit();

    }

    else if (ok == 2)
    {
        printf("Hotelul nu este disponibil deocamdata\n");
        printf("Redirectionam catre pagina principala...");
        Sleep(13000);
        return;
    }

    else
    {
        printf("Hotelul s-a gasit si este disponibil\n\n\n");
        NumarDePersoane = utility_getPersonsNumber();
        poz = utility_findHotelByID(ID);
        check = utility_checkLocuriRamase(NumarDePersoane, poz);

        if (check == 0)
        {
            printf("Nu sunt destule locuri disponibile\n");
            printf("Verificati din nou locurile disponibile, veti fi directionat la meniul principal");
            Sleep(13000);
            return;
        }

        int i = 1;

        while (i <= NumarDePersoane)
        {
            utility_adaugaPersoana();
            i++;
        }

        printf("Pregatim raportul de cazare...");
        Sleep(5500);
        utility_vizualizare_raport_cazare(poz, NumarDePersoane);
    }
}


int utility_getPersonsNumber()
{
    int n;

    printf("Pentru cate persoane se va face cazarea ?\n\n");
    printf("Perosane: "); scanf("%i", &n);
    printf("\n");
    printf("Introduceti numele tuturor persoanelor: \n\n");

    return n;
}


int utility_getIDForBooking()
{
    char id[100];
    system("cls");

    printf("********************************************************* MENIU DE REZERVARE A LOCULUI - SOLICITARE ID HOTEL*****************************************************************\n\n");


    printf("Scrieti ID-ul hotelului: \n\n");
    printf("ID: "); scanf("%s", &id);
    getchar();

    if ((strlen(id) >= 2) || (id[0] <= '0' || id[0] > '9'))
    {
        printf("\n\n");
        printf("EROARE: Acesta nu este un ID valid !\n\n");
        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n");
        printf("[3] Reintrodu ID-ul\n\n");

        int option = utility_readUserOption();

        if (option == 1)
        {
            main();
        }

        else if (option == 2) utility_exit();

        else
        {
            printf("Reincepem procesul...");

            Sleep(3500);
            rezerva_loc();
        }
    }

    return atoi(id);
}


int utility_receiveIDForReview()
{
    char id[100];

    printf("Scrieti ID-ul hotelului pentru care vreti sa faceti review-ul\n\n");
    printf("ID: "); scanf("%s", &id);

    getchar();

    if ((strlen(id) >= 2) || (id[0] <= '0' || id[0] > '9'))
    {
        system("cls");
        printf("Acesta nu este un ID valid !\n\n");
        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n");
        printf("[3] Reintrodu ID-ul\n\n");

        int option = utility_readUserOption();

        if (option == 1)
        {
            main();
        }

        else if (option == 2) utility_exit();

        else
        {
            printf("Reincepem procesul...\n\n");

            Sleep(3500);
            adauga_parere();
        }
    }

    return atoi(id);
}


int utility_checkAvailabilityAndExistanceForBookingByID(int ID)
{

    int i = 0;

    while (locatie[i].id != ID && i < cntHoteluri) i++;


    if (i < cntHoteluri)
    {
        if (locatie[i].disponibilitate == 1) return 1;
        else return 2;
    }

    return 3;

}


int utility_checkIDExistanceForReview(int ID)
{

    int i = 0;

    while (locatie[i].id != ID && i < cntHoteluri) i++;

    if (i < cntHoteluri) return 1;

    return 2;

}


void anuleaza_rezervare()
{
    system("clS");

    printf("************************************************************************ MENIUL DE ANULAT REZERVAREA ************************************************************************\n\n");

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n");
    printf("[3] Continua anularea rezervarii\n\n");

    int option = utility_readUserOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    if (option == 2) utility_exit();

    else
    {
        system("cls");
        int ID = utility_getIDForBooking();
        int poz = utility_findHotelByID(ID);

        locatie[poz].locuriRamase += NumarDePersoane;
        locatie[poz].disponibilitate = 1;

        FILE* ptr = fopen("raport.txt", "w");

        fprintf(ptr, "  ");

        fclose(ptr);

        fclose(ptr);

        printf("Cazarea a fost anulata, banii vor fi restituti cat de curand\n");
        printf("Redirectionam catre meniul principal...\n");
        Sleep(3500);
        main();

    }

}


void filtrare_optiuni()
{
    system("cls");
    fflush(stdin);
    printf("************************************************************************** MENIU - CAUTARE LOCATII **************************************************************************\n\n");
    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n");
    printf("[3] Cauta dupa locatie\n");
    printf("[4] Cauta dupa numar de review-uri\n");
    printf("[5] Cauta de la o anumita medie in sus\n\n");

    int option = utility_readUserOption();
    getchar();

    if (option == 1)
    {
        system("cls");
        return;
    }

    else if (option == 2) utility_exit();

    else if (option == 3)
    {
        char name[150];
        printf("Numele Locatiei: ");  scanf("%s", name);
        printf("\n\n");
        utility_printLocationsByLocationName(name);
        printf("\n\n");

        printf("*****************************************************************************************************************************************************\n\n");


        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n");
        printf("[3] Inapoi la criteriile de cautare\n\n");

        int option = utility_readUserOption();
        printf("\n\n");

        if (option == 1)
        {
            system("cls");
            return;
        }

        else if (option == 2) utility_exit();

        else if (option == 3) filtrare_optiuni();
    }

    else if (option == 4)
    {
        int num;
        printf("Numarul minim de review-uri: "); scanf("%i", &num);

        printf("\n\n");
        utility_printLocationsByReviewsNumber(num);
        printf("\n\n");
        printf("*****************************************************************************************************************************************************\n\n");


        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n");
        printf("[3] Inapoi la criteriile de cautare\n\n");

        int option = utility_readUserOption();

        if (option == 1)
        {
            system("cls");
            return;
        }

        else if (option == 2) utility_exit();

        else if (option == 3) filtrare_optiuni();

    }

    else if (option == 5)
    {
        int medie;
        printf("Media minima: "); scanf("%i", &medie);
        printf("\n\n");
        utility_printLocationsByMean(medie);
        printf("\n\n");

        printf("*****************************************************************************************************************************************************\n\n");


        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n");
        printf("[3] Inapoi la criteriile de cautare\n\n");

        int option = utility_readUserOption();

        if (option == 1)
        {
            system("cls");
            return;
        }

        else if (option == 2) utility_exit();

        else if (option == 3) filtrare_optiuni();

    }


}


void vezi_cazarileMele()
{

    system("cls");
    fflush(stdin);
    printf("************************************************************************* MENIU - CAZARILE MELE *****************************************************************************\n\n");
    FILE* cazari = fopen("raport.txt", "r");
    char txt[250];

    if (NULL == cazari) {
        printf("file can't be opened \n");
    }


    while (fgets(txt, 248, cazari)) {
        if (txt[0] == ' ')
        {
            printf("Nu aveti nicio rezervare facuta\n\n");
            break;
        }
        printf("%s\n", txt);
    }

    printf("\n");

    fclose(cazari);

    printf("\n\n");

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n\n");

    int option = utility_readUserOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    if (option == 2) utility_exit();
}


int main() {

    utility_storeLocationsData();
    utility_storeReviews();

    while (1)
    {
        system("cls");
        fflush(stdin);
        printf("***************************************************************************** MENIU PRINCIPAL *******************************************************************************\n\n");

        utility_mainMenus();

        printf("\n");
        printf("*****************************************************************************************************************************************************************************\n\n");


        int option = utility_readUserOption();

        if (option == 1) optiuniLocatii();

        else if (option == 2) pareri_fosti_clienti();

        else if (option == 3) rezerva_loc();

        else if (option == 4) anuleaza_rezervare();

        else if (option == 5) filtrare_optiuni();

        else if (option == 6) adauga_parere();

        else if (option == 7) vezi_cazarileMele();

        else if (option == 8) utility_exit();

    }
    return 0;

}
