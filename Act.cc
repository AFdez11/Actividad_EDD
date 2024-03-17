#include <iostream>
#include <malloc.h>
#include <String>

using namespace std;

struct productos
{
    int ID; //aquí almacenaremos el id del producto
    float precio;
    string nombre;
    char cantidad;

    productos *sig;

};

productos *cab, *aux, *aux2;

int agregar(){

    if (cab == NULL)
    {
        cab = (struct productos *) malloc (sizeof(struct productos));

        cout<<"Ingrese el nombre del producto: ";
        getline(cin, cab -> nombre);

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
        getline(cin, aux ->nombre);

        cout<<"Ingrese el ID del producto: ";
        cin >> aux -> ID;

        cout<<"Ingrese la cantidad del producto: ";
        cin >> aux-> cantidad;

        cout<<"Ingrese el precio del producto: ";
        cin>> aux -> precio;

        aux ->sig = NULL;

        while (aux2 != NULL )
        {
            aux2 = aux2 ->sig;
            aux2 ->sig = aux;
            aux2 = aux = NULL;
            free(aux);
            free(aux2);
        }

        cab -> sig = NULL;
        aux = NULL;
        free(aux);    
    }
    
    return 0;
}

int mostrar(){
    int i = 0; 
    for (aux = cab; aux != NULL; aux=aux->sig)
    {
        i++;     
        cout<<i<<". ID del producto: "<<aux->ID<<endl;
        cout<<". Nombre del producto: "<<aux->nombre<<endl;
        cout<<". Cantidades disponibles: "<<aux->cantidad<<endl;
        cout<<". Precio del producto: "<<aux->precio<<endl;     

    }
    return 0;
}

int buscar(){
    int busca;

    cout<<"Ingrese el ID del producto: "<<endl;
    cin>>busca;

    for(aux=cab; aux!=NULL; aux = aux->sig){
        if(aux->ID==busca){
            cout<<"Nombre: "<<aux->nombre<<endl;
            cout<<"Cantidades disponibles: "<<aux->cantidad<<endl;
            cout<<"Precio del producto: "<<aux->precio<<endl;
            
        }
    }


    return 0;
}

int eliminar(){

    return 0;
}

int administrador(){

    int opcion = 0;

        cout<<"";
        cout<<"-----------------------------"<<endl;
        cout<<"             MENU            "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.       AGREGAR PRODUCTO."<<endl;
        cout<<"2.       ELIMINAR PRODUCTO."<<endl;
        cout<<"3.       SALIR"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

    switch (opcion)
    {
    case 1:

        agregar();
        break;

    case 2: 

        eliminar();
        break;
    case 3:
        cout<<"¡GRACIAS POR CONFIAR EN NOSOTROS! :D";
        break; 

    default:
        cout<<"Opcion inválida.";
        break;
    }

    return 0;
}

int usuario(){

    int opcion;

        cout<<"";
        cout<<"-----------------------------"<<endl;
        cout<<"             MENU            "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.       AGREGAR PRODUCTO."<<endl;
        cout<<"2.       MOSTRAR PRODUCTOS."<<endl;
        cout<<"3.       BUSCAR PRODUCTO."<<endl;
        cout<<"4.       ELIMINAR PRODUCTO."<<endl;
        cout<<"5.       SALIR."<<endl;
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
        cout<<"¡GRACIAS POR CONFIAR EN NOSOTROS! :D";
        break; 

    default:
        cout<<"Opcion inválida.";
        break;
    }

}

int main (){

    int opcion = 0;
    cout<<"";
    cout<<"Bienvenido a Mercatodo."<<endl;

    do
    {
        cout<<"";
        cout<<"-----------------------------"<<endl;
        cout<<"             MENU            "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.       ADMINISTRADOR."<<endl;
        cout<<"2.       USUARIO."<<endl;
        cout<<"3.       SALIR."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        
        switch (opcion)
        {
        case 1:
            administrador();
                break;

        case 2:
            usuario();
                break;

        case 3: 
            cout<<"¡GRACIAS POR CONFIAR EN NOSOTROS! :D"<<endl;
                break;

        default:
            cout<<"opcion invalida..."<<endl;
                break;
        }

    } while (opcion != 3);
    return 0;
}

