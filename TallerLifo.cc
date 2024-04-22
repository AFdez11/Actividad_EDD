#include <iostream>
#include <malloc.h>

using namespace std;

struct p_motos //hacemos referencia al parqueadero de motos.
{
    int id = 0; 
    char placa_motos[6];
    p_motos *sig;
    
};
int contadormotos = 0; int contadormotos2 = 500; int acumuladomotos = 0;

struct p_carros //hacemos referencia al parqueadero de carros.
{
   int id = 0; 
   char placa_carros[6];
    p_carros *sig;
};
int contadorcarros = 0; int contadorcarros2 = 1000; int acumuladocarros = 0;

 
p_motos *top, *aux, *top_aux;
p_carros *top2, *aux2, *top_aux2;


int registrarMotos(){

    aux = ((struct p_motos *) malloc(sizeof(struct p_motos)));
    
    if (top == NULL)
    {
        top = aux;
        top->id = 1;
        contadormotos = 1;
        acumuladomotos = contadormotos * contadormotos2;
        cout<<"Ingrese la placa de su vehiculo: ";
        cin>> top->placa_motos;
        top->sig = NULL;


    } else {

        aux->sig = top;
        aux->id = top->id + 1;
        contadormotos++;
        acumuladomotos = contadormotos * contadormotos2;
        cout<<"Ingrese la placa de su vehiculo: ";
        cin>> aux->placa_motos;
        top = aux;

    }

    aux = NULL;
    free(aux); 
    return 0;
}

int registrarCarros(){

    aux2 = ((struct p_carros *) malloc(sizeof(struct p_carros)));
    
    if (top2 == NULL)
    {
        top2 = aux2;
        top2->id = top2->id + 1;
        contadorcarros = 1;
        acumuladocarros = contadorcarros * contadorcarros2;
        cout<<"Ingrese la placa de su vehiculo: ";
        cin>> top2->placa_carros;
        top2->sig = NULL;

    } else {

        aux2->sig = top2;
        aux2->id = top2->id + 1;
        contadorcarros++;
        acumuladocarros = contadorcarros * contadorcarros2;
        cout<<"Ingrese la placa de su vehiculo: ";
        cin>> aux2->placa_carros;
        top2 = aux2;

    }

    aux = NULL;
    free(aux); 
    return 0;
}

int mostrarMotos(){
    if (top == NULL)
    {
        cout << "No hay vehiculos en el parqueadero de motos." << endl;
        cout << "" << endl;
        return 0;
    }

    for (aux=top; aux != NULL; aux = aux->sig)
    {
        cout<<"-----------------------------------"<<endl;
        cout<<"Placa: "<<aux->placa_motos<<endl;
        cout<<"ID: "<<aux->id<<endl;
        cout<<endl;
    }
    return 0;
}

int mostrarCarros(){
     if (top2 == NULL)
    {
        cout << "No hay vehiculos en el parqueadero de carros." << endl;
        cout << "" << endl;
        return 0;
    }

    for (aux2 = top2; aux2 != NULL; aux2 = aux2->sig)
    {
        cout<<"Placa: "<<aux2->placa_carros<<endl;
        cout<<"ID: "<<aux2->id<<endl;
        cout<<endl;
    }
    return 0;
}

int eliminarMotos(){

    if (top != NULL)
    {
        int opcion = 0;
        int acumulador = 0;
        int descuento = 50;
        int total;

        cout<<"Actualmente estan registrados los siguientes vehiculos: "<<endl;

        mostrarMotos();
        cout<<"-----------------------------"<<endl;

        cout<<"Ingrese el ID del vehiculo que desea retirar: ";
        cin>>opcion;

        while (top != NULL && top->id != opcion)
        {
            if (top_aux == NULL)
            {
                top_aux = top;
                top = top->sig;
                top_aux->sig = NULL;

            } else {
                aux = top;
                top = top->sig;
                aux->sig = top_aux;
                top_aux = aux;
                aux = NULL;
            }

            acumulador++;
        }

        total = acumulador * descuento;
        acumuladomotos = acumuladomotos + total;

        if ((top != NULL) && (top->id == opcion))
        {
            aux = top;
            top = top->sig;
            cout<<"¡Su vehiculo ha sido retirado con exito!"<<endl;
            free(aux);
        } else {
            cout<<"ID no valida."<<endl;
        }
        while (top_aux != NULL)
        {
            aux = top_aux->sig;
            top_aux->sig = top;
            top = top_aux;
            top_aux = aux;
            aux = NULL;
        }
    } else {
        cout<<"No hay vehiculos registrados."<<endl;
    }
    
    

    return 0;
}

int eliminarCarros(){

    if (top2 != NULL)
    {
        int opcion = 0;
        int acumulador = 0;
        int descuento = 100;
        int total;

        cout<<"Actualmente estan registrados los siguientes vehiculos: "<<endl;
        mostrarCarros();
        cout<<"-----------------------------"<<endl;

        cout<<"Ingrese el ID del vehiculo que desea retirar: ";
        cin>>opcion;

        while (top2 != NULL && top2->id != opcion)
        {
            if (top_aux2 == NULL)
            {
                top_aux2 = top2;
                top2 = top2->sig;
                top_aux2->sig = NULL;

            } else {
                aux2 = top2;
                top2 = top2->sig;
                aux2->sig = top_aux2;
                top_aux2 = aux2;
                aux2 = NULL;
            }

            acumulador++;
        }

        total = acumulador * descuento;
        acumuladocarros = acumuladocarros - total;

        if ((top2 != NULL) && (top2->id == opcion))
        {
            aux2 = top2;
            top2 = top2->sig;
            cout<<"¡Su vehiculo ha sido retirado con exito!"<<endl;
            free(aux2);
        } else {
            cout<<"ID no valida."<<endl;
        }
        while (top_aux2 != NULL)
        {
            aux2 = top_aux2->sig;
            top_aux2->sig = top2;
            top2 = top_aux2;
            top_aux2 = aux2;
            aux2 = NULL;
        }
    } else {
        cout<<"No hay vehiculos registrados."<<endl;
    }

    return 0;
}

int recaudado(){
    int total = 0;
    total = acumuladomotos + acumuladocarros;

    cout<<"Su total recaudado por parte de las motos es de: "<<acumuladomotos<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Su total recaudado por parte de los carros es de: "<<acumuladocarros<<endl;

    cout<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Su total general es de: "<<total<<endl;

    return 0;
}

int main(){

int opcion = 0;
int opcion2 = 0;
int opcion3 = 0;

cout<<"(RECUERDA QUE TODO VEHICULO EXPEDIDO EN COLOMBIA CUENTA CON UNA PLACA DE SEIS DIGITOS.)"<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"     Bienvenido a parqueaderos 'Elsayayin'   "<<endl;
do{

    cout<<"---------------------------------------------"<<endl;
    cout<<"1.           Registrar vehiculo              "<<endl;
    cout<<"2.           Mostrar vehiculos               "<<endl;
    cout<<"3.           Retirar vehiculo                "<<endl;
    cout<<"4.           Mostrar total monetario recaudado     "<<endl;
    cout<<"5.           Salir                           "<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"Opcion: ";
    cin>> opcion;

    switch (opcion){

        case 1:

            cout<<"1.       Registrar moto."<<endl;
            cout<<"2.       Registrar carro."<<endl;
            cout<<"3.       salir."<<endl;
            cout<<"Opcion: ";
            cin>>opcion2;

            switch (opcion2){

                case 1:
                    registrarMotos(); break;

                case 2:
                    registrarCarros(); break;

                case 3:
                    cout<<"¡Gracias por confiar en nosotros!"<<endl;
                    break;


                default:
                    cout<<"Opcion invalida."<<endl;
                    break;
            }

            break;

        case 2:

            cout<<"1.       Mostrar motos."<<endl;
            cout<<"2.       Mostrar carros."<<endl;
            cout<<"3.       Salir."<<endl;
            cout<<"Opcion: ";
            cin>>opcion3;

            switch (opcion3){

                case 1:
                mostrarMotos(); break;

                case 2:
                mostrarCarros(); break;

                case 3:
                    cout<<"¡Gracias por confiar en nosotros!"<<endl;
                    break;


                default:
                    cout<<"Opcion invalida."<<endl;
                    break;
            }

            break;

        case 3: 

            cout<<"1.       Retirar moto."<<endl;
            cout<<"2.       Retirar carro."<<endl;
            cout<<"3.       Salir."<<endl;
            cout<<"Opcion: ";
            cin>>opcion3;

            switch (opcion3){

                case 1:
                eliminarMotos(); break;

                case 2:
                eliminarCarros(); break;

                case 3:
                    cout<<"¡Gracias por confiar en nosotros!"<<endl;
                    break;


                default:
                    cout<<"Opcion invalida."<<endl;
                    break;
            }

            break;

        case 4:
            recaudado();
            break;

        case 5:
            cout<<"¡Gracias por confiar en nosotros!"<<endl;
            break;

        default:
            cout<<"Opcion invalida."<<endl;
            break;
        }

} while (opcion != 5);


}