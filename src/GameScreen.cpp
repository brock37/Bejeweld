#include "GameScreen.h"

GameScreen::GameScreen()
: m_boardModel(8,8,3),
  m_boardView(m_boardModel)
{
    //ctor
}

GameScreen::~GameScreen()
{
    //dtor
}

int GameScreen::Run(sf::RenderWindow &App)
{
    return -1;
}
