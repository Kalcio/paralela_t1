# Taller 1 - Computación Paralela y Distribuida

## Descripción del Trabajo 

Este programa elaborado en C++ cumple con la función de calcular la raíz de un polinomio, esto mediante em método de Newton Rhapson.
Es importante destacar que el programa está desarrollado en Linux y se inicializa usando el la herramienta "make", herramienta que funciona mediante el uso de un Makefile incluído en el repositorio.

## Instrucciones de ejecución
El programa debe de ser ejecutado en un entorno Linux, para su desarrollo se utilizó Ubuntu 22.04 LTS.

1. Clonar el repositorio utilizando el método que estime conveniente https://github.com/Kalcio/paralela_t1.git
2. Abrir la terminal al interior de la carpeta
3. En la terminal ingresar el comando "make":
 ```
make
```
 4. Para la ejecución del programa se debe de ingresar la ruta del archivo, en este caso "programa" o más específicamente "./programa", seguido del polinomio y el valor inicial, como se muestra en el siguiente ejemplo:
```
./programa x**3+x-1 2
```
 5. Una vez ingresados estos datos, presionamos enter y el programa entregará los resultados.

## Razonamiento
Para poder calcular la raíz del polinomio se separaron los polinomios en monomios, lo cual simplifica la utilización del método Newton-Raphson.

## Integrantes
- Matías Muñoz
- Felipe Barrera
- Joaquín Gómez
- Mauricio Quiroz
- Dante Cáceres
