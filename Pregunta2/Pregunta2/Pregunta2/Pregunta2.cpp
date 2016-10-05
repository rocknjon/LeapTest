// Pregunta2.cpp : main project file.
//
//TOMAR ESTE CODIGO A FORMA DE PSEUDOCÓDIGO
//EMPEZAR A LEER DESDE EL MAIN Y SEGUIR EL FLUJO DE LAS FUNCIONES
//ASUMIMOS QUE NUESTROS TRIANGULOS SE ENCUENTRAN EN UN PLANO 2D
//ASUMIMOS QUE NUESTRO TRIANGULOS SON EQUILATEROS PARA SIMPLIFICAR EL CÁLCULO DE SUS VÉRTICES
#include "stdafx.h"
#include <vector>
using namespace System;
using namespace std;
typedef pair<float, float> Pf;


//Suponemos que Los triangulos se encuentran en un plano 2D

bool SameSide(Pf p1, Pf p2,Pf a,Pf b)
{
	//cp1 y cp2 representan nuestros vectores 
	//esta fórmula sale de la teoría de que si dos vectores se encuentran en el mismo lado de la linea, su producto punto será >= 0
	//de no ser el caso, el punto se encuentra fuera de la linea, es decir, fuera de nuestro triangulo.
		cp1 = CrossProduct(b - a, p1 - a) // Asuminos que la función de Producto cruzado ya está implementada
		cp2 = CrossProduct(b - a, p2 - a)
		if (DotProduct(cp1, cp2) >= 0)//asuminos que la función de producto punto ya se encuentra implementada
			return true; 
		else return false;
}

bool PointInTriangle(Pf p, Pf a, Pf  b, Pf c)
{
	if (SameSide(p, a, b, c) && SameSide(p, b, a, c) && SameSide(p, c, a, b))
	{
		return true;
	}
	else {
		return false;
	}
}

bool Line_intersection(Pf p1, Pf p2, Pf p3, Pf p4)
{
	double int_x = 0, int_y = 0;
	//tenemos los puntos de inicio y fin de 2 lineas
	//vamos a convertir esos puntos a ecuaciones Ax+By=C
	float A1, A2, B1, B2, C1, C2;
	A1 = p2.second - p1.second;
	B1 = p1.first - p2.first;
	C1 = A1*p1.first + B1*p1.second;

	A2 = p4.second - p3.second;
	B2 = p3.first - p4.first;
	C2 = A2*p3.first + B2*p3.first;
	//tenemos nuestras 2 ecuaciones
	//Ahora resolvemos esas 2 ecuaciones
	//lo primero que tenemos que hacer es ver si el determninante de esta operación es cero
	//de ser así las lineas son paralelas.

	double det = A1*B2 - A2*B1;
	if (det == 0)
	{
		//las lineas son paralelas
	}
	else
	{
		int_x = (B2*C1 - B1*C2) / det;
		int_y = (A1*C2 - A2*C1) / det;
		//esta operación devuelve la intersección de las 2 lineas que se efectua en el punto int_x, int_y
	}
	

	if (int_x != 0 && int_y != 0)
	{
		//si nuestra intersección es difertente de cero, es decir, sí existe intersección entre ambas lineas, debemos de medir si esta se encuentra
		//dentro del rango de nuestros triángulos, ya que esta funcion mide las lineas como si fueran infinitas.

		float menor_x,menor_y,mayor_x,mayor_y ; //asumimos que ya calculamos los valores mayores y menores de X y Y.
		if (int_x < mayor_x && int_x > menor_x && int_y < mayor_y && int_y > menor_y)
		{
			//entonces se encuentra en el rango delimitado por nuestras lineas.
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		//no existe intersección entre esas 2 lineas
		return false;
	}

}

int main()
{ 
	//TRIANGULOS
	//tenemos el punto medio (xa,ya), wa: width y ha: height
	Pf ptMedio;
	float wa, ha;
	//con esos valores hallamos los 3 puntos que conforman al triangulo
	//por motivos prácticos solo lo realizaremos con 1 triangulo
	Pf T1, T2, T3;
	//primero hallamos el vértice superior
	T1.first = ptMedio.first;
	T1.second = ptMedio.second + (0.5*ha);
	//hallamos el vértice de la derecha
	T2.first = ptMedio.first + (0.5*wa);
	T2.second = ptMedio.second - (0.5*ha);
	//hallamos el vértice de la izquierda
	T3.first = ptMedio.first - (0.5*wa);
	T3.second = ptMedio.second - (0.5*ha);
	//con esto ya tenemos nuestros 3 puntos del triangulo.

	//Para hallar si 2 triangulos han colisionado (ya que solo se puede dar colisión entre 2 objetos)
	//es necesario llamar a la funcion Line_Intersection 9 veces, haciendo la revisión para cada lado de un triangulo con todos los lados del otro.
	por cada lado (9 veces)
	{
		Line_intersection(punto1,punto2,punto3,punto4) //donde punto 1 y 2 es el inicio y fin del primer lado, y punto 3 y 4 el inicio y fin del segundo lado.
	}
	//Si luego de llamar a la función Line_Intersection para todos los lados del triangulo nos da falso, es necesario llamar a PointInTriangle
	//Esta función nos indica si es que hay un punto dentro de nuestro triangulo, en este caso la utilizamos para verificar que alguno de nuestros
	//vertices no esté en contacto con otro triangulo, ya que este contacto no aparecería en nuestra función Line_intersection.
	si(Line_intersection == false)
	{
		por cada vertice(6 veces) // revisa los 3 vertices de cada triangulo 
		{
			PointInTriangle(punto, A, B, C); // donde punto es el punto a analizar y A,B,C los puntos que conforman el triangulo.
		}
	}
	
	//si ambas funciones resultan falsas, no existe conlisión entre los triángulos.




    return 0;
}
