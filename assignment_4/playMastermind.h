#pragma once


void playMastermind();
/*funksjonen skal lage en tilfeldig kode p� 4 bokstaver (A-F).
Bruker skal dermed gjette hvilke bokstaver koden inneholder
og hvilke rekkef�lge de er i.
Etter hver gang skal programmet fortelle hvor mange bokstaver som var riktig
og hvor mange som var p� riktig plass.*/

int checkCharactersAndPosition(char arr1[], char arr2[]);
/*Skal sammenlikne 2 arrays or gi ut hvor mange av elementene
som er identiske p� samme plass.*/

int checkCharacters(char arr1[], char arr2[]);
/*Sammenlikner Fasit og gjett, og returnerer antall riktige bokstaver*/