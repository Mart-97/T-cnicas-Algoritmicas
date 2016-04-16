///PROGRAMADO POR MARTIN JAVIER AYALA MIRANDA
///Programa que realiza el algoritmo de ruta más corta(DIJKSTRA)
///ENTREGA: 15/04/2016
#include <stdio.h>
#define INF 1000000 /// EL VALOR CONSIDERADO COMO INFINITO

typedef struct{
	int sizee;
	int *elemarray;
	int  top;
}pila;
typedef struct{
	bool **matriz;
	int *padres;
	int *dist; 
	int *visitado; ///El código de colores es 0 = no visitado, 1=visitado
	int nvertices;
}grafo;

grafo g;
pila *CrearStack(int t);
bool IsEmptyy(pila s);
bool isFull(pila s);
bool Push(pila *s, int elem);
bool Pop(pila *s,int *elem);
void dijkstra(grafo *g, int origen , int destino);

int main(){
	int origen,destino;
	FILE *in;
	in = fopen("input.txt","r");
	pila *st;
	///Lectura de cantidad de nodos;
	fscanf(in,"%d",&g.nvertices);
	int v = g.nvertices;
	g.matriz = 0;
	g.matriz = new bool *[v + 1];
	for(int i = 1; i<=v; i++){
		g.matriz[i] = new bool [v + 1];
	}
	///Lectura de la matriz
	for(int i = 1; i<=v; i++){
		for(int j = 1; j<=v; j++){
			fscanf(in,"%d",&g.matriz[i][j]);
		}
	}
	///Nodo origen y nodo destino
	fscanf(in,"%d%d",&origen,&destino);
	g.padres = 0;
	g.padres = new int[v + 1];
	g.visitado = 0;
	g.visitado = new int[v + 1];
	g.dist = 0;
	g.dist = new int[v + 1];
	st = CrearStack(v);
	bool res;
	dijkstra(&g,origen,destino);
	printf("\n");
	///Si se pudo llegar, se reconstruye el camino
	if(g.dist[destino] != INF) {
	for(int i = 1; i<=g.nvertices; i++) printf("%d %d\n",g.dist[i], i);
	///if(res){
		int p = destino;
		///Insertamos los padres a la pila para reconstruir el camino
		while(p!=-1){
			Push(st,p);
			p = g.padres[p];
		}
		///La distancia del destino respecto al origen y el camino correspondiente
		printf("La distancia minima del origen al destino es: %d\n",g.dist[destino]);
		printf("El camino a seguir es: ");
		while(!IsEmptyy(*(st))){
			Pop(st,&p);
			printf("%d ",p);
		}
	} else {
		printf("No se puede llegar al destino\n");
	}

	fclose(in);
	return 0;
}
void dijkstra(grafo *g,int origen, int destino){
	///Inicializacion de los arreglos a usar en la dijkstra
	for(int i = 1; i<=g->nvertices; i++){
		g->visitado[i] = 0;
		g->padres[i] =  -1;
		g->dist[i] = INF;
	}
	g->dist[origen] = 0;
	g->padres[origen] = -1;	
	///dijkstra
	while(true){
		int best = INF;
		///Se buscan las distancias de menor peso
		for(int i = 1; i<=g->nvertices; i++){
			if(g->dist[i] < best && g->visitado[i]==0) best = i;
		}
		///Verifico si siguen habiendo elementos sin visitar, sino rompo el ciclo
		if(best == INF ) break;
 		for(int j = 1; j<=g->nvertices; j++){
			if(g->matriz[best][j] > 0 ){
				///Se hace la comparación de lo que hay en el nodo adyacente, para ver si
				/// tenemos un camino aun mas corto que el que tiene actualmente		
				if(g->dist[j] > g->dist[best] + g->matriz[best][j]){
					///Actualización de distancias
					g->dist[j] = g->dist[best] + g->matriz[best][j];
					g->padres[j] = best;
				}	
			}
		}
		g->visitado[best] = 1;
	}
	return;
}
pila *CrearStack(int t){
	pila *pointer = 0;
    pointer = new pila;
    pointer -> elemarray = new int [t];
    pointer->top = -1;
    pointer->sizee = t;
 return pointer;
}

bool IsEmptyy(pila s){
    if(s.top < 0 ) return true;
    return false;
}

bool isFull(pila s){
    if(s.top >=s.sizee - 1) return true;
    return false;
}

bool Push(pila *s, int elem){
    if(isFull(*(s)))  return false;
    s->elemarray[++s->top] = elem;
    return true;
}

bool Pop(pila *s,int *elem){
    if(s->top < 0 ) return false;
    *elem = s->elemarray[s->top--];
    return true;
}
