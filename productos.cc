#include <iostream>
#include <malloc.h>

using namespace std;

struct productos
{
    int ID; //aquí almacenaremos el id del producto
    float precio;
    char nombre[30];
    int cantidad;
    int i;
    productos *sig;

};

productos *cab, *aux, *aux2, *borrar, *anterior = NULL, *actual;

int agregar(){

    

    if (cab == NULL)
    {
        
        cab = (struct productos *) malloc (sizeof(struct productos));

        cout<<"Ingrese el nombre del producto: ";
        cin>> cab->nombre;

        cout<<"Ingrese el ID del producto: ";
        cin >> cab -> ID;

        cout<<"Ingrese la cantidad del producto: ";
        cin >> cab -> cantidad;

        cout<<"Ingrese el precio del producto: ";
        cin>> cab -> precio;

        cab -> sig = NULL;
        
    } else {
        aux = (struct productos *) malloc (sizeof(struct productos));
        
        cout<<"Ingrese el nombre del producto: ";
        cin>> aux->nombre;

        cout<<"Ingrese el ID del producto: ";
        cin >> aux -> ID;

        if (cab->ID != aux->ID)
        {
            cout<<"Ingrese la cantidad del producto: ";
            cin >> aux-> cantidad;

            cout<<"Ingrese el precio del producto: ";
            cin>> aux -> precio;

            aux ->sig = NULL;
            aux2 = cab;

             while (aux2 ->sig != NULL)
            {
                aux2 = aux2 ->sig;
            }
                aux ->i = aux2 ->i +1;
                aux2 ->sig = aux;
                aux2 = aux = NULL;
                free(aux);
                free(aux2);
        }
        else {
            cout<<"¡NO SE PUEDE UTILIZAR EL MISMO ID PARA 2 O MAS PRODUCTOS!"<<endl;
        }
        
    }
    
    return 0;
}

int mostrar(){
    int i2 = 0; 
    for (aux = cab; aux != NULL; aux=aux->sig)
    {
        i2++;     
        cout<<i2<<". ID del producto: "<<aux->ID<<endl;
        cout<<". Nombre del producto: "<<aux->nombre<<endl;
        cout<<". Cantidades disponibles: "<<aux->cantidad<<endl;
        cout<<". Precio del producto (C/U): "<<aux->precio<<endl; 
        cout<<"-----------------------------------------------------"<<endl;    

    }
    return 0;
}

int eliminar(){

    int id = 0;

    if (cab != NULL)
    {

        borrar = cab;

        cout<<"Ingrese el ID del producto a eliminar: ";
        cin>>id;


        while (borrar != NULL && borrar->ID != id)
        {
            anterior = borrar;
            borrar = borrar->sig;
        } if (borrar == NULL) {

            cout<<"Producto no encontrado."<<endl;

        }else if (anterior == NULL) {

            cab = cab->sig;
            free(borrar);
            cout<<"Producto eliminado."<<endl;

        } else {

            anterior->sig = borrar->sig;
            free(borrar);
            cout<<"Producto eliminado."<<endl;
        }      
        
    }
    else
    {
        cout<<"Actualmente no hay productos."<<endl;
    }
        

    return 0;
}

int promedio(){

    int resultado = 0; //esta variable almacena el dinero total de los productos

    if (cab != NULL)
    {
        for (aux = cab; aux != NULL; aux=aux->sig){


            resultado = aux->cantidad * aux->precio;

            cout<<"EL VALOR DEL INVENTARIO ES DE: "<<resultado<<endl;
        }
    }
    else
    {
        cout<<"Actualmente no hay productos."<<endl;
    }
    

    return 0;
}

int buscar(){
    int busca;
    
        cout<<"Ingrese el ID del producto: ";
        cin>>busca;

        for (aux = cab; aux != NULL; aux=aux->sig){

            if (busca==aux->ID)
            {
            cout<<"Producto registrado"<<endl;
            cout<<"Producto en posicion: "<<aux->i+1<<endl;    
            cout<<"-----------------------"<<endl;
            cout<<"El producto encontrado es: "<<aux->nombre<<endl;
            cout<<"ID: "<<aux->ID<<endl;
            cout<<"Cantidades disponibles: "<<aux->cantidad<<endl;
            cout<<"Precio (C/U): "<<aux->precio<<endl;
            return 0;
            }
        }
                   
        cout<<"Actualmente no hay productos con ese ID."<<endl;
    
    return 0;
}

int venta(){

    int venta = 0;
    int opcion = 0;
    int cant = 0; //cantidad a vender

    if (cab != NULL)
    {  

        cout<<"Ingrese el ID del producto a vender: ";
        cin>>venta;

        if (venta == aux->ID)
        {
            mostrar();
        } else {

            cout<<"No hay productos con ese ID.";
        }
        


        for(aux=cab; aux!=NULL; aux = aux->sig){

            if(aux->ID==venta){

                cout<<"Ingrese la cantidad que desea vender: ";
                cin>>cant;

                if (cant <= aux->cantidad)
                {
                    cout<<"-------------------------------------"<<endl;
                    cout<<"Su venta ha sido realizada. "<<endl;
                    cout<<"-------------------------------------"<<endl;

                    cout<<"¿Desea ver la factura de los productos vendidos?"<<endl;
                    cout<<"";
                    cout<<"1.       SI"<<endl;
                    cout<<"2.       NO"<<endl;
                    cout<<"Opcion: ";
                    cin>>opcion;
                
                    switch (opcion) {

                    case 1:
                        if (aux ->cantidad >= cant) {

                        aux->cantidad = aux->cantidad - cant;
                        int resulta2=0;
                        resulta2 = aux->precio * cant;

                        cout<<"--------------------------------"<<endl;
                        cout<<"Nombre: "<<aux->nombre<<endl;
                        cout<<"ID: "<<aux->ID<<endl;
                        cout<<"Cantidades vendidas: "<<cant<<endl;
                        cout<<"Ganancias de la venta: "<<resulta2<<endl;

                        }
                        break;

                    case 2:
                        cout<<"RECIBIDO."<<endl;
                        break;    
                
                    default:
                        cout<<"Opcion invalida."<<endl;
                        break;
                    }
                }
                else
                {
                    cout<<"No hay esa cantidad disponible del producto."<<endl;
                }
                
            } else {

                cout<<"No hay productos con ese ID."<<endl;
            }
            
        }


    } else {

        cout<<"Actualmente no hay productos."<<endl;
    }

    return 0;
}

int ingresar(){

    int opcion = 0;

        cout<<""<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.       AGREGAR PRODUCTO."<<endl;
        cout<<"2.       MOSTRAR PRODUCTOS."<<endl;
        cout<<"3.       BUSCAR PRODUCTO."<<endl;
        cout<<"4.       ELIMINAR PRODUCTO."<<endl;
        cout<<"5.       VENDER PRODUCTO."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
    
        switch (opcion)
        {

        case 1:
            agregar();
                break;

        case 2: 
            mostrar();
                break;

        case 3: 
            buscar();
                break;
    
        case 4: 
            eliminar();
                break;

        case 5:
            venta();
                break;

        default:
            cout<<"";
            cout<<"Opcion invalida."<<endl;
            break;
        
    }

    return 0;
}



int main (){

    int opcion = 0;
    cout<<"";
    cout<<"Bienvenido, digite la opcion que desee realizar."<<endl;

    do
    {
        cout<<""<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"          MERCATODO          "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.       INGRESAR."<<endl;
        cout<<"2.       PROMEDIO DEL INVENTARIO."<<endl;
        cout<<"3.       SALIR."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        
        switch (opcion)
        {
        case 1:
            cout<<"";
            ingresar();
                break;

        case 2:
                promedio();
                break;

        case 3:
            cout<<"";
            cout<<"¡GRACIAS POR CONFIAR EN NOSOTROS! :D"<<endl;
            break;

        default:
            cout<<"";
            cout<<"Opcion invalida..."<<endl;
                break;
        }

    } while (opcion != 3);
}

//Autores:
//Ing, gamer y  ginecólogo en sus tiempos libres - Andres Fernando Fernandez.
//Ing, gamer y actor en sus tiempos libres - Luis David Cabezas.

//Akira Toriyama (1955-2024)