The program to implement 2-pass macroprocessor is done using C in two separate .c files:pass1.c and pass2.c.pass1.c implements the first pass of the macroprocessor while pass2.c implements pass 2 of the macroprocessor.The two .c files are executed in codeblocks under the project name"Two pass macroprocessor".

The input file "minp2.txt" is created and saved in the same folder where the codeblocks project is saved.


Pass1.c:

The required libraries,stdio.h,conio.h,string.h,stdlib.h are included.The rest of the program is implemented in the main function.Three file pointers are created to point to the input file,nametab("ntab2.txt") and deftab("dtab2.txt") files respectively.The required initialisations and input validations are done.The input file "minp2.txt" is opened to read.The two output files "ntab2.txt" and "deftab2.txt" are created and opened to write.
    A while loop is run to read till the macroend(mend) is reached.If the mneumonic is 'MACRO',the macro name is written into the nametab(ntab2.txt) and the macro name and arguments are written into the deftab(dtab2.txt).All the other statements within the macro definition are written into the deftab.When the 'MEND' mneumonic is encountered,pass-1 of the 2-pass macroprocessor is completed.All the 3 opened files are closed.The success message is printed on the .exe console after the program is build and run.The 2 output files,"ntab2.txt" and "dtab2.txt" can be opened to see the name and the definition of the macro respectively.


Pass2.c:

The required libraries are included.In the main function,5 file pointers are created.The output files are "atab2.txt" and "op2.txt" which contain the argument list array and the input program with the expanded macro definition respectively.The required input validation for the input,deftab and nametab files are done and opened to read.The output files are created and opened to write.
    The macro definition is read from the input file.The macro name is read from the nametab.The operation mneumonic of each input line is checked to see if it is a name in the nametab.When a call is found,the formal arguments from the deftab are replaced with the actual arguments from the input file and written into the "op2.txt" file.The actual arguments are written into the argument list array in the "arg2.txt" file.The file pointers to the nametab and argtab are repositioned to point to the beginning of the file stream.The rest of the input file ,following the macro is written into the "op2.txt" file.All the opened files are closed.The output files created by the program can be read from the saved location.The success of the pass-2 is indicated on the console after the code is built(compiled) and run(executed).
