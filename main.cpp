#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <Windows.h>

struct date {
    char loc[151];
    char nume[101];
    int id;
    float price;
    int left; // locuri
    int eval; // evaluare in stele
    float mean; // medie reviwes
    int reviews;
    int availability;
}p[100];


struct parere {
    char locP[151];
    char numeP[101];
    char nume_prenume[55];
    char txt[401];
    float nota;
}c[100];


struct persoana
{
    char nume[55];
    struct persoana* next;
};

struct persoana* head = NULL;


void utility_printData()
{
    for (int i = 0; i <= 5; ++i)
    {
        printf("---------------------------------------\n\n");
        printf("Loc: ");
        printf("%s", p[i].loc);

        printf("Nume Hotel: ");
        printf("%s", p[i].nume);

        printf("ID: ");
        printf("%i\n", p[i].id);

        printf("Pret: ");
        printf("%f\n", p[i].price);

        printf("Locuri Ramase: ");
        printf("%i\n", p[i].left);

        printf("Numar de stele: ");
        printf("%i\n", p[i].eval);

        printf("Medie Review-uri: ");
        printf("%f\n", p[i].mean);

        printf("Numar de Review-uri: ");
        printf("%i\n", p[i].reviews);

        printf("Disponibilitate: ");
        printf(p[i].availability == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

    }

    //if ((n+1) % 2) 
    printf("---------------------------------------\n\n");
}

void utility_printReviews(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        printf("------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("Loc: ");
        printf("%s", c[i].locP);

        printf("Nume Hotel: ");
        printf("%s", c[i].numeP);

        printf("Nume si Prenume: ");
        printf("%s\n", c[i].nume_prenume);

        printf("Parere: ");
        printf("%s\n", c[i].txt);

        printf("Nota: ");
        printf("%f\n", c[i].nota);
    }

    if ((n + 1) % 2) printf("-------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void utility_storeData()
{
    FILE* locatii = fopen("locuri.txt", "r");
    char var[151];
    int cnt = 0;

    while (fgets(var, 150, locatii))
    {
        if (var[0] == '-') cnt++;

        else
        {
            strcpy(p[cnt].loc, var);

            fgets(var, 150, locatii);
            strcpy(p[cnt].nume, var);

            fgets(var, 150, locatii);
            p[cnt].id = atoi(var);

            fgets(var, 150, locatii);
            p[cnt].price = atof(var);

            fgets(var, 150, locatii);
            p[cnt].left = atoi(var);

            fgets(var, 150, locatii);
            p[cnt].eval = atoi(var);

            fgets(var, 150, locatii);
            p[cnt].mean = atof(var);

            fgets(var, 150, locatii);
            p[cnt].reviews = atoi(var);

            fgets(var, 150, locatii);
            p[cnt].availability = atoi(var);
        }
    }


    // utility_printData(cnt);

}

void utility_exit()
{
    system("cls");
    exit(0);
}

int utility_readOption()
{
    int option;
    printf("Numarul actiunii: ");
    scanf("%i", &option);

    return option;
}

void utility_mainMenus()
{
    printf("[1] Optiuni\n");
    printf("[2] Pareri Fosti Clienti\n");
    printf("[3] Rezerva loc\n");
    printf("[4] Anuleaza Rezervarea\n");
    printf("[5] Vizualizare zboruri\n");
    printf("[6] Oprire Program\n\n");
}

void utility_storeReviews()
{
    FILE* opinii = fopen("pareri.txt", "r");
    char store[255];
    int cnt = 0;


    while (fgets(store, 255, opinii))
    {
        if (store[0] == '-') cnt++;

        else
        {
            strcpy(c[cnt].locP, store);

            fgets(store, 255, opinii);
            strcpy(c[cnt].numeP, store);

            fgets(store, 255, opinii);
            strcpy(c[cnt].nume_prenume, store);

            fgets(store, 255, opinii);
            strcpy(c[cnt].txt, store);

            fgets(store, 255, opinii);
            c[cnt].nota = atof(store);

        }
    }

    utility_printReviews(cnt);

}

void optiuni()
{
    system("clS");

    utility_printData();

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n\n");

    int option = utility_readOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    else if (option == 2)  utility_exit();


    // arata optiunile complete
}

void utility_Plata()
{
    system("cls");

    printf("[1] Anularea procesului de plata\n");
    printf("[2] Continua Plata\n\n");

    int option = utility_readOption();

    if (option == 1)  utility_exit();

    char IBAN[40], cvv[40];
    printf("Pentru confirmarea cazarii trebuie sa platiti online cu cardul si sa generati raportul de cazare\n");
    printf("Neindeplinirea celor 2 pasi va duce la nealocarea cazarii si restituirea banilor \n\n");
    printf("Introduceti IBAN: ");     scanf("%s", IBAN);

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

    utility_storeReviews();

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n\n");

    int option = utility_readOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    if (option == 2) utility_exit();
}

void generare_raport(int i)
{
    system("clS");

    printf("[1] Genereaza raport de cazare\n");
    printf("[2] Revino la meniul principal\n");
    printf("[3] Opreste Programul\n\n");

    int option = utility_readOption();

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
        fprintf(cazare, "Locatie: %s", p[i].loc);
        fprintf(cazare, "Nume Hotel: %s", p[i].nume);
        fprintf(cazare, "ID: %i\n", p[i].id);
        fprintf(cazare, "Pret: %f\n", p[i].price);
        fprintf(cazare, "Locuri Ramase: %i\n", p[i].left);
        fprintf(cazare, "Stele: %i\n", p[i].eval);
        fprintf(cazare, "Medie Review-uri: %f\n", p[i].mean);
        fprintf(cazare, "Numar Review-uri%i\n", p[i].reviews);
        fprintf(cazare, "Disponibilitate: %s\n\n", p[i].availability == 0? "Nu este disponibil":"Este disponibil");
        fprintf(cazare, "*****************************\n\n");

        fclose(cazare);


    }

    else if (option == 2)
    {
        system("cls");
        return;
    }

    else if (option == 3)  utility_exit();

    printf("Raportul a fost generat, cazarea a fost facut, vom redirectiona catre meniul principal. Multumim!");
    Sleep(4500);
    system("cls");

}

int utility_checkLeft(int persoane, int i)
{
    return ((p[i].left - persoane) > 0);
}

void vizualizare_raport_cazare(int ID, int persoane)
{
    system("clS");


    int i = 0;
    int catelocatii = 5;

    while (p[i].id != ID && i < catelocatii) i++;

    printf("Ati ales:\n\n");

    printf("---------------------------------------\n\n");
    printf("Loc: ");
    printf("%s", p[i].loc);

    printf("Nume Hotel: ");
    printf("%s", p[i].nume);

    printf("ID: ");
    printf("%i\n", p[i].id);

    printf("Pret: ");
    printf("%f\n", persoane * p[i].price);

    printf("Locuri Ramase: ");
    printf("%i\n", p[i].left);

    printf("Numar de stele: ");
    printf("%i\n", p[i].eval);

    printf("Medie Review-uri: ");
    printf("%f\n", p[i].mean);

    printf("Numar de Review-uri: ");
    printf("%i\n", p[i].reviews);

    printf("Disponibilitate: ");
    printf(p[i].availability == 0 ? "Nu mai este disponibil\n\n" : "Este disponibil\n\n");

    printf("---------------------------------------\n\n");

    printf("[1] Confirmati\n");
    printf("[2] Revino la meniul principal\n");
    printf("[3] Opreste Programul\n\n");

    int option = utility_readOption();

    if (option == 1)
    {   
        printf("Vom redirectiona catre zona de plata\n");
        printf("Daca va razganditi in timpul platii, din motive de securitate a banilor, singura posibilitate este de a opri programul\n");
        Sleep(20000);
        utility_Plata();
        printf("Vom redirectiona catre generarea formularului de cazare...");
        Sleep(4500);
        generare_raport(i);
    }

    else if (option == 2)
    {
        system("cls");
        return;
    }

    else if (option == 3)  utility_exit();

}

void adauga_p()
{
    struct persoana* om = malloc(sizeof(struct persoana));
    char var[55];

    printf("Nume Persoana: ");
    scanf("%s", var);
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


int utility_findByID(int ID)
{
    int i = 0;

    while (p[i].id != ID && i < 5) i++;

    if (i == 5) return 0;

    return 1;
}

void rezerva_loc()
{
    system("clS");

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n");
    printf("[3] Continuati\n\n");

    int option = utility_readOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    else if (option == 2) utility_exit();

    int poz, persoane, check;

    printf("\n");
    int ID = utility_getID();
    printf("\n");
    int ok = utility_checkID(ID);

    if (ok == 3)
    {
        printf("ID-ul nu exista, verificati inca odata\n\n");
        printf("[1] Revino la meniul principal\n");
        printf("[2] Opreste Programul\n\n");

        int option = utility_readOption();

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
        printf("Hotelul s-a gasit si este disponibil\n\n");
        printf("\n");
        persoane = utility_getNumber();
        poz = utility_findByID(ID);
        check = utility_checkLeft(persoane, poz);

        if (check == 0)
        {
            printf("Nu sunt destule locuri disponibile\n");
            printf("Verificati din nou locurile disponibile, veti fi directionat la meniul principal");
            Sleep(13000);
            return;
        }

        int i = 1;

        while (i <= persoane)
        {
            adauga_p();
            i++;
        }

        printf("Pregatim raportul de cazare...");
        Sleep(4500);
        vizualizare_raport_cazare(ID, persoane);
    }

}

int utility_getNumber()
{
    int n;

    printf("Pentru cate persoane se va face cazarea ?\n\n");
    printf("Perosane: "); scanf("%i", &n);

    return n;
}

int utility_getID()
{
    int id;

    printf("Scrieti ID-ul hotelului unde vreti sa se faca cazarea\n\n");
    printf("ID: "); scanf("%i", &id);

    return id;
}

int utility_checkID(int ID)
{

    int i = 0;
    int catelocatii = 5;

    while (p[i].id != ID && i < catelocatii) i++;

    if (i < catelocatii)
    {
        if (p[i].availability == 1) return 1;
        else return 2;
    }

    return 3;

}

void anuleaza_rezervare()
{
    system("clS");

    printf("[1] Revino la meniul principal\n");
    printf("[2] Opreste Programul\n\n");

    int option = utility_readOption();

    // anuleaza rezervarea pe baza resetarii unei valori booleene

    if (option == 1)
    {
        system("cls");
        return;
    }

    if (option == 2) utility_exit();
}

void vizualizare_zboruri()
{
    system("cls");
    printf("[1] Revino la meniul principal");
    printf("[2] Opreste Programul");
    int option = utility_readOption();

    if (option == 1)
    {
        system("cls");
        return;
    }

    if (option == 2) utility_exit();

}

int main() {

    utility_storeData();

    while (1)
    {
        system("cls");

        utility_mainMenus();

        int option = utility_readOption();

        if (option == 1) optiuni();

        else if (option == 2) pareri_fosti_clienti();

        else if (option == 3) rezerva_loc();

        else if (option == 4) anuleaza_rezervare();

        else if (option == 5) vizualizare_zboruri();

        else if (option == 6) utility_exit();
    }
    return 0;
}
