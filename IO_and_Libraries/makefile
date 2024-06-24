CC = gcc
CFLAGS = -Wall -g
AR = ar

all: mains maindloop maindrec loops
#Libraries
loops: libclassloops.a

libclassloops.a: basicClassification.o advancedClassificationLoop.o
			$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

basicClassification.o: basicClassification.c NumClass.h
			$(CC) $(CFLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
			$(CC) $(CFLAGS) -c advancedClassificationLoop.c

recursives: libclassrec.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
			$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
			$(CC) $(CFLAGS) -c advancedClassificationRecursion.c

recursived: libclassrec.so

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
			$(CC) -shared -fPIC -o libclassrec.so basicClassification.o advancedClassificationRecursion.o -lm

loopd: libclassloops.so

libclassloops.so: basicClassification.o advancedClassificationLoop.o
			$(CC) -shared -fPIC -o libclassloops.so basicClassification.o advancedClassificationLoop.o -lm
#Main
mains: main.o libclassrec.a
			$(CC) $(CFLAGS) main.o libclassrec.a -o mains -lm

main.o: main.c NumClass.h
			$(CC) $(CFLAGS) -c main.c

maindloop: main.o libclassloops.so
			$(CC) $(CFLAGS) main.o ./libclassloops.so -o maindloop


maindrec: main.o libclassrec.so
			$(CC) $(CFLAGS) main.o ./libclassrec.so -o maindrec

#Clean
clean: 
			rm -f mains maindloop maindrec *.o *.a *.so	libclassloops.* libclassrec.*
#PHONY
.PHONY: clean loops recursives recursived loopd 					