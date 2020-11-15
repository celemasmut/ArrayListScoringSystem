#include "studentScore.h"

studentScore student()
{
    studentScore aux;
    char file[5];
    srand(time(NULL));
    itoa(((rand()%9000)+1000),file,10);
    while((checkingFile(itoa(((rand()%9000)+1000),file,10))) == 1)
    {
        printf("Warning! that number file already exists ");

    }
    strcpy(aux.file,file);
    printf("Last Name: ");
    fflush(stdin);
    gets(aux.lastName);
    printf("Name: ");
    fflush(stdin);
    gets(aux.name);
    /*printf("Score: ");
    scanf("%d",aux.score);*/
    return aux;
}


int checkingFile(char file[])
{
    studentScore aux;
    int flag=0;
    FILE*school=fopen(StudentFile,"rb");
    fseek(school,0,SEEK_SET);
    while(flag == 0 && (fread(&aux,sizeof(studentScore),1,school)) > 0)
    {
        if(atoi(file) == atoi(aux.file))
        {
            flag=1;
        }
    }
    return flag;
}

/*void insertStudentToFile()
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
}*/
void showStudent(studentScore st)
{
    printf("FILE: %s",st.file);
    fflush(stdin);
    printf("\nName and Last name...%s %s",st.name,st.lastName);
    fflush(stdin);
    printf("Score: %d",st.score);
}
