#ifndef STUDENTSCORE_H_INCLUDED
#define STUDENTSCORE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define StudentFile "StudentScores"
typedef struct {
   int score;
   int file;
   char name[30];
   char lastName[30];
} studentScore;

studentScore student();
int checkingFile(int file);
void insertStudentToFile();
void saveStudentIntoFile(char fileStudent[],studentScore aux);
void showStudent(studentScore st);


#endif // STUDENTSCORE_H_INCLUDED
