#include <iostream>
#include <string>
#include <vector>
#include <cctype> // toupper

using namespace std;

struct Empleado
{
    string nombre;
    float base;
    float comision;
};

char menu();
void imprimirInforme(const vector<Empleado>& v);

int main()
{
    Empleado e;
    vector<Empleado> v;
    char opcion;
    int temp;

    do {
        cout << "\nDatos del empleado " << v.size() + 1 << ":\n";
        cout << "Nombre: "; getline(cin, e.nombre);
        cout << "Salario base: "; cin >> e.base;

        opcion = menu();

        switch (opcion)
        {
        case '1':
            e.comision = e.base * 0.05;
            break;

        case '2':
            cout << "Horas extra realizadas: "; cin >> temp;
            e.comision = e.base * temp * 0.01;
            break;

        case '3':
            cout << "Ventas realizadas: "; cin >> temp;
            e.comision = temp > 10 ? e.base * 0.03 : 0;
            break;

        default:
            break;
        }

        cout << "\n\nNombre: " << e.nombre;
        cout << "\nSueldo base: " << e.base;
        cout << "\nTipo: ";

        if (opcion == '1')
            cout << "Administrativo"
            << "\nComision 5% s/" << e.base << ": " << e.comision;

        else if (opcion == '2')
            cout << "Obrero"
            << "\nHoras extra: " << temp
            << "\nComision 1% * " << temp << " s/" << e.base << ": " << e.comision;

        else
        {
            cout << "Ventas"
                << "\nVentas realizadas: " << temp;

            if (temp > 10)
                cout << "\nComision por mas de 10 ventas, 3% s/" << e.base << ": " << e.comision;
            else
                cout << "\nComision: Sin comision";
        }

        v.push_back(e);

        cout << "\n\nOtro empleado (S/n): "; cin >> opcion;
        opcion = toupper(opcion);
        cin.ignore(80, '\n');

    } while (opcion == 'S');

    imprimirInforme(v);

    return EXIT_SUCCESS;
}

char menu()
{
    char opcion;

    do {
        cout << "\n    TIPO DE EMPLEADO"
            << "\n========================="
            << "\n1.- Administrativo .. [1]"
            << "\n2.- Obrero .......... [2]"
            << "\n3.- Ventas .......... [3]"
            << "\n========================="
            << "\nOPCION (1-3): ";

        cin >> opcion;

    } while (opcion != '1' && opcion != '2' && opcion != '3');

    return opcion;
}

void imprimirInforme(const vector<Empleado>& v)
{
    float base = 0.0f, comisiones = 0.0f;

    for (size_t i = 0; i < v.size(); i++)
    {
        base += v[i].base;
        comisiones += v[i].comision;
    }

    cout << "\nInforme final:"
        << "\nTotal emplados: " << v.size()
        << "\nTotal sueldos base: " << base
        << "\nTotal comisiones: " << comisiones
        << "\nGran total: " << base + comisiones
        << endl;
}