#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED

int getInt(int input,char message[], char eMessage[], int lowLimit, int hiLimit);
int getFloat(float* input,char message[], char eMessage[], float lowLimit, float hiLimit);
int getChar(char* input,char message[], char eMessage[], char lowLimit, char hiLimit);
int getString(char* input,char message[], char eMessage[], int lowLimit, int hiLimit);

#endif // VALIDAR_H_INCLUDED
