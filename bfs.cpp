#include <stdio.h>

typedef struct{
	int sizee;
	int *elemarray;
	int frontt;
	int endd;
}cola;
typedef struct{
	int sizee;
	int *elemarray;
	int  top;
}pila;
typedef struct{
	bool **matriz;
	int *padres;
	int *niveles; 
	int *color; ///El código de colores es 0 = White, 1= Gray, 2 =  Black
	int nvertices;
}grafo;
grafo g;
pila *CrearStack(int t);
bool IsEmptyy(pila s);
bool isFull(pila s);
bool Push(pila *s, int elem);
bool Pop(pila *s,int *elem);
bool IsEmpty(cola s);
bool isFull(cola s);
bool InQueue(cola *s, int elem);
bool dQueue(cola *s,int *elem);
cola *CrearQueue(int t);
bool bfs(grafo *g, int origen , int destino,cola *q);

int main(){
	int origen,destino;
	FILE *in;
	in = fopen("input.txt","r");
	cola *s;
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
	g.color = 0;
	g.color = new int[v + 1];
	g.niveles = 0;
	g.niveles = new int[v + 1];
	s = CrearQueue(v);
	st = CrearStack(v);
	bool res;
	res = bfs(&g,origen,destino,s);
	printf("\n");
	///Si se pudo llegar, se reconstruye el camino
	if(res){
		int p = destino;
		///Insertamos los padres a la pila para reconstruir el camino
		while(p!=-1){
			Push(st,p);
			p = g.padres[p];
		}
		///La distancia del destino respecto al origen y el camino correspondiente
		printf("La distancia es: %d\n",g.niveles[destino]);
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
bool bfs(grafo *g,int origen, int destino,cola *q){
	///Inicializacion de los arreglos a usar en la BFS
	for(int i = 1; i<=g->nvertices; i++){
		g->color[i] = 0;
		g->padres[i] =  -1;
		g->niveles[i] = -1;
	}
	g->color[origen] = 1;
	g->niveles[origen] = 0;
	g->padres[origen] = -1;
	InQueue(q,origen);
	int actual;
	///BFS
	while(!IsEmpty(*(q))){
		dQueue(q,&actual);
		///Verifico si el elemento fue encontrado
		if(actual == destino) return true;
		for(int j = 1; j<=g->nvertices; j++){
			if(g->matriz[actual][j]==1 && g->color[j]==0){
				g->color[j] = 1;
				g->niveles[j] = g->niveles[actual] + 1;
				g->padres[j] = actual;
				InQueue(q,j);
			}
		}
		g->color[actual] = 2;
	}
	return false;
}
cola *CrearQueue(int t){
 cola *pointer = 0;
    pointer = new cola;
    pointer->frontt = -1;
    pointer->sizee = t;
    pointer->endd  = -1;
 return pointer;
}

bool IsEmpty(cola s){
    if(s.frontt  < 0 && s.endd < 0 ) return true;
    return false;
}

bool isFull(cola s){
    if((s.endd + 1) % s.sizee == s.frontt) return true;
    return false;
}

bool InQueue(cola *s, int elem){
    if(isFull(*(s))) {
          return false;
    }else if(s->frontt < 0 && s->endd < 0){
            s->frontt++;
            s->endd++;
             s->elemarray[s->endd] = elem;
          } else {
            s->endd = (s->endd + 1) % s->sizee;
              s->elemarray[s->endd] = elem;
          }
    return true;
}

bool dQueue(cola *s,int *elem){
    if(s->frontt<0 && s->endd < 0 ) return false;
    if(s->endd == s->frontt){
        *elem = s->elemarray[s->frontt];
        s->endd = -1;
        s->frontt = -1;
        return true;
    } else {
            *elem = s->elemarray[s->frontt];
         s->frontt = s->frontt + 1 % s->sizee;
    }
    return true;
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
