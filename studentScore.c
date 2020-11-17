#include "studentScore.h"
#include "utilities.h"

#define subjects "arraySubjects.bin"


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
    fflush(stdin);
    aux.file=file;
    fflush(stdin);
    printf("\nFile: %d",aux.file);
    fflush(stdin);
    printf("\nLast Name: ");
    fflush(stdin);
    gets(aux.lastName);
    printf("\nName: ");
    fflush(stdin);
    gets(aux.name);
    fflush(stdin);
    printf("Score: ");
    scanf("%d",&aux.score);
    fflush(stdin);
    return aux;
}


int checkingFile(int file)
{
    fileRegister aux;
    int flag=0;
    FILE*school=fopen(subjects,"rb");
    fseek(school,0,SEEK_SET);
    while(flag == 0 && (fread(&aux,sizeof(fileRegister),1,school)) > 0)
    {
        if(file == aux.student.file)
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
        saveStudentIntoFile(STscore,aux);
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
    }
    else
    {
        printf("no hay arch");
    }
    fclose(arch);
}*/
void showStudent(studentScore st)
{
    printf("\nFILE: %d",st.file);
    fflush(stdin);
    printf("\nName and Last name...%s %s",st.name,st.lastName);
    fflush(stdin);
    printf("\nScore: %d",st.score);
}
/*void showArcStudent(char stscore[])
{
    studentScore aux;
    FILE*school;
    school=fopen(stscore,"rb");
    while((fread(&aux,sizeof(studentScore),1,school)) > 0)
    {
        showStudent(aux);
    }
    fclose(school);
}*/
