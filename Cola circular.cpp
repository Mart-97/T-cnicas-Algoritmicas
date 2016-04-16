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
    QueueInt *cola;
    int elemento;
    bool res;
    cola = CrearQueue(2);
    res = InQueue(cola,3);
    ///if(res) printf("Se pudo\n");
    res = InQueue(cola,5);
     ///if(res) printf("Se pudo\n");
    res = InQueue(cola,4);
      ///if(res) printf("Se pudo\n");
   res = dQueue(cola,&elemento);
    if(res) printf("Se pudo\n");
    printf("%d\n",elemento);
     res =  dQueue(cola,&elemento);
        if(res) printf("Se pudo\n");
   printf("%d\n",elemento);

  res =  dQueue(cola,&elemento);
   if(res) printf("Se pudo\n");
   printf("%d\n",elemento);

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
 ///printf("%d %d\n",s->frontt,s->endd);
    return true;
}
