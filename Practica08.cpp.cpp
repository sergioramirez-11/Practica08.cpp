#include <iostream>
#define MaxTamC 10

typedef int TipoDato;

int main() {
	int frente = 0, final = 0;
	TipoDato A[MaxTamC];
	int contador = 0;

	//Inicializar la cola
	frente = 0;
	final = 0;

	std::cout << "¿Desea agregar elementos a la cola? (s/n): ";
	char respuesta;
	std::cin >> respuesta;

	while ((respuesta == 's' || respuesta == 's') && contador < 10) {
		if ((final + 1) % MaxTamC == frente) {
			std::cout << "Desbordamiento de la cola" << std::endl;
			return 1;
		}

		std::cout << "Ingrese un elemento para la cola: ";
		TipoDato elemento;
		std::cin >> elemento;

		final = (final + 1) % MaxTamC;
		A[final] = elemento;

		contador++;
		std::cout << "Elemento " << contador << "Agregado a la cola: " << elemento << std::endl;

		if (contador < 10) {
			std::cout << "¿Desea agregar mas elementos a la cola? (s/n): ";
			std::cin >> respuesta;
		}
	}

	//Validar si la cola esta vacia
	if (frente == final) {
		std::cout << "La cola esta vacia" << std::endl;
		return 1;
	}

	//Obtener  el primer elemento de la cola
	TipoDato primerElemento = A[(frente + 1) % MaxTamC];
	std::cout << "El primer elemento de la cola es: " << primerElemento << std::endl;

	//Eliminar un elemento de la cola
	frente = (frente + 1) % MaxTamC;

	//Imprimir elementos de la cola en el orden que en que fueron ingresados
	std::cout << "Elementos de la cola en el orden de ingreso:" << std::endl;
	for (int i = frente + 1; i <= final; i = (i + 1) % MaxTamC) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}