#include <stdio.h>
#include <stdlib.h>
#include "studentList.h"
#include "studentScore.h"
#include "utilities.h"


#define subjects "arraySubjects.bin"



//void archToListDP2(nodo**list,char archStudent[]);


int main()
{
    cell Subjects[15];
    int valid=0;
    int totPassed=0;
    //insertRegisterToFile();
    showArchSubject();
   valid=arch2Adl(Subjects,valid,15);//valido es 4 por que son 4 materias.
    printf("\nValid= %d",valid);
    showAdl(Subjects,valid);
    totPassed=fromAdl2ArchPassed(Subjects,valid);
    printf("\nTotal of passed: %d",totPassed);
    return 0;
}


/*void archToListDP2(nodo**list,char archStudent[])
{
    studentScore st;
    FILE *arch=fopen(archStudent,"rb");
    if(arch)
    {
        while(fread(&st,sizeof(studentScore),1,arch) > 0) // se lee el dato de empleado en el archivo
        {
            addInOrderByLnameDP(list,createNewNodo(st));
        }
        fclose(arch);
    }
    //atencion con la funcion mostrar
    // showList(*lista);// showlist pide un puntero simple y como estamoc trabajando con DP a lista se le debe pasar un * simple.
}*/
