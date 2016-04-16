#include <stdio.h>
typedef struct puntoT{
	unsigned x;
	unsigned y;
	char color;
	puntoT *izq;
	puntoT *der;

};
puntoT *CreaNodo(puntoT elem);
bool Inserta(puntoT elem ,puntoT *raiz);
void EntreOrden(puntoT *raiz);
int main(){
puntoT *raiz;
bool res;
puntoT elem;
elem.x = 100;
if((raiz = CreaNodo(elem))==0) return 1;

elem.x = 25;
res = Inserta(elem,raiz);
elem.x = 312;
res = Inserta(elem,raiz);
elem.x = 100;
res = Inserta(elem,raiz);

EntreOrden(raiz);

	return 0;
}

puntoT *CreaNodo(puntoT nelem){
	puntoT *nuevonodo = 0;
	if((nuevonodo = new puntoT) == 0) return 0;
	*nuevonodo = nelem;
	nuevonodo->izq = nuevonodo;
	nuevonodo->der = nuevonodo;
	return nuevonodo;

}

void EntreOrden(puntoT *raiz){
	if(raiz->izq != raiz){
		EntreOrden(raiz->izq);
	}
	printf("%u ",raiz->x);

	if(raiz->der!= raiz){
		EntreOrden(raiz->der);
	}
}

bool Inserta(puntoT elem , puntoT *raiz){
    printf("inserta\n");
	if(raiz->x > elem.x){
		if(raiz->izq != raiz){
			return Inserta(elem,raiz->izq);
		} else {
			puntoT *ap = 0;
			if((ap = CreaNodo(elem)) == 0) return false;

			raiz->izq = ap;
			return true;
		}
	} else {

		if(raiz->der != raiz){
			return Inserta(elem,raiz->der);
		} else {
			puntoT *ap = 0;
			if((ap = CreaNodo(elem))==0) return false;

			raiz->der = ap;
			return true;
		}
	}
}
