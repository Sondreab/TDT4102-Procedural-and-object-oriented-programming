#include <iostream>
#include <iomanip>
#include <math.h>

//Oppgave 1
//deloppgave a)

void inputAndPrintInteger() {
	int a;
	std::cout << "Skriv inn et heltall:" << std::endl;
	std::cin >> a;
	std::cout << "Du skrev inn: " << a << std::endl;
}

//deloppgave b)

int inputInteger() {
	int a;
	std::cout << "Skriv inn et heltall" << std::endl;
	std::cin >> a;
	return a;
}

//deloppgave c)

void inputIntegerAndPrintSum() {
	int a = inputInteger();
	int b = inputInteger();
	int sum = a + b;
	std::cout << "Summen av tallene: " << sum << std::endl;

	//deloppgave d)
	/*Her brukte jeg inputInteger fordi den returnerer verdien som brukeren
	skriver inn. Dette gjør at denne funksjonen kan hente ut verdien som brukeren
	skrev, noe den ikke klarer når verdien bare printes.*/
}

//deloppgave e)

bool isOdd(int a) {
	if (a % 2 == 1) {
		return true;
	}
}

//deloppgave f)

void printHumanReadableTime(int sek) {
	int t = sek / 3600;
	sek -= t * 3600;
	int m = sek / 60;
	sek -= m * 60;

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
	if (sek == 1) {
		std::cout << sek << " sekund" << std::endl;
	}
	else if (sek == 0) {
	}
	else {
		std::cout << sek << " sekunder" << std::endl;
	}
}

//Oppgave 2
//deloppgave a)

void inputIntegersUsingLoopAndPrintSum() {
	int sum = 0;
	int a;
	do {
		a = inputInteger();
		sum += a;
	} while (a != 0);
	std::cout << "Summen av tallene: " << sum << std::endl;

	//deloppgave b)
	/*En for løkke er bra å bruke når man vet hvor mange tall man skal summere,
	fordi da vet man hvor mange iterasjoner man må utføre.
	En while løkke er best når man vil summere input fra brukeren helt til et spesielt
	input (i dette tilfellet 0) er skrevet inn.*/
}

//deloppgave c)

double inputDouble() {
	double a;
	std::cout << "Skriv inn et desimaltall:" << std::endl;
	std::cin >> a;
	return a;
}

//deloppgave d)

void convertFromNokToEuro() {
	double ratio = 9.64;
	double nok = -1;
	while (nok < 0) {
		nok = inputDouble();
		if (nok < 0) {
			std::cout << "Beløpet må være positivt." << std::endl;
		}
	}
	double euro = nok / /*static_cast<double>*/(ratio);
	std::cout << nok << " NOK er " << std::setprecision(2) << euro << " Euro." << std::endl;

	/*Her burde vi bruke inputDouble istedenfor inputInteger fordi vi skal dividere antall
	NOK med 9,64 (et desimaltall), og hvis vi har en int her blir det heltallsdivisjon og
	vi "mister" dermed informasjon i beregningen*/
}

//oppg 2 b)

void multiplicativeTable() {
	int b;
	int h;
	std::cout << "Angi gangetabellens høyde:" << std::endl;
	std::cin >> h;
	std::cout << "Angi gangetabellens bredde" << std::endl;
	std::cin >> b;
	for (int i = 1; i < h + 1; i++) {
		for (int j = 1; j < b + 1; j++) {
			if (j == b) {
				std::cout << i << "*" << j << "=" << i*j << "\n" << std::endl;
			}
			else {
				std::cout << i << "*" << j << "=" << i*j << "\t";
			}
		}
	}
}

//Oppgave 4

//oppg 4 a)

int discriminant(double a, double b, double c) {
	double disc = (b*b) - (4 * a*c);
	return disc;
}

//oppg 4 b)

void printRealRoots(double a, double b, double c) {
	double root1;
	double root2;
	double disc = discriminant(a, b, c);
	if (disc < 0) {
		std::cout << "negativ diskriminant, altså ingen relle losninger." << std::endl;
	}
	else if (disc == 0) {
		root1 = ((-b) + sqrt(discriminant(a, b, c))) / static_cast<double>(2 * a);
		std::cout << "1 losning: x = " << root1 << std::endl;
	}
	else {
		root1 = ((-b) + sqrt(discriminant(a, b, c))) / static_cast<double>(2 * a);
		root2 = ((-b) - sqrt(discriminant(a, b, c))) / static_cast<double>(2 * a);
		std::cout << "2 losninger: x = " << root1 << " og x = " << root2 << std::endl;
	}
}

//oppg 4 c)

void solveQuadraticEquation() {
	double a, b, c;
	std::cout << "Til 2. gradsligningen a(x^2) + bx + c, skriv inn: \n" << "a:" << std::endl;
	std::cin >> a;
	std::cout << "b:" << std::endl;
	std::cin >> b;
	std::cout << "c:" << std::endl;
	std::cin >> c;
	std::cout << "Ligningen: (" << a << ")(x^2) + (" << b << ")x + (" << c << ") har ";
	printRealRoots(a, b, c);
}

//Oppgave 5
//oppg 5 a)

void calculateLoanPayments() {
	int totLån;
	int rente;
	int antAvdrag;
	std::cout << "Skriv inn laanebelop:" << std::endl;
	std::cin >> totLån;
	std::cout << "Skriv inn rente i %" << std::endl;
	std::cin >> rente;
	std::cout << "Antall avdrag (antall år):" << std::endl;
	std::cin >> antAvdrag;
	double gjenståendeLån = totLån;
	std::cout << "Aar \t" << "innbetaling \t" << "Gjenstaaende laan" << std::endl;
	for (int i = 1; i < antAvdrag + 1; i++) {
		double renteKostn = (rente / static_cast<double>(100))*gjenståendeLån;
		double avdrag = (totLån / static_cast<double>(antAvdrag));
		double innbetaling = avdrag + renteKostn;
		gjenståendeLån -= avdrag;
		std::cout << i << "\t" << innbetaling << "\t" << gjenståendeLån << std::endl;
	}
}

//main
int main() {
	/*inputAndPrintInteger();
	std::cout << "Du skrev inn: " << inputInteger() << std::endl;
	inputIntegerAndPrintSum();
	for (int i = 10; i < 15; i++) {
	if (isOdd(i)) {
	std::cout << i << " er et oddetall." << std::endl;
	}
	else {
	std::cout << i << " er et partall." << std::endl;
	}
	}
	printHumanReadableTime(3722);
	inputIntegersUsingLoopAndPrintSum();
	inputDouble();
	convertFromNokToEuro();*/
	//meny
	int valg;
	do {
		std::cout << "Velg funksjon:\n"
			<< "0) Avslutt \n"
			<< "1) Summer to tall \n"
			<< "2) Summer flere tall \n"
			<< "3) Konverter NOK til EURO \n"
			<< "4) Skriv ut gangetabell \n"
			<< "5) Lose 2. gradsfunksjon \n"
			<< "6) Beregne nedbetaling av laan" << std::endl;
		std::cin >> valg;
		switch (valg) {
		case 0: break;
		case 1: inputIntegerAndPrintSum();
			system("pause");
			std::cout << "-------------------" << std::endl;
			break;
		case 2: inputIntegersUsingLoopAndPrintSum();
			system("pause");
			std::cout << "-------------------" << std::endl;
			break;
		case 3: convertFromNokToEuro();
			system("pause");
			std::cout << "-------------------" << std::endl;
			break;
		case 4: multiplicativeTable();
			system("pause");
			std::cout << "-------------------" << std::endl;
			break;
		case 5: solveQuadraticEquation();
			system("pause");
			std::cout << "-------------------" << std::endl;
			break;
		case 6: calculateLoanPayments();
			system("pause");
			std::cout << "-------------------" << std::endl;
			break;
		}
	} while (valg != 0);
	return 0;
}
