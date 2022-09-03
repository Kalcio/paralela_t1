#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


string gen_form(double degree);
string polynomial(double degree, vector<double> coeffs);
double p_of_x(double x, double degree, vector<double> coeffs);
double derivative(double x, double degree, vector<double> coeffs);
double* root(double x, double degree, vector<double> coeffs);
double Verify(double x, double degree, vector<double> coeffs);

/**
 * Evaluador de polinomios.
 *
 * @param argc Cantidad de argumentos
 * @param argv matriz de argumentos
 * @return El código de salida del programa.
 */
int main(int argc, char **argv) {
  int exitCode;
  vector<double> coeff;

  /// Si no hay argumentos suficientes mostramos un texto por defecto.
  if (argc != 3) {
    cout
        << "Argumentos inválidos, ejecute el programa de la siguiente forma:"
        << endl;
    cout << argv[0] << " \"[integral polinomica]\" [valor]" << endl;
    exitCode = EXIT_FAILURE;
  } else {
    /// Procesamos
    const string polinomio(argv[1]);
    const double valor = atof(argv[2]);
    cout << endl << "Polinomio: " << polinomio << endl;
    cout << "Valor inicial: " << valor << endl;
    vector<Monomio> monomios = Utils::convertir(polinomio);
    vector<Monomio>::size_type i = 0;

    //Obtener el primer grado del primer monomio
    Monomio prim_monomio = monomios[0];
    double grado = prim_monomio.GetGrado();

    //Se trasladan los datos de coeficiente del vector monomio a un vector coeficiente
    double aux_grado = grado;
    for(i=0; aux_grado >= 0;i++){
        Monomio monomio = monomios[i];

        //Genera coeficiente "0" para evitar errores
        while(monomio.GetGrado() < aux_grado){
            coeff.push_back(0);
            aux_grado--;
        }

        double aux = monomio.GetCoeficiente();
        coeff.push_back(aux);
        aux_grado--;
    }

    while(1){
        double* rt = root(valor, grado, coeff);
        if(rt[1] == 1){
            cout << endl << "La solución es de alrededor de " << rt[0] << endl;
            cout << endl << "===Integrantes===" << endl <<"Matias Munoz" << endl << "Felipe Barrera" << endl << "Joaquin Gomez" << endl << "Mauricio Quiroz" << endl << "Dante Caceres" << endl;
            return exitCode;
        } else {
            cout << "Ninguna raiz encontrada. El Loop paro en el valor: " << rt[0] << endl;
            cout << endl << "===Integrantes===" << endl <<"Matias Munoz" << endl << "Felipe Barrera" << endl << "Joaquin Gomez" << endl << "Mauricio Quiroz" << endl << "Dante Caceres" << endl;
            return exitCode;
        }
    }
    exitCode = EXIT_SUCCESS;
  }
  return exitCode;
}

double p_of_x(double x, double degree, vector<double> coeffs)
{
    double value = 0;
    int i = 0;
    degree = degree+1;
    while(degree--)
    {
        value = value + coeffs[i]*pow(x,degree);
        i++;
    }

    return value;
}


double derivative(double x, double degree, vector<double> coeffs)
{

    double value = 0;
    int i = 0;

    while (degree > 1)
    {
        value += degree*coeffs[i]*pow(x,degree-1);
        i++;
        degree--;
    }
    value += coeffs[i];

    return value;
}


double* root(double x, double degree, vector<double> coeffs)
{

    double* y = new double[2]; 
    for (int i = 0; i < 200; i++)
    {
        double z = p_of_x(x,degree,coeffs);

        if (z > 0.000001 || z < -0.000001){
            x = x - (p_of_x(x,degree,coeffs)/derivative(x,degree,coeffs));
        }
        else{
            y[0] = x;
            y[1] = 1;
            return y;
        }
    }
    y[0] = x;
    y[1] = 0;
    return y;
}