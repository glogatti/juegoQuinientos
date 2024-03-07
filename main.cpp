#include <iostream>
#include<ctime>

using namespace std;
#include"rlutil.h"
#include"funciones.h"
#include"dados.h"

int main()
{
    int y=0, j, posicionDado, color, menuColor = 0;
    int jug1, jug2;
    const int TAM = 6;
    char nombre1[20], apellido1[20], nombre2[20], apellido2[20], nombGanador[20], apeGanador[20];
    int maximaPuntuacion = 0, maximoIntento = 0;
    int dados[TAM];
    int uno, dos, tres, cuatro, cinco, seis;
    int puntosAcumulados = 0, puntos = 0, puntosAcumulados1, puntosAcumulados2;
    int ronda = 0, intento = 0, rondaGanadora = 0, restante;
    char salida;
    bool menu = true;
    bool ganador = false;
    bool dosJugadores = true;
    rlutil::hidecursor();
    while(menu){
        ronda = 0;
        rlutil::locate(5,2);
        cout<<"BIENVENIDOS AL JUEGO QUINIENTOS/ESCALERA!"<<endl;
        rlutil::locate(20,3);
        cout<<"--MENU--"<<endl;
        rlutil::locate(7,4);
        cout<<"-(UTILICE LAS FLECHAS PARA NAVEGAR)-"<<endl;
        rlutil::locate(7,5);
        cout<<"1 JUGADOR"<<endl;
        rlutil::locate(7,6);
        cout<<"2 JUGADORES"<<endl;
        rlutil::locate(7,7);
        cout<<"PUNTUACION MAS ALTA"<<endl;
        rlutil::locate(7,8);
        cout<<"SALIR"<<endl;
        //cursor selector
        rlutil::locate(5,5+y);
        cout<<(char)175<<endl;
        rlutil::locate(30,5+y);
        cout<<(char)174<<endl;
        //mover el cursor
        int key = rlutil::getkey();
        switch(key){
        case 14: //SUBIR
            rlutil::locate(5,5+y);
            cout<<" "<<endl;
            rlutil::locate(30,5+y);
            cout<<" "<<endl;
            y--;
            if(y<0) y = 0;
            break;
        case 15: //BAJAR
            rlutil::locate(5,5+y);
            cout<<" "<<endl;
            rlutil::locate(30,5+y);
            cout<<" "<<endl;
            y++;
            if(y>3) y = 3;
            break;
        case 1: //ENTER
            switch(y){
            case 0: //MODO 1 JUGADOR
                system("cls");
                rlutil::setBackgroundColor(rlutil::BLUE);
                cout<<"USTED HA SELECCIONADO EL MODO 1 JUGADOR!"<<endl;
                cout<<"POR FAVOR INGRESE SU NOMBRE:"<<endl;
                cin>>nombre1;
                cout<<"POR FAVOR INGRESE SU APELLIDO:"<<endl;
                cin>>apellido1;
                rlutil::setBackgroundColor(rlutil::BLACK);
                system("cls");
                puntosAcumulados = 0;
                cout<<"SELECCIONE EL COLOR DE LOS DADOS: "<<endl;
                cout<<"(Ingrese un numero para seleccionar el color)"<<endl;
                rlutil::setBackgroundColor(rlutil::BLUE);
                cout<<"1.- AZUL" <<endl;
                rlutil::setBackgroundColor(rlutil::RED);
                cout<<"2.- ROJO" <<endl;
                rlutil::setBackgroundColor(rlutil::GREEN);
                cout<<"3.- VERDE" <<endl;
                rlutil::setBackgroundColor(rlutil::CYAN);
                cout<<"4.- CYAN" <<endl;
                rlutil::setBackgroundColor(rlutil::MAGENTA);
                cout<<"5.- MAGENTA" <<endl;
                rlutil::setBackgroundColor(rlutil::BLACK);
                cin>>color;

                while(puntosAcumulados<500){
                    system("cls");
                    ronda++;
                    for(intento=1;intento<=3;intento++){
                        cout<<"TURNO DE: "<<nombre1<<" "<< apellido1<<" | ";
                        cout<<" RONDA: "<< ronda<< " | "<<" PUNTAJE: "<<puntosAcumulados<<endl;
                        cout<<"LANZAMIENTO N° "<<intento<<endl;
                        cout<<"------------------------------------------------" <<endl;
                        //LANZAMIENTO DE DADOS
                        cargarAleatorio(dados,TAM,6);
                        ///mostrarVector(dados,TAM);
                        posicionDado = 0;
                        for(j=0;j<6;j++){
                            dibujarDado(color, dados[j], posicionDado, 4);
                            posicionDado+=10;
                        }
                        cout<<endl;

                        uno = contarNumerosRepetidos(dados,1,TAM);
                        dos = contarNumerosRepetidos(dados,2,TAM);
                        tres = contarNumerosRepetidos(dados,3,TAM);
                        cuatro = contarNumerosRepetidos(dados,4,TAM);
                        cinco = contarNumerosRepetidos(dados,5,TAM);
                        seis = contarNumerosRepetidos(dados,6,TAM);

                        //ANALISIS DE LA JUGADA
                        if(uno==1 && dos==1 && tres==1 && cuatro==1 && cinco==1 && seis==1){
                            cout<<endl;
                            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                            rlutil::setColor(rlutil::BLACK);
                            cout<<"SACASTE ESCALERA! PONETE A FESTEJAR QUE GANASTE!!"<<endl;
                            intento+=3;
                            restante = 500 - puntosAcumulados;
                            maximoIntento = restante;
                            rlutil::setBackgroundColor(rlutil::BLACK);
                            rlutil::setColor(rlutil::WHITE);

                            if(ronda<rondaGanadora){
                                copiarVector(nombre1,nombGanador,20);
                                copiarVector(apellido1,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                                maximaPuntuacion = 500;
                            }

                        }
                            else if(seis==6){
                                cout<<endl;
                                rlutil::setBackgroundColor(rlutil::WHITE);
                                rlutil::setColor(rlutil::BLACK);
                                cout<<"MAL AHI! SEXTETO6-- PERDISTE LOS PUNTOS DE LA RONDA"<<endl;
                                maximoIntento = 0;
                                intento += 3;
                                rlutil::setBackgroundColor(rlutil::BLACK);
                                rlutil::setColor(rlutil::WHITE);
                            }
                                else if(seis>2){
                                    cout<<endl;
                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                    rlutil::setColor(rlutil::BLACK);
                                    cout<<"TRIO 6++ | 60 PUNTOS!"<<endl;
                                    puntos = 60;
                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                    rlutil::setColor(rlutil::WHITE);
                                }
                                else if(cinco==6){
                                    cout<<endl;
                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                    rlutil::setColor(rlutil::BLACK);
                                    cout<<"SEXTETO 5++ | 250 PUNTOS!"<<endl;
                                    puntos = 250;
                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                    rlutil::setColor(rlutil::WHITE);
                                }
                                    else if(cinco>2){
                                        cout<<endl;
                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                        rlutil::setColor(rlutil::BLACK);
                                        cout<<"TRIO 5++ | 50 PUNTOS!"<<endl;
                                        puntos = 50;
                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                        rlutil::setColor(rlutil::WHITE);
                                    }
                                    else if(cuatro==6){
                                        cout<<endl;
                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                        rlutil::setColor(rlutil::BLACK);
                                        cout<<"SEXTETO 4++ | 200 PUNTOS!"<<endl;
                                        puntos = 200;
                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                        rlutil::setColor(rlutil::WHITE);
                                    }
                                        else if(cuatro>2){
                                            cout<<endl;
                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                            rlutil::setColor(rlutil::BLACK);
                                            cout<<"TRIO 4++ | 40 PUNTOS!"<<endl;
                                            puntos = 40;
                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                            rlutil::setColor(rlutil::WHITE);
                                        }
                                        else if(tres==6){
                                            cout<<endl;
                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                            rlutil::setColor(rlutil::BLACK);
                                            cout<<"SEXTETO 3++ | 150 PUNTOS!"<<endl;
                                            puntos = 150;
                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                            rlutil::setColor(rlutil::WHITE);
                                        }
                                            else if(tres>2){
                                                cout<<endl;
                                                rlutil::setBackgroundColor(rlutil::WHITE);
                                                rlutil::setColor(rlutil::BLACK);
                                                cout<<"TRIO 3++ | 30 PUNTOS!"<<endl;
                                                puntos = 30;
                                                rlutil::setBackgroundColor(rlutil::BLACK);
                                                rlutil::setColor(rlutil::WHITE);
                                            }
                                            else if(dos==6){
                                                cout<<endl;
                                                rlutil::setBackgroundColor(rlutil::WHITE);
                                                rlutil::setColor(rlutil::BLACK);
                                                cout<<"SEXTETO 2++ | 100 PUNTOS!"<<endl;
                                                puntos = 100;
                                                rlutil::setBackgroundColor(rlutil::BLACK);
                                                rlutil::setColor(rlutil::WHITE);
                                            }
                                                else if(dos>2){
                                                    cout<<endl;
                                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                                    rlutil::setColor(rlutil::BLACK);
                                                    cout<<"TRIO 2++ | 20 PUNTOS!"<<endl;
                                                    puntos = 20;
                                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                                    rlutil::setColor(rlutil::WHITE);
                                                }
                                                else if(uno==6){
                                                    cout<<endl;
                                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                                    rlutil::setColor(rlutil::BLACK);
                                                    cout<<"SEXTETO 1++ | 50 PUNTOS!"<<endl;
                                                    puntos = 50;
                                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                                    rlutil::setColor(rlutil::WHITE);
                                                }
                                                    else if(uno>2){
                                                        cout<<endl;
                                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                                        rlutil::setColor(rlutil::BLACK);
                                                        cout<<"TRIO 1++ | 10 PUNTOS!"<<endl;
                                                        puntos = 10;
                                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                                        rlutil::setColor(rlutil::WHITE);
                                                    }

                                                        else{
                                                            puntos = sumaVector(dados,TAM);
                                                            cout<<endl;
                                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                                            rlutil::setColor(rlutil::BLACK);
                                                            cout<<"SUMA DE DADOS | "<<puntos<<" PUNTOS!"<<endl;
                                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                                            rlutil::setColor(rlutil::WHITE);
                                                        }

                        cout<<endl;
                        system("pause");
                        system("cls");
                        if(puntos>maximoIntento) maximoIntento = puntos;
                    }
                    puntosAcumulados += maximoIntento;
                    cout<<"RONDA N°" <<ronda<<" DE "<<nombre1<<" " <<apellido1 <<endl;
                    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<maximoIntento <<" PUNTOS" <<endl;
                    cout<<"PUNTAJE ACUMULADO:"<<puntosAcumulados <<endl;
                    maximoIntento = 0;

                    system("pause");
                    system("cls");
                    //LLEGADA A 500 PUNTOS
                    if(puntosAcumulados>499){

                        rlutil::setBackgroundColor(rlutil::CYAN);
                        rlutil::setColor(rlutil::BLACK);
                        cout<<"                                                 "<<endl;
                        cout<<"    GANASTE!! HICISTE UN TOTAL DE "<<puntosAcumulados<<" PUNTOS!    "<<endl;
                        cout<<"                  EN "<<ronda<<" RONDAS!                  "<<endl;
                        cout<<"                                                 "<<endl;
                        rlutil::setBackgroundColor(rlutil::BLACK);
                        rlutil::setColor(rlutil::WHITE);
                        system("pause");
                        system("cls");
                        if(ganador == false){
                                copiarVector(nombre1,nombGanador,20);
                                copiarVector(apellido1,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                                maximaPuntuacion = puntosAcumulados;
                                ganador = true;
                        }
                        else if(ronda<rondaGanadora){
                            copiarVector(nombre1,nombGanador,20);
                            copiarVector(apellido1,apeGanador,20);
                            intento+=3;
                            rondaGanadora = ronda;
                            maximaPuntuacion = puntosAcumulados;
                        }
                        else if(ronda==rondaGanadora){
                            if(puntosAcumulados>maximaPuntuacion){
                                maximaPuntuacion = puntosAcumulados;
                                copiarVector(nombre1,nombGanador,20);
                                copiarVector(apellido1,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                            }
                        }
                    }
                }

                break;
            case 1: //MODO 2 JUGADORES
                system("cls");
                cout<<"USTED HA SELECCIONADO EL MODO 2 JUGADORES!"<<endl;
                cout<<"POR FAVOR INGRESE EL NOMBRE DEL JUGADOR 1:"<<endl;
                cin>>nombre1;
                cout<<"POR FAVOR INGRESE EL APELLIDO DEL JUGADOR 1:"<<endl;
                cin>>apellido1;
                cout<<"POR FAVOR INGRESE EL NOMBRE DEL JUGADOR 2:"<<endl;
                cin>>nombre2;
                cout<<"POR FAVOR INGRESE EL APELLIDO DEL JUGADOR 2:"<<endl;
                cin>>apellido2;
                system("cls");
                cout<<"SELECCIONE EL COLOR DE LOS DADOS: "<<endl;
                cout<<"(Ingrese un numero para seleccionar el color)"<<endl;
                rlutil::setBackgroundColor(rlutil::BLUE);
                cout<<"1.- AZUL" <<endl;
                rlutil::setBackgroundColor(rlutil::RED);
                cout<<"2.- ROJO" <<endl;
                rlutil::setBackgroundColor(rlutil::GREEN);
                cout<<"3.- VERDE" <<endl;
                rlutil::setBackgroundColor(rlutil::CYAN);
                cout<<"4.- CYAN" <<endl;
                rlutil::setBackgroundColor(rlutil::MAGENTA);
                cout<<"5.- MAGENTA" <<endl;
                rlutil::setBackgroundColor(rlutil::BLACK);
                cin>>color;

                puntosAcumulados1 = 0;
                puntosAcumulados2 = 0;
                dosJugadores = true;
                while(dosJugadores){
                system("cls");
                ronda++;
                for(jug1=1;jug1<=3;jug1++){
                        cout<<"TURNO DE: "<<nombre1<<" "<< apellido1<<" | ";
                        cout<<" RONDA: "<< ronda<< " | "<<" PUNTAJE: "<<puntosAcumulados1<<endl;
                        cout<<"LANZAMIENTO N° "<<jug1<<endl;
                        cout<<"------------------------------------------------" <<endl;
                        //LANZAMIENTO DE DADOS
                        cargarAleatorio(dados,TAM,6);
                        ///mostrarVector(dados,TAM);
                        posicionDado = 0;
                        for(j=0;j<6;j++){
                            dibujarDado(color, dados[j], posicionDado, 4);
                            posicionDado+=10;
                        }
                        cout<<endl;

                        uno = contarNumerosRepetidos(dados,1,TAM);
                        dos = contarNumerosRepetidos(dados,2,TAM);
                        tres = contarNumerosRepetidos(dados,3,TAM);
                        cuatro = contarNumerosRepetidos(dados,4,TAM);
                        cinco = contarNumerosRepetidos(dados,5,TAM);
                        seis = contarNumerosRepetidos(dados,6,TAM);

                        //ANALISIS DE LA JUGADA
                        if(uno==1 && dos==1 && tres==1 && cuatro==1 && cinco==1 && seis==1){
                            cout<<endl;
                            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                            rlutil::setColor(rlutil::BLACK);
                            cout<<"SACASTE ESCALERA! PONETE A FESTEJAR QUE GANASTE!!"<<endl;
                            jug1+=3;
                            restante = 500 - puntosAcumulados1;
                            maximoIntento = restante;
                            rlutil::setBackgroundColor(rlutil::BLACK);
                            rlutil::setColor(rlutil::WHITE);

                            if(ronda<rondaGanadora){
                                copiarVector(nombre1,nombGanador,20);
                                copiarVector(apellido1,apeGanador,20);
                                jug1+=3;
                                rondaGanadora = ronda;
                                maximaPuntuacion = 500;
                            }

                        }
                            else if(seis==6){
                                cout<<endl;
                                rlutil::setBackgroundColor(rlutil::WHITE);
                                rlutil::setColor(rlutil::BLACK);
                                cout<<"MAL AHI! SEXTETO6-- PERDISTE LOS PUNTOS DE LA RONDA"<<endl;
                                maximoIntento = 0;
                                jug1 += 3;
                                rlutil::setBackgroundColor(rlutil::BLACK);
                                rlutil::setColor(rlutil::WHITE);
                            }
                                else if(seis>2){
                                    cout<<endl;
                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                    rlutil::setColor(rlutil::BLACK);
                                    cout<<"TRIO 6++ | 60 PUNTOS!"<<endl;
                                    puntos = 60;
                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                    rlutil::setColor(rlutil::WHITE);
                                }
                                else if(cinco==6){
                                    cout<<endl;
                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                    rlutil::setColor(rlutil::BLACK);
                                    cout<<"SEXTETO 5++ | 250 PUNTOS!"<<endl;
                                    puntos = 250;
                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                    rlutil::setColor(rlutil::WHITE);
                                }
                                    else if(cinco>2){
                                        cout<<endl;
                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                        rlutil::setColor(rlutil::BLACK);
                                        cout<<"TRIO 5++ | 50 PUNTOS!"<<endl;
                                        puntos = 50;
                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                        rlutil::setColor(rlutil::WHITE);
                                    }
                                    else if(cuatro==6){
                                        cout<<endl;
                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                        rlutil::setColor(rlutil::BLACK);
                                        cout<<"SEXTETO 4++ | 200 PUNTOS!"<<endl;
                                        puntos = 200;
                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                        rlutil::setColor(rlutil::WHITE);
                                    }
                                        else if(cuatro>2){
                                            cout<<endl;
                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                            rlutil::setColor(rlutil::BLACK);
                                            cout<<"TRIO 4++ | 40 PUNTOS!"<<endl;
                                            puntos = 40;
                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                            rlutil::setColor(rlutil::WHITE);
                                        }
                                        else if(tres==6){
                                            cout<<endl;
                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                            rlutil::setColor(rlutil::BLACK);
                                            cout<<"SEXTETO 3++ | 150 PUNTOS!"<<endl;
                                            puntos = 150;
                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                            rlutil::setColor(rlutil::WHITE);
                                        }
                                            else if(tres>2){
                                                cout<<endl;
                                                rlutil::setBackgroundColor(rlutil::WHITE);
                                                rlutil::setColor(rlutil::BLACK);
                                                cout<<"TRIO 3++ | 30 PUNTOS!"<<endl;
                                                puntos = 30;
                                                rlutil::setBackgroundColor(rlutil::BLACK);
                                                rlutil::setColor(rlutil::WHITE);
                                            }
                                            else if(dos==6){
                                                cout<<endl;
                                                rlutil::setBackgroundColor(rlutil::WHITE);
                                                rlutil::setColor(rlutil::BLACK);
                                                cout<<"SEXTETO 2++ | 100 PUNTOS!"<<endl;
                                                puntos = 100;
                                                rlutil::setBackgroundColor(rlutil::BLACK);
                                                rlutil::setColor(rlutil::WHITE);
                                            }
                                                else if(dos>2){
                                                    cout<<endl;
                                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                                    rlutil::setColor(rlutil::BLACK);
                                                    cout<<"TRIO 2++ | 20 PUNTOS!"<<endl;
                                                    puntos = 20;
                                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                                    rlutil::setColor(rlutil::WHITE);
                                                }
                                                else if(uno==6){
                                                    cout<<endl;
                                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                                    rlutil::setColor(rlutil::BLACK);
                                                    cout<<"SEXTETO 1++ | 50 PUNTOS!"<<endl;
                                                    puntos = 50;
                                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                                    rlutil::setColor(rlutil::WHITE);
                                                }
                                                    else if(uno>2){
                                                        cout<<endl;
                                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                                        rlutil::setColor(rlutil::BLACK);
                                                        cout<<"TRIO 1++ | 10 PUNTOS!"<<endl;
                                                        puntos = 10;
                                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                                        rlutil::setColor(rlutil::WHITE);
                                                    }

                                                        else{
                                                            puntos = sumaVector(dados,TAM);
                                                            cout<<endl;
                                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                                            rlutil::setColor(rlutil::BLACK);
                                                            cout<<"SUMA DE DADOS | "<<puntos<<" PUNTOS!"<<endl;
                                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                                            rlutil::setColor(rlutil::WHITE);
                                                        }

                        cout<<endl;
                        system("pause");
                        system("cls");
                        if(puntos>maximoIntento) maximoIntento = puntos;
                    }
                    puntosAcumulados1 += maximoIntento;
                    cout<<"RONDA N°" <<ronda<<" DE "<<nombre1<<" " <<apellido1 <<endl;
                    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<maximoIntento <<" PUNTOS" <<endl;
                    cout<<"PUNTAJE ACUMULADO:"<<puntosAcumulados1 <<endl;
                    system("pause");
                    system("cls");


                    cout<<"RONDA N°" <<ronda<<endl;
                    cout<<"PROXIMO TURNO: "<<nombre2 <<endl;
                    cout<<endl;
                    cout<<"PUNTAJE DE "<<nombre1<<": "<<puntosAcumulados1<<" PUNTOS"<<endl;
                    cout<<"PUNTAJE DE "<<nombre2<<": "<<puntosAcumulados2<<" PUNTOS"<<endl;

                    maximoIntento = 0;

                    system("pause");
                    system("cls");


                for(jug2=1;jug2<=3;jug2++){
                        cout<<"TURNO DE: "<<nombre2<<" "<< apellido2<<" | ";
                        cout<<" RONDA: "<< ronda<< " | "<<" PUNTAJE: "<<puntosAcumulados2<<endl;
                        cout<<"LANZAMIENTO N° "<<jug2<<endl;
                        cout<<"------------------------------------------------" <<endl;
                        //LANZAMIENTO DE DADOS
                        cargarAleatorio(dados,TAM,6);
                        ///mostrarVector(dados,TAM);
                        posicionDado = 0;
                        for(j=0;j<6;j++){
                            dibujarDado(color, dados[j], posicionDado, 4);
                            posicionDado+=10;
                        }
                        cout<<endl;

                        uno = contarNumerosRepetidos(dados,1,TAM);
                        dos = contarNumerosRepetidos(dados,2,TAM);
                        tres = contarNumerosRepetidos(dados,3,TAM);
                        cuatro = contarNumerosRepetidos(dados,4,TAM);
                        cinco = contarNumerosRepetidos(dados,5,TAM);
                        seis = contarNumerosRepetidos(dados,6,TAM);

                        //ANALISIS DE LA JUGADA
                        if(uno==1 && dos==1 && tres==1 && cuatro==1 && cinco==1 && seis==1){
                            cout<<endl;
                            rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
                            rlutil::setColor(rlutil::BLACK);
                            cout<<"SACASTE ESCALERA! PONETE A FESTEJAR QUE GANASTE!!"<<endl;
                            jug2+=3;
                            restante = 500 - puntosAcumulados2;
                            maximoIntento = restante;
                            rlutil::setBackgroundColor(rlutil::BLACK);
                            rlutil::setColor(rlutil::WHITE);

                            if(ronda<rondaGanadora){
                                copiarVector(nombre2,nombGanador,20);
                                copiarVector(apellido2,apeGanador,20);
                                jug2+=3;
                                rondaGanadora = ronda;
                                maximaPuntuacion = 500;
                            }

                        }
                            else if(seis==6){
                                cout<<endl;
                                rlutil::setBackgroundColor(rlutil::WHITE);
                                rlutil::setColor(rlutil::BLACK);
                                cout<<"MAL AHI! SEXTETO6-- PERDISTE LOS PUNTOS DE LA RONDA"<<endl;
                                maximoIntento = 0;
                                jug2 += 3;
                                rlutil::setBackgroundColor(rlutil::BLACK);
                                rlutil::setColor(rlutil::WHITE);
                            }
                                else if(seis>2){
                                    cout<<endl;
                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                    rlutil::setColor(rlutil::BLACK);
                                    cout<<"TRIO 6++ | 60 PUNTOS!"<<endl;
                                    puntos = 60;
                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                    rlutil::setColor(rlutil::WHITE);
                                }
                                else if(cinco==6){
                                    cout<<endl;
                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                    rlutil::setColor(rlutil::BLACK);
                                    cout<<"SEXTETO 5++ | 250 PUNTOS!"<<endl;
                                    puntos = 250;
                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                    rlutil::setColor(rlutil::WHITE);
                                }
                                    else if(cinco>2){
                                        cout<<endl;
                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                        rlutil::setColor(rlutil::BLACK);
                                        cout<<"TRIO 5++ | 50 PUNTOS!"<<endl;
                                        puntos = 50;
                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                        rlutil::setColor(rlutil::WHITE);
                                    }
                                    else if(cuatro==6){
                                        cout<<endl;
                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                        rlutil::setColor(rlutil::BLACK);
                                        cout<<"SEXTETO 4++ | 200 PUNTOS!"<<endl;
                                        puntos = 200;
                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                        rlutil::setColor(rlutil::WHITE);
                                    }
                                        else if(cuatro>2){
                                            cout<<endl;
                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                            rlutil::setColor(rlutil::BLACK);
                                            cout<<"TRIO 4++ | 40 PUNTOS!"<<endl;
                                            puntos = 40;
                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                            rlutil::setColor(rlutil::WHITE);
                                        }
                                        else if(tres==6){
                                            cout<<endl;
                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                            rlutil::setColor(rlutil::BLACK);
                                            cout<<"SEXTETO 3++ | 150 PUNTOS!"<<endl;
                                            puntos = 150;
                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                            rlutil::setColor(rlutil::WHITE);
                                        }
                                            else if(tres>2){
                                                cout<<endl;
                                                rlutil::setBackgroundColor(rlutil::WHITE);
                                                rlutil::setColor(rlutil::BLACK);
                                                cout<<"TRIO 3++ | 30 PUNTOS!"<<endl;
                                                puntos = 30;
                                                rlutil::setBackgroundColor(rlutil::BLACK);
                                                rlutil::setColor(rlutil::WHITE);
                                            }
                                            else if(dos==6){
                                                cout<<endl;
                                                rlutil::setBackgroundColor(rlutil::WHITE);
                                                rlutil::setColor(rlutil::BLACK);
                                                cout<<"SEXTETO 2++ | 100 PUNTOS!"<<endl;
                                                puntos = 100;
                                                rlutil::setBackgroundColor(rlutil::BLACK);
                                                rlutil::setColor(rlutil::WHITE);
                                            }
                                                else if(dos>2){
                                                    cout<<endl;
                                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                                    rlutil::setColor(rlutil::BLACK);
                                                    cout<<"TRIO 2++ | 20 PUNTOS!"<<endl;
                                                    puntos = 20;
                                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                                    rlutil::setColor(rlutil::WHITE);
                                                }
                                                else if(uno==6){
                                                    cout<<endl;
                                                    rlutil::setBackgroundColor(rlutil::WHITE);
                                                    rlutil::setColor(rlutil::BLACK);
                                                    cout<<"SEXTETO 1++ | 50 PUNTOS!"<<endl;
                                                    puntos = 50;
                                                    rlutil::setBackgroundColor(rlutil::BLACK);
                                                    rlutil::setColor(rlutil::WHITE);
                                                }
                                                    else if(uno>2){
                                                        cout<<endl;
                                                        rlutil::setBackgroundColor(rlutil::WHITE);
                                                        rlutil::setColor(rlutil::BLACK);
                                                        cout<<"TRIO 1++ | 10 PUNTOS!"<<endl;
                                                        puntos = 10;
                                                        rlutil::setBackgroundColor(rlutil::BLACK);
                                                        rlutil::setColor(rlutil::WHITE);
                                                    }

                                                        else{
                                                            puntos = sumaVector(dados,TAM);
                                                            cout<<endl;
                                                            rlutil::setBackgroundColor(rlutil::WHITE);
                                                            rlutil::setColor(rlutil::BLACK);
                                                            cout<<"SUMA DE DADOS | "<<puntos<<" PUNTOS!"<<endl;
                                                            rlutil::setBackgroundColor(rlutil::BLACK);
                                                            rlutil::setColor(rlutil::WHITE);
                                                        }

                        cout<<endl;
                        system("pause");
                        system("cls");
                        if(puntos>maximoIntento) maximoIntento = puntos;
                    }
                    puntosAcumulados2 += maximoIntento;
                    cout<<"RONDA N°" <<ronda<<" DE "<<nombre2<<" " <<apellido2 <<endl;
                    cout<<"MAXIMO PUNTAJE DE LA RONDA: "<<maximoIntento <<" PUNTOS" <<endl;
                    cout<<"PUNTAJE ACUMULADO:"<<puntosAcumulados2 <<endl;
                    system("pause");
                    system("cls");

                    cout<<"RONDA N°" <<ronda<<endl;
                    cout<<"PROXIMO TURNO: "<<nombre1 <<endl;
                    cout<<endl;
                    cout<<"PUNTAJE DE "<<nombre1<<": "<<puntosAcumulados1<<" PUNTOS"<<endl;
                    cout<<"PUNTAJE DE "<<nombre2<<": "<<puntosAcumulados2<<" PUNTOS"<<endl;

                    maximoIntento = 0;

                    system("pause");
                    system("cls");

                    //LLEGADA A 500 PUNTOS
                    if(puntosAcumulados1>499){
                            dosJugadores = false;

                        rlutil::setBackgroundColor(rlutil::CYAN);
                        rlutil::setColor(rlutil::BLACK);
                        cout<<"                                                 "<<endl;
                        cout<<"    GANASTE!! HICISTE UN TOTAL DE "<<puntosAcumulados1<<" PUNTOS!    "<<endl;
                        cout<<"                  EN "<<ronda<<" RONDAS!                  "<<endl;
                        cout<<"                                                 "<<endl;
                        rlutil::setBackgroundColor(rlutil::BLACK);
                        rlutil::setColor(rlutil::WHITE);
                        system("pause");
                        system("cls");
                        if(ganador == false){
                                copiarVector(nombre1,nombGanador,20);
                                copiarVector(apellido1,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                                maximaPuntuacion = puntosAcumulados1;
                                ganador = true;
                        }
                        else if(ronda<rondaGanadora){
                            copiarVector(nombre1,nombGanador,20);
                            copiarVector(apellido1,apeGanador,20);
                            intento+=3;
                            rondaGanadora = ronda;
                            maximaPuntuacion = puntosAcumulados1;
                        }
                        else if(ronda==rondaGanadora){
                            if(puntosAcumulados>maximaPuntuacion){
                                maximaPuntuacion = puntosAcumulados1;
                                copiarVector(nombre1,nombGanador,20);
                                copiarVector(apellido1,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                            }
                        }
                    }
                    else if(puntosAcumulados2>499){
                            dosJugadores = false;

                        rlutil::setBackgroundColor(rlutil::CYAN);
                        rlutil::setColor(rlutil::BLACK);
                        cout<<"                                                 "<<endl;
                        cout<<"    GANASTE!! HICISTE UN TOTAL DE "<<puntosAcumulados2<<" PUNTOS!    "<<endl;
                        cout<<"                  EN "<<ronda<<" RONDAS!                  "<<endl;
                        cout<<"                                                 "<<endl;
                        rlutil::setBackgroundColor(rlutil::BLACK);
                        rlutil::setColor(rlutil::WHITE);
                        system("pause");
                        system("cls");
                        if(ganador == false){
                                copiarVector(nombre2,nombGanador,20);
                                copiarVector(apellido2,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                                maximaPuntuacion = puntosAcumulados2;
                                ganador = true;
                        }
                        else if(ronda<rondaGanadora){
                            copiarVector(nombre2,nombGanador,20);
                            copiarVector(apellido2,apeGanador,20);
                            intento+=3;
                            rondaGanadora = ronda;
                            maximaPuntuacion = puntosAcumulados2;
                        }
                        else if(ronda==rondaGanadora){
                            if(puntosAcumulados>maximaPuntuacion){
                                maximaPuntuacion = puntosAcumulados2;
                                copiarVector(nombre2,nombGanador,20);
                                copiarVector(apellido2,apeGanador,20);
                                intento+=3;
                                rondaGanadora = ronda;
                            }
                        }
                    }
                }




                break;
            case 2: //PUNTUACION MAS ALTA
                system("cls");
                if(maximaPuntuacion == 0){
                    cout<<"AUN NO SE HA JUGADO NINGUNA PARTIDA!"<<endl;
                }
                else{
                    cout<<"LA PUNTUACION MAXIMA ES: "<<maximaPuntuacion<< " PUNTOS"<<endl;
                    cout<<"OBTENIDA POR: "<<nombGanador<<" "<<apeGanador<<endl;
                    cout<<"EN "<<rondaGanadora<<" RONDAS"<<endl;
                }
                system("pause");
                system("cls");
                break;
            case 3: //SALIR
                rlutil::setBackgroundColor(rlutil::RED);
                rlutil::setColor(rlutil::BLACK);
                cout<<"ESTA SEGURO QUE DESEA SALIR DEL JUEGO? S/N"<<endl;
                rlutil::setBackgroundColor(rlutil::BLACK);
                rlutil::setColor(rlutil::WHITE);
                cin>>salida;
                switch(salida){
                    case 'S':
                    case 's':
                        menu = false;
                        break;
                    case 'N':
                    case 'n':
                        menu = true;
                }
                system("cls");
            break;
            }
        }
    }

    system("cls");
    rlutil::setBackgroundColor(rlutil::BLUE);

    if(maximaPuntuacion>0){
        cout<<"EL CAMPEON DE QUINIENTOS ES: "<<nombGanador<<" "<<apeGanador<<endl;
    }
    cout<<"GRACIAS POR JUGAR QUINIENTOS!"<<endl;
    cout<<"Juego desarrollado por Gustavo Logatti"<<endl;
    cout<<"Para TP Integrador de Laboratorio 1 2C 2023" <<endl;
    cout<<"DNI: 36288255" <<endl;
    cout<<"Legajo 27582" <<endl;


    return 0;
}
