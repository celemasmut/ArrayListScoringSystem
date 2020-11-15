#include "studentList.h"
#include "studentScore.h"

nodo* inicList()
{
    return NULL;
}

nodo* createNewNodo(studentScore e)
{
    nodo* aux= (nodo*)malloc(sizeof(nodo));
    aux->dat=e;
    aux->next=NULL;
    return aux;
}
void addAtFirstDP(nodo**lista,nodo*newNodo)//paso por parametro lista con puntero doble para modificar por parametro por lo que no se necesita el retorno de lista
{
    if((*lista) == NULL)
    {
        (*lista)=newNodo;
    }
    else
    {
        newNodo->next=(*lista);
        (*lista)=newNodo;
    }
}

void addInOrderByLnameDP(nodo**list,nodo*newNodo)
{
    if((*list)== NULL)//primera posibilidad verficar si la lusta es nula
    {

        (*list)=newNodo;
    }
    else
    {

        if(strcmpi(newNodo->dat.lastName,(*list)->dat.lastName) < 0) //segunda posibilidad, se evalua si el dato nuevo es menor al primer dato de la lista
        {
            addAtFirstDP(list,newNodo);
        }
        else
        {
            nodo*before=(*list);//puntero a la lista que va a a ser la anterior
            nodo*next=(*list)->next;//puntero al siguiente nodo de la lista
            while(next && strcmpi(newNodo->dat.lastName,next->dat.lastName) > 0)// si no cumple 1° ni 2°, recorro y comparo que el nuevo dato sea mayor o igual al
            {
                // funcion atoi convierte un string en int.
                before=next;//en caso de entrar, guardo la direccion de memoria de next.
                next=next->next;// a next le asigno al puntero del proximo nodo para seguir evaluando.

            }
            newNodo->next=next;//apunto desdee el nuevo nodo a next para no perderlo.
            before->next=newNodo;//apunto desde el nodo before a nuevo nodo. asi se inserta el nuevo nodo entre el before y next.

        }
    }
}
void showNodo(nodo* studentNodo)
{
    showStudent(studentNodo->dat);
}
void showList(nodo*studentList)
{
    while(studentList)
    {
        showNodo;
    }
}
void showRecursiveList(nodo*list)// aca no se usa auxiliar por que la llamada recursiva es un viaje de ida y vuelta
{
    if(list)//condicion de corte, solucion trivial implicita
    {
        showNodo(list);
        showRecursiveList(list->next);//llamada recursiva y acercamiento a la condicion de corte
    }
}

int sumScoreRecursiveList(nodo*list)
{
    int sum=0;
    if(list)
    {
        sum=list->dat.score + sumScoreRecursiveList(list->next);
    }
    return sum;
}

void eraseSpecificNodoByFileDP(nodo**list, char file[])
{
    nodo*next;
    nodo*before;
    if((*list) && strcmp((*list)->dat.file, file)==0)//primer plateo es comparar con el primero
    {
        nodo*aux=(*list);//copio la direccion de memoria del primer nodo de lista
        (*list)=(*list)->next;//me muevo
        free(aux);//desvinculo y borro. Free libera la memoria
    }
    else
    {
        next=(*list);//copio la direccion de memoria del primer nodo de lista
        while(strcmp(next->dat.file,file)!=0)//ciclo corta hasta que encuentre dato o quede sin datos para recorrer
        {
            before=next;//va a ser la direccion de memoria anterior al que luego voy a vincular una vez haya borrado el nodo buscado
            next=next->next;//muevo puntero
        }
        if(next)//si encuantra ej: next queda parado en 3 el num a buscar
        {
            before->next=next->next;//before apuntaba a 3 ahora lo cambiamos para que apunte a 4
            free(next);//elimino nodo desvinculado
        }
    }
}

void eraseListaDP(nodo** list)//borra toda la lista
{
    nodo*prox;
    // nodo*next=(*lista);
    while(*list)
    {
        prox=(*list)->next;
        free(*list);
        (*list)=prox;
    }
}

nodo* insertStListToFile(nodo*stlist)
{
    nodo*aux;
    char option;
    do
    {
        aux->dat=student();
        showStudent(aux->dat);
       /* addAtFirstDP(&stlist,createNewNodo(aux->dat));
        showNodo(stlist);*/
        printf("\n ESC para salir..... ");
        fflush(stdin);
        option=getch();
    }
    while(option!=27);
    saveStListIntoFile(StudentFile,stlist);
    return stlist;
}
void saveStListIntoFile(char fileStudent[],nodo*stlist)
{
    FILE*arch=fopen(fileStudent,"ab");
    if(arch)
    {
        while(stlist)
        {
            fwrite(&stlist,sizeof(nodo),1,arch);
            stlist->next;
        }
        fclose(arch);
    }
}
int insertScore(nodo*list)
{
    int score=0;
    printf("Score: ");
    scanf("%d",list->dat.score);
    return score;
}
