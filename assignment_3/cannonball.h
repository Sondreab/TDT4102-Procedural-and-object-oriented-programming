#pragma once

double acclY();
/*returnerer akselerasjonen i y-retning*/

double velY(double initVelocityY, double time);
/*tar inn startsfart i y retning og tid i sekunder, returnerer farten i y retning*/

double posX(double initVelocityX, double time);
/*tar inn startsfart i x retning og tid i sekunder, returnerer posisjonen i x retning.
(Antar at initPosition = 0)*/

double posY(double initVelocityY, double time);
/*tar inn startsfart i y retning og tid i sekunder, returnerer posisjonen i y retning.
(Antar at initPosition = 0)*/

void printTime(double time);
/*tar inn tid i sekunder og printer tiden(muligens i leselig format)*/

double flightTime(double initVelocityY);
/*tar inn startsfarten i Y-retning og returnerer flytiden i sekunder*/

void getUserInput(double *theta, double *absVelocity);
/*ber bruker om en vinkel og en fart.
Disse verdiene skal lagres i minnet som pekerne theta og absVelocity peker på*/

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
/*returnerer henoldsvis farten i x-, og y-retning, gitt en vinkel,
theta, og en absoluttfart absVelocity*/

void getVelocityVector(double theta, double absVelocity,
	double *velocityX, double *velocityY);
/*dekomponer farten gitt av absVelocity, i x- og y-komponentene gitt vinkelen theta.
Disse komponentene lagres i minnet.
Bruker getVelocityX() og getVelocityY().*/

double getDistanceTraveled(double velocityX, double velocityY);
/*Returnere horisontal lengde reist, bruker posX() og flightTime()*/

double targetPractice(double distanceToTarget, double velocityX, double velocityY);
/*Tar inn en avstand distanceToTarget og returnerer avviket mellom distanceToTarget,
og der kulen lander.*/

void playTargetPractice();
/*Brukeren bes om en vinkel og en startsfart, som bestemmer hvordan kanonkula skal skytes
ut. En blink blir plassert et tilfeldig sted mellom 100 og 1000 m unna,
og forskjellen mellom blinken og kulas klandingspunkt, inkludert retning.
Brukeren får 10 forsøk, og skal få gratulasjon hvis bruker klarer å treffe blinken
(avvik < 5 m) innen 10 forsøk, og få melding om tap hvis ikke.*/