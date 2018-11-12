#pragma once
#include <random>

/*Øving 3*/
int randomWithLimits(int min, int max);
/*tar inn en øvre og nedre grense (inkludert i intervallet) og returnerer et,
pseudotilfeldig tall i intervallet*/

int modernRandomWithLimits(int min, int max, std::default_random_engine& generator);
/*tar inn en øvre og en nedre grense(inkludert i intervall),
returnerer tilfeldig heltall i intervallet*/

/*Øving 4*/
void incrementByValueNumTimes(int *startValue, int increment, int numTimes);
/*incrementerer startValue numTimes ganger or returnerer verdien startvalue har etter
inkrementereringen*/

void swapNumbers(int *a, int *b);
/*Tar inn to heltall og swapper dem.
Ja, denne funksjonen burde bruke pekere fordi den skal resultere i 2 "returverdier", 
men en funksjon kan bare returnere én verdi.*/

void printArray(int arr[], int length);
/*printer en array av hvilken som helst lengde*/

void randomizeArray(int arr[], int length);
/*Tar inn et array og lengden, og fyller arrayet med tilfeldige verdier [0-100]*/

void insertionSort(int arr[], int length);
/*Sorterer arr[] med insertion sort.
Sammenlikner to og to elementer og bytter plass på dem hvis det første
er større enn det andre. Repeterer helt til listen er sortert.*/

void selectionSort(int arr[], int length);
/*Sorterer arr[] med selection sort.
Går gjennom hele arrayet, finner minste verdi og plasserer elementet først, 
går dermed gjennom alle bortsett fra det første, finner det minste og
plasserer det på neste plass, osv.*/

double medianOfArray(int arr[], int length);
/*Tar inn array og lengde og returnerer medianen (midterste element).
Tar høyde for om det er odde- eller partall antall elementer i arrayet*/

void randomizeCString(char arr[], int length, char min, char max);
/*Tar inn en c-streng og fyller arrayet med tilfeldige bokstaver*/

//sier det er 3 elementer i arrayet..
/*void readInputToCString(char arr[], char min, char max);
Tar inn en c-sting og ber bruker om å fylle den ut.
Bruker skal bes om ny verdi om tegnet er utenfor [min, max]*/

//Substitutt for funksjonen over
void readInputToCString(char arr[], int length, char min, char max);

int countOccurencesOfCharacter(char arr[], int length, char tegn);
/*Tar inn en c-streng, lengden til denne og et tegn funksjonen skal
returnere antall forekomster av.*/