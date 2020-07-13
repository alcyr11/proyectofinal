#include <iostream>

const int longCad = 20;

//declaracion de estructura
struct costoPorArticulo {
    char nombreArticulo[longCad + 1]; 
    int cantidad;
    float precio;
    float costoPorArticulo;
};

using namespace std;

//declaracion de funciones
costoPorArticulo leerArray(int, costoPorArticulo arr []);
costoPorArticulo calcularCosto(int, costoPorArticulo arr []);
void recorrerArray(int, costoPorArticulo arr []);
float totalaPagar(int, costoPorArticulo arr []);

int main()
{   
    //variables
    int n;
    float precioTotal;
    //input - output
    cout << "Programa que procesa informacion sobre productos comprados por un cliente en una tienda." << endl;
    cout << "-------------" << endl;
    cout << "Ingrese el numero de productos a procesar: " << endl;
    cin >> n; 
    cin.ignore(100, '\n');
    
        //llenado de informacion
        costoPorArticulo arr [n];
        //calculos
        leerArray(n, arr);
        calcularCosto(n, arr);
        recorrerArray(n, arr);
        precioTotal = totalaPagar(n, arr);
        //output
        cout << "---------" << endl;
        cout << "El total a pagar es: $" << precioTotal;
   

    return 0;
}

//funcion para llenar el arreglo
costoPorArticulo leerArray(int n, costoPorArticulo arr []) {
    //variables
    int cantidad;
    float precio;
    //Completar arreglo
    for(int i = 0; i < n; i++) {
        int n = i + 1;
        cout << "Ingrese informacion del producto: " << n << endl;
        cout << "Nombre del producto: " << endl;
        cin.getline(arr [i].nombreArticulo, 20, '\n');
        cout << "Cantidad del producto: " << endl;
        cin >> cantidad;
        cout << "Precio del producto: " << endl;
        cin >> precio;
        cin.ignore(100, '\n');
        cout << "-------------" << endl;
        //Validar cantidad
        if (cantidad > 0 && precio > 0) {
            arr [i].cantidad = cantidad;
            arr [i].precio = precio;
        } else {
            i--;
            cout << "Precio o cantidad no validos." << endl;
        }
    }

    return arr [0];
}

// funcion para calcular el costo final
costoPorArticulo calcularCosto(int n, costoPorArticulo arr []) {
    float costoFinal = 0;
    for(int i = 0; i < n; i++) {
        //Calcular precio total por articulo
        costoFinal = arr [i].precio * arr [i].cantidad;
        arr [i].costoPorArticulo = costoFinal;
    }

    return arr [0];
}

// funcion para recorrer el arreglo
void recorrerArray(int x, costoPorArticulo arr []) {
    //mostrar informacion de compra
    cout << "--- FACTURA --- " << endl;
    for(int i = 0; i < x; i++) {
        int n = i + 1;
        cout << "Producto " << n <<  ": " << arr [i].nombreArticulo <<  " -- Cantidad: " << arr [i].cantidad <<  " -- Precio: $" 
        << arr [i].precio << " -- Precio final por articulo: $" << arr [i].costoPorArticulo << endl;
    }
}

// funcion para calcular el total a pagar
float totalaPagar(int x, costoPorArticulo arr []) {
    //acumulador
    float precioTotal = 0;
    //proceso
    for(int i = 0; i < x; i++) {
        precioTotal += arr [i].costoPorArticulo;
    }
    
    return precioTotal;
}


