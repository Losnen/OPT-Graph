#include "grafo.h"



int main(){
  
 char letra;
 char nombre[50];
 int error=0;
 
 
 cout<<"introduce el nombre del fichero en el que se encuentra el grafo"<<endl;
 cin>>nombre;


GRAFO A(nombre,error);

if(error==1){
    cout << "Error en la apertura del fichero" <<endl;
    return 0;
}


do{ 
 switch(A.dirigido){
   case 0:
      cout<<"c. [c]argar grafo desde fichero"<<endl;
      cout<<"i. Mostrar [i]nformacion basica del grafo"<<endl;
      cout<<"a. Mostrar la lista de [a]dyacencia del grafo"<<endl;
      cout<<"l. [l]ista de componentes del grafo"<<endl;
      cout<<"q. Finalizar el programa"<<endl;
      cout<<"Introduce la letra de la accion a ejecutar: ";
      cin>>letra;
   
      switch(letra){
	case 'c':
	  cout<<"introduce el nombre del fichero en el que se encuentra el grafo"<<endl;
	  cin>>nombre;
	  A.actualizar(nombre, error);
                
		  if(error=0)
		    cout<<"Fichero cargado"<<endl;
		  else
                    cout << "Error en la apertura del fichero" <<endl;
		  
	  break;
	case 'i':  A.Info_Grafo(); break;
	case 'a':  A.Mostrar_Listas(1); break;
	case 'l': A.ComponentesConexas(); break;
        case 'q': exit(0); break;	
      }
      
 break;
   case 1:
      cout<<"c. [c]argar grafo desde fichero"<<endl;
      cout<<"i. Mostrar [i]nformacion basica del grafo"<<endl;
      cout<<"s. Mostrar la lista de [s]ucesores del grafo"<<endl;
      cout<<"p. Mostrar la lista de [p]redecesores del grafo"<<endl;
      cout<<"d. Caminos mínimos: Dijstra" <<endl;
      cout<<"b. Caminos mínimos: Bellman-Ford-Moore"<<endl;
      cout<<"q. Finalizar el programa"<<endl;
      cout<<"Introduce la letra de la accion a ejecutar:";
      cin>>letra;
   
      switch(letra){
	case 'c':
	  cout<<"introduce el nombre del fichero en el que se encuentra el grafo"<<endl;
	  cin>>nombre;
	  A.actualizar(nombre, error);
                if(error==0)
		    cout<<"Fichero cargado"<<endl;
		 else
                    cout << "Error en la apertura del fichero" <<endl;
	break;
	case 'i': A.Info_Grafo(); break;
	case 's': A.Mostrar_Listas(1); break;
	case 'p': A.Mostrar_Listas(2); break;
	case 'd': A.Dijkstra();         break;
	case 'b': A.BellmanFordMoore(); break;
	case 'q': exit(0); break;
      }
  break; 
 }
}while(letra!='q');

A.~GRAFO();

 return 0;
 
}
  
