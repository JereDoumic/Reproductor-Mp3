#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    char nombre[30];
    struct nodo * sig;
} nodo;

typedef struct
{
    char nombre[40];
} stCanciones;

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(char nombre[30])
{
    nodo * nuevoNodo = (nodo*)malloc(sizeof(nodo));
    strcpy(nuevoNodo->nombre, nombre);
    return nuevoNodo;
}

nodo * agregarAlPrincipioDeLalista(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}

void mostrarNodo(nodo * nuevoNodo)
{
    gotoxy(20,10);
    printf("   \n Nombre de la cancion: %s", nuevoNodo->nombre);
}

void mostrarLista(nodo * lista)
{
    nodo * seg = lista;
    int i = 20;
    int x = 20;
    while(seg != NULL)
    {
        gotoxy(x, i);
        mostrarNodo(seg);
        seg = seg->sig;
        i--;
    }
}

void mostrarPlaylist(nodo * lista)
{
    ///VISUAL
    marco();

    Logo(79,17);

    gotoxy(2,1);
    printf("CANCIONES FAVORITAS");
    gotoxy(1,2);
    for(int i = 0; i <= 100-2; i++)
    {
        printf("%c",205);
    }
    ///FUNCIONALIDAD
    nodo * aux = lista;
    int x = 2;
    int y = 5;
    while(aux != NULL)
    {
        gotoxy(x,y);
        printf("%s", aux->nombre);
        aux = aux->sig;
        y++;
    }
}

void PreguntaCrearPlaylist()
{
    nodo * lista = inicLista();
    marco();

    Logo(79,17);
    Logo(2,17);

    gotoxy(2,1);
    printf("CREAR PLAYLIST");
    gotoxy(1,2);
    for(int i = 0; i <= 100-2; i++)
    {
        printf("%c",205);
    }

    gotoxy(34,10);
    printf("Seguro que quiere crear una playlist?");
    botonInicio(40, 15, "[S] SI");
    botonInicio(40, 20, "[N] NO");
    switch(getch())
    {
    case 's':
        crearPlaylist(lista);
        break;
    case 'n':
        MenuPrincipal();
        break;
    default:
        PreguntaCrearPlaylist();
        break;
    }
}

void guardarCancionEnArchivo(char nombreDeCancion[30])
{
    FILE * archivo = fopen("canciones.bin", "ab");
    stCanciones cancion;
    if(archivo != NULL)
    {
        strcpy(cancion.nombre, nombreDeCancion);
        fwrite(&cancion, sizeof(stCanciones), 1,archivo);
        fclose(archivo);
    }
}

void crearPlaylistInicio()
{
    marco();

    TituloMenu(11,1);
    Logo(5,12);
    Logo(76,12);
    gotoxy(32,15);
    printf("Seleccione la cancion que quiera");
    gotoxy(38,16);
    printf("agregar a la Playlist");
    gotoxy(48,20);
    printf("3");
    Sleep(800);
    gotoxy(48,20);
    printf("2");
    Sleep(800);
    gotoxy(48,20);
    printf("1");
    Sleep(800);
}

void crearPlaylist(nodo * lista)
{
    int teclaUsuario;
    ///TECLA 1 CLASICA
    if(teclaUsuario != 113)
    {
        marco();

        TituloMenu(11,1);
        Logo(5,12);
        Logo(76,12);

        gotoxy(40,8);
        printf("Seleccione el genero");

        botonInicio(28,11,"[1]Clasica");
        botonInicio(52,11,"[2]Electro");
        botonInicio(28,14,"[3]Latina");
        botonInicio(52,14,"[4]Nacional");
        botonInicio(28,17,"[5]Rap");
        botonInicio(52,17,"[6]Rock");
        botonInicio(40,20,"[7]Pop");

        teclaUsuario = getch();

        if(teclaUsuario == 49)
        {
            system("cls");
            marco();

            TituloClasica(35,1);

            gotoxy(44,8);
            printf("Elija una cancion");

            botonInicio(15,14,"[1]Clair de Lune");
            botonInicio(40,14,"[2]Nocturne op.9");
            botonInicio(65,14,"[3]Moonlight Sonata");
            botonInicio(15,20,"[4]Winter");
            botonInicio(40,20,"[5]December");
            botonInicio(65,20,"[6]Gymnopedie No.1");

            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Clair de Lune"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Nocturne op.9"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Moonlight Sonata"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Winter"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("December"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Gymnopedie No.1"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }

            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();

                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }
            }
        }
        ///TECLA 2 ELECTRO
        if(teclaUsuario == 50)
        {
            system("cls");
            marco();

            TituloElectro(22,1);

            gotoxy(20,8);
            printf("Canciones para los amantes de los sintetizadores y lo digital.");

            gotoxy(45,12);
            printf("Canciones:");

            botonInicio(15,14,"[1]Faded");
            botonInicio(40,14,"[2]E3");
            botonInicio(65,14,"[3]The Business");
            botonInicio(15,20,"[4]You Are The One");
            botonInicio(40,20,"[5]Levels");
            botonInicio(65,20,"[6]Roses Remix");


            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Faded"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("E3"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("The Business"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("You Are The One"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Levels"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Roses Remix"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }

            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();
                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                    switch(getch())
                    {
                    case 'm' :
                        MenuPrincipal();
                    }
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }

            }

        }
        ///TECLA 3 LATINA
        if(teclaUsuario == 51)
        {
            system("cls");
            marco();

            TituloLatina(28,1);

            gotoxy(20,8);
            printf("Todo el pop latino, el reggaeton y el trap en esta playlist.");

            gotoxy(45,12);
            printf("Canciones:");

            botonInicio(15,14,"[1]Despacito");
            botonInicio(40,14,"[2]Dile");
            botonInicio(65,14,"[3]Goteo");
            botonInicio(15,20,"[4]Todo de Ti");
            botonInicio(40,20,"[5]Ella Me Levanto");
            botonInicio(65,20,"[6]Felices Los 4");

            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Despacito"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Dile"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Goteo"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Todo de Ti"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Ella Me Levanto"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Felices Los 4"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }

            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();
                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                    switch(getch())
                    {
                    case 'm' :
                        MenuPrincipal();
                    }
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }
            }
        }
        ///TECLA 4 NACIONAL
        if(teclaUsuario == 52)
        {
            system("cls");
            marco();

            TituloNacional(20,1);

            gotoxy(31,8);
            printf("La epoca dorada de la musica argentina.");

            gotoxy(45,12);
            printf("Canciones:");

            botonInicio(15,14,"[1]De Musica Ligera");
            botonInicio(40,14,"[2]Los Dinosaurios");
            botonInicio(65,14,"[3]Bajan");
            botonInicio(15,20,"[4]Tira Para Arriba");
            botonInicio(40,20,"[5]Lamento Boliviano");
            botonInicio(65,20,"[6]Ji Ji Ji");

            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("De Musica Ligera"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Los Dinosaurios"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Bajan"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Tira Para Arriba"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Lamento Boliviano"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Ji Ji Ji"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }

            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();
                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                    switch(getch())
                    {
                    case 'm' :
                        MenuPrincipal();
                    }
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }
            }
        }
        ///TECLA 5 RAP
        if(teclaUsuario == 53)
        {
            system("cls");
            marco();

            TituloRap(35,2);

            gotoxy(30,9);
            printf("Barra tras barra, R A P en su estado puro.");

            gotoxy(45,12);
            printf("Canciones:");

            botonInicio(15,14,"[1]Shook Ones");
            botonInicio(40,14,"[2]Juicy");
            botonInicio(65,14,"[3]Lose Yourself");
            botonInicio(15,20,"[4]Fuck Tha Police");
            botonInicio(40,20,"[5]All Of The Lights");
            botonInicio(65,20,"[6]In Da Club");

            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Shook Ones"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Juicy"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Lose Yourself"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Fuck Tha Police"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("All Of The Lights"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("In Da Club"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }

            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();
                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                    switch(getch())
                    {
                    case 'm' :
                        MenuPrincipal();
                    }
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }
            }
        }
        ///TECLA 6 ROCK
        if(teclaUsuario == 54)
        {
            system("cls");
            marco();

            TituloRock(35,1);

            gotoxy(12,10);
            printf("Guitarra electrica, bateria y parlantes al maximo, esta es la playlist del rock.");

            gotoxy(45,12);
            printf("Canciones:");

            botonInicio(15,14,"[1]Thunderstruck");
            botonInicio(40,14,"[2]We Will Rock You");
            botonInicio(65,14,"[3]Blitzkrieg Bop");
            botonInicio(15,20,"[4]Beautiful Day");
            botonInicio(40,20,"[5]Enter Sandman");
            botonInicio(65,20,"[6]Paint It, Black");

            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Thunderstruck"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("We Will Rock You"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Blitzkrieg Bop"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Beautiful Day"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Enter Sandman"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Paint It, Black"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }
            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();
                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                    switch(getch())
                    {
                    case 'm' :
                        MenuPrincipal();
                    }
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }
            }
        }
        ///TECLA 7 POP
        if(teclaUsuario == 55)
        {
            system("cls");
            marco();

            TituloPop(35,2);

            gotoxy(26,10);
            printf("Si queres musica popular, esta playlist es para ti.");

            gotoxy(45,12);
            printf("Canciones:");

            botonInicio(15,14,"[1]Stay");
            botonInicio(40,14,"[2]Shivers");
            botonInicio(65,14,"[3]Levitating");
            botonInicio(15,20,"[4]Blinding Lights");
            botonInicio(40,20,"[5]Good 4 u");
            botonInicio(65,20,"[6]Circles");

            botonInicio(40,25,"[V]olver");

            botonInicio(40,25,"[V]olver");
            teclaUsuario = getch();
            if(teclaUsuario == 49)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Stay"));
            }
            if(teclaUsuario == 50)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Shivers"));

            }
            if(teclaUsuario == 51)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Levitating"));
            }
            if(teclaUsuario == 52)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Blinding Lights"));
            }
            if(teclaUsuario == 53)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Good 4 u"));
            }
            if(teclaUsuario == 54)
            {
                lista = agregarAlPrincipioDeLalista(lista, crearNodo("Circles"));
            }
            if(teclaUsuario == 118)
            {
                crearPlaylist(lista);
            }
            system("cls");
            marco();

            Logo(79,17);
            Logo(2,17);

            gotoxy(2,1);
            printf("CREAR PLAYLIST");
            gotoxy(1,2);
            for(int i = 0; i <= 100-2; i++)
            {
                printf("%c",205);
            }

            gotoxy(36,10);
            printf("Desea seguir cargando musica?");
            botonInicio(40, 15, "[S] SI");
            botonInicio(40, 20, "[N] NO");
            switch(getch())
            {
            case 's':
                crearPlaylist(lista);
                break;
            case 'n':
                system("cls");
                marco();

                Logo(79,17);
                Logo(2,17);

                gotoxy(2,1);
                printf("CREAR PLAYLIST");
                gotoxy(1,2);
                for(int i = 0; i <= 100-2; i++)
                {
                    printf("%c",205);
                }
                boton(35,10, "[V] VER PLAYLIST CREADA");
                boton(35,20, "[M] VOLVER AL MENU");
                teclaUsuario = getch();
                if(teclaUsuario == 118)
                {
                    system("cls");
                    marco();
                    mostrarPlaylist(lista);
                    boton(35, 25, "[M] VOLVER AL MENU PRINCIPAL");
                    switch(getch())
                    {
                    case 'm' :
                        MenuPrincipal();
                    }
                }
                if(teclaUsuario == 109)
                {
                    MenuPrincipal();
                }
            }
        }
    }
}

