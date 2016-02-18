#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const unsigned UERROR = 65000;
const int maxint = 1000000;


typedef struct 
{ 
 unsigned j; // nodo 
 int c; // atributo para expresar su peso, longitud, coste� 
} ElementoLista; 

typedef vector<ElementoLista> LA_nodo; 

class GRAFO 
 { 
	private:
		unsigned n; // n�mero de nodos o v�rtices 
		unsigned m; // n�mero de arcos o aristas 
		vector<LA_nodo> LS; // lista de sucesores o de adyacencia
		vector<LA_nodo> LP; // lista de predecesores 
	public: 
		unsigned dirigido; //0 si el grafo es no dirigido,1 si es dirigido 
		GRAFO(char nombrefichero[], int &errorapertura); 
		void actualizar (char nombrefichero[], int &errorapertura); 
		void Info_Grafo(); 
		void Mostrar_Listas(int l); 
		void ListaPredecesores();
		void dfs(unsigned i, vector<bool> &visitado);
		void ComponentesConexas(void); 
		void MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred);
		void Dijkstra(void);
		void BellmanFordMoore(void);
		~GRAFO();
		};
