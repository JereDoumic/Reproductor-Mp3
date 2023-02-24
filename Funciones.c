#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <pthread.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int idUsuario;
    char nombreUsuario[40];
    char pass[40];
    int anioNacimiento;
    char genero[40];
    char pais[40];
    //int eliminado; // indica 1 o 0 si el cliente fue eliminado
} stUsuario;

typedef struct
{
    int idPlaylist;
    int idUsuario;
    int idCancion;
} stPlaylist;

const int anchoVentana = 100;
const int altoVentana = 30;

///BORDES
void marco()
{
    gotoxy(0,0);

    ///FILA SUPERIOR
    printf("%c",201);
    for(int i = 0; i <= anchoVentana-2; i++)
    {
        printf("%c",205);
    }
    printf("%c",187);

    ///FILA INTERMEDIA
    for(int i = 1; i <= altoVentana-2; i++)
    {
        gotoxy(0,i);
        printf("%c",186);
        for(int i = 0; i <= anchoVentana-2; i++)
        {
            printf("%c",32);
        }
        gotoxy(anchoVentana,i);
        printf("%c",186);
    }

    ///FILA INFERIOR
    gotoxy(0,altoVentana-2);
    printf("%c",200);
    for(int i = 0; i <= anchoVentana-2; i++)
    {
        printf("%c",205);
    }
    printf("%c",188);
}

void botonInicio(int x, int y, char texto[])
{

    const int ancho = 20;
    const int alto = 3;

    gotoxy(x,y);

    ///FILA SUPERIOR
    printf("%c",218);
    for(int i = 0; i <= ancho-2; i++)
    {
        printf("%c",196);
    }
    printf("%c",191);

    ///FILA INTERMEDIA
    for(int i = 0; i < alto-2; i++)
    {

        gotoxy(x,y+i+1);
        printf("%c",179);

        gotoxy(x+((ancho/2)-(strlen(texto)/2)),y+i+1);
        printf("%s",texto);// IMPRIMO EL TEXTO

        gotoxy(x+ancho,y+i+1);
        printf("%c",179);
    }

    ///FILA INFERIOR
    gotoxy(x,y+alto-1);
    printf("%c",192);

    for(int i = 0; i <= ancho-2; i++)
    {
        printf("%c",196);
    }
    printf("%c",217);
}

void boton(int x, int y, char texto[])
{
    const int ancho = 30;
    const int alto = 3;

    gotoxy(x,y);

    ///FILA SUPERIOR
    printf("%c",218);
    for(int i = 0; i <= ancho-2; i++)
    {
        printf("%c",196);
    }
    printf("%c",191);

    ///FILA INTERMEDIA
    for(int i = 0; i < alto-2; i++)
    {

        gotoxy(x,y+i+1);
        printf("%c",179);

        gotoxy(x+((ancho/2)-(strlen(texto)/2)),y+i+1);
        printf("%s",texto);// IMPRIMO EL TEXTO

        gotoxy(x+ancho,y+i+1);
        printf("%c",179);

    }

    ///FILA INFERIOR
    gotoxy(x,y+alto-1);
    printf("%c",192);

    for(int i = 0; i <= ancho-2; i++)
    {
        printf("%c",196);
    }
    printf("%c",217);
}

void input(int x, int y, char texto[])
{
    gotoxy(x,y);
    printf("%s:", texto);
}

void input2(int x, int y, char label[])
{
    gotoxy(x,y);
    printf("%s:", label);
    gotoxy(x+20,y);
    printf("________________________");
}

///TITULOS
void TituloInicio(int x, int y)
{
    gotoxy(20,1);
    printf("%s","                                  ___     ___    ___    __ \n");
    gotoxy(20,1+1);
    printf("%s","     /\\                          |__ \\   / _ \\  |__ \\  /_ |\n");
    gotoxy(20,1+2);
    printf("%s","    /  \\     _ __    ___  ___       ) | | | | |    ) |  | |\n");
    gotoxy(20,1+3);
    printf("%s","   / /\\ \\   | '__| / _ \ // __|     / /  | | | |   / /   | |\n");
    gotoxy(20,1+4);
    printf("%s","  / ____ \\  | |   |  __/ \\__ \\    / /_  | |_| |  / /_   | |\n");
    gotoxy(20,1+5);
    printf("%s"," /_/    \\_\\ |_|    \\___| |___/   |____|  \\___/  |____|  |_|\n");
}

void TituloMenu(int x, int y)
{
    gotoxy(x,y);
    printf("%s","   _____  ____________________  _________     ______________   ________  ____ \n");
    gotoxy(x,y+1);
    printf("%s","  /  _  \\ \\______  \\_   _____/ /   _____/     \\_____ \\   _  \\  \\_____  \\/_   |\n");
    gotoxy(x,y+2);
    printf("%s"," /  /_\\  \\|       _/|    __)_  \\_____ \\       /  ____/  /_\\  \\  /  ____/ |   |\n");
    gotoxy(x,y+3);
    printf("%s","/    |    \\    |   \\|        \\/        \\     /       \\  \\_/   \\/       \\ |   |\n");
    gotoxy(x,y+4);
    printf("%s","\\____|__  /____|_  /_______  /_______  /     \\_______ \\_____  /\\_______ \\|___|\n");
    gotoxy(x,y+5);
    printf("%s","        \\/       \\/        \\/        \\/              \\/     \\/         \\/     \n");
}

void TituloSalir(int x, int y)
{
    gotoxy(x,y);
    printf("%s","       _           ___                        \n");
    gotoxy(x,y+1);
    printf("%s","      dM.          `MM 68b                    \n");
    gotoxy(x,y+2);
    printf("%s","     ,MMb           MM Y89                    \n");
    gotoxy(x,y+3);
    printf("%s","     d'YM.      ____MM ___   _____     ____   \n");
    gotoxy(x,y+4);
    printf("%s","    ,P `Mb     6MMMMMM `MM  6MMMMMb   6MMMMb\\ \n");
    gotoxy(x,y+5);
    printf("%s","    d'  YM.   6M'  `MM  MM 6M'   `Mb MM'    ` \n");
    gotoxy(x,y+6);
    printf("%s","   ,P   `Mb   MM    MM  MM MM     MM YM.      \n");
    gotoxy(x,y+7);
    printf("%s","   d'    YM.  MM    MM  MM MM     MM  YMMMMb  \n");
    gotoxy(x,y+8);
    printf("%s","  ,MMMMMMMMb  MM    MM  MM MM     MM      `Mb \n");
    gotoxy(x,y+9);
    printf("%s","  d'      YM. YM.  ,MM  MM YM.   ,M9 L    ,MM \n");
    gotoxy(x,y+10);
    printf("%s","_dM_     _dMM_ YMMMMMM__MM_ YMMMMM9  MYMMMM9  \n");
}

void TituloReproductor(int x, int y)
{
    gotoxy(x,y);
    printf("%s"," _______                        _                     _        \n");
    gotoxy(x,y+1);
    printf("%s","(_______)                      | |                   | |       \n");
    gotoxy(x,y+2);
    printf("%s"," _____    ___  ____ _   _  ____| | _   ____ ____   _ | | ___ _ \n");
    gotoxy(x,y+3);
    printf("%s","|  ___)  /___)/ ___) | | |/ ___) || \\ / _  |  _ \\ / || |/ _ (_)\n");
    gotoxy(x,y+4);
    printf("%s","| |_____|___ ( (___| |_| ( (___| | | ( ( | | | | ( (_| | |_| | \n");
    gotoxy(x,y+5);
    printf("%s","|_______|___/ \\____)\\____|\\____)_| |_|\\_||_|_| |_|\\____|\\___(_)\n");
}

void TituloClasica(int x, int y)
{
    gotoxy(x,y);
    printf("%s","   ___ _           _           \n");
    gotoxy(x,y+1);
    printf("%s","  / __\\ | __ _ ___(_) ___ __ _ \n");
    gotoxy(x,y+2);
    printf("%s"," / /  | |/ _` / __| |/ __/ _` |\n");
    gotoxy(x,y+3);
    printf("%s","/ /___| | (_| \\__ \| | (_| (_| |\n");
    gotoxy(x,y+4);
    printf("%s","\\____/|_|\\__,_|___/_|\\___\\__,_|\n");
}

void TituloElectro(int x, int y)
{
    gotoxy(x,y);
    printf("%s"," ______  __      ______  ______  ______ ______  ______    \n");
    gotoxy(x,y+1);
    printf("%s","/\\  ___\\/\\ \\    /\\  ___\\/\\  ___\\/\\__  _/\\  == \\/\\  __ \\   \n");
    gotoxy(x,y+2);
    printf("%s","\\ \\  __\\\\\ \\ \\___\\ \\  __\\\\ \\ \\___\\/_/\\ \\\\ \\  __<\\ \\ \\/\\ \\  \n");
    gotoxy(x,y+3);
    printf("%s"," \\ \\_____\\ \\_____\\ \\_____\\ \\_____\\ \\ \\_\\\\ \\_\\ \\_\\ \\_____\\ \n");
    gotoxy(x,y+4);
    printf("%s","  \\/_____/\\/_____/\\/_____/\\/_____/  \\/_/ \\/_/ /_/\\/_____/ \n");
}

void TituloLatina(int x, int y)
{
    gotoxy(x,y);
    printf("%s","'||               ||                          \n");
    gotoxy(x,y+1);
    printf("%s"," ||               ||     ''                   \n");
    gotoxy(x,y+2);
    printf("%s"," ||      '''|.  ''||''   ||  `||''|,   '''|.  \n");
    gotoxy(x,y+3);
    printf("%s"," ||     .|''||    ||     ||   ||  ||  .|''||  \n");
    gotoxy(x,y+4);
    printf("%s",".||...| `|..||.   `|..' .||. .||  ||. `|..||. \n");
}

void TituloNacional(int x, int y)
{
    gotoxy(x,y);
    printf("%s"," ____  _____                 _                          __   \n");
    gotoxy(x,y+1);
    printf("%s","|_   \\|_   _|               (_)                        [  |  \n");
    gotoxy(x,y+2);
    printf("%s","  |   \\ | |   ,--.   .---.  __   .--.   _ .--.   ,--.   | |  \n");
    gotoxy(x,y+3);
    printf("%s","  | |\\ \\| |  `'_\\ : / /'`\\][  |/ .'`\\ \\[ `.-. | `'_\\ :  | |  \n");
    gotoxy(x,y+4);
    printf("%s"," _| |_\\   |_ // | |,| \\__.  | || \\__. | | | | | // | |, | |  \n");
    gotoxy(x,y+5);
    printf("%s","|_____|\\____|\\'-;__/'.___.'[___]'.__.' [___||__]\\'-;__/[___] \n");
}

void TituloRap(int x, int y)
{
    gotoxy(x,y);
    printf("%s","    _/_/_/      _/_/    _/_/_/    \n");
    gotoxy(x,y+1);
    printf("%s","   _/    _/  _/    _/  _/    _/   \n");
    gotoxy(x,y+2);
    printf("%s","  _/_/_/    _/_/_/_/  _/_/_/      \n");
    gotoxy(x,y+3);
    printf("%s"," _/    _/  _/    _/  _/           \n");
    gotoxy(x,y+4);
    printf("%s","_/    _/  _/    _/  _/             \n");
    gotoxy(x,y+5);
    printf("%s","\n");
}

void TituloRock(int x, int y)
{
    gotoxy(x,y);
    printf("%s"," (         )                )  \n");
    gotoxy(x,y+1);
    printf("%s"," )\\ )   ( /(      (      ( /(  \n");
    gotoxy(x,y+2);
    printf("%s","(()/(   )\\())     )\\     )\\()) \n");
    gotoxy(x,y+3);
    printf("%s"," /(_)) ((_)\\    (((_)   ((_)\\  \n");
    gotoxy(x,y+4);
    printf("%s","(_))     ((_)   )\\___   _ ((_) \n");
    gotoxy(x,y+5);
    printf("%s","| _ \\   / _ \\  ((/ __| | |/ /  \n");
    gotoxy(x,y+6);
    printf("%s","|   /  | (_) |  | (__  | ' <   \n");
    gotoxy(x,y+7);
    printf("%s","|_|_\\   \\___/    \\___| |_|\\_\\  \n");
}

void TituloPop(int x, int y)
{
    gotoxy(x,y);
    printf("%s",":::::::::   ::::::::  :::::::::  \n");
    gotoxy(x,y+1);
    printf("%s",":+:    :+: :+:    :+: :+:    :+: \n");
    gotoxy(x,y+2);
    printf("%s","+:+    +:+ +:+    +:+ +:+    +:+ \n");
    gotoxy(x,y+3);
    printf("%s","+#++:++#+  +#+    +:+ +#++:++#+  \n");
    gotoxy(x,y+4);
    printf("%s","+#+        +#+    +#+ +#+        \n");
    gotoxy(x,y+5);
    printf("%s","#+#        #+#    #+# #+#        \n");
    gotoxy(x,y+6);
    printf("%s","###         ########  ###        \n");
}

///LOGO
void Logo(int x, int y)
{
    gotoxy(x,y);
    printf("%s","         _          \n");
    gotoxy(x,y+1);
    printf("%s","        / /\\        \n");
    gotoxy(x,y+2);
    printf("%s","       / / \ \\      \n");
    gotoxy(x,y+3);
    printf("%s","      / / /\\ \\     \n");
    gotoxy(x,y+4);
    printf("%s","     / / /\\ \\ \\     \n");
    gotoxy(x,y+5);
    printf("%s","    / / /  \\ \\ \\    \n");
    gotoxy(x,y+6);
    printf("%s","   / / /___/ /\\ \\   \n");
    gotoxy(x,y+7);
    printf("%s","  / / /_____/ /\\ \\  \n");
    gotoxy(x,y+8);
    printf("%s"," / /_________/\\ \\ \\ \n");
    gotoxy(x,y+9);
    printf("%s","/ / /_       __\\ \\_\\ \n");
    gotoxy(x,y+10);
    printf("%s","\\_\\___\\     /____/_/\n");
}

///FUNCIONES PARA EL REGISTRO E INICIO DE SESION
stUsuario crearUsuario(char nombreUsuario[40], char password[40], int IDusuario, int anioNacimiento, char genero[40], char pais[40])
{
    stUsuario usuario;
    strcpy(usuario.nombreUsuario, nombreUsuario);
    strcpy(usuario.pass, password);
    strcpy(usuario.genero, genero);
    strcpy(usuario.pais, pais);
    usuario.idUsuario = IDusuario;
    usuario.anioNacimiento = anioNacimiento;
    return usuario;
}

void mostrarUsuario(stUsuario usuario)
{
    printf("\n\n nombre: %s", usuario.nombreUsuario);
    printf("\n id: %d", usuario.idUsuario);
    printf("\n password: %s", usuario.pass);
    printf("\n anio Nacimiento: %d", usuario.anioNacimiento);
    printf("\n genero: %s", usuario.genero);
    printf("\n pais: %s", usuario.pais);
}

void guardarUsuarioEnArchivo(stUsuario usuario)
{
    FILE * archivo = fopen("usuarios.bin", "a+b");
    if(archivo != NULL)
    {
        fwrite(&usuario, sizeof(usuario), 1, archivo);

        fclose(archivo);
    }
}

int buscarPorID(int id)
{
    FILE* archivo = fopen("usuarios.bin", "rb");

    int flag = 0;

    if(archivo != NULL)
    {
        stUsuario usuario;

        while(fread(&usuario, sizeof(usuario), 1, archivo) > 0 && flag == 0)
        {
            if(id == usuario.idUsuario)
            {
                flag = 1;
            }
        }

        fclose(archivo);
    }
    return flag;
}

int validarUsuarioID(int ID)
{
    FILE * archivo = fopen("usuarios.bin", "rb");
    int flag = 0;
    stUsuario usuario;
    if(archivo != NULL)
    {
        while(fread(&usuario, sizeof(stUsuario), 1, archivo)> 0)
        {
            if (usuario.idUsuario == ID)
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

int validarIDusuarioYPassword(int ID, char password[40])
{
    int flag = 0;
    FILE * archivo = fopen("usuarios.bin", "rb");
    if(archivo != NULL)
    {
        stUsuario usuario;
        while(fread(&usuario, sizeof(stUsuario), 1, archivo) > 0)
        {
            if(usuario.idUsuario == ID && strcmpi(password, usuario.pass == 0))
            {
                flag = 1;
            }
        }
        fclose(archivo);
    }
    return flag;
}

stUsuario eliminarUsuario(stUsuario usuario)
{
    strcpy(usuario.nombreUsuario, " ");
    usuario.idUsuario = 0;
    return usuario;
}

///PANTALLAS
//MOVILIDAD
void Inicio()
{
    marco();
///TITULO Y LOGOS
    TituloInicio(20,5);
    Logo(5,12);
    Logo(76,12);
///TEXTO DE BIENVENIDA
    gotoxy(35,10);
    printf("Bienvenido al nuevo Ares 2021");
    gotoxy(30,12);
    printf("< Toda la musica que quieras aqui y ahora >");
///BOTONES
    botonInicio(40,12+3*1,"[L]og In");
    botonInicio(40,12+3*2,"[R]egistrarse");
    botonInicio(40,12+3*3,"[S]salir de Ares");
///AGREGADOS DE ABAJO
    gotoxy(2,27);
    printf("Derechos reservados hasta que los compre Facebook.\n\n");
    gotoxy(90,27);
    printf("Ares2021©.\n\n");
//FUNCIONALIDAD
    switch(getch())
    {
    case 'l':
        Login();
        break;
    case 'r':
        Registro();
        break;
    case 's':
        Salir();
        break;
    default:
        Inicio();
        break;
    }
}

void Registro()
{
    marco();

    gotoxy(2,1);
    printf("REGISTRO: Cree su perfil siguiendo las instrucciones");
    gotoxy(1,2);
    for(int i = 0; i <= anchoVentana-2; i++)
    {
        printf("%c",205);
    }

    gotoxy(2,3);
    printf("ID > numero de 4 digitos \n");
    gotoxy(2,5);
    printf("NOMBRE DE USUARIO > debe contener al menos 4 letras \n");
    gotoxy(2,7);
    printf("CONTRASENA > minimo 4 caracteres \n");
    gotoxy(2,9);
    printf("GENERO > M (masculino), F (femenino) u O (Otro) \n");

    gotoxy(1,11);
    for(int i = 0; i <= anchoVentana-2; i++)
    {
        printf("%c",96);
    }

    input2(2,12,"NOMBRE DE USUARIO");
    input2(2,12+2,"PASSWORD");
    input2(2,12+4,"ID DE USUARIO");
    input2(2,12+6,"ANIO DE NACIMIENTO");
    input2(2,12+8,"GENERO");
    input2(2,12+10,"PAIS");


    char nombreUsuario[40];
    char password[40];
    int IDusuario;
    int anioNacimiento;
    char genero[40];
    char pais[40];

    gotoxy(22,12);
    fflush(stdin);
    gets(&nombreUsuario);

    gotoxy(22,12+2);
    fflush(stdin);
    gets(&password);

    gotoxy(22,12+4);
    fflush(stdin);
    scanf("%d", &IDusuario);


    gotoxy(22,12+6);
    fflush(stdin);
    scanf("%d", &anioNacimiento);


    gotoxy(22,12+8);
    fflush(stdin);
    gets(&genero);

    gotoxy(22,12+10);
    fflush(stdin);
    gets(&pais);

    if(buscarPorID(IDusuario) == 0)
    {

        guardarUsuarioEnArchivo(crearUsuario(nombreUsuario, password, IDusuario, anioNacimiento, genero, pais));
        gotoxy(20,26);
        printf("REGISTRO EXITOSO");
        Sleep(1000);
        system("cls");
        Inicio();
    }
    else
    {
        system("cls");
        gotoxy(20,20);
        printf("ESE ID YA ESTA EN USO, PRUEBE CON OTRO");
        getch();
        system("cls");
        Registro();
    }

    botonInicio(40,25,"[V]olver");

    Logo(79,17);
}

void Login()
{
    marco();

    Logo(79,17);
    Logo(2,17);

    gotoxy(2,1);
    printf("LOGIN: Ingrese sus datos");
    gotoxy(1,2);
    for(int i = 0; i <= anchoVentana-2; i++)
    {
        printf("%c",205);
    }
    gotoxy(5,9);
    printf("(Recuerde chequear si el Bloq Mayus esta activado).");

    input2(5,5,"ID DE USUARIO");
    input2(5,5+2,"CONTRASENA");

    int IDusuario;
    char password[40];

    gotoxy(5+20,5);//usuario
    fflush(stdin);
    scanf("%d", &IDusuario);

    gotoxy(5+20,5+2);//contrasena
    fflush(stdin);
    gets(&password);

    if(validarIDusuarioYPassword(IDusuario, password) == 1)
    {
        gotoxy(35,20);
        printf("BIENVENIDO A ARES");
        gotoxy(55,20);
        printf("3");
        Sleep(800);
        gotoxy(55,20);
        printf("2");
        Sleep(800);
        gotoxy(55,20);
        printf("1");
        Sleep(800);

        MenuPrincipal();
    }
    if(IDusuario == 1111)
    {
        pantallaUsuarioAdministrador();
    }
    else
    {
        ErrorLogin();
    }
}

void ErrorLogin()
{
    marco();

    Logo(79,17);
    Logo(2,17);

    gotoxy(2,1);
    printf("ERROR: Sus datos son incorrectos");
    gotoxy(1,2);
    for(int i = 0; i <= anchoVentana-2; i++)
    {
        printf("%c",205);
    }

    gotoxy(22,9);
    printf("Revise si su ID y su contrasena son los correctos.");

    boton(30, 15+2, "[V]OLVER");
    boton(30, 10+2, "[I]NTENTAR DE NUEVO");
    switch(getch())
    {
    case 'i':
        system("cls");
        Login();
        break;
    case 'v':
        system("cls");
        Inicio();
        break;
    }
}

void MenuPrincipal()
{
    marco();

    TituloMenu(11,1);
    Logo(5,12);
    Logo(76,12);

    gotoxy(10,8);
    printf("Seleccione una playlist predeteminada, o cree una propia con los temas que quiera");

    botonInicio(28,11,"[1]Clasica");
    botonInicio(52,11,"[2]Electro");
    botonInicio(28,14,"[3]Latina");
    botonInicio(52,14,"[4]Nacional");
    botonInicio(28,17,"[5]Rap");
    botonInicio(52,17,"[6]Rock");
    botonInicio(40,20,"[7]Pop");
    botonInicio(75,25,"[C]rear Playlist");
    botonInicio(5,25,"[G]uardar Canciones");

    botonInicio(40,25,"[V]olver");

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        Clasica();
        break;
    case '2':
        Electro();
        break;
    case '3':
        Latina();
        break;
    case '4':
        Nacional();
        break;
    case '5':
        Rap();
        break;
    case '6':
        Rock();
        break;
    case '7':
        Pop();
        break;
    case 'v':
        Inicio();
        break;
    case 'c':
        PreguntaCrearPlaylist();
        break;
    case 'g':
        pantallaGuardarCanciones();
        break;
    default:
        MenuPrincipal();
        break;
    }
}

void Salir()
{
    marco();

    TituloSalir(28,1);

    gotoxy(38,17);
    printf("Gracias por usar Ares 2021.");
    gotoxy(43,19);
    printf("Hasta la proxima!");

    Logo(5,17);
    Logo(76,17);

}

void pantallaUsuarioAdministrador()
{
    system("cls");
    marco();
    gotoxy(35,10);
    printf("BIENVENIDO ADMINISTRADOR!");
    boton(15,20, "[D] DAR DE BAJA UN USUARIO");
    boton(50,20, "[M] MODIFICAR UN USUARIO");
    boton(68,25, "[V] VOLVER");

    switch(getch())
    {
    case 'd':
        pantallaDarDeBajaUnUsuario();
    case 'm':
        pantallaModificarUnUsuario();
    case 'v':
        Inicio();
    }

}

void pantallaDarDeBajaUnUsuario()
{
    int flag = 0;
    FILE * archivo = fopen("usuarios.bin", "r+b");
    marco();
    gotoxy(22,15);
    printf("Introduzca el ID del usuario que desea eliminar: ");
    int usuarioAEliminar;
    scanf("%d", &usuarioAEliminar);
    if(archivo != NULL)
    {
        stUsuario usuario;
        while(fread(&usuario, sizeof(usuario), 1, archivo) > 0)
        {
            if(usuario.idUsuario == usuarioAEliminar)
            {
                flag = 1;
                system("cls");
                marco();
                gotoxy(25,15);
                printf("Seguro que desea eliminar al usuario: %s", usuario.nombreUsuario);
                gotoxy(42,17);
                printf("con ID: %d",usuario.idUsuario);
                boton(15, 20, "[S] Si");
                boton(50, 20, "[N] No");
                int pos = ftell(archivo)-sizeof(usuario);
                fseek(archivo, pos, SEEK_SET);
                stUsuario aux;
                strcpy(aux.nombreUsuario, " ");
                strcpy(aux.pass, " ");
                strcpy(aux.genero, " ");
                strcpy(aux.pais, " ");
                aux.idUsuario = 0;
                aux.anioNacimiento = 0;
                switch(getch())
                {
                case 's':
                    fwrite(&aux, sizeof(aux), 1, archivo);
                    system("cls");
                    marco();
                    gotoxy(35,15);
                    printf("Eliminado con exito!");
                    Sleep(2000);
                    pantallaUsuarioAdministrador();
                    break;
                case 'n':
                    pantallaDarDeBajaUnUsuario();
                    break;

                }

            }
        }
        fclose(archivo);
        if(flag == 0)
        {
            system("cls");
            marco();
            gotoxy(35,15);
            printf("Usuario no encontrado");
            Sleep(1600);
            pantallaUsuarioAdministrador();
        }
    }

}

void pantallaModificarUnUsuario()
{
    int flag = 0;
    FILE * archivo = fopen("usuarios.bin", "r+b");
    marco();
    gotoxy(22,15);
    printf("Introduzca el ID del usuario que desea modificar: ");
    int usuarioAEliminar;
    scanf("%d", &usuarioAEliminar);
    if(archivo != NULL)
    {
        stUsuario usuario;
        while(fread(&usuario, sizeof(usuario), 1, archivo) > 0)
        {
            if(usuario.idUsuario == usuarioAEliminar)
            {
                flag = 1;
                system("cls");
                marco();
                gotoxy(25,15);
                printf("Seguro que desea modificar al usuario: %s", usuario.nombreUsuario);
                gotoxy(42,17);
                printf("con ID: %d",usuario.idUsuario);
                boton(15, 20, "[S] Si");
                boton(50, 20, "[N] No");
                int pos = ftell(archivo)-sizeof(usuario);
                fseek(archivo, pos, SEEK_SET);
                stUsuario aux;
                switch(getch())
                {
                case 's':
                    system("cls");
                    marco();
                    input2(2,12,"NOMBRE DE USUARIO");
                    input2(2,12+2,"PASSWORD");
                    input2(2,12+4,"ID DE USUARIO");
                    input2(2,12+6,"ANIO DE NACIMIENTO");
                    input2(2,12+8,"GENERO");
                    input2(2,12+10,"PAIS");

                    gotoxy(22,12);
                    fflush(stdin);
                    gets(&aux.nombreUsuario);

                    gotoxy(22,12+2);
                    fflush(stdin);
                    gets(&aux.pass);

                    gotoxy(22,12+4);
                    fflush(stdin);
                    scanf("%d", &aux.idUsuario);


                    gotoxy(22,12+6);
                    fflush(stdin);
                    scanf("%d", &aux.anioNacimiento);


                    gotoxy(22,12+8);
                    fflush(stdin);
                    gets(&aux.genero);

                    gotoxy(22,12+10);
                    fflush(stdin);
                    gets(&aux.pais);
                    fwrite(&aux, sizeof(aux), 1, archivo);
                    system("cls");
                    marco();
                    gotoxy(35,15);
                    printf("Cambiado con exito con exito!");
                    Sleep(2000);
                    pantallaUsuarioAdministrador();
                    break;
                case 'n':
                    pantallaDarDeBajaUnUsuario();
                default:
                    pantallaModificarUnUsuario();
                    break;

                }

            }
        }
        fclose(archivo);
        if(flag == 0)
        {
            system("cls");
            marco();
            gotoxy(35,15);
            printf("Usuario no encontrado");
            Sleep(1600);
            pantallaUsuarioAdministrador();
        }
    }
}

void pantallaGuardarCanciones()
{
    system("cls");
    marco();
    gotoxy(10,8);
    printf("Seleccione una playlist predeteminada, o cree una propia con los temas que quiera");

    botonInicio(28,11,"[1]Clasica");
    botonInicio(52,11,"[2]Electro");
    botonInicio(28,14,"[3]Latina");
    botonInicio(52,14,"[4]Nacional");
    botonInicio(28,17,"[5]Rap");
    botonInicio(52,17,"[6]Rock");
    botonInicio(40,20,"[7]Pop");
    char can[30];
    switch(getch())
    {
    case '3':
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
        FILE * archivo = fopen("canciones.bin", "ab");
        if(archivo != NULL)
        {
            switch(getch())
            {
            case '1':
                fwrite("Despacito", sizeof("Despacito"), 1, archivo);
                pantallaSeguirGuardandoCanciones();
                break;
            case '2':
                fwrite("Dile", sizeof("Dile"), 1, archivo);
                pantallaSeguirGuardandoCanciones();
                break;
            case '3':
                fwrite("Goteo", sizeof("Goteo"), 1, archivo);
                pantallaSeguirGuardandoCanciones();
                break;
            case '4':
                fwrite("Todo de ti", sizeof("Todo de ti"), 1, archivo);
                pantallaSeguirGuardandoCanciones();
                break;
            case '5':
                fwrite("Ella me levanto", sizeof("Ella me levanto"), 1, archivo);
                pantallaSeguirGuardandoCanciones();
                break;
            case '6':
                fwrite("Felices los 4", sizeof("Felices los 4"), 1, archivo);
                pantallaSeguirGuardandoCanciones();
                break;
            case 'v':
                MenuPrincipal();
                break;
            default:
                Latina();
                break;
            }



        }
    }
}


void pantallaSeguirGuardandoCanciones()
{
    system("cls");
    marco();
    gotoxy(30,15);
    printf("Quiere seguir guardando canciones?");
    boton(15, 20, "[S] Si");
    boton(50, 20, "[N] No");
    switch(getch())
    {
    case 's':
        pantallaGuardarCanciones();
        break;;
    case 'n':
        MenuPrincipal();
        break;
    default:
        pantallaSeguirGuardandoCanciones();
    }
}

//PLAYLISTS
void Clasica()
{
    marco();

    TituloClasica(35,1);

    gotoxy(10,8);
    printf("Esta playlist esta disenada para los apasionados de la muscia culta europea");
    gotoxy(30,9);
    printf("desarrollada entre 1750 y 1900 aproximadamente.");

    gotoxy(45,12);
    printf("Canciones:");

    botonInicio(15,14,"[1]Clair de Lune");
    botonInicio(40,14,"[2]Nocturne op.9");
    botonInicio(65,14,"[3]Moonlight Sonata");
    botonInicio(15,20,"[4]Winter");
    botonInicio(40,20,"[5]December");
    botonInicio(65,20,"[6]Gymnopedie No.1");

    botonInicio(40,25,"[V]olver");

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        ClairdeLune();
        break;
    case '2':
        Nocturne();
        break;
    case '3':
        MoonlightSonata();
        break;
    case '4':
        Winter();
        break;
    case '5':
        December();
        break;
    case '6':
        Gymnopedie();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Clasica();
        break;
    }
}

void Electro()
{
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

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        Faded();
        break;
    case '2':
        E3();
        break;
    case '3':
        TheBusiness();
        break;
    case '4':
        YouAreTheOne();
        break;
    case '5':
        Levels();
        break;
    case '6':
        RosesRemix();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Electro();
        break;
    }
}

void Latina()
{
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

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        Despacito();
        break;
    case '2':
        Dile();
        break;
    case '3':
        Goteo();
        break;
    case '4':
        TododeTi();
        break;
    case '5':
        EllaMeLevanto();
        break;
    case '6':
        FelicesLos4();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Latina();
        break;
    }
}

void Nacional()
{
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

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        DeMusicaLigera();
        break;
    case '2':
        LosDinosaurios();
        break;
    case '3':
        Bajan();
        break;
    case '4':
        TiraParaArriba();
        break;
    case '5':
        LamentoBoliviano();
        break;
    case '6':
        JiJiJi();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Nacional();
        break;
    }
}

void Rap()
{
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

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        ShookOnes();
        break;
    case '2':
        Juicy();
        break;
    case '3':
        LoseYourself();
        break;
    case '4':
        FuckThaPolice();
        break;
    case '5':
        AllOfTheLights();
        break;
    case '6':
        InDaClub();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Rap();
        break;
    }
}

void Rock()
{
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

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        Thunderstruck();
        break;
    case '2':
        WeWillRockYou();
        break;
    case '3':
        BlitzkriegBop();
        break;
    case '4':
        BeautifulDay();
        break;
    case '5':
        EnterSandman();
        break;
    case '6':
        PaintItBlack();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Rock();
        break;
    }
}

void Pop()
{
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

    //FUNCIONALIDAD
    switch(getch())
    {
    case '1':
        Stay();
        break;
    case '2':
        Shivers();
        break;
    case '3':
        Levitating();
        break;
    case '4':
        BlindingLights();
        break;
    case '5':
        Good4u();
        break;
    case '6':
        Circles();
        break;
    case 'v':
        MenuPrincipal();
        break;
    default:
        Pop();
        break;
    }
}

///FUNCIONES PARA REPRODUCIR CANCIONES MEDIANTE HILOS
void detenerCancion()
{
    switch(getch())
    {
    case 'v':
        sndPlaySound("silencio.wav", 0);
        break;
    }
}

void detenerHilo(char hilo[20])
{
    pthread_mutexattr_destroy(hilo);
}

//CLASICA
void ClairDeluneCancion()
{
    sndPlaySound("ClairDeLune.wav", SND_ASYNC);
}

void NocturneCancion()
{
    sndPlaySound("Nocturne.wav", SND_ASYNC);
}

void MoonlightSonataCancion()
{
    sndPlaySound("MoonlightSonata.wav", SND_ASYNC);
}

void WinterCancion()
{
    sndPlaySound("Winter.wav", SND_ASYNC);
}

void DecemberCancion()
{
    sndPlaySound("December.wav", SND_ASYNC);
}

void GymnopedieCancion()
{
    sndPlaySound("Gymnopedie.wav", SND_ASYNC);
}

//ELECTRO
void FadedCancion()
{
    sndPlaySound("Faded.wav", SND_ASYNC);
}

void E3Cancion()
{
    sndPlaySound("E3.wav", SND_ASYNC);
}

void TheBusinessCancion()
{
    sndPlaySound("TheBusiness.wav", SND_ASYNC);
}

void YouAreTheOneCancion()
{
    sndPlaySound("YouAreTheOne.wav", SND_ASYNC);
}

void LevelsCancion()
{
    sndPlaySound("Levels.wav", SND_ASYNC);
}

void RosesRemixCancion()
{
    sndPlaySound("Roses.wav", SND_ASYNC);
}

//LATINA
void DespacitoCancion()
{
    sndPlaySound("Despacito.wav", SND_ASYNC);
}

void DileCancion()
{
    sndPlaySound("Dile.wav", SND_ASYNC);
}

void GoteoCancion()
{
    sndPlaySound("Goteo.wav", SND_ASYNC);
}

void TododeTiCancion()
{
    sndPlaySound("TododeTi.wav", SND_ASYNC);
}

void EllaMeLevantoCancion()
{
    sndPlaySound("Ella Me Levanto.wav", SND_ASYNC);
}

void FelicesLos4Cancion()
{
    sndPlaySound("FelicesLos4.wav", SND_ASYNC);
}

//NACIONAL
void DeMusicaLigeraCancion()
{
    sndPlaySound("DeMusicaLigera.wav", SND_ASYNC);
}

void LosDinosauriosCancion()
{
    sndPlaySound("LosDinosaurios.wav", SND_ASYNC);
}

void BajanCancion()
{
    sndPlaySound("Bajan.wav", SND_ASYNC);
}

void TiraParaArribaCancion()
{
    sndPlaySound("TiraParaArriba.wav", SND_ASYNC);
}

void LamentoBolivianoCancion()
{
    sndPlaySound("LamentoBoliviano.wav", SND_ASYNC);
}

void JiJiJiCancion()
{
    sndPlaySound("JiJiJi.wav", SND_ASYNC);
}

//RAP
void ShookOnesCancion()
{
    sndPlaySound("ShookOnes.wav", SND_ASYNC);
}

void JuicyCancion()
{
    sndPlaySound("Juicy.wav", SND_ASYNC);
}

void LoseYourselfCancion()
{
    sndPlaySound("LoseYourself.wav", SND_ASYNC);
}

void FuckThaPoliceCancion()
{
    sndPlaySound("FuckThaPolice.wav", SND_ASYNC);
}

void AllOfTheLightsCancion()
{
    sndPlaySound("AllOfTheLights.wav", SND_ASYNC);
}

void InDaClubCancion()
{
    sndPlaySound("InDaClub.wav", SND_ASYNC);
}

//ROCK
void ThunderstruckCancion()
{
    sndPlaySound("Thunderstruck.wav", SND_ASYNC);
}

void WeWillRockYouCancion()
{
    sndPlaySound("WeWillRockYou.wav", SND_ASYNC);
}

void BlitzkriegBopCancion()
{
    sndPlaySound("BlitzkriegBop.wav", SND_ASYNC);
}

void BeautifulDayCancion()
{
    sndPlaySound("BeautifulDay.wav", SND_ASYNC);
}

void EnterSandmanCancion()
{
    sndPlaySound("EnterSandman.wav", SND_ASYNC);
}

void PaintItBlackCancion()
{
    sndPlaySound("PaintItBlack.wav", SND_ASYNC);
}

//POP
void StayCancion()
{
    sndPlaySound("Stay.wav", SND_ASYNC);
}

void ShiversCancion()
{
    sndPlaySound("Shivers.wav", SND_ASYNC);
}

void LevitatingCancion()
{
    sndPlaySound("Levitating.wav", SND_ASYNC);
}

void BlindingLightsCancion()
{
    sndPlaySound("BlindingLights.wav", SND_ASYNC);
}

void Good4uCancion()
{
    sndPlaySound("Good4u.wav", SND_ASYNC);
}

void CirclesCancion()
{
    sndPlaySound("Circles.wav", SND_ASYNC);
}

///REPRODUCTOR
//CLASICA
void ClairdeLunePantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Claire de Lune");
    gotoxy(6,13);
    printf("Artista: Claude Debussy");
    gotoxy(6,16);
    printf("Album: Fetes Galantes");
    gotoxy(6,19);
    printf("Ano: 1905");
    gotoxy(6,22);
    printf("Genero: Clasica");

    gotoxy(40,22);
    printf("Duracion: 5:03");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Clair de Lune, Luz de Luna. El joven Claude Debussy se");
    gotoxy(40,14);
    printf("inspiro en Paul Verlaine para componer sus Fetes Galantes,");
    gotoxy(40,16);
    printf("un conjunto de cinco canciones para voz y piano entre las");
    gotoxy(40,18);
    printf("que se encontraba el Clair de lune.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Clasica();
        break;
    case 75:
        ClairdeLune();
        break;
    case 77:
        Nocturne();
        break;
    default:
        ClairdeLunePantalla();
        break;
    }
}
void ClairdeLune()
{
    pthread_t HiloClairdeLuneCancion;
    pthread_t HiloClairdeLune;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloClairdeLuneCancion, NULL, ClairDeluneCancion, NULL);
    pthread_create(&HiloClairdeLune, NULL, ClairdeLunePantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloClairdeLuneCancion, NULL);
    pthread_join(HiloClairdeLune, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void NocturnePantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Nocturne op.9");
    gotoxy(6,13);
    printf("Artista: Frederic Chopin");
    gotoxy(6,16);
    printf("Album: Los Nocturnos");
    gotoxy(6,19);
    printf("Ano: 1832");
    gotoxy(6,22);
    printf("Genero: Clasica");

    gotoxy(40,22);
    printf("Duracion: 4:30");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Nocturne op.9 fue dedicado a Madame Marie Pleyel.");
    gotoxy(40,14);
    printf("Chopin compuso su nocturno masv conocido en la tonalidad de");
    gotoxy(40,16);
    printf("mi bemol mayor, cuando tenia alrededor de 20 anos.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Clasica();
        break;
    default:
    case 75:
        ClairdeLune();
        break;
    case 77:
        MoonlightSonata();
        break;
        NocturnePantalla();
        break;
    }
}
void Nocturne()
{
    pthread_t HiloNocturneCancion;
    pthread_t HiloNocturne;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloNocturneCancion, NULL, NocturneCancion, NULL);
    pthread_create(&HiloNocturne, NULL, NocturnePantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloNocturneCancion, NULL);
    pthread_join(HiloNocturne, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void MoonlightSonataPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Moonlight Sonata");
    gotoxy(6,13);
    printf("Artista: Ludwig van Beethoven");
    gotoxy(6,16);
    printf("Album: Sonata para piano n.14");
    gotoxy(6,19);
    printf("Ano: 1802");
    gotoxy(6,22);
    printf("Genero: Clasica");

    gotoxy(40,22);
    printf("Duracion: 7:35");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Se trata de una de las obras mavs famosas del autor.");
    gotoxy(40,14);
    printf("La pieza fue compuesta en 1801 y publicada por Giovanni");
    gotoxy(40,16);
    printf("Cappi en Viena en marzo de 1802.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Clasica();
        break;
    case 75:
        Nocturne();
        break;
    case 77:
        Winter();
        break;
    default:
        MoonlightSonataPantalla();
        break;
    }
}
void MoonlightSonata()
{
    pthread_t HiloMoonlightSonataCancion;
    pthread_t HiloMoonlightSonata;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloMoonlightSonataCancion, NULL, MoonlightSonataCancion, NULL);
    pthread_create(&HiloMoonlightSonata, NULL, MoonlightSonataPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloMoonlightSonataCancion, NULL);
    pthread_join(HiloMoonlightSonata, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void WinterPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Winter");
    gotoxy(6,13);
    printf("Artista: Antonio Vivaldi");
    gotoxy(6,16);
    printf("Album: Las 4 Estaciones");
    gotoxy(6,19);
    printf("Ano: 1725");
    gotoxy(6,22);
    printf("Genero: Clasica");

    gotoxy(40,22);
    printf("Duracion: 9:30");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Las cuatro estaciones es la obra mas conocida de Vivaldi.");
    gotoxy(40,14);
    printf("Cada uno esta dedicado a una estacion: La primavera, El");
    gotoxy(40,16);
    printf("El verano, El otonvvvo y El invierno (Winter).");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Clasica();
        break;
    case 75:
        MoonlightSonata();
        break;
    case 77:
        December();
        break;
    default:
        WinterPantalla();
        break;
    }
}
void Winter()
{
    pthread_t HiloWinterCancion;
    pthread_t HiloWinter;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloWinterCancion, NULL, WinterCancion, NULL);
    pthread_create(&HiloWinter, NULL, WinterPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloWinterCancion, NULL);
    pthread_join(HiloWinter, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void DecemberPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: December. Christmas");
    gotoxy(6,13);
    printf("Artista: Ilyich Tchaikovsky");
    gotoxy(6,16);
    printf("Album: The Seasons");
    gotoxy(6,19);
    printf("Ano: 1875");
    gotoxy(6,22);
    printf("Genero: Clasica");

    gotoxy(40,22);
    printf("Duracion: 4:45");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("December es una de 12 cortas piezas para solo de piano.");
    gotoxy(40,14);
    printf("Cada pieza es la caracteristica de un mes diferente del");
    gotoxy(40,16);
    printf("ano en Rusia. La obra tambien se escucha a veces en");
    gotoxy(40,18);
    printf("arreglos orquestales y de otro tipo por otras manos.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Clasica();
        break;
    case 75:
        Winter();
        break;
    case 77:
        Gymnopedie();
        break;
    default:
        DecemberPantalla();
        break;
    }
}
void December()
{
    pthread_t HiloDecemberCancion;
    pthread_t HiloDecember;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloDecemberCancion, NULL, DecemberCancion, NULL);
    pthread_create(&HiloDecember, NULL, DecemberPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloDecemberCancion, NULL);
    pthread_join(HiloDecember, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void GymnopediePantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Gymnopedie No.1");
    gotoxy(6,13);
    printf("Artista: Erik Satie");
    gotoxy(6,16);
    printf("Album: Gymnopedies");
    gotoxy(6,19);
    printf("Ano: 1888");
    gotoxy(6,22);
    printf("Genero: Clasica");

    gotoxy(40,22);
    printf("Duracion: 3:37");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Un gran numero de producciones cinematograficas," );
    gotoxy(40,14);
    printf("televisivase incluso videojuegos han incluido alguna o");
    gotoxy(40,16);
    printf("varias gymnopedies dentro de su banda sonora.");
    gotoxy(40,18);
    printf("Satie se inspiro en las danzas de la antigua Grecia.");


    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Clasica();
        break;
    case 75:
        December();
        break;
    case 77:
        Gymnopedie();
        break;
    default:
        GymnopediePantalla();
        break;
    }
}
void Gymnopedie()
{
    pthread_t HiloGymnopedieCancion;
    pthread_t HiloGymnopedie;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloGymnopedieCancion, NULL, GymnopedieCancion, NULL);
    pthread_create(&HiloGymnopedie, NULL, GymnopediePantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloGymnopedieCancion, NULL);
    pthread_join(HiloGymnopedie, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

//ELECTRO
void FadedPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Faded");
    gotoxy(6,13);
    printf("Artista: Alan Walker");
    gotoxy(6,16);
    printf("Album: Different World");
    gotoxy(6,19);
    printf("Ano: 2015");
    gotoxy(6,22);
    printf("Genero: House progresivo");

    gotoxy(40,22);
    printf("Duracion: 3:31");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Cancion del DJ y productor discografico noruego Alan Walker.");
    gotoxy(40,14);
    printf("La cancion fue muy exitosa, alcanzando entrar a los diez");
    gotoxy(40,16);
    printf("primeros lugares en la mayoria de los paises en los que");
    gotoxy(40,18);
    printf("figuro y primera posicion en 10 de ellos.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Electro();
        break;
    case 75:
        Faded();
        break;
    case 77:
        E3();
        break;
    default:
        FadedPantalla();
        break;
    }
}
void Faded()
{
    pthread_t HiloFadedCancion;
    pthread_t HiloFaded;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloFadedCancion, NULL, FadedCancion, NULL);
    pthread_create(&HiloFaded, NULL, FadedPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloFadedCancion, NULL);
    pthread_join(HiloFaded, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void E3Pantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: E3");
    gotoxy(6,13);
    printf("Artista: Gastu Beats");
    gotoxy(6,16);
    printf("Album: Electros");
    gotoxy(6,19);
    printf("Ano: 2021");
    gotoxy(6,22);
    printf("Genero: EDM");

    gotoxy(40,22);
    printf("Duracion: 4:04");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Compuesta en el ano 2020 y lanzada en el 2021.");
    gotoxy(40,14);
    printf("La cancion contiene samples del plugin Arcade y");
    gotoxy(40,16);
    printf("es un tema que entra en el estilo clasico y puro EDM");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Electro();
        break;
    case 75:
        Faded();
        break;
    case 77:
        TheBusiness();
        break;
    default:
        E3Pantalla();
        break;
    }
}
void E3()
{
    pthread_t HiloE3Cancion;
    pthread_t HiloE3;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloE3Cancion, NULL, E3Cancion, NULL);
    pthread_create(&HiloE3, NULL, E3Pantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloE3Cancion, NULL);
    pthread_join(HiloE3, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void TheBusinessPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: The Business");
    gotoxy(6,13);
    printf("Artista: Tiesto");
    gotoxy(6,16);
    printf("Album: -");
    gotoxy(6,19);
    printf("Ano: 2020");
    gotoxy(6,22);
    printf("Genero: Dance");

    gotoxy(40,22);
    printf("Duracion: 2:44");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Hecha por DJ y productor Tiesto, con vocales por");
    gotoxy(40,14);
    printf("James Bell. Tambien lanzo The Buisness Part II ");
    gotoxy(40,16);
    printf("en colaboracion con Ty Dolla Sign");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Electro();
        break;
    case 75:
        E3();
        break;
    case 77:
        YouAreTheOne();
        break;
    default:
        TheBusinessPantalla();
        break;
    }
}
void TheBusiness()
{
    pthread_t HiloTheBusinessCancion;
    pthread_t HiloTheBusiness;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloTheBusinessCancion, NULL, TheBusinessCancion, NULL);
    pthread_create(&HiloTheBusiness, NULL, TheBusinessPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloTheBusinessCancion, NULL);
    pthread_join(HiloTheBusiness, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void YouAreTheOnePantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: You Are The One");
    gotoxy(6,13);
    printf("Artista: Gastu Beats");
    gotoxy(6,16);
    printf("Album: -");
    gotoxy(6,19);
    printf("Ano: 2021");
    gotoxy(6,22);
    printf("Genero: Dance");

    gotoxy(40,22);
    printf("Duracion: 3:20");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Compuesta en el ano 2020 y lanzada en el 2021.");
    gotoxy(40,14);
    printf("Se utilizo un emulador de voz digital para las");
    gotoxy(40,16);
    printf("vocales en el esrtribillo.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Electro();
        break;
    case 75:
        TheBusiness();
        break;
    case 77:
        Levels();
        break;
    default:
        YouAreTheOnePantalla();
        break;
    }
}
void YouAreTheOne()
{
    pthread_t HiloYouAreTheOneCancion;
    pthread_t HiloYouAreTheOne;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloYouAreTheOneCancion, NULL, YouAreTheOneCancion, NULL);
    pthread_create(&HiloYouAreTheOne, NULL, YouAreTheOnePantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloYouAreTheOneCancion, NULL);
    pthread_join(HiloYouAreTheOne, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void LevelsPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Levels");
    gotoxy(6,13);
    printf("Artista: Avicii");
    gotoxy(6,16);
    printf("Album: Levels");
    gotoxy(6,19);
    printf("Ano: 2011");
    gotoxy(6,22);
    printf("Genero: House Progresivo");

    gotoxy(40,22);
    printf("Duracion: 3:21");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Cancion producida por Avicii y su productor ejecutivo");
    gotoxy(40,14);
    printf("Ash Pournouri. Contiene el sample de la voz de Etta");
    gotoxy(40,16);
    printf("James de su cancion Somethings's Got A Hold On Me.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Electro();
        break;
    case 75:
        YouAreTheOne();
        break;
    case 77:
        RosesRemix();
        break;
    default:
        Levels();
        break;
    }
}
void Levels()
{
    pthread_t HiloLevelsCancion;
    pthread_t HiloLevels;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloLevelsCancion, NULL, LevelsCancion, NULL);
    pthread_create(&HiloLevels, NULL, LevelsPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloLevelsCancion, NULL);
    pthread_join(HiloLevels, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void RosesRemixPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Roses Remix");
    gotoxy(6,13);
    printf("Artista: SAINt JHN");
    gotoxy(6,16);
    printf("Album: Collection One");
    gotoxy(6,19);
    printf("Ano: 2019");
    gotoxy(6,22);
    printf("Genero: Slap House");

    gotoxy(40,22);
    printf("Duracion: 2:58");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("El productor Imanbek hizo este remix y lo lanzo en");
    gotoxy(40,14);
    printf("septiembre de 2019. En el mes de abril del 2020 llego");
    gotoxy(40,16);
    printf("a 4.5 billones de reproducciones en la App TikTok.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Electro();
        break;
    case 75:
        Levels();
        break;
    case 77:
        RosesRemix();
        break;
    default:
        RosesRemixPantalla();
        break;
    }
}
void RosesRemix()
{
    pthread_t HiloRosesRemixCancion;
    pthread_t HiloRosesRemix;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloRosesRemixCancion, NULL, RosesRemixCancion, NULL);
    pthread_create(&HiloRosesRemix, NULL, RosesRemixPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloRosesRemixCancion, NULL);
    pthread_join(HiloRosesRemix, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

//LATINA
void DespacitoPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Despacito");
    gotoxy(6,13);
    printf("Artista: Luis Fonsi");
    gotoxy(6,16);
    printf("Album: Vida");
    gotoxy(6,19);
    printf("Ano: 2017");
    gotoxy(6,22);
    printf("Genero: Reggaeton");

    gotoxy(40,22);
    printf("Duracion: 3:47");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La cancion obtuvo un excelente rendimiento comercial,");
    gotoxy(40,14);
    printf("logrando ubicarse en la posicion numero 1 en mas de 80");
    gotoxy(40,16);
    printf("paises y ser la cancion con mas reproducciones en YouTube");
    gotoxy(40,18);
    printf("en aquel entonces.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Latina();
        break;
    case 75:
        Despacito();
        break;
    case 77:
        Dile();
        break;
    default:
        DespacitoPantalla();
        break;
    }
}
void Despacito()
{
    pthread_t HiloDespacitoCancion;
    pthread_t HiloDespacito;
    pthread_t HiloDetenerCancion;
    pthread_create(&HiloDespacitoCancion, NULL, DespacitoCancion, NULL);
    pthread_create(&HiloDespacito, NULL, DespacitoPantalla, NULL);
    pthread_create(&HiloDetenerCancion, NULL, detenerCancion, NULL);
    pthread_join(HiloDespacitoCancion, NULL);
    pthread_join(HiloDespacito, NULL);
    pthread_join(HiloDetenerCancion, NULL);
}

void DilePantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Dile");
    gotoxy(6,13);
    printf("Artista: Don Omar");
    gotoxy(6,16);
    printf("Album: The Last Don");
    gotoxy(6,19);
    printf("Ano: 2004");
    gotoxy(6,22);
    printf("Genero: Reggaeton");

    gotoxy(40,22);
    printf("Duracion: 3:25");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("El propio Don Omar antes de dar salida a este sencillo");
    gotoxy(40,14);
    printf("habia declarado que <<estoy listo para emprender esta");
    gotoxy(40,16);
    printf("carrera y creo que con este disco la emprendere de una");
    gotoxy(40,18);
    printf("gran forma>>.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Latina();
        break;
    case 75:
        Despacito();
        break;
    case 77:
        Goteo();
        break;
    default:
        DilePantalla();
        break;
    }
}
void Dile()
{
    pthread_t HiloDileCancion;
    pthread_t HiloDile;
    pthread_t HiloDetenerCancion;
    pthread_create(&HiloDileCancion, NULL, DileCancion, NULL);
    pthread_create(&HiloDile, NULL, DilePantalla, NULL);
    pthread_create(&HiloDetenerCancion, NULL, detenerCancion, NULL);
    pthread_join(HiloDileCancion, NULL);
    pthread_join(HiloDile, NULL);
    pthread_join(HiloDetenerCancion, NULL);
}

void GoteoPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Goteo");
    gotoxy(6,13);
    printf("Artista: Duki");
    gotoxy(6,16);
    printf("Album: Super Sangre Joven");
    gotoxy(6,19);
    printf("Ano: 2019");
    gotoxy(6,22);
    printf("Genero: Trap");

    gotoxy(40,22);
    printf("Duracion: 2:45");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("En 2020, la cancion fue nominada para la n.21 Entrega Anual");
    gotoxy(40,14);
    printf("de los Premios Grammy Latinos en la categoria Mejor Cancion");
    gotoxy(40,16);
    printf("de Rap/Hip-Hop.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Latina();
        break;
    case 75:
        Dile();
        break;
    case 77:
        TododeTi();
        break;
    default:
        Goteo();
        break;
    }
}
void Goteo()
{
    pthread_t HiloGoteoCancion;
    pthread_t HiloGoteo;
    pthread_t HiloDetenerCancion;
    pthread_create(&HiloGoteoCancion, NULL, GoteoCancion, NULL);
    pthread_create(&HiloGoteo, NULL, GoteoPantalla, NULL);
    pthread_create(&HiloDetenerCancion, NULL, detenerCancion, NULL);
    pthread_join(HiloGoteoCancion, NULL);
    pthread_join(HiloGoteo, NULL);
    pthread_join(HiloDetenerCancion, NULL);
}

void TododeTiPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Todo de Ti");
    gotoxy(6,13);
    printf("Artista: Rauw Alejandro");
    gotoxy(6,16);
    printf("Album: -");
    gotoxy(6,19);
    printf("Ano: 2021");
    gotoxy(6,22);
    printf("Genero: Dance-Pop");

    gotoxy(40,22);
    printf("Duracion: 3:20");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Es una cancion dance y synth pop, inspiradav en el funk de");
    gotoxy(40,14);
    printf("los anos 80, tambien le hace guinos a la musica de los");
    gotoxy(40,16);
    printf("cantantes James Brown y Bruno Mars.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Latina();
        break;
    case 75:
        Goteo();
        break;
    case 77:
        EllaMeLevanto();
        break;
    default:
        TododeTiPantalla();
        break;
    }
}
void TododeTi()
{
    pthread_t HiloTododeTiCancion;
    pthread_t HiloTododeTi;
    pthread_t HiloDetenerCancion;
    pthread_create(&HiloTododeTiCancion, NULL, TododeTiCancion, NULL);
    pthread_create(&HiloTododeTi, NULL, TododeTiPantalla, NULL);
    pthread_create(&HiloDetenerCancion, NULL, detenerCancion, NULL);
    pthread_join(HiloTododeTiCancion, NULL);
    pthread_join(HiloTododeTi, NULL);
    pthread_join(HiloDetenerCancion, NULL);

}

void EllaMeLevantoPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Ella Me Levanto");
    gotoxy(6,13);
    printf("Artista: Daddy Yankee");
    gotoxy(6,16);
    printf("Album: El Cartel: The Big Boss");
    gotoxy(6,19);
    printf("Ano: 2007");
    gotoxy(6,22);
    printf("Genero: Reaggaeton");

    gotoxy(40,22);
    printf("Duracion: 3:29");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Conocida por su combinacion de reggaeton con salsa.");
    gotoxy(40,14);
    printf("La cancion fue producida por Elvis <<Mr. G>> Garcia,");
    gotoxy(40,16);
    printf("un reconocido productor de mufsica tropical.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");



    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Latina();
        break;
    case 75:
        TododeTi();
        break;
    case 77:
        FelicesLos4();
        break;
    default:
        EllaMeLevantoPantalla();
        break;
    }
}
void EllaMeLevanto()
{
    pthread_t HiloEllaMeLevantoCancion;
    pthread_t HiloEllaMeLevanto;
    pthread_t HiloDetenerCancion;
    pthread_create(&HiloEllaMeLevantoCancion, NULL, EllaMeLevantoCancion, NULL);
    pthread_create(&HiloEllaMeLevanto, NULL, EllaMeLevantoPantalla, NULL);
    pthread_create(&HiloDetenerCancion, NULL, detenerCancion, NULL);
    pthread_join(HiloEllaMeLevantoCancion, NULL);
    pthread_join(HiloEllaMeLevanto, NULL);
    pthread_join(HiloDetenerCancion, NULL);
}

void FelicesLos4Pantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Felices Los 4");
    gotoxy(6,13);
    printf("Artista: Maluma");
    gotoxy(6,16);
    printf("Album: F.A.M.E.");
    gotoxy(6,19);
    printf("Ano: 2017");
    gotoxy(6,22);
    printf("Genero: Reaggaeton");

    gotoxy(40,22);
    printf("Duracion: 3:50");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Originalmente iba a ser el sencillo lider del album");
    gotoxy(40,14);
    printf("F.A.M.E. pero Maluma la reemplazo por Corazon. Sin ");
    gotoxy(40,16);
    printf("embargo, volvio a ser el primer sencillo debido a su ");
    gotoxy(40,18);
    printf("inclusion en el album.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Latina();
        break;
    case 75:
        EllaMeLevanto();
        break;
    case 77:
        FelicesLos4();
    default:
        FelicesLos4Pantalla();
        break;
    }
}
void FelicesLos4()
{
    pthread_t HiloFelicesLos4Cancion;
    pthread_t HiloFelicesLos4;
    pthread_t HiloDetenerCancion;
    pthread_create(&HiloFelicesLos4Cancion, NULL, FelicesLos4Cancion, NULL);
    pthread_create(&HiloFelicesLos4, NULL, FelicesLos4Pantalla, NULL);
    pthread_create(&HiloDetenerCancion, NULL, detenerCancion, NULL);
    pthread_join(HiloFelicesLos4Cancion, NULL);
    pthread_join(HiloFelicesLos4, NULL);
    pthread_join(HiloDetenerCancion, NULL);
}

//NACIONAL
void DeMusicaLigeraPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: De Musica Ligera");
    gotoxy(6,13);
    printf("Artista: Soda Stereo");
    gotoxy(6,16);
    printf("Album: Cancion Animal");
    gotoxy(6,19);
    printf("Ano: 1990");
    gotoxy(6,22);
    printf("Genero: Rock alternativo");

    gotoxy(40,22);
    printf("Duracion: 3:36");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Es el tema mas conocido, popular, emblematico y un");
    gotoxy(40,14);
    printf("himno latinoamericano del grupo. Es considerado como uno");
    gotoxy(40,16);
    printf("de los himnos del rock en espanol y una de las composiciones");
    gotoxy(40,18);
    printf("mas reconocidas del rock argentino.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Nacional();
        break;
    case 75:
        DeMusicaLigera();
        break;
    case 77:
        LosDinosaurios();
    default:
        DeMusicaLigeraPantalla();
        break;
    }
}
void DeMusicaLigera()
{
    pthread_t HiloDeMusicaLigeraCancion;
    pthread_t HiloDeMusicaLigera;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloDeMusicaLigeraCancion, NULL, DeMusicaLigeraCancion, NULL);
    pthread_create(&HiloDeMusicaLigera, NULL, DeMusicaLigeraPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloDeMusicaLigeraCancion, NULL);
    pthread_join(HiloDeMusicaLigera, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void LosDinosauriosPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Los Dinosaurios");
    gotoxy(6,13);
    printf("Artista: Charly Garcia");
    gotoxy(6,16);
    printf("Album: Clics modernos");
    gotoxy(6,19);
    printf("Ano: 1983");
    gotoxy(6,22);
    printf("Genero: Rock");

    gotoxy(40,22);
    printf("Duracion: 3:27");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Debido a su letra, que dice que dice que todos <<pueden");
    gotoxy(40,14);
    printf("desaparecer... pero los dinosaurios van a desaparece>>, la");
    gotoxy(40,16);
    printf("cancion ha sido masivamente considerada una metafora de la ");
    gotoxy(40,18);
    printf("ultima dictadura que goberno en Argentina.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Nacional();
        break;
    case 75:
        DeMusicaLigera();
        break;
    case 77:
        Bajan();
    default:
        LosDinosauriosPantalla();
        break;
    }
}
void LosDinosaurios()
{
    pthread_t HiloLosDinosauriosCancion;
    pthread_t HiloLosDinosaurios;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloLosDinosauriosCancion, NULL, LosDinosauriosCancion, NULL);
    pthread_create(&HiloLosDinosaurios, NULL, LosDinosauriosPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloLosDinosauriosCancion, NULL);
    pthread_join(HiloLosDinosaurios, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void BajanPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Bajan");
    gotoxy(6,13);
    printf("Artista: Luis Alberto Spinetta");
    gotoxy(6,16);
    printf("Album: Artaud");
    gotoxy(6,19);
    printf("Ano: 1973");
    gotoxy(6,22);
    printf("Genero: Rock");

    gotoxy(40,22);
    printf("Duracion: 3:27");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Se inspiro en la obra del poeta y dramaturgo surrealista");
    gotoxy(40,14);
    printf("Antonin Artaud, especialmente en sus obras Heliogabalo o");
    gotoxy(40,16);
    printf("el anarquista coronado y Van Gohg, el suicidado por la");
    gotoxy(40,18);
    printf("sociedad.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Nacional();
        break;
    case 75:
        LosDinosaurios();
        break;
    case 77:
        TiraParaArriba();
    default:
        BajanPantalla();
        break;
    }
}
void Bajan()
{
    pthread_t HiloBajanCancion;
    pthread_t HiloBajan;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloBajanCancion, NULL, BajanCancion, NULL);
    pthread_create(&HiloBajan, NULL, BajanPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloBajanCancion, NULL);
    pthread_join(HiloBajan, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void TiraParaArribaPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Tira Para Arriba");
    gotoxy(6,13);
    printf("Artista: Miguel Mateos/ZAS");
    gotoxy(6,16);
    printf("Album: Tengo que parar");
    gotoxy(6,19);
    printf("Ano: 1984");
    gotoxy(6,22);
    printf("Genero: Rock");

    gotoxy(40,22);
    printf("Duracion: 5:04");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Es una de las canciones mas exitosas de la banda Miguel ");
    gotoxy(40,14);
    printf("Mateos/ZAS, y un verdadero himno del rock en espanol de ");
    gotoxy(40,16);
    printf("los años 1980.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Nacional();
        break;
    case 75:
        Bajan();
        break;
    case 77:
        LamentoBoliviano();
    default:
        TiraParaArribaPantalla();
        break;
    }
}
void TiraParaArriba()
{
    pthread_t HiloTiraParaArribaCancion;
    pthread_t HiloTiraParaArriba;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloTiraParaArribaCancion, NULL, TiraParaArribaCancion, NULL);
    pthread_create(&HiloTiraParaArriba, NULL, TiraParaArribaPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloTiraParaArribaCancion, NULL);
    pthread_join(HiloTiraParaArriba, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void LamentoBolivianoPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Lamento Boliviano");
    gotoxy(6,13);
    printf("Artista: Enanitos Verdes");
    gotoxy(6,16);
    printf("Album: Big Bang");
    gotoxy(6,19);
    printf("Ano: 1994");
    gotoxy(6,22);
    printf("Genero: Rock");

    gotoxy(40,22);
    printf("Duracion: 3:45");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Su creador e interprete original fue la banda de ");
    gotoxy(40,14);
    printf("rock argentina Alcohol Etilico. La version mas conocida");
    gotoxy(40,16);
    printf("de esta cancion es del grupo mendocino Enanitos Verdes");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Nacional();
        break;
    case 75:
        TiraParaArriba();
        break;
    case 77:
        JiJiJi();
    default:
        LamentoBolivianoPantalla();
        break;
    }
}
void LamentoBoliviano()
{
    pthread_t HiloLamentoBolivianoCancion;
    pthread_t HiloLamentoBoliviano;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloLamentoBolivianoCancion, NULL, LamentoBolivianoCancion, NULL);
    pthread_create(&HiloLamentoBoliviano, NULL, LamentoBolivianoPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloLamentoBolivianoCancion, NULL);
    pthread_join(HiloLamentoBoliviano, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void JiJiJiPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Ji Ji Ji");
    gotoxy(6,13);
    printf("Artista: Patricio Rey y sus");
    gotoxy(6,14);
    printf("         Redonditos de Ricota");
    gotoxy(6,16);
    printf("Album: Oktubre");
    gotoxy(6,19);
    printf("Ano: 1986");
    gotoxy(6,22);
    printf("Genero: Hard Rock");

    gotoxy(40,22);
    printf("Duracion: 5:36");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Fue escrita por el vocalista de la banda Indio Solari");
    gotoxy(40,14);
    printf("y el guitarrista Skay Beilinson para su segundo album de");
    gotoxy(40,16);
    printf("estudio titulado Oktubre del ano 1986.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Nacional();
        break;
    case 75:
        LamentoBoliviano();
        break;
    case 77:
        JiJiJi();
    default:
        JiJiJiPantalla();
        break;
    }
}
void JiJiJi()
{
    pthread_t HiloJiJiJiCancion;
    pthread_t HiloJiJiJi;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloJiJiJiCancion, NULL, JiJiJiCancion, NULL);
    pthread_create(&HiloJiJiJi, NULL, JiJiJiPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloJiJiJiCancion, NULL);
    pthread_join(HiloJiJiJi, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

//RAP
void ShookOnesPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Shook Ones, Part II");
    gotoxy(6,13);
    printf("Artista: Mobb Deep's");
    gotoxy(6,16);
    printf("Album: The Infamous");
    gotoxy(6,19);
    printf("Ano: 1995");
    gotoxy(6,22);
    printf("Genero: Hip Hop");

    gotoxy(40,22);
    printf("Duracion: 5:26");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La cancion es una secuela de su single Shook Ones de 1994,");
    gotoxy(40,14);
    printf("con letras parecidas pero con menos profanidades. La cancion");
    gotoxy(40,16);
    printf("original se encuentra en el lado b de algunos lanzamientos");
    gotoxy(40,18);
    printf("de Shook Ones Part II.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rap();
        break;
    case 75:
        ShookOnes();
        break;
    case 77:
        Juicy();
    default:
        ShookOnesPantalla();
        break;
    }
}
void ShookOnes()
{
    pthread_t HiloShookOnesCancion;
    pthread_t HiloShookOnes;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloShookOnesCancion, NULL, ShookOnesCancion, NULL);
    pthread_create(&HiloShookOnes, NULL, ShookOnesPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloShookOnesCancion, NULL);
    pthread_join(HiloShookOnes, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void JuicyPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Juicy");
    gotoxy(6,13);
    printf("Artista: The Notorious B.I.G.");
    gotoxy(6,16);
    printf("Album: Ready to Die");
    gotoxy(6,19);
    printf("Ano: 1994");
    gotoxy(6,22);
    printf("Genero: Gangsta Rap");

    gotoxy(40,22);
    printf("Duracion: 5:03");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("es el sencillo debut en solitario del rapero estadounidense ");
    gotoxy(40,14);
    printf("The Notorious B.I.G.. Fue producida por los productores");
    gotoxy(40,16);
    printf("de Bad Boy Records Poke y Sean Puffy Combs.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rap();
        break;
    case 75:
        ShookOnes();
        break;
    case 77:
        LoseYourself();
    default:
        JuicyPantalla();
        break;
    }
}
void Juicy()
{
    pthread_t HiloJuicyCancion;
    pthread_t HiloJuicy;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloJuicyCancion, NULL, JuicyCancion, NULL);
    pthread_create(&HiloJuicy, NULL, JuicyPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloJuicyCancion, NULL);
    pthread_join(HiloJuicy, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void LoseYourselfPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Lose Yourself");
    gotoxy(6,13);
    printf("Artista: Eminem");
    gotoxy(6,16);
    printf("Album: 8 Mile");
    gotoxy(6,19);
    printf("Ano: 2002");
    gotoxy(6,22);
    printf("Genero: Hip Hop");

    gotoxy(40,22);
    printf("Duracion: 5:26");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La cancion fue escrita por Eminem durante un tiempo libre");
    gotoxy(40,14);
    printf("durante la grabacion de 8 Mile. Desde hacia un tiempo los");
    gotoxy(40,16);
    printf("Bass Brothers y Eminem intentaban componer la cancion");
    gotoxy(40,18);
    printf("principal de la pelicula.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rap();
        break;
    case 75:
        Juicy();
        break;
    case 77:
        FuckThaPolice();
    default:
        LoseYourselfPantalla();
        break;
    }
}
void LoseYourself()
{
    pthread_t HiloLoseYourselfCancion;
    pthread_t HiloLoseYourself;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloLoseYourselfCancion, NULL, LoseYourselfCancion, NULL);
    pthread_create(&HiloLoseYourself, NULL, LoseYourselfPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloLoseYourselfCancion, NULL);
    pthread_join(HiloLoseYourself, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void FuckThaPolicePantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Fuck Tha Police");
    gotoxy(6,13);
    printf("Artista: N.W.A");
    gotoxy(6,16);
    printf("Album: Straight Outta Compton");
    gotoxy(6,19);
    printf("Ano: 1988");
    gotoxy(6,22);
    printf("Genero: Cancion Protesta");

    gotoxy(40,22);
    printf("Duracion: 5:44");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La letra protesta por la brutalidad policial y el perfil ");
    gotoxy(40,14);
    printf("racial y la cancion ocupo el numero 425 en la lista de las  ");
    gotoxy(40,16);
    printf("500 mejores canciones de todos los tiempos de Rolling Stone.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rap();
        break;
    case 75:
        LoseYourself();
        break;
    case 77:
        AllOfTheLights();
    default:
        FuckThaPolicePantalla();
        break;
    }
}
void FuckThaPolice()
{
    pthread_t HiloFuckThaPoliceCancion;
    pthread_t HiloFuckThaPolice;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloFuckThaPoliceCancion, NULL, FuckThaPoliceCancion, NULL);
    pthread_create(&HiloFuckThaPolice, NULL, FuckThaPolicePantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloFuckThaPoliceCancion, NULL);
    pthread_join(HiloFuckThaPolice, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void AllOfTheLightsPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: All Of The Lights");
    gotoxy(6,13);
    printf("Artista: Kanye West");
    gotoxy(6,16);
    printf("Album: My Beutiful Dark");
    gotoxy(6,17);
    printf("       Twisted Fantasy");
    gotoxy(6,19);
    printf("Ano: 2011");
    gotoxy(6,22);
    printf("Genero: Hip Hop");

    gotoxy(40,22);
    printf("Duracion: 4:59");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Fue producido por West y cuenta con voces adicionales de ");
    gotoxy(40,14);
    printf("varios artistas, entre ellos John Legend, The Dream,");
    gotoxy(40,16);
    printf("Elly Jackson, Alicia Keys, Fergie, Kid Cudi, Elton John, ");
    gotoxy(40,18);
    printf("y principalmente Rihanna.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rap();
        break;
    case 75:
        FuckThaPolice();
        break;
    case 77:
        InDaClub();
    default:
        AllOfTheLightsPantalla();
        break;
    }
}
void AllOfTheLights()
{
    pthread_t HiloAllOfTheLightsCancion;
    pthread_t HiloAllOfTheLights;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloAllOfTheLightsCancion, NULL, AllOfTheLightsCancion, NULL);
    pthread_create(&HiloAllOfTheLights, NULL, AllOfTheLightsPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloAllOfTheLightsCancion, NULL);
    pthread_join(HiloAllOfTheLights, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void InDaClubPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: In Da Club");
    gotoxy(6,13);
    printf("Artista: Kanye West");
    gotoxy(6,16);
    printf("Album: Get Rich or Die Tryin'");
    gotoxy(6,19);
    printf("Ano: 2003");
    gotoxy(6,22);
    printf("Genero: Hip Hop");

    gotoxy(40,22);
    printf("Duracion: 3:12");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La cancion fue producida por Dr. Dre y coproducida por Mike ");
    gotoxy(40,14);
    printf("Elizondo. Esta fue lanzada a finales de 2002 como sencillo ");
    gotoxy(40,16);
    printf("principal y recibio buenas criticas.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rap();
        break;
    case 75:
        FuckThaPolice();
        break;
    case 77:
        InDaClub();
    default:
        InDaClubPantalla();
        break;
    }
}
void InDaClub()
{
    pthread_t HiloInDaClubCancion;
    pthread_t HiloInDaClub;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloInDaClubCancion, NULL, InDaClubCancion, NULL);
    pthread_create(&HiloInDaClub, NULL, InDaClubPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloInDaClubCancion, NULL);
    pthread_join(HiloInDaClub, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

//ROCK
void ThunderstruckPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Thunderstruck");
    gotoxy(6,13);
    printf("Artista: AC/DC");
    gotoxy(6,16);
    printf("Album: The Razors Edge");
    gotoxy(6,19);
    printf("Ano: 1990");
    gotoxy(6,22);
    printf("Genero: Hard Rock");

    gotoxy(40,22);
    printf("Duracion: 4:52");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La cancion llego a posicionarse en el quinto puesto del ");
    gotoxy(40,14);
    printf("Mainstream Rock Tracks de Billboard en los Estados Unidos.");
    gotoxy(40,16);
    printf("Fue lanzada como sencillo en Alemania, Japon y Australia.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rock();
        break;
    case 75:
        Thunderstruck();
        break;
    case 77:
        WeWillRockYou();
    default:
        ThunderstruckPantalla();
        break;
    }
}
void Thunderstruck()
{
    pthread_t HiloThunderstruckCancion;
    pthread_t HiloThunderstruck;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloThunderstruckCancion, NULL, ThunderstruckCancion, NULL);
    pthread_create(&HiloThunderstruck, NULL, ThunderstruckPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloThunderstruckCancion, NULL);
    pthread_join(HiloThunderstruck, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void WeWillRockYouPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: We Will Rock You");
    gotoxy(6,13);
    printf("Artista: Queen");
    gotoxy(6,16);
    printf("Album: News of the World");
    gotoxy(6,19);
    printf("Ano: 1977");
    gotoxy(6,22);
    printf("Genero: Arena Rock");

    gotoxy(40,22);
    printf("Duracion: 2:01");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Es una cancion de rock compuesta por Brian May, guitarrista");
    gotoxy(40,14);
    printf("de la banda britanica Queen. Tiene un ritmo marcado por");
    gotoxy(40,16);
    printf("palmadas y bombo, y un solo de guitarra.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rock();
        break;
    case 75:
        Thunderstruck();
        break;
    case 77:
        BlitzkriegBop();
    default:
        WeWillRockYouPantalla();
        break;
    }
}
void WeWillRockYou()
{
    pthread_t HiloWeWillRockYouCancion;
    pthread_t HiloWeWillRockYou;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloWeWillRockYouCancion, NULL, WeWillRockYouCancion, NULL);
    pthread_create(&HiloWeWillRockYou, NULL, WeWillRockYouPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloWeWillRockYouCancion, NULL);
    pthread_join(HiloWeWillRockYou, NULL);
    pthread_join(HiloDetenerHilo, NULL);

}

void BlitzkriegBopPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Blitzkrieg Bop");
    gotoxy(6,13);
    printf("Artista: Ramones");
    gotoxy(6,16);
    printf("Album: Ramones");
    gotoxy(6,19);
    printf("Ano: 1976");
    gotoxy(6,22);
    printf("Genero: Punk Rock");

    gotoxy(40,22);
    printf("Duracion: 2:12");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Este tema es considerado un hito no solo del punk, sino ");
    gotoxy(40,14);
    printf("tambien del rock and roll en general. La cancion fue escrita");
    gotoxy(40,16);
    printf("principalmente por el baterista de la banda, Tommy Ramone.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rock();
        break;
    case 75:
        WeWillRockYou();
        break;
    case 77:
        BeautifulDay();
    default:
        BlitzkriegBopPantalla();
        break;
    }
}
void BlitzkriegBop()
{
    pthread_t HiloBlitzkriegBopCancion;
    pthread_t HiloBlitzkriegBop;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloBlitzkriegBopCancion, NULL, BlitzkriegBopCancion, NULL);
    pthread_create(&HiloBlitzkriegBop, NULL, BlitzkriegBopPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloBlitzkriegBopCancion, NULL);
    pthread_join(HiloBlitzkriegBop, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void BeautifulDayPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Beautiful Day");
    gotoxy(6,13);
    printf("Artista: U2");
    gotoxy(6,16);
    printf("Album: All That You Can't");
    gotoxy(6,17);
    printf("       Leave Behind");
    gotoxy(6,19);
    printf("Ano: 2000");
    gotoxy(6,22);
    printf("Genero: Pop Rock");

    gotoxy(40,22);
    printf("Duracion: 4:08");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Fue un gran exito comercial, ayudando a lanzar el album ");
    gotoxy(40,14);
    printf("al nivel de multi platino. El vocalista principal de la ");
    gotoxy(40,16);
    printf("banda, Bono, explico que la cancion optimista trata sobre");
    gotoxy(40,18);
    printf("perder todo pero aun encontrar alegria en lo que uno tiene.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rock();
        break;
    case 75:
        BlitzkriegBop();
        break;
    case 77:
        EnterSandman();
    default:
        BeautifulDayPantalla();
        break;
    }
}
void BeautifulDay()
{
    pthread_t HiloBeautifulDayCancion;
    pthread_t HiloBeautifulDay;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloBeautifulDayCancion, NULL, BeautifulDayCancion, NULL);
    pthread_create(&HiloBeautifulDay, NULL, BeautifulDayPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloBeautifulDayCancion, NULL);
    pthread_join(HiloBeautifulDay, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void EnterSandmanPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Enter Sandman");
    gotoxy(6,13);
    printf("Artista: Metallica");
    gotoxy(6,16);
    printf("Album: Metallica");
    gotoxy(6,19);
    printf("Ano: 1991");
    gotoxy(6,22);
    printf("Genero: Heavy Metal");

    gotoxy(40,22);
    printf("Duracion: 5:30");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Fue compuesta por Kirk Hammett, James Hetfield y Lars");
    gotoxy(40,14);
    printf("Ulrich y producida por Bob Rock. La letra fue escrita");
    gotoxy(40,16);
    printf("por Hetfield, cantante, hombre de honory guitarrista");
    gotoxy(40,18);
    printf("ritmico de la formacion.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rock();
        break;
    case 75:
        BeautifulDay();
        break;
    case 77:
        PaintItBlack();
    default:
        EnterSandmanPantalla();
        break;
    }
}
void EnterSandman()
{
    pthread_t HiloEnterSandmanCancion;
    pthread_t HiloEnterSandman;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloEnterSandmanCancion, NULL, EnterSandmanCancion, NULL);
    pthread_create(&HiloEnterSandman, NULL, EnterSandmanPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloEnterSandmanCancion, NULL);
    pthread_join(HiloEnterSandman, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void PaintItBlackPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Paint It, Black");
    gotoxy(6,13);
    printf("Artista: The Rolling Stones");
    gotoxy(6,16);
    printf("Album: Aftermath");
    gotoxy(6,19);
    printf("Ano: 1966");
    gotoxy(6,22);
    printf("Genero: Rock psicodelico");

    gotoxy(40,22);
    printf("Duracion: 3:22");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Alcanzo el numero uno tanto en el Billboard Hot 100");
    gotoxy(40,14);
    printf("como en el UK Singles Chart. La cancion se convirtio en");
    gotoxy(40,16);
    printf("el tercer numero uno de los Rolling Stones en Estados");
    gotoxy(40,18);
    printf("Unidos sexto en el Reino Unido.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Rock();
        break;
    case 75:
        EnterSandman();
        break;
    case 77:
        PaintItBlack();
    default:
        PaintItBlackPantalla();
        break;
    }
}
void PaintItBlack()
{
    pthread_t HiloPaintItBlackCancion;
    pthread_t HiloPaintItBlack;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloPaintItBlackCancion, NULL, PaintItBlackCancion, NULL);
    pthread_create(&HiloPaintItBlack, NULL, PaintItBlackPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloPaintItBlackCancion, NULL);
    pthread_join(HiloPaintItBlack, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

//POP
void StayPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Stay");
    gotoxy(6,13);
    printf("Artista: The Kid Laroi/");
    gotoxy(6,14);
    printf("         Justin Bieber");
    gotoxy(6,16);
    printf("Album: F*ck Love 3: Over You");
    gotoxy(6,19);
    printf("Ano: 2021");
    gotoxy(6,22);
    printf("Genero: Synth-Pop");

    gotoxy(40,22);
    printf("Duracion: 2:34");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("La cancio fue producida por Cashmere Cat, harlie Puth,");
    gotoxy(40,14);
    printf("Omer Fedi y Blake Slatkin. Fue escrito por los dos artistas");
    gotoxy(40,16);
    printf("y los productores, junto con los miembros de FnZ Michael");
    gotoxy(40,18);
    printf("Mule e Isaac De Boni y Haan.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Pop();
        break;
    case 75:
        Stay();
        break;
    case 77:
        Shivers();
    default:
        StayPantalla();
        break;
    }
}
void Stay()
{
    pthread_t HiloStayCancion;
    pthread_t HiloStay;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloStayCancion, NULL, StayCancion, NULL);
    pthread_create(&HiloStay, NULL, StayPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloStayCancion, NULL);
    pthread_join(HiloStay, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void ShiversPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Shivers");
    gotoxy(6,13);
    printf("Artista: Ed Sheeran");
    gotoxy(6,16);
    printf("Album: =");
    gotoxy(6,19);
    printf("Ano: 2021");
    gotoxy(6,22);
    printf("Genero: Dance-Pop");

    gotoxy(40,22);
    printf("Duracion: 3:27");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Entro al tope de las listas en UK, Irlanda, Alemania y");
    gotoxy(40,14);
    printf("Suecia, destronando el single anterior Bad Habits.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Pop();
        break;
    case 75:
        Stay();
        break;
    case 77:
        Levitating();
    default:
        ShiversPantalla();
        break;
    }
}
void Shivers()
{
    pthread_t HiloShiversCancion;
    pthread_t HiloShivers;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloShiversCancion, NULL, ShiversCancion, NULL);
    pthread_create(&HiloShivers, NULL, ShiversPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloShiversCancion, NULL);
    pthread_join(HiloShivers, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void LevitatingPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Levitating");
    gotoxy(6,13);
    printf("Artista: Dua Lipa");
    gotoxy(6,16);
    printf("Album: Future Nostalgia");
    gotoxy(6,19);
    printf("Ano: 2020");
    gotoxy(6,22);
    printf("Genero: Pop");

    gotoxy(40,22);
    printf("Duracion: 3:23");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Es una cancion dance, electro-disco, pop-funk, power pop");
    gotoxy(40,14);
    printf("y rock espacial, con un toque de pop y R&B de los noventa,");
    gotoxy(40,16);
    printf("y elementos de retro y de los ochenta.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Pop();
        break;
    case 75:
        Shivers();
        break;
    case 77:
        BlindingLights();
    default:
        LevitatingPantalla();
        break;
    }
}
void Levitating()
{
    pthread_t HiloLevitatingCancion;
    pthread_t HiloLevitating;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloLevitatingCancion, NULL, LevitatingCancion, NULL);
    pthread_create(&HiloLevitating, NULL, LevitatingPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloLevitatingCancion, NULL);
    pthread_join(HiloLevitating, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void BlindingLightsPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Blinding Lights");
    gotoxy(6,13);
    printf("Artista: The Weeknd");
    gotoxy(6,16);
    printf("Album: After Hours");
    gotoxy(6,19);
    printf("Ano: 2019");
    gotoxy(6,22);
    printf("Genero: ElectroPop");

    gotoxy(40,22);
    printf("Duracion: 3:22");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Un remix junto a la cantautora espanola Rosalia fue lanzado");
    gotoxy(40,14);
    printf("el 4 de diciembre de 2020. La cancion fue interpretada");
    gotoxy(40,16);
    printf("durante el espectaculo de medio tiempo del Super Bowl");
    gotoxy(40,18);
    printf("LV el 7 de febrero de 2021.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Pop();
        break;
    case 75:
        Levitating();
        break;
    case 77:
        Good4u();
    default:
        BlindingLightsPantalla();
        break;
    }
}
void BlindingLights()
{
    pthread_t HiloBlindingLightsCancion;
    pthread_t HiloBlindingLights;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloBlindingLightsCancion, NULL, BlindingLightsCancion, NULL);
    pthread_create(&HiloBlindingLights, NULL, BlindingLightsPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloBlindingLightsCancion, NULL);
    pthread_join(HiloBlindingLights, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void Good4uPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Good 4 U");
    gotoxy(6,13);
    printf("Artista: Olivia Rodrigo");
    gotoxy(6,16);
    printf("Album: Sour");
    gotoxy(6,19);
    printf("Ano: 2021");
    gotoxy(6,22);
    printf("Genero: Pop Punk");

    gotoxy(40,22);
    printf("Duracion: 2:58");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Es una cancion de pop-punk, pop rock y teen pop. Esta ");
    gotoxy(40,14);
    printf("ambientada con guitarras electricas y bateria, con letras ");
    gotoxy(40,16);
    printf("dirigidas a un antiguo amante que se mudo muy rapido");
    gotoxy(40,18);
    printf("despues de una ruptura.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Pop();
        break;
    case 75:
        BlindingLights();
        break;
    case 77:
        Circles();
    default:
        Good4uPantalla();
        break;
    }
}
void Good4u()
{
    pthread_t HiloGood4uCancion;
    pthread_t HiloGood4u;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloGood4uCancion, NULL, Good4uCancion, NULL);
    pthread_create(&HiloGood4u, NULL, Good4uPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloGood4uCancion, NULL);
    pthread_join(HiloGood4u, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}

void CirclesPantalla()
{
    marco();

    TituloReproductor(20,1);

    gotoxy(6,10);
    printf("Cancion: Circles");
    gotoxy(6,13);
    printf("Artista: Post Malone");
    gotoxy(6,16);
    printf("Album: Hollywood's Bleeding");
    gotoxy(6,19);
    printf("Ano: 2019");
    gotoxy(6,22);
    printf("Genero: Pop");

    gotoxy(40,22);
    printf("Duracion: 3:34");

    gotoxy(40,10);
    printf("Comentario:");
    gotoxy(40,12);
    printf("Fue publicada como el tercer sencillo de su tercer");
    gotoxy(40,14);
    printf("album de estudio Hollywood's Bleeding. Lanzado el 30 de ");
    gotoxy(40,16);
    printf("agosto de 2019 a traves de la discografica Republic Records.");

    botonInicio(5,25,"<- Anterior");
    botonInicio(40,25,"[V]olver");
    botonInicio(75,25,"Siguiente ->");

    //FUNCIONALIDAD
    switch(getch())
    {
    case 'v':
        Pop();
        break;
    case 75:
        Good4u();
        break;
    case 77:
        Circles();
    default:
        CirclesPantalla();
        break;
    }
}
void Circles()
{
    pthread_t HiloCirclesCancion;
    pthread_t HiloCircles;
    pthread_t HiloDetenerHilo;
    pthread_create(&HiloCirclesCancion, NULL, CirclesCancion, NULL);
    pthread_create(&HiloCircles, NULL, CirclesPantalla, NULL);
    pthread_create(&HiloDetenerHilo, NULL, detenerCancion, NULL);
    pthread_join(HiloCirclesCancion, NULL);
    pthread_join(HiloCircles, NULL);
    pthread_join(HiloDetenerHilo, NULL);
}















