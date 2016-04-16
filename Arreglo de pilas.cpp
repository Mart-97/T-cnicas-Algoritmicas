#include <stdio.h>
typedef struct{
	int sizee;
	int *elemarray;
	int  top;
}StackInt;

StackInt *CrearStack(int t);
bool IsEmpty(StackInt s);
bool isFull(StackInt s);
bool Push(StackInt *s, int elem);
bool Pop(StackInt *s,int *elem);
void imprime(StackInt *pila1,StackInt *pila2,StackInt *pila3);
void ShowStack(StackInt *p1,StackInt *p2, StackInt *p3);
int main(){
	int  tam,elemento,opcion,op2;
	StackInt *st1,*st2,*st3;
	st1 = CrearStack(10);
    st2 = CrearStack(6);
    st3 = CrearStack(10);
    Push(st1,1); Push(st1,2); Push(st1,3); Push(st1,4); Push(st1,5); Push(st1,6); Push(st1,7);
    Push(st2,-2); Push(st2,-1); Push(st2,0);
    Push(st3,8); Push(st3,9); Push(st3,10); Push(st3,11); Push(st3,12); Push(st3,13);
  do
  {
      printf("Presione 1 Quitar elemento de la Pila 1 , 2 para la 2, y 3 para la  3 :  ");
        scanf("%d",&opcion);
    switch(opcion){
            case 1:
                 Pop(st1,&elemento);
                 printf("Ingrese el numero de la pila a la que quiere insertar 2 o 3: ");
                    scanf("%d",&op2);
                switch(op2){
                    case 2:
                      if(!Push(st2,elemento)) {
                        st1->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                    case 3:
                      if(!Push(st3,elemento)) {
                        st1->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                }
            break;

                case 2:
                  Pop(st2,&elemento);
                 printf("Ingrese el numero de la pila a la que quiere insertar 1 o 3: ");
                    scanf("%d",&op2);
                switch(op2){
                    case 1:
                      if(!Push(st1,elemento)) {
                        st2->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                    case 3:
                      if(!Push(st3,elemento)) {
                        st2->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                }
                break;
                    case 3:
                        Pop(st3,&elemento);
                 printf("Ingrese el numero de la pila a la que quiere insertar 1 o 2: ");
                    scanf("%d",&op2);
                switch(op2){
                    case 1:
                      if(!Push(st1,elemento)) {
                        st3->top++;
                        printf("\nLa operacion no se realizo , la pila a la que se quiere insertar elementos esta llena\n\n");
                      }
                    break;
                    case 2:
                      if(!Push(st2,elemento)) {
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
void ShowStack(StackInt *p1,StackInt *p2, StackInt *p3){
int opc;
    printf("Presione 1 2 o 3 para mostrar la pila correspondiente o 4 para mostrar todas: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                if(p1->top > -1) {
                printf("La pila 1 esta asi: \n");
                    for(int i = 0; i<=p1->top; i++){
                        printf("%d ",p1->elemarray[i]);
                        }
                printf("\n");
            } else puts("\nLa pila 1 esta vacia\n");
            break;

            case 2:
               if(p2->top > -1 ) {
        printf("La pila 2 esta asi: \n");
            for(int i = 0; i<=p2->top; i++){
                printf("%d ",p2->elemarray[i]);
                }
                printf("\n");
            } else  puts("\nLa pila 2 esta vacia\n");
            break;

            case 3:
                if(p3->top > -1 ) {
            printf("La pila 3 esta asi: \n");
                for(int i = 0; i<=p3->top; i++){
                    printf("%d ",p3->elemarray[i]);
                    }
                printf("\n");
                }else  puts("\nLa pila 3 esta vacia\n");
            break;
            default:
              imprime(st1,st2,st3);
            break;
        }
}

void imprime(StackInt *pila1,StackInt *pila2,StackInt *pila3){
    if(pila1->top > -1) {
            printf("La pila 1 esta asi: \n");
                for(int i = 0; i<=pila1->top; i++){
                printf("%d ",pila1->elemarray[i]);
            }
printf("\n");
} else puts("\nLa pila 1 esta vacia\n");
if(pila2->top > -1 ) {
        printf("La pila 2 esta asi: \n");
    for(int i = 0; i<=pila2->top; i++){
        printf("%d ",pila2->elemarray[i]);
    }
    printf("\n");
} else  puts("\nLa pila 2 esta vacia\n");
if(pila3->top > -1 ) {
    printf("La pila 3 esta asi: \n");
        for(int i = 0; i<=pila3->top; i++){
            printf("%d ",pila3->elemarray[i]);
        }
    printf("\n");
    }else  puts("\nLa pila 3 esta vacia\n");
}

StackInt *CrearStack(int t){
 StackInt *pointer = 0;
    pointer = new StackInt;
        pointer -> elemarray = new int [t];
    pointer->top = -1;
    pointer->sizee = t;
 return pointer;
}

bool IsEmpty(StackInt s){
    if(s.top < 0 ) return true;
    return false;
}

bool isFull(StackInt s){
    if(s.top >=s.sizee - 1) return true;
    return false;
}

bool Push(StackInt *s, int elem){
    if(isFull(*(s)))  return false;
        s->elemarray[++s->top] = elem;
    return true;
}

bool Pop(StackInt *s,int *elem){
    if(s->top < 0 ) return false;
    ///printf("Tiene algo\n");
        *elem = s->elemarray[s->top--];
    return true;
}
