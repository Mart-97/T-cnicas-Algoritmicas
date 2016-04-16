#include <stdio.h>
typedef struct{
	int sizee;
	int *elemarray;
	int  frontt;
	int endd;
}QueueInt;

bool IsEmpty(QueueInt s);
bool isFull(QueueInt s);
bool InQueue(QueueInt *s, int elem);
bool dQueue(QueueInt *s,int *elem);
void imprime(QueueInt *cola1,QueueInt *cola2,QueueInt *cola3);
QueueInt *CrearQueue(int t);

int main(){
    QueueInt *cola,*cola2,*cola3;
    int elemento;
    bool res;
    InQueue(q1,1); InQueue(q1,2); InQueue(q1,3); InQueue(q1,4); InQueue(q1,5); InQueue(q1,6); InQueue(q1,7);
    InQueue(q2,-2); InQueue(q2,-1); InQueue(q2,0);
    InQueue(q3,8); InQueue(q3,9); InQueue(q3,10); InQueue(q3,11); InQueue(q3,12); InQueue(q3,13);

   do
  {
      printf("Presione 1 Quitar elemento de la Pila 1 , 2 para la 2, y 3 para la  3 :  ");
        scanf("%d",&opcion);
    switch(opcion){
            case 1:
                 dQueue(st1,&elemento);
                 printf("Ingrese el numero de la pila a la que quiere insertar 2 o 3: ");
                    scanf("%d",&op2);
                switch(op2){
                    case 2:
                      if(!InQueue(st2,elemento)) {
                        st1->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                    case 3:
                      if(!InQueue(st3,elemento)) {
                        st1->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                }
            break;

                case 2:
                  dQueue(st2,&elemento);
                 printf("Ingrese el numero de la pila a la que quiere insertar 1 o 3: ");
                    scanf("%d",&op2);
                switch(op2){
                    case 1:
                      if(!InQueue(st1,elemento)) {
                        st2->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                    case 3:
                      if(!InQueue(st3,elemento)) {
                        st2->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                }
                break;
                    case 3:
                        dQueue(st3,&elemento);
                 printf("Ingrese el numero de la pila a la que quiere insertar 1 o 2: ");
                    scanf("%d",&op2);
                switch(op2){
                    case 1:
                      if(!InQueue(st1,elemento)) {
                        st3->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                    case 2:
                      if(!InQueue(st2,elemento)) {
                        st3->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                }
                break;

    }
    ShowStack(st1,st2,st3);
    printf("\n");
  }while(opcion > 0 && opcion < 4);

	return 0;
}

QueueInt *CrearQueue(int t){
 QueueInt *pointer = 0;
    pointer = new QueueInt;
    pointer -> elemarray = new int[t];
    pointer->frontt = -1;
    pointer->sizee = t;
    pointer->endd  = -1;
 return pointer;
}

bool IsEmpty(QueueInt s){
    if(s.frontt  < 0 && s.endd < 0 ) return true;
    return false;
}

bool isFull(QueueInt s){
    if((s.endd + 1) % s.sizee == s.frontt) return true;
    return false;
}

bool InQueue(QueueInt *s, int elem){
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
          ///printf("%d %d\n",s->frontt,s->endd);
    return true;
}

bool dQueue(QueueInt *s,int *elem){
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

void ShowStack(QueueInt *q1,QueueInt *q2, QueueInt *q3){
int opc;
    printf("Presione 1 2 o 3 para mostrar la cola correspondiente o 4 para mostrar todas: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                if(q1->top > -1) {
                printf("La cola 1 esta asi: \n");
                    for(int i = 0; i<=q1->top; i++){
                        printf("%d ",q1->elemarray[i]);
                        }
                printf("\n");
            } else puts("\nLa cola 1 esta vacia\n");
            break;

            case 2:
               if(q2->top > -1 ) {
        printf("La cola 2 esta asi: \n");
            for(int i = 0; i<=q2->top; i++){
                printf("%d ",q2->elemarray[i]);
                }
                printf("\n");
            } else  puts("\nLa cola 2 esta vacia\n");
            break;

            case 3:
                if(q3->top > -1 ) {
            printf("La cola 3 esta asi: \n");
                for(int i = 0; i<=q3->top; i++){
                    printf("%d ",q3->elemarray[i]);
                    }
                printf("\n");
                }else  puts("\nLa cola 3 esta vacia\n");
            break;
            default:
              imprime(que1,que2,que3);
            break;
        }
}
