#include <iostream>
#include <stdio.h>
#include <string>
#include <mysql.h>

using namespace std;
int q_estado;

void insertar_p();
void mostrar_p();
void actualizar_p();
void eliminar_p();
void insertar_emp();
void mostrar_emp();
void actualizar_emp();
void eliminar_emp();

int main()
{
    int a;
    cout << "Seleccione en que tabla desea trabajar\nPuestos 1\nEmpleados 2: ";
    cin >> a;

    switch (a)
    {
    case 1:
        int p;
        cout << "Insertar 1\nMostrar 2\nModificar 3\nElminar 4:";
        cin >> p;

        switch (p)
        {
        case 1:
            insertar_p(); break;
        case 2:
            mostrar_p(); break;
        case 3: 
            actualizar_p(); break;
        case 4:
            eliminar_p(); break;
        default:
            break;
        }
        break;
    
    case 2:
        int e;
        cout << "Insertar 1\nMostrar 2\nModificar 3\nElminar 4:";
        cin >> e;

        switch (e)
        {
        case 1: 
            insertar_emp(); break;
        case 2:
            actualizar_emp(); break;
        case 3:
            mostrar_emp(); break;
        case 4:
            eliminar_emp(); break;
        default:
            break;
        }
        break;
      }

}

//PUESTO
void insertar_p() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);
    if (conectar) {
        string puesto;
        cout << "Ingrese puesto: ";
        cin >> puesto;

        string insertar = "INSERT INTO puestos(puesto) VALUES ('" + puesto + "');";

        const char* i = insertar.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar..." << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }
    return;

}

void mostrar_p() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);
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

void actualizar_p() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);
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

void eliminar_p() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);
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

//EMPLEADO
void insertar_emp() {
    string nombre, apellido, direccion, telefono, dpi, fecha_nac, fecha_inicio, fecha_ingreso;
    char genero, idpuesto;

    cout << "Ingrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese los apellidos del empleado: ";
    cin.ignore();
    getline(cin, apellido);

    cout << "Ingrese la direccion del empleado: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Ingrese el telefono del empleado: ";
    cin >> telefono;

    cout << "Ingrese el DPI del empleado: ";
    cin >> dpi;

    cout << "Ingrese el genero del empleado: ";
    cin >> genero;
  
    cout << "Ingrese la fecha de nacimiento: ";
    cin >> fecha_nac;

    cout << "Ingrese el id del puesto del empleado: ";
    cin >> idpuesto;

    cout << "Ingrese la fecha de inicio de labores: ";
    cin >> fecha_inicio;

    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);

    if (conectar) {
        string insert = "INSERT INTO `empleados`(`nombres`,`apellidos`,`direccion`,`telefono`,`DPI`,`genero`,`fecha_nacimiento`,`idPuesto`,`fecha_inicio_labores`,`fechaingreso`) VALUES ('" + nombre + "', '" + apellido + "', '" + direccion + "', '" + telefono + "', '" + dpi + "', '" + genero + "', '" + fecha_nac + "', " + idpuesto + ", '" + fecha_inicio + "', NOW())";
        cout << insert;
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Ingreso exitoso..." << endl;
        }
        else {
            cout << "Error al ingresar..." << endl;
            cout << insert << endl << mysql_error(conectar) << endl;
        }
    }
    else {
        cout << "Conexion fallida..." << endl;
    }

    system("pause");
}

void mostrar_emp() {
    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);
    if (conectar) {
        string consulta = "SELECT * FROM empleados";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);

        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while (fila = mysql_fetch_row(resultado)) {
                cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - " << fila[4] << " - " << fila[5] << " - " << fila[6] << " - " << fila[7] << " - " << fila[8] << " - " << fila[9] << " - " << fila[10] << endl;
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

void actualizar_emp() {
    string nombre, apellido, direccion, telefono, dpi, fecha_nac, fecha_inicio, fecha_ingreso;
    char genero, idpuesto, idempleado;

    cout << "Ingrese id que desea modificar: ";
    cin >> idempleado;

    cout << "Ingrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese los apellidos del empleado: ";
    cin.ignore();
    getline(cin, apellido);

    cout << "Ingrese la direccion del empleado: ";
    cin.ignore();
    getline(cin, direccion);

    cout << "Ingrese el telefono del empleado: ";
    cin >> telefono;

    cout << "Ingrese el DPI del empleado: ";
    cin >> dpi;

    cout << "Ingrese el genero del empleado: ";
    cin >> genero;

    cout << "Ingrese la fecha de nacimiento: ";
    cin >> fecha_nac;

    cout << "Ingrese el id del puesto del empleado: ";
    cin >> idpuesto;

    cout << "Ingrese la fecha de inicio de labores: ";
    cin >> fecha_inicio;

    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);

    if (conectar) {
        string update = "UPDATE `empleados` SET nombres = '" + nombre + "', apellidos = '" + apellido + "', direccion = '" + direccion + "', telefono = '" + telefono + "', dpi = '" + dpi + "', genero = '" + genero + "', fecha_nacimiento = '" + fecha_nac + "', idpuesto = " + idpuesto + ", fecha_inicio_labores = '" + fecha_inicio + "', fechaingreso = NOW() WHERE idempleado = " + idempleado + "\n";
        const char* i = update.c_str();
        q_estado = mysql_query(conectar, i);

        if (!q_estado) {
            cout << "Actualizacion exitoso..." << endl;
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
}

void eliminar_emp() {
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "naopc", "12345678", "db_parcialnaopc", 3306, NULL, 0);
    if (conectar) {

        string idempleado;
        cout << "Ingrese id que desea eliminar: ";
        cin >> idempleado;

        string eliminar = "DELETE FROM empleados WHERE idempleado = " + idempleado + "\n";
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