#include <iostream>
#include <cmath>

//Funktion zur Berechnung der Mitternachtsformel
void Mitternachtsformel(double a, double b, double c){
    if (a == 0) { //Spezialfall a = 0, da in Mnf durch a geteilt wird
        if (b == 0){ //Für a = b = 0 gibt es keine Lösungen da
            std::cout << "Keine Lösung da a = b = 0." << std::endl;
        }
        else { //Für b!=0 gilt x = -c/b
            std::cout << "Die Lösung ist x = " << -c/b << "." << std::endl;
        }

        return; //beendet Funktion für diese Fälle
    }

    double root = b * b - 4 * a * c; //berechnet Wert unter der Wurzel

    if (root < 0){ //Falls Wert unter der Wurzel < 0 gibt es nur komplexe Lösungen
        std::cout << "Die Lösungen sind komplex. " << std::endl;
        return; // beendet Funktion für diesen Fall 
    }

    if (root == 0){ //Falls die Wurzel = 0 ist, gibt es nur eine Lösung 
        std::cout << "Die Lösung ist x = " << (-b) / (2 * a) << ". " << std::endl; //Output an eine Lösung angepasst
        return; //beendet Funktion für diesen Fall
    }

    //Zwei Lösungen werden berechet, da +- vor der Wurzel
    double x1 = ((-b) + std::sqrt(root)) / (2 * a);
    double x2 = ((-b) - std::sqrt(root)) / (2 * a);

    //Lösungen werden ausgegeben
    std::cout << "Die Lösungen sind x_1 = " << x1 << " und x_2 = " << x2 << ". " << std::endl;
    
    return;
}

int main(int argc, char const *argv[])
{
    //Initialisiere 3 Variablen für die Koefffizienten der Gleichung
    double a;
    double b;
    double c;

    //Bittet um Eingabe und liest Eingabe ein
    std::cout << "Geben Sie die Koeffizienten einer quadratischen Gleichung der Form a*x^2 + b*x + c = 0 ein. " << std::endl;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;

    //Berechnet Mitternachtsformel
    Mitternachtsformel(a, b, c);
    return 0;
}

