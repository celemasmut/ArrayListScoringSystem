#include <stdio.h>
#include <stdlib.h>
#include "studentList.h"
#include "studentScore.h"
#include "utilities.h"

int main()
{
    cell Subjects[15];
    int valid=0;
    nodo*stStudent=inicList();
    valid=addAdl(Subjects,valid,stStudent);

    return 0;
}

void archToListDP2(nodo**list,char archStudent[])
{
    studentScore st;
    FILE *arch=fopen(archStudent,"rb");
    if(arch)
    {
        while(fread(&st,sizeof(studentScore),1,arch) > 0) // se lee el dato de empleado en el archivo
        {
            addAtFirstDP(list,createNewNodo(st));//no uso el ampersand por que ya recibo lista como puntero doble
        }
        fclose(arch);
    }
    //atencion con la funcion mostrar
    // showList(*lista);// showlist pide un puntero simple y como estamoc trabajando con DP a lista se le debe pasar un * simple.
}
