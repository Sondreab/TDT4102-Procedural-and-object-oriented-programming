#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include "cannonball.h"
#include "utilities.h"

const double PI = 3.141592653589793;

double acclY() {
	double gravitationalAcc = -9.81;
	return gravitationalAcc;
}
/*returnerer akselerasjonen i y-retning*/

double velY(double initVelocityY, double time) {
	return initVelocityY + acclY()*time;
}
/*tar inn startsfart i y retning og tid i sekunder, returnerer farten i y retning*/

double posX(double initVelocityX, double time) {
	double initPosX = 0.0;
	return initPosX + initVelocityX*time; //ingen info om x-akselerasjon
}
/*tar inn startsfart i x retning og tid i sekunder, returnerer posisjonen i x-retning*/

double posY(double initVelocityY, double time) {
	double initPosY = 0.0;
	return initPosY + initVelocityY*time + ((acclY()*time*time) / 2.0);
}
/*tar inn startsfart i y-retning og tid i sekunder, returnerer posisjonen i y-retning*/

void printTime(double time) {
	int t = time / 3600;
	time -= t * 3600;
	int m = time / 60;
	time -= m * 60;

	if (t == 1) {
		std::cout << t << " time" << std::endl;
	}
	else if (t == 0) {
	}
	else {
		std::cout << t << " timer" << std::endl;
	}

	if (m == 1) {
		std::cout << m << " minutt" << std::endl;
	}
	else if (m == 0) {
	}
	else {
		std::cout << m << " minutter" << std::endl;
	}

	if (time == 1.0) {
		std::cout << time << " sekund" << std::endl;
	}
	else if (time == 0.0) {
	}
	else {
		std::cout << time << " sekunder" << std::endl;
	}
}
/*tar inn tid i sekunder og printer i timer, minutter og sekunder*/

double flightTime(double initVelocityY) {
	double flightTimeUpwards = initVelocityY / (-acclY());
	double totalFlightTime = 2 * flightTimeUpwards;
	return totalFlightTime;
}
/*tar inn startsfarten i y-retning og returnerer flytiden i sekunder*/

void getUserInput(double *theta, double *absVelocity) {
	std::cout << "Angi en vinkel:" << std::endl;
	std::cin >> *theta;
	std::cout << "Angi en fart, i m/s, i retning av vinkelen:" << std::endl;
	std::cin >> *absVelocity;
}
/*ber bruker om en vinkel og en fart.
Disse verdiene skal lagres i minnet som pekerne theta og absVelocity peker på*/

double getVelocityX(double theta, double absVelocity) {
	double velocityX = absVelocity*cos(theta*(PI/180));
	return velocityX;
}
double getVelocityY(double theta, double absVelocity) {
	double velocityY = absVelocity*sin(theta*(PI/180));
	return velocityY;
}
/*returnerer henoldsvis farten i x-, og y-retning, gitt en vinkel,
theta, og en absoluttfart absVelocity*/

void getVelocityVector(double theta, double absVelocity,
	double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}
/*dekomponer farten gitt av absVelocity, i x- og y-komponentene gitt vinkelen theta.
Disse komponentene lagres i minnet.
Bruker getVelocityX() og getVelocityY().*/

double getDistanceTraveled(double velocityX, double velocityY) {
	double distanceTraveled = posX(velocityX, flightTime(velocityY));
	return distanceTraveled;
}
/*Returnere horisontal lengde reist, bruker posX() og flightTime()*/

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	double avvik = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
	return avvik;
}
/*Tar inn en avstand distanceToTarget og returnerer avviket mellom distanceToTarget,
og der kulen lander.*/

void playTargetPractice() {
	std::random_device seeder;
	std::default_random_engine generator(seeder());
	int distanceToTarget = modernRandomWithLimits(100, 1000, generator);
	double theta;
	double absVelocity;
	double velocityX;
	double velocityY;
	std::cout << "Velkommen til blinktrening!\n"
		<< "Du får 10 forsok til aa treffe blinken som er mellom 100 og 1000 meter unna. \n"
		<< "Per forsok faar du velge vinkelen og farten prosjektilet skal skytes ut med. \n"
		<< "Du vinner hvis du treffer innen 10 forsok har gaatt, og du taper hvis ikke. \n"
		<< "Lykke til!" << std::endl;
	system("pause");
	for (int i = 1; i <= 10; i++) {
		std::cout << "Forsok " << i << ":" << std::endl;
		getUserInput(&theta, &absVelocity);
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
		double avvik = targetPractice(distanceToTarget, velocityX, velocityY);
		if (avvik < 5.0 && avvik > -5.0) {
			std::cout << "\nGratulerer! Du traff blinken etter " << i << " forsok!" << std::endl;
			break;
		}
		else if (avvik >= 5.0) {
			std::cout << "Du bommet!\t" << avvik << " meter for kort!\n" << std::endl;
		}
		else {
			std::cout << "Du bommet!\t" << avvik*(-1) << " meter for langt!\n" << std::endl;
		}
		if (i == 10) {
			std::cout << "Det var siste forsok. Du tapte!\n" << std::endl;
		}
	}
}
/*Brukeren bes om en vinkel og en startsfart, som bestemmer hvordan kanonkula skal skytes
ut. En blink blir plassert et tilfeldig sted mellom 100 og 1000 m unna,
og forskjellen mellom blinken og kulas klandingspunkt, inkludert retning.
Brukeren får 10 forsøk, og skal få gratulasjon hvis bruker klarer å treffe blinken
(avvik < 5 m) innen 10 forsøk, og få melding om tap hvis ikke.*/