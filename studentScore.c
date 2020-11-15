#include "studentScore.h"
#define StudentFile "StudentScores"

studentScore student()
{
    studentScore aux;
    int file;
    srand(time(NULL));
    file=(rand()%9000)+1000;
    while((checkingFile(file)) == 1)
    {
        printf("Warning! that number file already exists ");

    }
    printf("pasawhile");
    fflush(stdin);
    aux.file=file;
    fflush(stdin);
    printf("File: %d",aux.file);
    fflush(stdin);
    printf("Last Name: ");
    fflush(stdin);
    gets(aux.lastName);
    printf("Name: ");
    fflush(stdin);
    gets(aux.name);
    aux.score=0;
    //ok showStudent(aux);
    return aux;
}


int checkingFile(int file)
{
    studentScore aux;
    int flag=0;
    FILE*school=fopen(StudentFile,"rb");
    fseek(school,0,SEEK_SET);
    while(flag == 0 && (fread(&aux,sizeof(studentScore),1,school)) > 0)
    {
        printf("pasa3");
        if(file == aux.file)
        {
            flag=1;
        }
    }
    printf("flag= %d",flag);
    return flag;
}

void insertStudentToFile()
{
    studentScore aux;
    char option;
    do
    {
        aux=student();
        saveStudentIntoFile(StudentFile,aux);
        printf("\n ESC para salir..... ");
        fflush(stdin);
        option=getch();
    }
    while(option!=27);
}
void saveStudentIntoFile(char fileStudent[],studentScore aux)
{
    FILE*arch=fopen(fileStudent,"ab");
    if(arch)
    {
        fwrite(&aux,sizeof(studentScore),1,arch);
        fclose(arch);
    }
}
void showStudent(studentScore st)
{
    printf("FILE: %s",st.file);
    fflush(stdin);
    printf("\nName and Last name...%s %s",st.name,st.lastName);
    fflush(stdin);
    printf("Score: %d",st.score);
}
