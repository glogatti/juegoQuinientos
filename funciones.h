#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//DECLARACION DE FUNCIONES
void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

int sumaVector(int v[], int tam); /// suma los valores contenidos en el vector

int contarNumerosRepetidos(int v[], int numero, int tam);///cuenta la cantidad de veces que se repite un //número en el vector

void copiarVector(char v[], char v2[],int tam ); ///copia el vector v en v2

void dadoUno(int x, int y);


//DESARROLLO DE FUNCIONES

void dadoUno(int x, int y){
    for(x=1; x<7; x++){
        for(y=1;y<3;y++){
                rlutil::locate(x,y);
            cout<<(char)219;
        }
    }
    rlutil::locate(4+x,2+y);
    rlutil::setColor(rlutil::BLACK);
    cout<<(char)220;
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}

int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}

void copiarVector(char v[], char v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}

int sumaVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}

#endif // FUNCIONES_H_INCLUDED
