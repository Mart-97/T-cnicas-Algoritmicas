/// Descripción: Programa que realiza la inserción en una tabla hash y ordenamiento de secuencias de ADN con arboles binarios
///Programado por: Martin Javier Ayala Miranda
///Fecha de creación: 22de Marzo de 2016
///Fecha de última actualización: 22 de Marzo de 2016
#include <stdio.h>
#include <string.h>
#include <math.h>
typedef struct nodo{
    char cadena[80];
    int cantidad; /// Para contar cuantos han entrado a cada casilla
    bool existe;/// Para saber si ya hay arbol creado o no
    nodo *root; ///Apuntador que utilizo como raiz de cada rendija, a esa igualo  cada creacion en casilla vacía
    nodo *izq;
    nodo *der;
};
FILE *pFile,*out,*in; ///Los coloqué de manera global para que me permita usarlos en todo el programa
bool compare(nodo elem,nodo *raiz); ///Funcion que compara 2 cadenas de modo que se sepa cual es lexicograficamente menor a la otra
int Ord(char letra,int pos);///Función para elevar a las potencias
bool Inserta(nodo elem , nodo *raiz);///Inserción en un arbol binario
int H(char *cadena,int tablatam);///Función Hash
void EntreOrden(nodo *raiz);///Impresión con recorrido InOrden
nodo *CreaNodo(nodo elem);///Creación de nodos
int main(){
    int tabletam = 31;
    nodo elem, tabla[100];
    ///Inicializo en cero todos las cadenas
    for(int i = 0; i<tabletam; i++){
        for(int j = 0; j<80; j++){
            tabla[i].cadena[j] = 0;
            elem.cadena[i]=0;
        }
    }
    bool sepudo,abierto;
    int opcion;
    in = fopen ("Secuencia.txt","r");
    out = fopen("output.txt","w"); ///Ocupe esto para poder visualizar mejor la salida en un archivo
    ///por eso mis printf estan escritos así fprintf (archivo,tipo,nombredevariable)
    */
    do{
        printf("Escoja una opcion:\n 1.- Cargar Archivo \n 2.- Buscar por clave \n 3.- Imprimir todas las secuencias\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                if(!abierto){
                    while(fscanf(in,"%s",elem.cadena)!=EOF){
                        int key = H(&elem.cadena[0],tabletam);
                        elem.cantidad = key;
                        tabla[key].cantidad++;
                        if(tabla[key].existe==true){
                            sepudo = Inserta(elem,tabla[key].root);
                            if(!sepudo) printf("No se pudo Insertar el elemento\n");

                        }else{
                            if((tabla[key].root = CreaNodo(elem))==0) return 1;
                            tabla[key].existe = true;
                        }
                        ///Me aseguro de que todo quede en 0's de nuevo
                        for(int i = 0; i<tabletam; i++){
                            for(int j = 0; j<80; j++) tabla[i].cadena[j] = 0;
                            elem.cadena[i]=0;
                        }
                    }
                    abierto = true;
                } else printf("Ya abriste el archivo anteriormente, ya esta cargado\n");
                fclose(in);
            break;

            case 2:
                if(abierto){
                    int bucket;
                    printf("Ingrese un numero de casilla: ");
                    scanf("%d",&bucket);
                     if(tabla[bucket].existe){
                        fprintf(out,"El arbol en la posicion %d es:\n", bucket);
                        EntreOrden(tabla[bucket].root);
                     } else fprintf(out,"La clave no contiene elementos\n");
                }
            break;

            case 3:
                if(abierto){
                    for(int i = 0; i<31;i++){
                        fprintf(out,"%d\n",tabla[i].cantidad);
                        if(tabla[i].existe)
                            EntreOrden(tabla[i].root);
                    }
                }
            break;
        }
    }while(opcion > 0 && opcion <4);
     fclose(out);
    return 0;
}
void EntreOrden(nodo *raiz){
	if(raiz->izq != raiz){
		EntreOrden(raiz->izq);
	}
    fprintf(out,"%s\n",raiz->cadena);
	if(raiz->der!= raiz){
		EntreOrden(raiz->der);
	}
}
int Ord(char letra,int pos){
    if(letra == 'A') return pow(3,pos);
    if(letra == 'C') return pow(4,pos);
    if(letra == 'G') return pow(5,pos);
    if(letra == 'T') return pow(6,pos);
}
int H(char *cadena,int tablatam){
    int ans  = 0;
    for(int i = 0; i<4; i++){
        ans+= Ord(cadena[i],i);
    }
    return ans % tablatam;
}
nodo *CreaNodo(nodo nelem){
	nodo *nuevonodo = 0;
	if((nuevonodo = new nodo) == 0) return 0;
	*nuevonodo = nelem;
	nuevonodo->izq = nuevonodo;
	nuevonodo->der = nuevonodo;
	return nuevonodo;
}
bool compare(nodo elem,nodo *raiz){
    int i = 0;
    int telem = strlen(elem.cadena);
    int traiz = strlen(raiz->cadena);
    while(elem.cadena[i]== raiz->cadena[i]) {
        i++;
        if(i == telem - 1 || traiz - 1 == i ) {
            break;
        }
    }
    ///Se rompe el while hasta un elemento antes del final para poder verificar el ultimo caracter
    ///Y de ser iguales, comparo tamaños de cadenas para colocar en base a eso
    if(elem.cadena[i]==raiz->cadena[i]){
        if(telem > traiz) return true;
        else return false;
    }
    ///En caso de ser distintos se checa cual es la cadena lexicograficamente menor
    if(elem.cadena[i]-'A' > raiz->cadena[i]-'A') return true;
        else return false;
    }

bool Inserta(nodo elem , nodo *raiz){
    bool chooseSide = compare(elem,raiz);
	if(!chooseSide){
		if(raiz->izq != raiz){
			return Inserta(elem,raiz->izq);
		} else {
			nodo *ap = 0;
			if((ap = CreaNodo(elem)) == 0) return false;
			raiz->izq = ap;
			return true;
		}
	} else {

		if(raiz->der != raiz){
			return Inserta(elem,raiz->der);
		} else {
			nodo *ap = 0;
			if((ap = CreaNodo(elem))==0) return false;
			raiz->der = ap;
			return true;
		}
	}
}
