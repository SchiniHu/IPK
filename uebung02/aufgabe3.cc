#include <iostream>
#include <cmath>
#include <cstdint>
#include <math.h>
#include <chrono>

//berechnet iterativ das n-te Folgenglied
unsigned long long fibb_iterative(int number){
    if(number <= 1) return 0; // gib 0 zurueck für negative Zahlen und 1
    else if (number == 2) // gib 1 zurueck für die erste Fibonacci Zahl
    {
         return 1;
    }
    
    unsigned long long f_nAlt = 0; // setze die Startwerte
    unsigned long long f_nNeu = 1;
    unsigned long long temp; // temporaere variable
    for(int i = 2; i < number; ++i){ // i muss bei 2 beginnen, da bereits 2 Folgenglieder berechnet wurden
        // in jedem Schritt setze f_nAlt nurch f_nNeu und f_nNeu durch den nächsten Wert in der Folge 
        temp = f_nAlt;
        f_nAlt = f_nNeu;
        f_nNeu = f_nNeu + temp;
    }
    return f_nNeu;
}

//der explizite Algorithmus, siehe LA1
// Wir muessen aber number - 1 verwenden, da wir bei 0 anfangen.
unsigned long long fibb_explicit(int number){
    return 1/sqrt(5) * ( std::pow((1+sqrt(5))/2 ,number-1) - std::pow((1-sqrt(5))/2 ,number-1) );
}

//Funktion, die alle Folgenglieder bis N berechnet und ausgibt. Die Funktion zur Berechnung wird übergeben.
void calc_till_N(int N, unsigned long long (*function)(int)){
    for (int i = 1; i <= N; i++)
    {
        std::cout << "f_" << i << ": "<< function(i) << std::endl;
    }
    
}


int main(int argc, char** argv){
    int n; // Variable in die der Startwert eingegben werden soll
    std::cout << "Welches Folgenglied soll berechnet werden? ";
    std::cin >> n; // Eingabe des Startwerts
    auto start = std::chrono::high_resolution_clock::now(); // Fuer die Geschwindigkeitsmessung
    calc_till_N(n, fibb_iterative); // Berechnung und Ausgabe des Folgenglieds mit iterativem Algorithmus
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedone = finish - start;
    std::cout << "Vergangene Zeit:  " << elapsedone.count() << " s\n"; // Ausgabe der vergangenen Zeit

    start = std::chrono::high_resolution_clock::now();
    calc_till_N(n, fibb_explicit); // Berechnung und Ausgabe des Folgenglieds mittels explizitem Algorithmus
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedtwo = finish - start;
    std::cout << "Vergangene Zeit:  " << elapsedtwo.count() << " s\n"; // Ausgabe der vergangenen Zeit
}