#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <string>

/**
 * Evaluador de polinomios.
 *
 * @param argc Cantidad de argumentos
 * @param argv matriz de argumentos
 * @return El código de salida del programa.
 */
int main(int argc, char **argv) {
  int exitCode;

  /// Si no hay argumentos suficientes mostramos un texto por defecto.
  if (argc != 3) {
    std::cout
        << "Argumentos inválidos, ejecute el programa de la siguiente forma:"
        << std::endl;
    std::cout << argv[0] << " \"[integral polinomica]\" [valor]" << std::endl;
    exitCode = EXIT_FAILURE;
  } else {
    /// Procesamos
    const std::string polinomio(argv[1]);
    const double valor = std::atof(argv[2]);
    std::cout << std::endl << "polinomio (cmd): " << polinomio << std::endl;
    std::cout << "Valor: " << valor << std::endl;

    std::cout << "polinomio (convertido): ";
    std::vector<Monomio> monomios = Utils::convertir(polinomio);
    std::vector<Monomio>::size_type i = 0;
    for (i = 0; i < monomios.size(); i++) {
      Monomio monomio = monomios[i];
      std::cout << monomio.GetCoeficiente() << "x^" << monomio.GetGrado()
                << " ";
    }
    std::cout << std::endl;

    double resultado = Utils::evaluar(monomios, valor);
    std::cout << "Resultado: " << resultado << std::endl;
    exitCode = EXIT_SUCCESS;
  }
  return exitCode;
}
