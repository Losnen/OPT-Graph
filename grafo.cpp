#include "grafo.h"



GRAFO::GRAFO(char nombrefichero[], int &errorapertura)
{

ifstream grafo(nombrefichero);

    if (grafo.fail())
    {
     errorapertura = 1;
    }

    else {

        grafo >> n;
        grafo >> m;
        grafo >> dirigido;

        unsigned nodo = 0;
        LS.resize(n);
        ElementoLista dummy;
        if (dirigido == 1)
        {
            while(!grafo.eof())
            {
                grafo >> nodo;
                if (!grafo.eof())
                {
                    grafo >> dummy.j;
                    grafo >> dummy.c;
		    LS[nodo-1].push_back(dummy); 
		    	     

                }
            }
        errorapertura = 0;
        ListaPredecesores();
        }

        if (dirigido == 0)
        {
            while (!grafo.eof())
            {
                grafo >> nodo;
                if (!grafo.eof())
                {
                    grafo >> dummy.j;
                    LS[nodo-1].push_back(dummy);
		   
                }
            }

            int size[n];
            for (int k= 0; k<n;k++)
            size[k]=LS[k].size();
            for (int k=0;k<n;k++)
            for(int i=0;i<size[k];i++)
            if(LS[k][i].j != k+1)
            {
                dummy.j = k+1;
                LS[(LS[k][i].j)-1].push_back(dummy);
            }
        }
    }
}





GRAFO::~GRAFO(void)
{
    n = 0;
    m = 0;
    LS.clear();
    LP.clear();
}






void GRAFO::actualizar(char nombrefichero[], int &errorapertura)
{

    n = 0;
    m = 0;
    LS.clear();
    LP.clear();

  


     ifstream grafo(nombrefichero);

     if (grafo.fail())
     {
        cout << "Error al tratar de abrir el grafo" << endl;
        errorapertura = 1;
     }

     else
     {
        grafo >> n;
        grafo >> m;
        grafo >> dirigido;

        unsigned nodo = 0;
        LS.resize(n);
        ElementoLista dummy;
        if (dirigido == 1)
        {
            while(!grafo.eof())
            {
                grafo >> nodo;
                if (!grafo.eof())
                {
                    grafo >> dummy.j;
                    grafo >> dummy.c;
		    LS[nodo-1].push_back(dummy);

                   
                }
            }
        errorapertura = 0;
        ListaPredecesores();
        }

        if (dirigido == 0)
        {
            while (!grafo.eof())
            {
                grafo >> nodo;
                if (!grafo.eof())
                {
                    grafo >> dummy.j;
                    LS[nodo-1].push_back(dummy);
                }
            }

            int size[n];
            for (int k= 0; k<n;k++)
            size[k]=LS[k].size();
            for (int k=0;k<n;k++)
            for(int i=0;i<size[k];i++)
            if(LS[k][i].j != k+1)
            {
                dummy.j = k+1;
                LS[(LS[k][i].j)-1].push_back(dummy);
            }
        }
    }

}





void GRAFO::ListaPredecesores()
{
    LP.resize(n);
    ElementoLista dummy;
    if (dirigido == 1)
    {
        for(int k = 0; k<n; k++)
        {
            for (int i= 0; i<LS[k].size(); i++)
            {
                dummy.j = k+1;
		dummy.c = LS[k][i].c;
                LP[(LS[k][i].j)-1].push_back(dummy);
            }
        }
    }

}




void GRAFO::Info_Grafo(){

    cout << "Número de nodos: " << n << endl;
    cout << "Número de Aristas: " << m << endl;
    if(dirigido == 1)
    cout << "Grafo dirigido" << endl;
    else
    cout << "Grafo no dirigido" << endl;
    cout << endl;

}




void GRAFO::Mostrar_Listas(int l)
{
    if ( l == 1)
    {
        for (int k = 0 ; k<n; k++)
        {
            cout << "Nodo " << k+1 << ": ";
            for(int i = 0; i<LS[k].size();i++)
            {
             cout << LS[k][i].j <<" ";
	     cout << " : ";
             cout << LS[k][i].c <<" ";
	     cout << " | ";
	     
            }
            cout << endl;
        }
        

    }

    if (l == 2)
    {
        for (int k = 0 ; k<n; k++)
        {
            cout <<"  " << "Nodo: " << k+1 << ": ";
            for(int i = 0; i<LP[k].size();i++)
            {
               cout << LP[k][i].j <<" ";
	       cout << " : ";
	       cout << LP[k][i].c <<" ";
	       cout << " | ";
            }
            cout << endl;
        }
        


    }

}


void GRAFO::dfs(unsigned i, vector<bool> &visitado)
{
    visitado[i] = true;
    cout << i+1 << ", ";
    for (unsigned j=0;j<LS[i].size();j++)
    if (visitado[LS[i][j].j-1] == false)
    dfs(LS[i][j].j-1, visitado);
}

void GRAFO::ComponentesConexas(void){
  unsigned i; 
  unsigned cc = 0;
  vector<bool> visitado;
  visitado.resize (n);
   
  for(i=0; i<n; i++)
    visitado[i]=false;
    
  for(i=0; i<n; i++) {
         if (visitado[i] == false) {
          cc++;
          cout << "Componente Conexa " << cc << " { " ;
          dfs (i, visitado);
	  cout << "}" << endl;
      }
      
   }
}


void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred) 
{ 
 if (i != s) 
 { 
 MostrarCamino(s,pred[i],pred); 
 cout << pred[i]+1 << " -> "; 
 } 
} 


void GRAFO::Dijkstra(){
  
	  vector<bool> PermanentementeEtiquetado;
	  vector<int> d;
	  vector<unsigned> pred;
	  int min;
	  unsigned s, candidato;
	  //Inicialmente no hay ningun nodo permanentemente etiquetado
	  PermanentementeEtiquetado.resize(n,false);
	  //Inicialmente todas las etiquetas distancias son infinito
	  d.resize(n,maxint);
	  //Inicialmente el pred es null
	  pred.resize(n,UERROR);
	  //Solicitamos al usuario nodo origen
	  cout << endl;
	  cout << "Caminos minimos: Dijkstra" << endl;
	  cout << "Nodo de partida? [1-"<< n << "]: ";
	  cin >> (unsigned &) s;
	  //La etiqueta distancia del nodo origen es 0, y es su propio pred
	  d[--s]=0; pred[s]=s;
	  do
	  {
	    
	    
			candidato = UERROR;
	min = maxint;

	for(int i=0; i < n; i++) {

               if (PermanentementeEtiquetado[i] == false && d[i] < min){ // La etiqueta permanente es falsa.

		    		 candidato = i;

                     min = d[i];

                      //Candidato coge el valor de i y se sale del bucle
               }
       }



	  if (candidato !=UERROR) {

		PermanentementeEtiquetado[candidato] = true;

        	for (int k = 0; k < LS[candidato].size(); k++) { //Recorremos los sucesores.

			  

            		if (( d[LS[candidato][k].j-1]) > (d[candidato] + LS[candidato][k].c)) {   //Si la distancia de los sucesores, es mayor que la distancia del candidato más el coste.

				if(PermanentementeEtiquetado[LS[candidato][k].j-1]==false){
				   d[LS[candidato][k].j-1] = (d[candidato] + LS[candidato][k].c); //Sustituimos la nueva distancia por el valor que nos dio la suma anterior.
				   pred[LS[candidato][k].j-1] = candidato; //El predecesor es el nuevo candidato.
            		
				}
				}
        	 }
       }

	  }
	  while (min < maxint);
	  cout << "Soluciones:" << endl;
	  //En esta parte del código, mostramos los caminos mínimos, si los hay
	  
	   for (int i = 0; i < n; i++) {

	     if (i != s){

	        if(PermanentementeEtiquetado[i] == true) {

               cout << "El camino  " << s + 1 << " a " << i +1 << " es: ";
			   MostrarCamino(s,i,pred);

			   cout << i + 1 << " con coste " << d[i] << endl;

            }

            else

               cout <<"No hay camino desde: " << s + 1 <<" a " << i + 1 <<endl;

            }
	}

}


void GRAFO::BellmanFordMoore(){
  
      vector<int> d;
      vector<unsigned> pred;
      unsigned s, numeromejoras = 0;
      bool mejora;
      //Idem que en el algoritmo de Dijkstra
      d.resize(n,maxint);
      pred.resize(n,UERROR);
      cout << endl;
      cout << "Caminos minimos: Bellman – Ford - Moore" << endl;
      cout << "Nodo de partida? [1-"<< n << "]: ";
      cin >> (unsigned &) s;
      d[--s]=0; pred[s]=s;
      mejora = false;
      
      do{
	
	 

       for (unsigned i = 0; i < n; i++) {

          for (unsigned k = 0; k < LS[i].size(); k++) { //Recorremos los sucesores.

            if (( d[LS[i][k].j]-1) > (d[i] + LS[i][k].c)) {   //Si la distancia de los sucesores, es mayor que la distancia del candidato mas el coste.
	       d[LS[i][k].j-1] = (d[i] + LS[i][k].c); //Sustituimos la nueva distancia por el valor que nos dio la suma anterior.
               pred[LS[i][k].j-1] = i; //El predecesor es el nuevo candidato.


            }

		numeromejoras++;

        mejora = true;

         }

       }
	    
	
      }	    while ((numeromejoras < n) && (mejora == true));
      
      
      
	    if (numeromejoras > n)

      		  cout << "Nos encontramos ante un ciclo negativo" << endl;

 		 else {

	 	    cout << "SOLUCIONES:" << endl;

		    
     			 for (unsigned i = 0; i < n; i++){

 			     //Mostrar los caminos posibles.

	     			if (i!=s) {

		    			if (pred[i]!= UERROR){

              				 cout << "El camino  " << s+ 1 << " a " << i +1 << " es: ";

	         			  MostrarCamino(s,i,pred);

					  cout << i + 1 << " con coste " << d[i] << endl;

            				}  else


           				   cout <<"No hay camino desde: " << s + 1 <<" a " << i + 1 <<endl;
        			}
			}
   		}
}


	      
	    
  
  
  
  
  
  


