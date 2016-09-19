#include "Administrador.h"

Administrador::Administrador()
{
    //ctor
}

sf::RenderWindow window;
sf::Vector2f mouse;
sf::Texture text_aristas[23];
sf::Sprite back_aristas[23];
bool mostrarAristas[23] = {false};
char* prueba;

void Administrador::ventanaPrincipal()
{

    sf::Texture text_fondo, txt_lateral, txt_nuevaRuta, text_consultar;
    sf::Sprite back_fondo, back_lateral, back_nuevaRuta, back_consultar;

    sf::Texture txt_puntos[23];
    sf::Sprite back_puntos[23];

    window.create(sf::VideoMode(1280,680),"Transportes Inter-Urbanos");
    window.setPosition(sf::Vector2i(50,0));

    text_fondo.loadFromFile("mapa.png");
    back_fondo.setTexture(text_fondo);

    txt_lateral.loadFromFile("barra_lateral.png");
    back_lateral.setTexture(txt_lateral);
    back_lateral.setPosition(1100,0);

    txt_nuevaRuta.loadFromFile("botones/nueva_ruta.png");
    back_nuevaRuta.setTexture(txt_nuevaRuta);
    back_nuevaRuta.setPosition(1105,60);

    text_consultar.loadFromFile("botones/consultar_ruta.png");
    back_consultar.setTexture(text_consultar);
    back_consultar.setPosition(1105,130);

    ruta->llenarPuntos();
    ruta->setAdyacencias();
    ruta->setCaminos();
    ruta->rutasPosibles();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        if(utility->clickSprite(back_nuevaRuta,mouse))
        {
            crearRuta();
        }

        if(utility->clickSprite(back_consultar,mouse))
        {
            ventanaConsultarCaminos();
        }

        window.draw(back_fondo);
        window.draw(back_lateral);
        window.draw(back_nuevaRuta);
        window.draw(back_consultar);
        dibujarPuntos(txt_puntos, back_puntos);
        drawLineas();
        window.display();
    }
}

void Administrador::dibujarPuntos(sf::Texture texture[], sf::Sprite sprite[])
{
    if(!llenar)
    {
        for(int s = 0; s < 15; s++)
        {
            puntos[s] = new Puntos;
            puntos[s]->texture.loadFromFile("punto_mapa.png");
            puntos[s]->sprite.setTexture(puntos[s]->texture);
            puntos[s]->nombre_punto = ruta->puntos[s];
        }
        llenar = true;
    }


    puntos[0]->sprite.setPosition(265,185);
    window.draw(puntos[0]->sprite);

    if(utility->clickSprite(puntos[0]->sprite,mouse))
    {

    }

    puntos[1]->sprite.setPosition(465,155);
    window.draw(puntos[1]->sprite);

    if(utility->clickSprite(puntos[1]->sprite,mouse))
    {

    }

    puntos[2]->sprite.setPosition(605,135);
    window.draw(puntos[2]->sprite);

    if(utility->clickSprite(puntos[2]->sprite,mouse))
    {

    }

    puntos[3]->sprite.setPosition(405,235);
    window.draw(puntos[3]->sprite);

    if(utility->clickSprite(puntos[3]->sprite,mouse))
    {

    }

    puntos[4]->sprite.setPosition(615,285);
    window.draw(puntos[4]->sprite);

    if(utility->clickSprite(puntos[4]->sprite,mouse))
    {

    }

    puntos[5]->sprite.setPosition(400,385);
    window.draw(puntos[5]->sprite);

    if(utility->clickSprite(puntos[5]->sprite,mouse))
    {

    }

    puntos[6]->sprite.setPosition(450,400);
    window.draw(puntos[6]->sprite);

    if(utility->clickSprite(puntos[6]->sprite,mouse))
    {

    }

    puntos[7]->sprite.setPosition(400,475);
    window.draw(puntos[7]->sprite);

    if(utility->clickSprite(puntos[7]->sprite,mouse))
    {

    }

    puntos[8]->sprite.setPosition(350,460);
    window.draw(puntos[8]->sprite);

    if(utility->clickSprite(puntos[8]->sprite,mouse))
    {

    }

    puntos[9]->sprite.setPosition(335,335);
    window.draw(puntos[9]->sprite);

    if(utility->clickSprite(puntos[9]->sprite,mouse))
    {

    }

    puntos[10]->sprite.setPosition(245,355);
    window.draw(puntos[10]->sprite);

    if(utility->clickSprite(puntos[10]->sprite,mouse))
    {

    }

    puntos[11]->sprite.setPosition(180,315);
    window.draw(puntos[11]->sprite);

    if(utility->clickSprite(puntos[11]->sprite,mouse))
    {

    }

    puntos[12]->sprite.setPosition(240,265);
    window.draw(puntos[12]->sprite);

    if(utility->clickSprite(puntos[12]->sprite,mouse))
    {

    }

    puntos[13]->sprite.setPosition(145,285);
    window.draw(puntos[13]->sprite);

    if(utility->clickSprite(puntos[13]->sprite,mouse))
    {

    }

    puntos[14]->sprite.setPosition(75,325);
    window.draw(puntos[14]->sprite);

    if(utility->clickSprite(puntos[14]->sprite,mouse))
    {

    }
}

void Administrador::crearRuta()
{
    char* pasarChar;
    char* pasarChar1;
    bool controlarIngreso = true;
    sf::RenderWindow window1;
    sf::Font fuente;
    sf::Vector2f mouse1;

    sf::Texture text_fondo, text_btnSalir, text_btnCrear, text_btnBuscar, text_btnBorrar,text_btnBorrar2;
    sf::Sprite back_fondo, back_btnSalir, back_btnCrear, back_btnBuscar, back_btnBorrar,back_btnBorrar2;
    sf::Text txt_punto, txt_destino, txt_puntos1, txt_puntos2, txt_puntos3, txt_puntos4;
    sf::String nombre_punto, nombre_destino;
    string pasarString, pasarString1;

    window1.create(sf::VideoMode(600,500),"Crear Ruta");
    window1.setPosition(sf::Vector2i(150,150));
    window1.setVisible(true);

    fuente.loadFromFile("arial.ttf");

    txt_punto.setFont(fuente);
    txt_punto.setCharacterSize(30);
    txt_punto.setColor(sf::Color::Black);
    txt_punto.setStyle(sf::Text::Bold);
    txt_punto.setPosition(240,30);

    txt_destino.setFont(fuente);
    txt_destino.setCharacterSize(30);
    txt_destino.setColor(sf::Color::Black);
    txt_destino.setStyle(sf::Text::Bold);
    txt_destino.setPosition(230,345);

    txt_puntos1.setFont(fuente);
    txt_puntos1.setCharacterSize(30);
    txt_puntos1.setColor(sf::Color::Black);
    txt_puntos1.setStyle(sf::Text::Bold);
    txt_puntos1.setPosition(40,130);

    txt_puntos2.setFont(fuente);
    txt_puntos2.setCharacterSize(30);
    txt_puntos2.setColor(sf::Color::Black);
    txt_puntos2.setStyle(sf::Text::Bold);
    txt_puntos2.setPosition(40,160);

    txt_puntos3.setFont(fuente);
    txt_puntos3.setCharacterSize(30);
    txt_puntos3.setColor(sf::Color::Black);
    txt_puntos3.setStyle(sf::Text::Bold);
    txt_puntos3.setPosition(40,190);

    txt_puntos4.setFont(fuente);
    txt_puntos4.setCharacterSize(30);
    txt_puntos4.setColor(sf::Color::Black);
    txt_puntos4.setStyle(sf::Text::Bold);
    txt_puntos4.setPosition(40,220);

    text_fondo.loadFromFile("back_crearRuta.png");
    back_fondo.setTexture(text_fondo);

    text_btnSalir.loadFromFile("botones/salir.png");
    back_btnSalir.setTexture(text_btnSalir);
    back_btnSalir.setPosition(450,420);

    text_btnCrear.loadFromFile("botones/crear_ruta.png");
    back_btnCrear.setTexture(text_btnCrear);
    back_btnCrear.setPosition(250,420);

    text_btnBuscar.loadFromFile("botones/buscar.png");
    back_btnBuscar.setTexture(text_btnBuscar);
    back_btnBuscar.setPosition(500,80);

    text_btnBorrar.loadFromFile("botones/erase.png");
    back_btnBorrar.setTexture(text_btnBorrar);
    back_btnBorrar.setPosition(500,30);

    text_btnBorrar2.loadFromFile("botones/erase.png");
    back_btnBorrar2.setTexture(text_btnBorrar2);
    back_btnBorrar2.setPosition(500,340);

    while(window1.isOpen())
    {
        sf::Event event;
        while(window1.pollEvent(event))
        {
            mouse1 = window1.mapPixelToCoords(sf::Mouse::getPosition(window1));

            if(utility->clickSprite(back_btnSalir,mouse1))
            {
                imprimeCaminos();
                window1.close();
            }

            if(utility->clickSprite(back_btnCrear,mouse1))
            {
                ruta->reestablecerCaminosDirectos();
                ruta->nuevoCamino(pasarChar, pasarChar1);

                if(ruta->consultarCamino(pasarChar, pasarChar1))
                {
                    dibujarAristas(pasarChar,pasarChar1);
                    cout<<ruta->existeCamino(pasarChar,pasarChar1)<<endl;
                }
                else{
                    cout<<"Esta ruta No EXISTE!"<<endl;
                    cout<<ruta->existeCamino(pasarChar,pasarChar1)<<endl;
                    //Working Here
                }
                nombre_punto.clear();
                nombre_destino.clear();
                txt_punto.setString("");
                txt_destino.setString("");
                txt_puntos1.setString("");
                txt_puntos2.setString("");
                txt_puntos3.setString("");
                txt_puntos4.setString("");
                controlarIngreso = true;
            }

            if(controlarIngreso)
            {
                if(event.type == sf::Event::TextEntered)
                {
                    nombre_punto.insert(nombre_punto.getSize(),event.text.unicode);
                    txt_punto.setString(nombre_punto);
                    pasarString = nombre_punto;
                    pasarChar = new char[pasarString.size()+1];
                    copy(pasarString.begin(),pasarString.end(),pasarChar);
                    pasarChar[pasarString.size()] = '\0';
                }
            }

            if(!controlarIngreso)
            {
                if(event.type == sf::Event::TextEntered)
                {
                    nombre_destino.insert(nombre_destino.getSize(),event.text.unicode);
                    txt_destino.setString(nombre_destino);
                    pasarString1 = nombre_destino;
                    pasarChar1 = new char[pasarString1.size()+1];
                    copy(pasarString1.begin(),pasarString1.end(),pasarChar1);
                    pasarChar1[pasarString1.size()] = '\0';
                }
            }
        }

        if(utility->clickSprite(back_btnBuscar,mouse1))
        {
            ruta->obtenerCaminosDirectos(pasarChar);
            txt_puntos1.setString(ruta->caminoDirecto[0]);
            txt_puntos2.setString(ruta->caminoDirecto[1]);
            txt_puntos3.setString(ruta->caminoDirecto[2]);
            txt_puntos4.setString(ruta->caminoDirecto[3]);
            controlarIngreso = false;
        }

        if(utility->clickSprite(back_btnBorrar,mouse1))
        {
            nombre_punto.clear();
            txt_punto.setString("");
            txt_puntos1.setString("");
            txt_puntos2.setString("");
            txt_puntos3.setString("");
            txt_puntos4.setString("");
            ruta->reestablecerCaminosDirectos();
            controlarIngreso = true;
        }

        if(utility->clickSprite(back_btnBorrar2,mouse1))
        {
            nombre_destino.clear();
            txt_destino.setString("");
        }

        window1.draw(back_fondo);
        window1.draw(back_btnBuscar);
        window1.draw(back_btnBorrar);
        window1.draw(back_btnBorrar2);
        window1.draw(txt_punto);
        window1.draw(txt_destino);
        window1.draw(txt_puntos1);
        window1.draw(txt_puntos2);
        window1.draw(txt_puntos3);
        window1.draw(txt_puntos4);
        window1.draw(back_btnSalir);
        window1.draw(back_btnCrear);
        window1.display();
    }
}

void Administrador::ventanaConsultarCaminos()
{
    bool controlar_inputs = true, controlar_msj1 = false, controlar_msj2 = false;
    char* cadena1;
    char* cadena2;
    sf::RenderWindow window1;
    sf::Vector2f mouse1;
    sf::Text txt_texto1, txt_texto2;
    sf::Font fuente;
    sf::String texto1, texto2;
    string pasarTexto1, pasarTexto2;
    sf::Texture text_fondo, text_ingreso2, text_btnConsultar, text_btnSalir, text_borrar1, text_borrar2, text_msjCamino,
    text_btnAceptar;
    sf::Sprite back_fondo, back_ingreso2, back_btnConsultar, back_btnSalir, back_borrar1, back_borrar2, back_msjCamino,
    back_btnAceptar;

    window1.create(sf::VideoMode(400,300),"Consultar Caminos");
    window1.setVerticalSyncEnabled(true);

    fuente.loadFromFile("arial.ttf");

    txt_texto1.setFont(fuente);
    txt_texto1.setCharacterSize(30);
    txt_texto1.setColor(sf::Color::Black);
    txt_texto1.setStyle(sf::Text::Bold);
    txt_texto1.setPosition(40,60);

    txt_texto2.setFont(fuente);
    txt_texto2.setCharacterSize(30);
    txt_texto2.setColor(sf::Color::Black);
    txt_texto2.setStyle(sf::Text::Bold);
    txt_texto2.setPosition(40,145);

    text_fondo.loadFromFile("back_consultarCamino.png");
    back_fondo.setTexture(text_fondo);

    text_ingreso2.loadFromFile("botones/back_ingreso2.png");
    back_ingreso2.setTexture(text_ingreso2);
    back_ingreso2.setPosition(30,140);

    text_btnConsultar.loadFromFile("botones/consulta.png");
    back_btnConsultar.setTexture(text_btnConsultar);
    back_btnConsultar.setPosition(30,220);

    text_btnSalir.loadFromFile("botones/salir_ventanaConsulta.png");
    back_btnSalir.setTexture(text_btnSalir);
    back_btnSalir.setPosition(200,220);

    text_borrar1.loadFromFile("botones/erase.png");
    back_borrar1.setTexture(text_borrar1);
    back_borrar1.setPosition(320,55);

    text_borrar2.loadFromFile("botones/erase.png");
    back_borrar2.setTexture(text_borrar2);
    back_borrar2.setPosition(320,140);

    while(window1.isOpen())
    {
        sf::Event event;
        while(window1.pollEvent(event))
        {
            mouse1 = window1.mapPixelToCoords(sf::Mouse::getPosition(window1));

            if(event.type == sf::Event::TextEntered)
            {
                if(controlar_inputs)
                {
                    texto1.insert(texto1.getSize(),event.text.unicode);
                    txt_texto1.setString(texto1);

                    pasarTexto1 = texto1;
                    cadena1 = new char[pasarTexto1.size()+1];
                    copy(pasarTexto1.begin(),pasarTexto1.end(),cadena1);
                    cadena1[pasarTexto1.size()] = '\0';
                }
                else{
                    texto2.insert(texto2.getSize(),event.text.unicode);
                    txt_texto2.setString(texto2);

                    pasarTexto2 = texto2;
                    cadena2 = new char[pasarTexto2.size()+1];
                    copy(pasarTexto2.begin(),pasarTexto2.end(),cadena2);
                    cadena2[pasarTexto2.size()] = '\0';
                }
            }

            if(utility->clickSprite(back_btnConsultar,mouse1))
            {
                text_btnAceptar.loadFromFile("botones/btnAceptar.png");
                back_btnAceptar.setTexture(text_btnAceptar);
                back_btnAceptar.setPosition(120,140);

                if(ruta->existeCamino(cadena1,cadena2))
                {
                    text_msjCamino.loadFromFile("si_camino.png");
                    controlar_msj1 = true;
                    controlar_inputs = true;
                }
                else{
                    text_msjCamino.loadFromFile("no_camino.png");
                    controlar_msj2 = true;
                    controlar_inputs = true;
                }
                back_msjCamino.setTexture(text_msjCamino);
                back_msjCamino.setPosition(40,30);
            }

            if(utility->clickSprite(back_ingreso2,mouse1))
            {
                controlar_inputs = false;
            }

            if(utility->clickSprite(back_borrar1,mouse1))
            {
                texto1.clear();
                txt_texto1.setString("");
            }

            if(utility->clickSprite(back_borrar2,mouse1))
            {
                texto2.clear();
                txt_texto2.setString("");
            }

            if(utility->clickSprite(back_btnAceptar,mouse1))
            {
                controlar_msj1 = false;
                controlar_msj2 = false;
            }
        }

        if(utility->clickSprite(back_btnSalir,mouse1))
        {
            window1.close();
        }

        window1.draw(back_fondo);
        window1.draw(back_ingreso2);
        window1.draw(back_btnConsultar);
        window1.draw(back_btnSalir);
        window1.draw(back_borrar1);
        window1.draw(back_borrar2);
        window1.draw(txt_texto1);
        window1.draw(txt_texto2);
        if(controlar_msj1){window1.draw(back_msjCamino);}
        if(controlar_msj2){window1.draw(back_msjCamino);}
        if(controlar_msj1 || controlar_msj2){window1.draw(back_btnAceptar);}
        window1.display();
    }
}

void Administrador::imprimeCaminos()
{
    for(int j = 0; j < 15; j++)
    {
        for(int k = 0; k < 15; k++)
        {
            cout<<ruta->caminos[j][k]<<" , ";
        }
        cout<<endl<<endl;
    }
}

void Administrador::dibujarAristas(char* nombre_punto1, char* nombre_punto2)
{
    if((utility->compareTo(nombre_punto1,ruta->puntos[0]) && utility->compareTo(nombre_punto2,ruta->puntos[13]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[13]) && utility->compareTo(nombre_punto2,ruta->puntos[0])))
    {
        text_aristas[0].loadFromFile("Aristas/sanPedro-santaRosa.png");
        back_aristas[0].setTexture(text_aristas[0]);
        back_aristas[0].setPosition(165,190);
        mostrarAristas[0] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[13]) && utility->compareTo(nombre_punto2,ruta->puntos[14]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[14]) && utility->compareTo(nombre_punto2,ruta->puntos[13])))
    {
        text_aristas[1].loadFromFile("Aristas/santaRosa-Ocotepeque.png");
        back_aristas[1].setTexture(text_aristas[1]);
        back_aristas[1].setPosition(90,295);
        mostrarAristas[1] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[1]) && utility->compareTo(nombre_punto2,ruta->puntos[0]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[0]) && utility->compareTo(nombre_punto2,ruta->puntos[1])))
    {
        text_aristas[2].loadFromFile("Aristas/ceiba-sanPedro.png");
        back_aristas[2].setTexture(text_aristas[2]);
        back_aristas[2].setPosition(285,160);
        mostrarAristas[2] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[1]) && utility->compareTo(nombre_punto2,ruta->puntos[4]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[4]) && utility->compareTo(nombre_punto2,ruta->puntos[1])))
    {
        text_aristas[3].loadFromFile("Aristas/ceiba-olancho.png");
        back_aristas[3].setTexture(text_aristas[3]);
        back_aristas[3].setPosition(485,170);
        mostrarAristas[3] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[9]) && utility->compareTo(nombre_punto2,ruta->puntos[10]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[10]) && utility->compareTo(nombre_punto2,ruta->puntos[9])))
    {
        text_aristas[4].loadFromFile("Aristas/comayagua-intibuca.png");
        back_aristas[4].setTexture(text_aristas[4]);
        back_aristas[4].setPosition(250,345);
        mostrarAristas[4] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[9]) && utility->compareTo(nombre_punto2,ruta->puntos[12]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[12]) && utility->compareTo(nombre_punto2,ruta->puntos[9])))
    {
        text_aristas[5].loadFromFile("Aristas/comayagua-santaBarbara.png");
        back_aristas[5].setTexture(text_aristas[5]);
        back_aristas[5].setPosition(255,275);
        mostrarAristas[5] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[9]) && utility->compareTo(nombre_punto2,ruta->puntos[3]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[3]) && utility->compareTo(nombre_punto2,ruta->puntos[9])))
    {
        text_aristas[6].loadFromFile("Aristas/comayagua-yoro.png");
        back_aristas[6].setTexture(text_aristas[6]);
        back_aristas[6].setPosition(350,245);
        mostrarAristas[6] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[6]) && utility->compareTo(nombre_punto2,ruta->puntos[4]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[4]) && utility->compareTo(nombre_punto2,ruta->puntos[6])))
    {
        text_aristas[7].loadFromFile("Aristas/elParaiso-catacamas.png");
        back_aristas[7].setTexture(text_aristas[7]);
        back_aristas[7].setPosition(465,295);
        mostrarAristas[7] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[6]) && utility->compareTo(nombre_punto2,ruta->puntos[7]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[7]) && utility->compareTo(nombre_punto2,ruta->puntos[6])))
    {
        text_aristas[8].loadFromFile("Aristas/elParaiso-choluteca.png");
        back_aristas[8].setTexture(text_aristas[8]);
        back_aristas[8].setPosition(410,405);
        mostrarAristas[8] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[11]) && utility->compareTo(nombre_punto2,ruta->puntos[10]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[10]) && utility->compareTo(nombre_punto2,ruta->puntos[11])))
    {
        text_aristas[9].loadFromFile("Aristas/gracias-intibuca.png");
        back_aristas[9].setTexture(text_aristas[9]);
        back_aristas[9].setPosition(190,325);
        mostrarAristas[9] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[8]) && utility->compareTo(nombre_punto2,ruta->puntos[7]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[7]) && utility->compareTo(nombre_punto2,ruta->puntos[8])))
    {
        text_aristas[10].loadFromFile("Aristas/nacaome-choluteca.png");
        back_aristas[10].setTexture(text_aristas[10]);
        back_aristas[10].setPosition(360,465);
        mostrarAristas[10] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[0]) && utility->compareTo(nombre_punto2,ruta->puntos[12]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[12]) && utility->compareTo(nombre_punto2,ruta->puntos[0])))
    {
        text_aristas[11].loadFromFile("Aristas/sanPedro-santaBarbara.png");
        back_aristas[11].setTexture(text_aristas[11]);
        back_aristas[11].setPosition(250,195);
        mostrarAristas[11] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[0]) && utility->compareTo(nombre_punto2,ruta->puntos[3]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[3]) && utility->compareTo(nombre_punto2,ruta->puntos[0])))
    {
        text_aristas[12].loadFromFile("Aristas/sanPedro-yoro.png");
        back_aristas[12].setTexture(text_aristas[12]);
        back_aristas[12].setPosition(275,195);
        mostrarAristas[12] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[12]) && utility->compareTo(nombre_punto2,ruta->puntos[11]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[11]) && utility->compareTo(nombre_punto2,ruta->puntos[12])))
    {
        text_aristas[13].loadFromFile("Aristas/santaBarbara-gracias.png");
        back_aristas[13].setTexture(text_aristas[13]);
        back_aristas[13].setPosition(195,275);
        mostrarAristas[13] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[13]) && utility->compareTo(nombre_punto2,ruta->puntos[11]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[11]) && utility->compareTo(nombre_punto2,ruta->puntos[13])))
    {
        text_aristas[14].loadFromFile("Aristas/santaRosa-gracias.png");
        back_aristas[14].setTexture(text_aristas[14]);
        back_aristas[14].setPosition(155,295);
        mostrarAristas[14] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[13]) && utility->compareTo(nombre_punto2,ruta->puntos[12]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[12]) && utility->compareTo(nombre_punto2,ruta->puntos[13])))
    {
        text_aristas[15].loadFromFile("Aristas/santaRosa-santaBarbara.png");
        back_aristas[15].setTexture(text_aristas[15]);
        back_aristas[15].setPosition(155,275);
        mostrarAristas[15] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[5]) && utility->compareTo(nombre_punto2,ruta->puntos[9]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[9]) && utility->compareTo(nombre_punto2,ruta->puntos[5])))
    {
        text_aristas[16].loadFromFile("Aristas/tegus-comayagua.png");
        back_aristas[16].setTexture(text_aristas[16]);
        back_aristas[16].setPosition(350,345);
        mostrarAristas[16] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[5]) && utility->compareTo(nombre_punto2,ruta->puntos[6]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[6]) && utility->compareTo(nombre_punto2,ruta->puntos[5])))
    {
        text_aristas[17].loadFromFile("Aristas/tegus-elParaiso.png");
        back_aristas[17].setTexture(text_aristas[17]);
        back_aristas[17].setPosition(410,390);
        mostrarAristas[17] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[5]) && utility->compareTo(nombre_punto2,ruta->puntos[8]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[8]) && utility->compareTo(nombre_punto2,ruta->puntos[5])))
    {
        text_aristas[18].loadFromFile("Aristas/tegus-nacaome.png");
        back_aristas[18].setTexture(text_aristas[18]);
        back_aristas[18].setPosition(370,395);
        mostrarAristas[18] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[5]) && utility->compareTo(nombre_punto2,ruta->puntos[4]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[4]) && utility->compareTo(nombre_punto2,ruta->puntos[5])))
    {
        text_aristas[19].loadFromFile("Aristas/tegus-olancho.png");
        back_aristas[19].setTexture(text_aristas[19]);
        back_aristas[19].setPosition(410,290);
        mostrarAristas[19] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[2]) && utility->compareTo(nombre_punto2,ruta->puntos[1]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[1]) && utility->compareTo(nombre_punto2,ruta->puntos[2])))
    {
        text_aristas[20].loadFromFile("Aristas/trujillo-ceiba.png");
        back_aristas[20].setTexture(text_aristas[20]);
        back_aristas[20].setPosition(475,145);
        mostrarAristas[20] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[3]) && utility->compareTo(nombre_punto2,ruta->puntos[1]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[1]) && utility->compareTo(nombre_punto2,ruta->puntos[3])))
    {
        text_aristas[21].loadFromFile("Aristas/yoro-ceiba.png");
        back_aristas[21].setTexture(text_aristas[21]);
        back_aristas[21].setPosition(420,160);
        mostrarAristas[21] = true;
    }

    if((utility->compareTo(nombre_punto1,ruta->puntos[3]) && utility->compareTo(nombre_punto2,ruta->puntos[4]))
       || (utility->compareTo(nombre_punto1,ruta->puntos[4]) && utility->compareTo(nombre_punto2,ruta->puntos[3])))
    {
        text_aristas[22].loadFromFile("Aristas/yoro-olancho.png");
        back_aristas[22].setTexture(text_aristas[22]);
        back_aristas[22].setPosition(415,245);
        mostrarAristas[22] = true;
    }
}

void Administrador::drawLineas()
{
    for(int x = 0; x < 23; x++)
    {
        if(mostrarAristas[x])
        {
            window.draw(back_aristas[x]);
        }
    }
}

Administrador::~Administrador()
{
    delete ruta->caminoDirecto;
}
