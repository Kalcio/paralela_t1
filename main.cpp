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
  std::vector<double> coeff;

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
    // std::cout << "polinomio (convertido): ";
    std::vector<Monomio> monomios = Utils::convertir(polinomio);
    std::vector<Monomio>::size_type i = 0;

    //Encontrar el primer grado del primer monomio
    Monomio prim_monomio = monomios[0];
    double grado = prim_monomio.GetGrado();
    cout << "GRADO " << grado << endl;

    double aux_grado = grado;
    for(i=0; aux_grado >= 0;i++){
        Monomio monomio = monomios[i];

        cout << "Grado monomio " << monomio.GetGrado() << endl;
        cout << "Grado real " << aux_grado << endl;

        while(monomio.GetGrado() < aux_grado){
            coeff.push_back(0);
            cout << "push" << endl;
            aux_grado--;
            cout << "Grado monomio " << monomio.GetGrado() << endl;
            cout << "Grado real " << aux_grado << endl;
        }

        // if(monomio.GetGrado() == aux_grado) {
        double aux = monomio.GetCoeficiente();
        cout << "Cof " << i << ": " << aux << endl;
        coeff.push_back(aux);
        aux_grado--;
        // } else {
        //     double aux2 = monomio.GetCoeficiente();
        //     cout << "Cof " << i << ": " << aux2 << endl;
        //     coeff.push_back(0);
        //     aux_grado--;
        // }
        // coeff[i] = monomio.GetCoeficiente();
        
        // std::cout << "Coef" << i << ": " << monomio.GetCoeficiente() << std::endl;
        // std::cout << "Grado" << i << ": " << monomio.GetGrado() << std:: endl;
    }

    for(i=0;i < coeff.size();i++){
        std::cout << "Coef " << i << ": " << coeff[i] << std::endl;
    }

    // for(i=0; i<3;i++){
    //     Monomio monomio = monomios[i];
    //     double aux = monomio.GetGrado();
    //     coeff.push_back(aux);

    //     std::cout << "Coef " << i << ": " << coeff[i] << std::endl;
    // }

    /*
    for (i = 0; i < monomios.size(); i++) {
      Monomio monomio = monomios[i];
      std::cout << monomio.GetCoeficiente() << "x^" << monomio.GetGrado()
                << " ";
    }*/
    std::cout << std::endl;

    // double resultado = Utils::evaluar(monomios, valor);
    // std::cout << "Resultado: " << resultado << std::endl;

    cout << "Valores coeff: " << endl;

    for(i=0; i<coeff.size(); i++){
        cout << coeff[i] << endl;
    }

    while(1){
        double* rt = root(valor, grado, coeff);
        cout << rt << endl;
        if(rt[1] == 1){
            cout << "El resultado de la raíz es: " << rt[0] << endl;
            return exitCode;
        } else {
            cout << "Ninguna raiz encontrada. El Loop paro en el valor: " << rt[0] << endl;
            return exitCode;
        }
        cout << "Verificacion: " << Verify(rt[0], grado, coeff) << endl;
    }

    exitCode = EXIT_SUCCESS;
  }
  return exitCode;
}

// int vectorCoef(vector<Monomio> monomios, vector<int> coeff){
//     int i;
//     for(i=0; i<coeff.size();i++){
//         Monomio monomio = monomios[i];
//         int aux = monomio.GetGrado();
        
//         int grado = coeff.push_back(aux);
//         cout << "Coef " << i << ": " << grado << endl;
//     }

// }
/*
string gen_form(double degree)
{
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string poly = "";
    int i = 0;

    while (degree > 1)
    {
        poly = poly + letters[i] + "x^" + to_string(degree) + "+";
        i++;
        degree--;
    }
    poly = poly + letters[i] + "x+";
    i++;
    poly = poly + letters[i];

    return poly;
}
*/
/*
string polynomial(double degree, vector<double> coeffs)
{
    int i = 0;
    string poly = "";
    while (degree > 1)
    {
        if (coeffs[i] < 0 && i > 0)
        {
            poly.erase(poly.length()-1,1);
        }
        poly += to_string(coeffs[i]) + "x^" + to_string(degree) + "+";
        i++;
        degree--;
    }
    if (coeffs[i] < 0 && i > 0)
    {
        poly.erase(poly.length()-1,1);
    }
    poly += to_string(coeffs[i]) + "x" + "+";
    i++;
    if (coeffs[i] < 0 && i > 0)
    {
        poly.erase(poly.length()-1,1);
    }
    poly += to_string(coeffs[i]);
    return poly;
}*/

double p_of_x(double x, double degree, vector<double> coeffs)
{
    // cout << "   POFX   " << endl;
    double value = 0;
    int i = 0;
    degree = degree+1;
    while(degree--)
    {
        cout << "Valor " << value << endl;
        // cout << "Grado: " << degree << endl;
        // cout << "I: " << i << endl;
        // cout << "while pofx" << endl;
        // cout << " Pow " << pow(x,degree) << endl;
        value = value + coeffs[i]*pow(x,degree);
        i++;
    }
    
    // cout << "return POFX" << endl;
    return value;
}


double derivative(double x, double degree, vector<double> coeffs)
{
    // cout << "   derivate   " << endl;
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
    // cout << "   root   " << endl;

    double* y = new double[2]; 
    for (int i = 0; i < 200; i++)
    {
        double z = p_of_x(x,degree,coeffs);

        if (z > 0.000001 || z < -0.000001)
        {
            // cout << "Antes de Derivar " << endl;
            x = x - (p_of_x(x,degree,coeffs)/derivative(x,degree,coeffs));
        }
        else{
            y[0] = x;
            y[1] = 1;
            // cout << "retorna root 1 " << endl;
            return y;
        }
    }
    y[0] = x;
    y[1] = 0;
    // cout << "retorna root 2 " << endl;
    return y;
}

double Verify(double x, double degree, vector<double> coeffs)
{
    double value = p_of_x(x,degree,coeffs);
    value = (value*1000000)/100000;

    return value;
}
