#include<iostream>
#include<random>
//#include<time.h>


using namespace std;


int random(int low, int high)
{
typedef mt19937 rng_type;

uniform_int_distribution<rng_type::result_type> udist(low, high);

rng_type rng;

// seed rng first:
rng_type::result_type const seedval = (const unsigned int)time(NULL);	// get this from somewhere
rng.seed(seedval);

rng_type::result_type random_number = udist(rng);

return random_number;
}

// VON ChatGPT (Gibt allerdings ab und zu eine bereits zuvor generierte Random Nummer zurück) ->>>

//In C++ können Sie die Funktion rand() aus der Standardbibliothek verwenden, um Zufallszahlen zu generieren.Aber für eine bessere und modernere Methode zur Generierung von Zufallszahlen, sollten Sie die Funktionen in der Bibliothek verwenden.
//
//Hier ist ein Beispielcode, der Zufallszahlen zwischen 1 und 10 generiert:

//#include <random>
//#include <iostream>
//
//int main() {
//    // Initialisiere einen random_device Objekt
//    std::random_device rd;
//
//    // Initialisiere einen Mersenne-Twister-Zufallszahlengenerator mit rd als Seed
//    std::mt19937 gen(rd());
//
//    // Initialisiere eine gleichmäßige Verteilung zwischen 1 und 10
//    std::uniform_int_distribution<> dis(1, 10);
//
//    // Generiere und drucke zehn Zufallszahlen
//    for (int n = 0; n < 10; ++n)
//        std::cout << dis(gen) << ' ';
//    std::cout << '\n';
//
//    return 0;
//}

//Dieser Code verwendet den Mersenne Twister Algorithmus(std::mt19937),
//der ein hochwertiger Zufallszahlengenerator ist.Die Funktion std::uniform_int_distribution sorgt dafür,
//dass die generierten Zahlen gleichmäßig über den angegebenen Bereich verteilt sind.