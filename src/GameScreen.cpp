#include "GameScreen.h"

GameScreen::GameScreen()
: m_boardModel(8,8,3),
  m_boardView(m_boardModel),
  m_boardState(UNITIALIZED)
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
                    
                }
                
                
            }
        }
        
        App.clear();
        App.draw(m_boardView);
        App.display();
    }
    
    return -1;
}
