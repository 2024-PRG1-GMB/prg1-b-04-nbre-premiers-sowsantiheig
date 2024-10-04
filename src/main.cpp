// Fichier     main.cpp
// Auteur      Santiago Sugrañes
// Date        03/10/20204
//
// But         Programme qui affiche tous les nombres premiers compris entre 1
// et une valeur saisie par l’utilisateur.
//
// Compilateur g++
#include <iostream>

int main() {
  int limit;
  int foundCount; // amount of prime numbers found, used for output formatting
  char restartChar;

  std::cout << "=====================================================\n";
  std::cout << "= Ce programme affiche tous les nombres premiers    =\n";
  std::cout << "= compris entre 1 et la valeur entrée.              =\n";
  std::cout << "=====================================================\n";

  do {
    // reset user limit and number of prime numbers found
    limit = 0;
    foundCount = 0;

    while (limit < 2 || limit > 1000000) {
      std::cout << "Entrer une valeur [2-1000] : ";
      std::cin >> limit;
    }

    std::cout << "\nVoici la liste des nombres premiers : \n";
    for (int nbr = 2; nbr <= limit; nbr++) {
      bool primme = true;

      // check if number is prime
      for (int j = 2; j < nbr; j++) {
        if (nbr % j == 0) {
          primme = false;
          break;
        }
      }

      if (primme) {
        foundCount++;
        std::cout << nbr << "\t";

        // new line if there are already 5 numbers on the line
        if (foundCount % 5 == 0)
          std::cout << "\n";
      }
    }

    std::cout << "\n\n"; // better spacing

    do {
      std::cout << "Voulez-vous recommencer? [O/N] : ";
      std::cin >> restartChar;
    } while (restartChar != 'O' && restartChar != 'N');

  } while (restartChar == 'O');

  return EXIT_SUCCESS;
}
