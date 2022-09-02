#ifndef MONOMIO_H
#define MONOMIO_H

/**
 * @brief Clase que representa un monomio algebraico.
 *
 */
class Monomio {
public:
  /**
   * @brief Constructor de un objeto Monomio.
   *
   */
  Monomio();

  /**
   * @brief Constructor de un objeto Monomio.
   *
   * @param orig Objeto original.
   */
  Monomio(const Monomio &orig);

  /**
   * @brief Destructor de un objeto Monomio
   *
   */
  ~Monomio();

  /**
   * @brief Getter del Coeficiente
   *
   * @return double
   */
  double GetCoeficiente() const;

  /**
   * @brief Setter del Coeficiente
   *
   * @param coeficiente
   */
  void SetCoeficiente(double coeficiente);

  /**
   * @brief Getter del Grado
   *
   * @return int
   */
  int GetGrado() const;

  /**
   * @brief Setter del Grado
   *
   * @param grado
   */
  void SetGrado(int grado);

private:
  /**
   * @brief Coeficiente del monomio.
   *
   */
  double coeficiente;

  /**
   * @brief Grado del monomio.
   *
   */
  int grado;
};

#endif /* MONOMIO_H */
