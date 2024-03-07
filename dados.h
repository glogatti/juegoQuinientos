#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

///DECLARACION

void dibujarCuadrado(int, int, int);

void dibujarDado(int, int, int, int);

void dibujarPuntos(int, int, int, int);

void dibujarSombra(int, int);



///IMPLEMENTACION
void dibujarCuadrado(int color, int posx, int posy){
    for(int x=1; x<=7; x++){
            switch(color){
            case 1:
                rlutil::setColor(rlutil::BLUE);
                break;
            case 2:
                rlutil::setColor(rlutil::RED);
                break;
            case 3:
                rlutil::setColor(rlutil::GREEN);
                break;
            case 4:
                rlutil::setColor(rlutil::CYAN);
                break;
            case 5:
                rlutil::setColor(rlutil::MAGENTA);
                break;
            }
        for(int y=1; y<=3; y++){
            rlutil::locate(x+posx, y+posy);
            cout<<(char)219<<endl;
        }
    }
}

void dibujarPuntos(int color, int numero, int posx, int posy){
    switch (color){
        case 1:
                rlutil::setBackgroundColor(rlutil::BLUE);
                break;
        case 2:
                rlutil::setBackgroundColor(rlutil::RED);
                break;
        case 3:
                rlutil::setBackgroundColor(rlutil::GREEN);
                break;
        case 4:
                rlutil::setBackgroundColor(rlutil::CYAN);
                break;
        case 5:
                rlutil::setBackgroundColor(rlutil::MAGENTA);
                break;
    }
    switch (numero)
    {
    case 1:
        rlutil::locate(posx+4, posy+2);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)254;
        break;
    case 2:
        rlutil::locate(posx+2, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        break;
    case 3:
        rlutil::locate(posx+4, posy+2);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)254;
        rlutil::locate(posx+2, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        break;
    case 4:
        rlutil::locate(posx+2, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        rlutil::locate(posx+2, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        break;
    case 5:
        rlutil::locate(posx+2, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+4, posy+2);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)254;
        rlutil::locate(posx+6, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        rlutil::locate(posx+2, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        break;
    case 6:
        rlutil::locate(posx+2, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+4, posy+1);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)220;
        rlutil::locate(posx+6, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        rlutil::locate(posx+2, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
        rlutil::locate(posx+4, posy+3);
        ///rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout<<(char)223;
    }

}

void dibujarSombra(int posx, int posy){
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::DARKGREY);
    for(int x=1; x<=7; x++){
        rlutil::locate(x+posx+1, posy+4);
        cout<<(char)223;
    }
    for(int y=0; y<3; y++){
        rlutil::locate(posx+8,posy+y+1);
        cout<<(char)219;
    }
}

void dibujarDado(int color, int numero, int posx, int posy){
    dibujarCuadrado(color, posx, posy);
    dibujarPuntos(color, numero, posx, posy);
    dibujarSombra(posx, posy);
}

#endif // DADOS_H_INCLUDED
