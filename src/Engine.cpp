#include "Engine.h"

const string Engine::WINDOW_TITLE="BEJEWELD";

Engine::Engine()
{
    //ctor
    ///Creation de la fenetre
    sf::RenderWindow m_window(sf::VideoMode(500, 400), WINDOW_TITLE);

    ///Remplissage du manager de texture
    Texture_manager m_textureManager;
    m_textureManager.ajouterTexture("ressources/Images/background.png");
    m_textureManager.ajouterTexture("ressources/Images/tileset.png");
    m_textureManager.ajouterTexture("ressources/Images/food.png");
    m_textureManager.ajouterTexture("ressources/Images/wood.png");
    m_textureManager.ajouterTexture("ressources/Images/gold.png");


    ///Initialisation du(des) screen(s)
}

Engine::~Engine()
{
    //dtor
}

void Engine::runEngine()
{

}//Fin de la fonction run


