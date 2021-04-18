#include <iostream>
#include <stdio.h>
#include <string>
#include <mysql.h>

using namespace std;
int q_estado;

void insertar_puesto();
void mostrar_puesto();
void actualizar_puesto();
void eliminar_puesto();

int main()
{
    int a;
    cout << "Si desea\nIngresar, modificar o consultar datos de puestos presione 1 \nIngresar, modificar o consultar datos de empleados presione 2: ";
    cin >> a;

    switch (a)
    {
    case 1:
        int p;
        cout << "Si desea\ninsertar presione 1\n modificar presione 2 \n consultar presione 3 \n eliminar presione 4:";
        cin >> p;

        switch (p)
        {
        case 1:
            insertar_puesto(); break;
        case 2:
            actualizar_puesto(); break;
        case 3: 
            mostrar_puesto(); break;
        case 4:
            eliminar_puesto(); break;
        default:
            break;
        }
        break;
    
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
            cout << "Ingreso de puesto exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar marca..." << endl;
            cout << insertar << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    return;

}

void mostrar_puesto() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_parcial2", 3306, NULL, 0);
    if (conectar) {
        string consulta = "SELECT * FROM puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);

        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << " - " << fila[1] << endl;
            }
        }
        else {
            cout << "Error al consultar..." << endl;
        }

    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
}

void actualizar_puesto() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_parcial2", 3306, NULL, 0);
    if (conectar) {
        //cout << "Conexion exitosa..." << endl;
        char idpuesto;
        string puesto;
        cout << "Ingrese id que desea modificar: ";
        cin >> idpuesto;

        cout << "Ingrese nuevo puesto: ";
        cin >> puesto;

        string update = "UPDATE puestos SET puesto = '" + puesto + "' WHERE idpuesto = " + idpuesto + "";
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Actualizacion exitosa..." << endl;
        }
        else {
            cout << "Error al actualizar..." << endl;
            cout << update << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    system("pause");
    system("exit");
}

void eliminar_puesto() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "150289", "db_parcial2", 3306, NULL, 0);
    if (conectar) {

        string idpuesto;
        cout << "Ingrese id que desea eliminar: ";
        cin >> idpuesto;

        string eliminar = "DELETE FROM puestos WHERE idpuesto = " + idpuesto +"\n";
        cout << eliminar;
        const char* i = eliminar.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Eliminacion exitosa..." << endl;
            return;
        }
        else {
            cout << "Error al eliminar..." << endl;
            cout << eliminar << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    
}