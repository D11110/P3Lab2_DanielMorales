#include <iostream>
#include <cmath>
#include <array>
#include <iomanip>
using namespace std;

double metodoNewton(double xSubCero, double a, double b, double c, int limit)
{
    if (limit == 0)
    {
        return xSubCero;
    }
    else
    {
        double division = ((a * pow(xSubCero, 2)) + (b * xSubCero) + c) / (2 * (a * xSubCero) + b);
        double xSubN = xSubCero - division;
        return metodoNewton(xSubN, a, b, c, --limit);
    }
}

void pie(double limite, double acum, double acumDiv)
{
    if (acum >= limite)
    {
        std::cout << "La aprox de pi de " << limite << " es " << 4 * acumDiv << std::endl;
    }
    else
    {
        double div = pow(-1.0, acum) / ((2.0 * acum) + 1.0);
        acumDiv = acumDiv + div;
        pie(limite, acum + 1, acumDiv);
    }
}

int main()
{
    bool vive = true;
    while (vive)
    {
        std::cout << "****Menu****" << std::endl;
        std::cout << "1. Metodo de Newton" << std::endl;
        std::cout << "2. Normalizacion de matriz" << std::endl;
        std::cout << "3. Aproximacion a Pi" << std::endl;
        std::cout << "4. Salir" << std::endl;
        int selUsuario;
        std::cin >> selUsuario;
        switch (selUsuario)
        {
        case 1:
        {
            double a, b, c, primeraRaiz, segundaRaiz;
            std::cout << "Ingrese a:" << std::endl;
            std::cin >> a;

            while (a == 0)
            {
                std::cout << "A no puede ser 0" << std::endl;
                std::cout << "Ingrese a: " << std::endl;
                cin >> a;
            }

            std::cout << "Ingrese b:" << std::endl;
            std::cin >> b;

            std::cout << "Ingrese c:" << std::endl;
            std::cin >> c;

            double verticeX = -b / (2 * a);
            primeraRaiz = verticeX - 200;
            segundaRaiz = verticeX + 200;

            std::cout << "Raiz 1: " << metodoNewton(primeraRaiz, a, b, c, 100) << std::endl;
            std::cout << "Raiz 2: " << metodoNewton(segundaRaiz, a, b, c, 100) << std::endl;
        }
        break;

        case 2:
        {
            std::cout << "Ingrese N para la matriz (N x N): " << std::endl;
            int NdeMatriz, numeroGeneradoRandom = 0;
            std::cin >> NdeMatriz;
            double matriz[NdeMatriz][NdeMatriz];

            //llenado de matriz con nums randoms
            for (int i = 0; i < NdeMatriz; i++)
            {
                for (int j = 0; j < NdeMatriz; j++)
                {
                    numeroGeneradoRandom = 10 + rand() % (90);
                    matriz[i][j] = numeroGeneradoRandom;
                }
            }

            //imprimiendo matriz generada por numeros randoms
            cout << "La matriz generada es: " << endl;
            for (int i = 0; i < NdeMatriz; i++)
            {
                for (int j = 0; j < NdeMatriz; j++)
                {
                    std::cout << setw(2) << " [" << matriz[i][j] << "] ";
                }
                std::cout << "" << std::endl;
            }

            //suma de todos los datos de la matriz
            int sumaParaPromedio = 0;

            for (int i = 0; i < NdeMatriz; i++)
            {
                for (int j = 0; j < NdeMatriz; j++)
                {
                    sumaParaPromedio = sumaParaPromedio + matriz[i][j];
                }
            }

            //Saco la media de los datos
            double mediaDatosMatriz = (sumaParaPromedio) / (NdeMatriz);
            int sumaParaMedia = 0;

            for (int i = 0; i < NdeMatriz; i++)
            {
                for (int j = 0; j < NdeMatriz; j++)
                {
                    sumaParaMedia = (sumaParaMedia) + (pow((matriz[i][j] - mediaDatosMatriz), 2));
                }
            }

            //datos normalizados
            double desviacionEstandar = (sumaParaMedia) / ((pow(NdeMatriz, 2)));
            for (int i = 0; i < NdeMatriz; i++)
            {
                for (int j = 0; j < NdeMatriz; j++)
                {
                    matriz[i][j] = (matriz[i][j] - mediaDatosMatriz) / (desviacionEstandar);
                }
            }

            //imprimiendo matriz resultante
            std::cout << "La matriz normalizada es: " << std::endl;
            for (int i = 0; i < NdeMatriz; i++)
            {
                for (int j = 0; j < NdeMatriz; j++)
                {
                    std::cout << setw(6) << " [" << matriz[i][j] << "] ";
                }
                std::cout << "" << std::endl;
            }
        }
        break;

        case 3:
        {
            std::cout << "Ingrese el valor de n a aproximar a Pi: " << std::endl;
            double limite;
            std::cin >> limite;
            pie(limite, 0, 0);
        }
        break;
        default:
            return (0);
            break;
        }
    }
}