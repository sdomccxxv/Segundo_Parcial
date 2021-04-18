// Segundo_Parcial.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <mysql.h>

using namespace std;
int q_estado;

void insertar_puesto();

int main()
{
    int a;
    cout << "Si desea\nIngresar, modificar o consultar datos de puestos presione 1 \nIngresar, modificar o consultar datos de empleados presione 2: ";
    cin >> a;

    switch (a)
    {
    case 1:
        int p;
        cout << "Si desea\ninsertar presione 1\n modificar presione 2 \n consultar presione 3: ";
        cin >> p;

        switch (p)
        {
        case 1:
            insertar_puesto(); break;
        default:
            break;
        }
    
    case 2:
        int e;
        cout << "Si desea\ninsertar presione 1\n modificar presione 2 \n consultar presione 3: ";
        cin >> e;

      }

}

void insertar_puesto() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_parcial2", 3306, NULL, 0);
    if (conectar) {
        string puesto;
        cout << "Ingrese puesto: ";
        cin >> puesto;

        string insertar = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "');";

        const char* i = insertar.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso de marca exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar marca..." << endl;
            cout << insertar << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }

}