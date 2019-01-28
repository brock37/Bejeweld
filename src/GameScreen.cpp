#include "GameScreen.h"

GameScreen::GameScreen()
: m_boardModel(8,8,3),
  m_boardView(m_boardModel),
  m_boardState(UNITIALIZED),
  m_selected_tile(-1,-1),
  m_prevSelectedTile(-1,-1)
{
    std::cout << "Create GameScreen" << std::endl;
    //ctor
}

GameScreen::~GameScreen()
{
    //dtor
}

int GameScreen::Run(sf::RenderWindow &App)
{
    std::cout << "Start Run GameScreen" << std::endl;
    bool running= true;
    sf::Event Event;
    
    while(running)
    {
        //Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return (0);
					break;
				default:
					break;
				}
			}
			//Mouse pressed
			if (Event.type == sf::Event::MouseButtonReleased && Event.mouseButton.button == sf::Mouse::Button::Left)
            {
                int x= Event.mouseButton.x;
                int y= Event.mouseButton.y;
                
                if(m_boardState == READY || m_boardState == WAIT_SELECT2)
                {
                    if( m_boardView.isTileAtCoordinate(x,y))
                    {
                        int row= m_boardView.getTileColumnbyX(x);
                        int col=m_boardView.getTileRowByY(y);
                        
                        if(m_boardState == WAIT_SELECT2)
                        {
                            m_prevSelectedTile= m_selected_tile;
                            m_boardState= SELECT2;
                        }
                        else
                        {
                            m_boardState= SELECT1;
                        }
                        m_selected_tile= sf::Vector2i(x,y);
                    }
                }
                
                
            }
        }
        
        App.clear();
        App.draw(m_boardView);
        App.display();
    }
    
    return -1;
}
