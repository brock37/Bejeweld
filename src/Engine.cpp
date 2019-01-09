#include "Engine.h"

const string Engine::WINDOW_TITLE="BEJEWELD";

Engine::Engine()
{
    int m_screen=0;
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
    std::vector<Cscreen*> m_Screens;

    GameScreen* m_gameScreen= new GameScreen();

    m_Screens.push_back(m_gameScreen);


}

Engine::~Engine()
{
    //dtor
}

void Engine::runEngine()
{
	while (m_screen >= 0)
	{
		m_screen = m_Screens[m_screen]->Run(m_window);
	}

}//Fin de la fonction run


