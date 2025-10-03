#include <iostream>
#include <limits>
#include <cmath>
#include <string>


using namespace std;

// FUNCIONES 

// FUNCION PARA INGRESAR LAS TEMPERATURAS (pide al usuario ingresar las 12 temperaturas de un departamento y las guarda en el vector temperaturas, se utiliza void porque la funcion no devuelve nada.)
void ingreso(double temperaturas[12], string departamento) { 
	for (int i = 0; i < 12; i++) {
		cout << "Ingrese la temperatura del mes " << i + 1 << " del departamento " << departamento << ": ";
		cin >> temperaturas[i];
	}
}

// FUNCION PARA CALCULAR EL PROMEDIO ANUAL DE CADA DEPARTAMENTO (recibe el vector de temperaturas y devuelve el promedio anual como un valor double)
double promedioanual(double temperaturas[12]) {
	double suma = 0;
	for (int i = 0; i < 12; i++) {
		suma += temperaturas[i];
	}
	return suma / 12;
}

// FUNCION PARA DETERMINAR EL PROMEDIO NACIONAL (recibe los promedios anuales de los tres departamentos y devuelve el promedio nacional como un valor double)

double promedioNacional(double promSa, double promNa, double promGua) {
	return (promSa + promNa + promGua) / 3;
}

// FUNCION PARA DETERMINAR EL MES MAS CALIENTE (recibe el vector de temperaturas y devuelve el mes con la temperatura más alta)
int mesmascaliente(double temperaturas[12]) {
	int mes = 0;
	double mayortemp = temperaturas[0];
	for (int i = 1; i < 12; i++) {
		if (temperaturas[i] > mayortemp) {
			mayortemp = temperaturas[i];
			mes = i;
		}
	}
	return mes;
}
// FUNCION PARA DETERMINAR EL PROMEDIO DE LOS PICOS (recibe los vectores de temperaturas de los tres departamentos y toma el valor máximo de cada departamento devolviendo el promedio de las tres temperaturas más altas)
double promediopicos(double santander[12], double narino[12], double guajira[12]) {
	double picoSa = santander[0], picoNa = narino[0], picoGua = guajira[0];
	for (int i = 1; i < 12; i++) {
		if (santander[i] > picoSa) 
			picoSa = santander[i];
		if (narino[i] > picoNa) 
			picoNa = narino[i];
		if (guajira[i] > picoGua) 
			picoGua = guajira[i];
	}
	return (picoSa + picoNa + picoGua) / 3;
}
// FUNCION PARA DETERMINAR EL DEPARTAMENTO CON MAYOR PROMEDIO (recibe los promedios anuales de los tres departamentos y devuelve el departamento con el mayor promedio anual)
string mayorpromedio(double promediosantander, double promedionarino, double promedioguajira) {
	if (promediosantander >= promedionarino && promediosantander >= promedioguajira)
		return "Santander";
	else if (promedionarino >= promediosantander && promedionarino >= promedioguajira)
		return "Nariño";
	else 
		return "Guajira";
}
// FUNCION PARA DETERMINAR LA TEMPERATURA MAXIMA ANUAL GLOBAL (recibe los vectores de temperaturas de los tres departamentos y devuelve la temperatura máxima, el departamento y el mes en que ocurrió)

double TempMaxAnual(double Sa[12], double Na[12], double Gua[12]) {
	double max = Sa[0];
	int mes = 1;
	string departamento = "Santander";

	for (int i = 0; i < 12; i++) {
		if (Sa[i] > max) {
			max = Sa[i];
			mes = i + 1;
			departamento = "Santander";
		}
		if (Na[i] > max) {
			max = Na[i];
			mes = i + 1;
			departamento = "Nariño";
		}
		if (Gua[i] > max) {
			max = Gua[i];
			mes = i + 1;
			departamento = "Guajira";
		}
	}

	// Aquí mismo se imprime el resultado completo
	cout << "El mes más cálido del año fue el mes " << mes << " en el departamento de " << departamento << " con una temperatura de: " << max << " °C" << endl;

	return max; // devuelve solo la temperatura máxima
}

// FUNCION DESVIACION ESTANDAR (recibe el vector de temperaturas y devuelve la desviación estándar de las temperaturas como un valor double)
double desviacionestandar(double temperaturas[12], double promedio) {
	double suma = 0;
	for (int i = 0; i < 12; i++) {
		suma += (temperaturas[i] - promedio) * (temperaturas[i] - promedio);
	}
	return sqrt(suma / 12);
}
int main() {
	// VARIABLES

	double vectorSa[12], vectorNa[12], vectorGua[12];
	
	//LLAMAR LAS FUNCIO0NES EN MAIN

	// INGRESO DE DATOS
	ingreso(vectorSa, "Santander");
	ingreso(vectorNa, "Nariño");
	ingreso(vectorGua, "Guajira");
	// PROMEDIOS POR DEPARTAMENTO
	double promSa = promedioanual(vectorSa);
	double promNa = promedioanual(vectorNa);
	double promGua = promedioanual(vectorGua);
	// PROMEDIO NACIONAL
	double promNacional = promedioNacional(promSa, promNa, promGua);
	// MES MÁS CALIENTE POR DEPARTAMENTO
	int mesSa = mesmascaliente(vectorSa);
	int mesNa = mesmascaliente(vectorNa);
	int mesGua = mesmascaliente(vectorGua);
	// PROMEDIO DE LOS PICOS
	double promPicos = promediopicos(vectorSa, vectorNa, vectorGua);
	// DEPARTAMENTO CON MAYOR PROMEDIO
	string deptoMayor = mayorpromedio(promSa, promNa, promGua);
	// TEMPERATURA MAXIMA ANUAL GLOBAL SE LLAMA EN EL INFORME DE RESULTADOS
	// DESVIACION ESTANDAR POR DEPARTAMENTO
	double desvSa = desviacionestandar(vectorSa, promSa);
	double desvNa = desviacionestandar(vectorNa, promNa);
	double desvGua = desviacionestandar(vectorGua, promGua);

	// INFORME DE RESULTADOS 
	cout << "===== INFORME METEOROLÓGICO =====" << endl;
	cout << "Promedio anual Santander: " << promSa << " °C" << endl;
	cout << "Promedio anual Nariño: " << promNa << " °C" << endl;
	cout << "Promedio anual Guajira: " << promGua << " °C" << endl;
	cout << "Promedio nacional: " << promNacional << " °C" << endl;
	cout << "Mes más caliente en Santander: " << mesSa + 1 << endl;
	cout << "Mes más caliente en Nariño: " << mesNa + 1 << endl;
	cout << "Mes más caliente en Guajira: " << mesGua + 1 << endl;
	cout << "Promedio de los picos: " << promPicos << " °C" << endl;
	cout << "Departamento con mayor promedio anual: " << deptoMayor << endl;
	TempMaxAnual(vectorSa, vectorNa, vectorGua);
	cout << "Desviación estándar anual Santander: " << desvSa << endl;
	cout << "Desviación estándar anual Nariño: " << desvNa << endl;
	cout << "Desviación estándar anual Guajira: " << desvGua << endl;
	
}
