#include <iostream>
#include <malloc.h>

using namespace std;

struct paciente
{
    char nombre [30];
    char apellido [30];
    char documento [20];
    int i;// este es un iterador el cual nos facilitará el almacenamiento de los pacientes que van despues de la cabeza.

    paciente *sig;

};

paciente *cab, *aux, *aux2;

int agregar (){

    if (cab == NULL)
    {
        cab = (struct paciente *) malloc (sizeof(struct paciente));

        cout<<"Ingrese el primer nombre del pacienteee: ";
        cin>> cab -> nombre;

        cout<<"Ingrese el primer apellido del paciente: ";
        cin>> cab -> apellido;

        cout<<"Ingrese el documento de identidad del paciente: ";
        cin>> cab -> documento;


        cab ->sig = NULL;

        if (cab == NULL)
        {
            cab = aux;
            cab ->i = 1;
            aux = NULL;

            free (aux);
        }
        return 0;

    } else {

        aux = (struct paciente *) malloc (sizeof(struct paciente));

        cout<<"Ingrese el primer nombre del paciente: ";
        cin>> aux -> nombre;

        cout<<"Ingrese el primer apellido del paciente: ";
        cin>> aux -> apellido;

        cout<<"Ingrese el documento de identidad del paciente: ";
        cin>> aux -> documento;

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
    
    
    
    return 0;
}

int mostrar (){

int i2 = 0; // este iterador nos permitirá saber el número del paciente en la fila.
    for (aux = cab; aux != NULL; aux=aux->sig)
    {
        
        i2++;
        cout<<i2<<". El paciente: "<<aux->nombre<<endl;
        cout<<"Con apellido: "<<aux->apellido<<endl;
        cout<<"Identificado con documento: "<<aux->documento<<endl;     
        
    }

    return 0;
}

int main (){

    int opcion = 0;

        cout<<"";
        cout<<"Bienvenidos a 'EPS promedio de Colombia' "<<endl;
    do
    {


        cout<<"";
        cout<<"-----------------------------"<<endl;
        cout<<"             Menu            "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1.       agregar paciente."<<endl;
        cout<<"2.       Ver pacientes."<<endl;
        cout<<"3.       Salir."<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion)

        {
        case 1:

            agregar();
            cout<<"";
            cout<<"*******************************"<<endl;
            cout<<"El paciente ha sido registrado."<<endl;
            cout<<"*******************************"<<endl;
                break;   
        case 2: 

            if (cab != NULL)
            {
                cout<<"La lista de pacientes es la siguiente: "<<endl;
                mostrar();
            } else {

                cout<<"No hay pacientes registrados, por el momento."<<endl;
            }
            
            
                break;
        case 3: 

            cout<<"Gracias por confiar en nosotros."<<endl;
                break;

        default:

            cout<<"opcion invalida."<<endl;
                break;
        }

    } while (opcion != 3);

    return 0;
}

//Integrates: 
// *Cabezas Pinillo Luis.
// *Andres Fernando Fernandez.


//Q.E.P.D: Akira Toriyama