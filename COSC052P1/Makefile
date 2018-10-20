#
# Makefile for P1
# COSC 052
# Fall 2018
#

a.out: main.o IncidentLog.o PHMSA7000.o DateTime.o
	g++ -std=c++11 main.o IncidentLog.o PHMSA7000.o DateTime.o

main.o: main.cpp main.h IncidentLog.h PHMSA7000.h DateTime.h
	g++ -std=c++11 -c main.cpp

IncidentLog.o: IncidentLog.cpp IncidentLog.h PHMSA7000.h
	g++ -std=c++11 -c IncidentLog.cpp

PHMSA7000.o: PHMSA7000.cpp PHMSA7000.h DateTime.h
	g++ -std=c++11 -c PHMSA7000.cpp

DateTime.o: DateTime.cpp DateTime.h
	g++ -std=c++11 -c DateTime.cpp

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip main.cpp main.h IncidentLog.cpp IncidentLog.h PHMSA7000.cpp PHMSA7000.h DateTime.cpp DateTime.h Makefile

clean:
	rm -f *.o core a.out
