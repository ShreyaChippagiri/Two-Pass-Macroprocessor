#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3,*f4,*f5;                                          //Create 5 file pointers
int i,len;
char mne[20],opnd[20],la[20],name[20],mne1[20],opnd1[20],arg[20];   //Initialisation of the mneumonic,operands,la,name,mneumonic1,operands1 and arguments char arrays
f1=fopen("minp2.txt","r");  //Open input file to read
if(f1==NULL)
{
printf("Please create the input file\n");
exit(0);
}
f2=fopen("ntab2.txt","r");  //Open name table to read
if(f2==NULL)
{
printf("Please check the name table to be created by pass1\n");
exit(0);
}
f3=fopen("dtab2.txt","r");  //Open definition table to read
if(f3==NULL)
{
printf("Please check the definition table to be created by pass1\n");
exit(0);
}
f4=fopen("atab2.txt","w+");  //Open argument table to write
f5=fopen("op2.txt","w");     //Open output file to write
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"END")!=0)
{
if(strcmp(mne,"MACRO")==0)        //Reading the macro definition part from the input file
{
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"MEND")!=0)
fscanf(f1,"%s%s%s",la,mne,opnd);
}
else
{
fscanf(f2,"%s",name);             //Check for the name of the macro in the nametab and process the macro call
if(strcmp(mne,name)==0)
{
len=strlen(opnd);
for(i=0;i<len;i++)
{
if(opnd[i]!=',')
fprintf(f4,"%c",opnd[i]);       //Write the arguments in the "atab2.txt"
else
fprintf(f4,"\n");
}
fseek(f2,SEEK_SET,0);          //Reposition the file pointers to the beginning of the file stream
fseek(f4,SEEK_SET,0);
fscanf(f3,"%s%s",mne1,opnd1);  // Processing the macro call and expansion.
fprintf(f5,".\t%s\t%s\n",mne1,opnd);
fscanf(f3,"%s%s",mne1,opnd1);
while(strcmp(mne1,"MEND")!=0)
{
if((opnd1[0]=='&'))
{
fscanf(f4,"%s",arg);            //Replace the formal arguments by the actual arguments in the argtab and write in the output file
fprintf(f5,"-\t%s\t%s\n",mne1,arg);
}
else
fprintf(f5,"-\t%s\t%s\n",mne1,opnd1);
fscanf(f3,"%s%s",mne1,opnd1);
}
}
else
fprintf(f5,"%s\t%s\t%s\n",la,mne,opnd); //Write the rest of the input file into the output file
}
fscanf(f1,"%s%s%s",la,mne,opnd);
}
fprintf(f5,"%s\t%s\t%s\n",la,mne,opnd);
fclose(f1);                              //Close all the opened files
fclose(f2);
fclose(f3);
fclose(f4);
fclose(f5);
printf("pass2 is successful. ");
getch();
}

