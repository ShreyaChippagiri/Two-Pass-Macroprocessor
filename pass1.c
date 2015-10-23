#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3;                          //create three file pointers
char mne[20],opnd[20],la[20];              //initialize the mneumonic,operands and la fields
f1=fopen("minp2.txt","r");                 //open input file "minp2.txt"(macro input) to read
if(f1==NULL)
{
printf("Input file empty.\nPlease input the file!"); //Input validation
}
f2=fopen("ntab2.txt","w+");                          //open input file "ntab2.txt"(name table) to write
f3=fopen("dtab2.txt","w+");                          //Open input file "dtab2.txt"(definition table) to write
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"MEND")!=0)                        //Processing the macro
{
if(strcmp(mne,"MACRO")==0)
{
fprintf(f2,"%s\n",la);                            //Write into name table,the name of the macro
fprintf(f3,"%s\t%s\n",la,opnd);                   //Write into definition table,the name of the macro and its arguments
}
else                                              //If not a macro
fprintf(f3,"%s\t%s\n",mne,opnd);                  //Write into the definition table the remaining mneumonics with their operands until the end of the macro(macro end(mend))
fscanf(f1,"%s%s%s",la,mne,opnd);
}
fprintf(f3,"%s",mne);                            //Indicate macro-end
fclose(f1);                                      //close all the files
fclose(f2);
fclose(f3);
printf("PASS 1 is successful.");
getch();
}


