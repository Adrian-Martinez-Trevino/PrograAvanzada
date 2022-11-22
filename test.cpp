
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

struct User {
    char user[100];
    char password[100];
    char alias[100];
    char comercio[100];
    bool tipoUser;
    int Usu_matricula = 0;
    User* User_sig;
};

struct Client {
    char cliente[100];
    char correo[100];
    char alias[100];
    int telefono;
    char comercio[100];
    char fecha[100];
    int Cliente_matricula = 0;
    Client* Client_sig;
};

struct Promo {
    int numpromo = 0;
    char nombrepromo[100];
    int montopromo;
    int porcentaje;
    bool estatus;
    char fecha[100];
    Promo* Promo_sig;
};

struct Consu {
    char cliente[100];
    int monto;
    int subtotal;
    int descuento;
    int total;
    char fecha[100];
    Consu* Consu_sig;
};

User* UserInicio, * UserAux = nullptr;
Client* ClientInicio, * ClientAux = nullptr;
Promo* PromoInicio, * PromoAux = nullptr;
Consu* ConsuInicio, * ConsuAux = nullptr;

void guardarBin(User* Usunodo, Client* Clientnodo, Promo* Promonodo, Consu* Consunodo);
void leerBin();
void doUser(int op, User* nodo);
void modUser(int opmod, User* nodomod);
void doClient(int opclient, Client* nodo);
void modClient(int opmodclient, Client* nodo);
void doPromo(int opPromo, Promo* nodo);
void doConsu(Consu* nodo);
void list(int oplist, User* Usunodo, Client* Clientnodo, Promo* Promonodo, Consu* Consunodo);

int main()
{
    int menu = 0;
    User* nodoUser = new User;
    Client* nodoClient = new Client;
    Promo* nodoPromo = new Promo;
    Consu* nodoConsu = new Consu;

    //leerBin();

    do {
        system("cls");
        cout << ":::::MENÚ:::::" << endl;
        cout << "1) Alta/Baja de Usuario." << endl;
        cout << "2) Modificar Usuario/Contraseña." << endl;
        cout << "3) Alta/Baja de Cliente." << endl;
        cout << "4) Modificar Cliente." << endl;
        cout << "5) Alta/Baja de Promoción." << endl;
        cout << "6) Alta de Consumo." << endl;
        cout << "7) Mostrar lista." << endl;
        cout << "8) Salir." << endl;

        cin >> menu;
        cin.ignore();

        switch (menu) {
        case 1:
            // Alta/Baja de usuario
            int opUsu;
            cout << "     MENU USUARIO" << endl;
            cout << "1) Alta de usuario." << endl;
            cout << "2) Baja de usuario." << endl;
            cout << "3) Regresar al menú." << endl;
            cin >> opUsu;
            cin.ignore();

            if (opUsu == 1) {
                cout << "     AGREGAR USUARIO\n" << endl;
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Tipo de usuario \n0. Cajero\n1. Administrador\n";
                cin >> nodoUser->tipoUser;
                cin.ignore();
                cout << "Nombre del usuario: ";
                cin.ignore();
                cin.getline(nodoUser->user, sizeof(nodoUser->user));
                cout << "Contraseña de usuario: ";
                cin.ignore();
                cin.getline(nodoUser->password), sizeof(nodoUser->password));
                cout << "Comercio del usuario: ";
                cin.ignore();
                cin.getline(nodoUser->comercio, sizeof(nodoUser->comercio));
                cout << "Alias de usuario: ";
                cin.ignore();
                getline(cin, nodoUser->alias);
                nodoUser->Usu_matricula += 1;
            }

            if (opUsu != 1 and opUsu != 2) {
                if (opUsu != 3) {
                    cout << "El valor que introdujo es incorrecto. Intentelo de nuevo.";
                }
                return main();
            }

            doUser(opUsu, nodoUser);
            break;

        case 2:
            // Modificar usuario
            int opmodUsu;

            cout << "     MODIFICAR USUARIO\n" << endl;
            cout << "   DATOS DEL USUARIO\n" << endl;
            cout << "Matricula del usuario: ";
            cin >> nodoUser->Usu_matricula;
            cin.ignore();

            cout << "     MENU MODIFICAR USUARIO" << endl;
            cout << "1) Tipo de usuario." << endl;
            cout << "2) Nombre de usuario." << endl;
            cout << "3) Contraseña de usuario." << endl;
            cout << "4) Alias del usuario." << endl;
            cout << "5) Comercio del usuario." << endl;
            cout << "6) Todo." << endl;
            cout << "7) Regresar al menú." << endl;
            cin >> opmodUsu;
            cin.ignore();

            switch (opmodUsu) {

            case 1:
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Tipo de usuario \n0. Cajero\n1. Administrador\n";
                cin >> nodoUser->tipoUser;
                cin.ignore();

                break;

            case 2:
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Nombre del usuario: ";
                getline(cin, nodoUser->user);

                break;

            case 3:
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Contraseña de usuario: ";
                getline(cin, nodoUser->password);

                break;

            case 4:
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Alias de usuario: ";
                getline(cin, nodoUser->alias);

                break;

            case 5:
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Comercio del usuario: ";
                getline(cin, nodoUser->comercio);

                break;

            case 6:
                cout << "   DATOS DEL USUARIO\n" << endl;
                cout << "Tipo de usuario \n0. Cajero\n1. Administrador\n";
                cin >> nodoUser->tipoUser;
                cin.ignore();
                cout << "Nombre del usuario: ";
                getline(cin, nodoUser->user);
                cout << "Contraseña de usuario: ";
                getline(cin, nodoUser->password);

                break;

            case 7:
                return main();
                break;

            default:
                cout << "El valor que introdujo es incorrecto. Intentelo de nuevo.";
                break;
            }

            modUser(opmodUsu, nodoUser);
            break;

        case 3:
            // Alta/Baja de cliente

            int opClient;
            cout << "     MENU CLIENTE" << endl;
            cout << "1) Alta de cliente." << endl;
            cout << "2) Baja de cliente." << endl;
            cout << "3) Regresar al menú." << endl;
            cin >> opClient;
            cin.ignore();

            if (opClient == 1) {
                cout << "     AGREGAR CLIENTE\n" << endl;
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Nombre del cliente: ";
                getline(cin, nodoClient->cliente);
                cout << "Correo del cliente: ";
                getline(cin, nodoClient->correo);
                cout << "Alias del cliente: ";
                getline(cin, nodoClient->alias);
                cout << "Telefono del cliente: ";
                cin >> nodoClient->telefono;
                cin.ignore();
                cout << "Comercio del cliente: ";
                getline(cin, nodoClient->comercio);

                nodoClient->Cliente_matricula += 1;
            }

            if (opClient == 2) {
                cout << "     ELIMINAR USUARIO\n" << endl;
                cout << "Matricula del usuario: ";
                cin >> nodoClient->Cliente_matricula;
                cin.ignore();
            }

            if (opClient != 1 and opClient != 2) {
                if (opClient != 3) {
                    cout << "El valor que introdujo es incorrecto. Intentelo de nuevo.";
                }
                return main();
            }

            doClient(opClient, nodoClient);
            break;

        case 4:
            // Modificar cliente

            int opmodClient;

            cout << "     MODIFICAR CLIENTE\n" << endl;
            cout << "   DATOS DEL CLIENTE\n" << endl;
            cout << "Matricula del cliente: ";
            cin >> nodoClient->Cliente_matricula;
            cin.ignore();

            cout << "     MENU MODIFICAR USUARIO" << endl;
            cout << "1) Nombre de cliente." << endl;
            cout << "2) Correo de cliente." << endl;
            cout << "3) Alias del cliente." << endl;
            cout << "4) Comercio del cliente." << endl;
            cout << "5) Telefono del cliente." << endl;
            cout << "6) Todo." << endl;
            cout << "7) Regresar al menú." << endl;
            cin >> opmodClient;
            cin.ignore();

            switch (opmodClient) {

            case 1:
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Nombre del cliente: ";
                getline(cin, nodoClient->cliente);

                break;

            case 2:
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Correo del cliente: ";
                getline(cin, nodoClient->correo);

                break;

            case 3:
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Alias del cliente: ";
                getline(cin, nodoClient->alias);

                break;

            case 4:
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Comercio del cliente: ";
                getline(cin, nodoClient->comercio);

                break;

            case 5:
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Telefono del cliente: ";
                cin >> nodoClient->telefono;
                cin.ignore();

                break;

            case 6:
                cout << "   DATOS DEL CLIENTE\n" << endl;
                cout << "Nombre del cliente: ";
                getline(cin, nodoClient->cliente);
                cout << "Correo del cliente: ";
                getline(cin, nodoClient->correo);
                cout << "Alias del cliente: ";
                getline(cin, nodoClient->alias);
                cout << "Telefono del cliente: ";
                cin >> nodoClient->telefono;
                cin.ignore();
                cout << "Comercio del cliente: ";
                getline(cin, nodoClient->comercio);

                break;

            case 7:
                return main();
                break;

            default:
                cout << "El valor que introdujo es incorrecto. Intentelo de nuevo.";
                break;
            }

            modClient(opmodClient, nodoClient);
            break;

        case 5:
            // Alta/Baja Promoción
            int opPromo;

            cout << "     MENU CLIENTE" << endl;
            cout << "1) Alta de promoción." << endl;
            cout << "2) Baja de promoción." << endl;
            cout << "3) Regresar al menú." << endl;
            cin >> opPromo;
            cin.ignore();

            if (opPromo == 1) {
                cout << "   DATOS DE LA PROMOCIÓN\n" << endl;
                nodoPromo->numpromo += 1;
                cin.ignore();
                cout << "Nombre de la promoción: ";
                getline(cin, nodoPromo->nombrepromo);
                cout << "Monto de la promoción: ";
                cin >> nodoPromo->montopromo;
                cin.ignore();
                cout << "Porcentaje de descuento: ";
                cin >> nodoPromo->porcentaje;
                cin.ignore();
                cout << "Estatus de la promoción\n0. Inactiva\n1. Activa\n ";
                cin >> nodoPromo->estatus;
                cin.ignore();
                //cout << "Comercio del cliente: ";
                //getline(cin, nodoPromo->fecha);
            }

            if (opPromo == 2) {
                cout << "   DATOS DE LA PROMOCIÓN\n" << endl;
                cin >> nodoPromo->numpromo;
                cin.ignore();
            }

            if (opPromo != 1 and opPromo != 2) {
                if (opPromo != 3) {
                    cout << "El valor que introdujo es incorrecto. Intentelo de nuevo.";
                }
                return main();
            }

            doPromo(opPromo, nodoPromo);
            break;

        case 6:
            // Alta de consumo

            cout << "   DATOS DEL CONSUMO\n" << endl;
            cout << "Nombre del cliente: ";
            getline(cin, nodoConsu->cliente);
            cout << "Monto del consumo: ";
            cin >> nodoConsu->monto;
            cin.ignore();
            cout << "Sub-Total del consumo: ";
            cin >> nodoConsu->subtotal;
            cin.ignore();
            cout << "Porcentaje de descuento: ";
            cin >> nodoConsu->descuento;
            cin.ignore();
            cout << "Total del consumo: ";
            cin >> nodoConsu->total;
            cin.ignore();
            //cout << "Comercio del cliente: ";
            //getline(cin, nodoPromo->fecha);

            doConsu(nodoConsu);
            break;

        case 7:
            // Mostrar lista

            int opList;
            cout << "     MENU CLIENTE" << endl;
            cout << "1) Lista de usuarios." << endl;
            cout << "2) Lista de clientes." << endl;
            cout << "3) Lista de promociones." << endl;
            cout << "4) Lista de consumo." << endl;
            cout << "5) Regresar al menú." << endl;
            cin >> opList;
            cin.ignore();

            if (opPromo != 1 and opPromo != 2 and opPromo != 3 and opPromo != 4) {
                if (opPromo != 5) {
                    cout << "El valor que introdujo es incorrecto. Intentelo de nuevo.";
                }
                return main();
            }

            list(opList, nodoUser, nodoClient, nodoPromo, nodoConsu);
            break;

        case 8:
            // Salir
            system("cls");
            cout << "Saliendo...";
            exit(0);
            break;

        default:
            system("cls");
            cout << "El valor que introdujo es invalido. Intente de nuevo";
        }

    } while (menu != 8);

    guardarBin(nodoUser, nodoClient, nodoPromo, nodoConsu);
}

void guardarBin(User* Usunodo, Client* Clientnodo, Promo* Promonodo, Consu* Consunodo) {
    UserAux = UserInicio;
    ClientAux = ClientInicio;
    PromoAux = PromoInicio;
    ConsuAux = ConsuInicio;

    ofstream escribirListas;
    escribirListas.open("C:\\Users\\listas.bin", ios::out | ios::binary | ios::trunc);

    if (escribirListas.is_open()) {
        while (UserAux != nullptr)
        {
            escribirListas.write((char*)UserAux, sizeof(Usunodo));
            UserAux = UserAux->User_sig;
        }
        while (ClientAux != nullptr)
        {
            escribirListas.write((char*)ClientAux, sizeof(Clientnodo));
            ClientAux = ClientAux->Client_sig;
        }
        while (PromoAux != nullptr)
        {
            escribirListas.write((char*)PromoAux, sizeof(Promonodo));
            PromoAux = PromoAux->Promo_sig;
        }
        while (ConsuAux != nullptr)
        {
            escribirListas.write((char*)ConsuAux, sizeof(Consunodo));
            ConsuAux = ConsuAux->Consu_sig;
        }
        escribirListas.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo.";
        system("PAUSE");
    }
}


void leerBin() {

    ifstream archivoListas;
    archivoListas.open("C:\\Users\\listas.bin", ios::in | ios::binary);


    if (archivoListas.is_open()) {

        User* nodovisto = new User;

        while (!archivoListas.read((char*)nodovisto, sizeof(User)).eof()) {

            if (UserInicio == nullptr) {
                UserInicio = nodovisto;
                UserInicio->User_sig = nullptr;
                UserAux = UserInicio;
            }
            else {
                UserAux->User_sig = nodovisto;
                UserAux = UserAux->User_sig;
                UserAux->User_sig = nullptr;
            }

            nodovisto = new User;
        }
        archivoListas.close();
        delete nodovisto;
    }
    else {
        cout << "No es posible abrir el archivo.";
        system("PAUSE");
    }

}

void doUser(int op, User* nodo) {

    switch (op) {

    case 1:
        // Alta de usuario

        if (UserInicio == nullptr) {
            UserInicio = new User;
            UserAux = UserInicio;

            UserAux->Usu_matricula = nodo->Usu_matricula;
            UserAux->tipoUser = nodo->tipoUser;
            strcpy_s(UserAux->user, nodo->user);
            strcpy_s(UserAux->password, nodo->password);
            strcpy_s(UserAux->alias, nodo->alias);
            strcpy_s(UserAux->comercio, nodo->comercio);
            UserAux->User_sig = nullptr;
        }
        else {
            UserAux = UserInicio;
            while (UserAux->User_sig != nullptr)
            {
                UserAux = UserAux->User_sig;
            }
            UserAux->User_sig = new User;

            UserAux = UserAux->User_sig;

            UserAux->Usu_matricula = nodo->Usu_matricula;
            UserAux->tipoUser = nodo->tipoUser;
            UserAux->user = nodo->user;
            strcpy_s(UserAux->password, nodo->password);
            strcpy_s(UserAux->alias, nodo->alias);
            strcpy_s(UserAux->comercio, nodo->comercio);
            UserAux->User_sig = nullptr;
        }

        break;

    case 2:
        // Baja de usuario

        cout << "     ELIMINAR USUARIO\n" << endl;
        cout << "Matricula del usuario: ";
        cin >> nodo->Usu_matricula;
        cin.ignore();

        UserAux = UserInicio;
        User* anterior = nullptr;

        if (UserAux == nullptr)
        {
            cout << "La lista esta vacia." << endl;
        }
        else {

            while (UserAux != nullptr && UserAux->Usu_matricula != nodo->Usu_matricula) {
                anterior = UserAux;
                UserAux = UserAux->User_sig;
            }
            if (UserAux == nullptr) {
                cout << "Cancion no encontrada" << endl;
            }
            else if (UserAux == UserInicio) {
                cout << "    Usuario encontrado " << endl;
                cout << "Nombre del usuario: " << UserAux->user << endl;
                cout << "\n";

                UserInicio = UserAux->User_sig;


                delete UserAux;

                UserAux = UserInicio;

                cout << "Usuario eliminado exitosamente" << endl;
            }
            else {
                cout << "Usuario encontrado" << endl;
                cout << "Nombre del usuario: " << UserAux->user << endl;
                cout << "\n";

                anterior->User_sig = UserAux->User_sig;

                delete UserAux;

                UserAux = UserInicio;

                cout << "Usuario eliminado" << endl;

            }
        }

        system("PAUSE");

        break;

    default:
        system("cls");
        cout << "El valor que introdujo es invalido. Intente de nuevo";
        break;
    }
}

void modUser(int opmod, User* nodomod) {
    UserAux = UserInicio;

    if (UserAux == nullptr)
    {
        cout << "No hay usuarios en esta lista." << endl;
    }
    else {	//Nos movemos en el arreglo
        while (UserAux != nullptr && UserAux->Usu_matricula != nodomod->Usu_matricula) { //strcmp devuelve 0 si las dos son iguales
                                                                    //Las 2 condiciones deben de ser SI para que entre al while
            UserAux = UserAux->User_sig;
        }
        if (UserAux == nullptr) {	//Como se sale de while si una de las dos es no, aquí preguntamos en caso de que se salió
            cout << "Usuario no encontrado" << endl;	//porque terminó la lista y entonces no la encontró
        }
        else {											//O porque encontró la canción y entonces la modificamos
            cout << "----Usuario encontrado" << endl;
            cout << "Nombre del usuario: " << UserAux->user << endl;
            cout << "\n";

            switch (opmod)
            {
            case 1:
                cout << "Nuevo tipo de usuario: \n0. Cajero \n1. Administrador" << endl;
                cin >> UserAux->tipoUser;
                break;

            case 2:
                cout << "Nuevo nombre de usuario: " << endl;
                getline(cin, UserAux->user);
                break;

            case 3:
                cout << "Nueva contraseña: " << endl;
                getline(cin, UserAux->password);
                break;

            case 4:
                cout << "Nuevo alias: " << endl;
                getline(cin, UserAux->alias);
                break;

            case 5:
                cout << "Nuevo comercio: " << endl;
                getline(cin, UserAux->comercio);
                break;

            case 6:
                cout << "Nuevo tipo de usuario: \n0. Cajero \n1. Administrador" << endl;
                cin >> UserAux->tipoUser;
                cout << "Nuevo nombre de usuario: " << endl;
                getline(cin, UserAux->user);
                cout << "Nueva contraseña: " << endl;
                getline(cin, UserAux->password);
                cout << "Nuevo alias: " << endl;
                getline(cin, UserAux->alias);
                cout << "Nuevo comercio: " << endl;
                getline(cin, UserAux->comercio);
                break;

            default:
                break;
            }

            cout << "----Usuario modificado" << endl;

        }
    }

    system("PAUSE");
}

void doClient(int opclient, Client* nodo) {
    switch (opclient) {

    case 1:
        // Alta de usuario

        if (ClientInicio == nullptr) {
            ClientInicio = new Client;
            ClientAux = ClientInicio;

            ClientAux->Cliente_matricula = nodo->Cliente_matricula;
            ClientAux->telefono = nodo->telefono;
            strcpy_s(ClientAux->cliente, nodo->cliente);
            strcpy_s(ClientAux->correo, nodo->correo);
            strcpy_s(ClientAux->alias, nodo->alias);
            strcpy_s(ClientAux->comercio, nodo->comercio);
            ClientAux->Client_sig = nullptr;
        }
        else {
            UserAux = UserInicio;
            while (UserAux->User_sig != nullptr)
            {
                ClientAux = ClientAux->Client_sig;
            }
            ClientAux->Client_sig = new Client;

            ClientAux = ClientAux->Client_sig;

            ClientAux->Cliente_matricula = nodo->Cliente_matricula;
            ClientAux->telefono = nodo->telefono;
            strcpy_(ClientAux->cliente, nodo->cliente);
            strcpy_s(ClientAux->correo, nodo->correo);
            strcpy_s(ClientAux->alias, nodo->alias);
            strcpy_s(ClientAux->comercio, nodo->comercio);
            ClientAux->Client_sig = nullptr;
        }

        break;

    case 2:
        // Baja de usuario

        cout << "     ELIMINAR CLIENTE\n" << endl;
        cout << "Matricula del Cliente: ";
        cin >> nodo->Cliente_matricula;
        cin.ignore();

        ClientAux = ClientInicio;
        Client* anterior = nullptr;

        if (ClientAux == nullptr)
        {
            cout << "No existe ningun cliente." << endl;
        }
        else {

            while (ClientAux != nullptr && ClientAux->Cliente_matricula != nodo->Cliente_matricula) {
                anterior = ClientAux;
                ClientAux = ClientAux->Client_sig;
            }
            if (UserAux == nullptr) {
                cout << "Cliente no encontrado" << endl;
            }
            else if (ClientAux == ClientInicio) {
                cout << "    Cleinte encontrado " << endl;
                cout << "Nombre del cliente: " << ClientAux->cliente << endl << endl;

                ClientInicio = ClientAux->Client_sig;


                delete ClientAux;

                ClientAux = ClientInicio;

                cout << "Cliente eliminado exitosamente" << endl;
            }
            else {
                cout << "Cliente encontrado" << endl;
                cout << "Nombre del cliente: " << UserAux->user << endl;
                cout << "\n";

                anterior->Client_sig = ClientAux->Client_sig;

                delete ClientAux;

                ClientAux = ClientInicio;

                cout << "Cliente eliminado" << endl;

            }
        }

        system("PAUSE");

        break;

    default:
        system("cls");
        cout << "El valor que introdujo es invalido. Intente de nuevo";
        break;
    }
}

void modClient(int opmodclient, Client* nodo) {

}

void doPromo(int opPromo, Promo* nodo) {

}

void doConsu(Consu* nodo) {

}

void list(int oplist, User* Usunodo, Client* Clientnodo, Promo* Promonodo, Consu* Consunodo) {

}