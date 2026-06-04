#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int i,j,k;


/*Imagina que estás organizando un torneo y necesitas administrar a 3 jugadores. De cada 
jugador necesitas guardar su nombre, su nivel de cuenta y su puntaje final.

Tu programa debe registrar los datos, ordenarlos de mayor a menor puntaje usando la burbuja, 
y usar una función con apuntadores para decidir si el torneo fue de "Alto Rendimiento"*/




struct jugador {
	
    string nombre;
    int nivel;
    float pfinal;
    
};

void cargadatos(jugador lista[]){
	
	for(i=0;i<3;i++){
		cout<<"ingrese el nombre del jugador # "<<i+1<<endl;cin>>lista[i].nombre;
		cout<<"ingrese nivel de la cuenta "<<endl;cin>>lista[i].nivel;
		cout<<"ingrese el puntaje final del jugador"<<endl;cin>>lista[i].pfinal;
	}
	
}



void burbuja(jugador lista[]){
    
    jugador aux;
    for(i=0;i<3;i++){ 	
    for(j=0;j<2;j++){	
    if(lista[j].pfinal<lista[j+1].pfinal){	
    aux=lista[j];	
    lista[j]=lista[j+1];
    lista[j+1]=aux;    		
    }
    } 
    }
    
}

void evaluar(jugador lista[],bool *altoren){
	
	float suma=0,promedio=0;
	
	for(i=0;i<3;i++){
		suma+=lista[i].pfinal;
		
	}
	promedio=suma/3;
	
	if(promedio>80){
		*altoren=true;
	}else{
		*altoren=false;
	}
	
	
	
}


int main(){
    
    jugador lista[3];
    cargadatos(lista);
    burbuja(lista);
    bool resultado=false;
    evaluar(lista,&resultado);
    cout<<"tabla de posiciones"<<endl;
    for(i=0;i<3;i++){	
    cout<<"lugar # "<<i+1<<" es "<<lista[i].nombre<<endl;}
    if(resultado==1){
    	cout<<"este juego si es competitivo"<<endl;
	}else{
		cout<<"este juego no es competitivo"<<endl;
	}
    
}
