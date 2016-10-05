// Pregunta 3.cpp : main project file.
//ACONTINUACIÓN SE PRESENTA UN ALGORITMO QUE DADO UN NUMERO N DE PUNTOS, LOS REPARTIRA EN UNA SEMI CIRCUNFERENCIA DE RADIO R CON CENTRO EN P
//DE FORMA EQUITATIVA.
//SE ASUME QUE CONTAMOS CON LAS FUNCIONES GRAFICAS PARA PODER REALIZAR EL DIBUJADO DE LOS PUNTOS
#include "stdafx.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	float rad;//Radio de la circunferencia
	int Px, Py; //punto de inicio, centro del círculo
	int n;//número de puntos
	float steep = pi / (n - 2); //cada cuanto va a dibujar, se le resta 2 por que esos son los puntos fijos de arriba y abajo del semicirculo.
	//Asumimos que tenemos definido Pi
	for (float radians = Pi / 2; radians<(3 * pi / 2); radians += steep)//empieza en pi/2 que es arriba, y va hasta 3pi/2 que es abajo de la circunferencia
	{
		float x = rad*cos(radians); //se calcula la coordenada X y Y donde se va a dibujar el punto
		float y = rad*sin(radians);

		Draw_Point(Px + x, Py + y); //asumimos que la función pinta un punto en la coordenada indicada.
	}
	return 0;
}
