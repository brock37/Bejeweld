#include "GameScreen.h"

GameScreen::GameScreen()
: m_boardModel(8,8,3),
  m_boardView(m_boardModel),
  m_boardState(UNITIALIZED),
  m_selected_tile(-1,-1),
  m_prevSelectedTile(-1,-1)
{
    std::cout << "Create GameScreen" << std::endl;
    
    m_boardState= READY;
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
                
                std::cout << "Mouse Pos: " << x << " " << y << std::endl;
                
                if(m_boardState == READY || m_boardState == WAIT_SELECT2)
                {
                    if( m_boardView.isTileAtCoordinate(x,y))
                    {
                        int row= m_boardView.getTileColumnbyX(x);
                        int col=m_boardView.getTileRowByY(y);
                        std::cout << "Grid Pos: " << row << " " << col << std::endl;
                        
                        if(m_boardState == WAIT_SELECT2)
                        {
                            m_prevSelectedTile= m_selected_tile;
                            m_boardState= SELECT2;
                        }
                        else
                        {
                            m_boardState= SELECT1;
                        }
                        m_selected_tile= sf::Vector2i(row,col);
                    }
                }
                
                
            }
        }
        
        update();
        
        App.clear();
        App.draw(m_boardView);
        App.display();
    }
    
    return -1;
}

void GameScreen::update()
{
    switch(m_boardState)
    {
        case SELECT1:
            m_boardModel.setItemSelected(m_selected_tile.x, m_selected_tile.y);
            m_boardState=WAIT_SELECT2;
            m_boardModel.printGrid();
            break;
            
        case WAIT_SELECT2:
            break;
            
        case SELECT2:
            if( !(m_boardModel.swapItem(m_selected_tile.x, m_selected_tile.y, m_prevSelectedTile.x, m_prevSelectedTile.y)))
            {
                //Unable to switch
                m_boardState=READY;
            }
            else
            {
                m_boardState= READY;
                //Si l'echange ne donne pas de sequence on remmet en place
                //m_boardModel.swapItem(m_selected_tile.x, m_selected_tile.y, m_prevSelectedTile.x, m_prevSelectedTile.y)
            }
            m_boardModel.printGrid();
            break;
            
        default:
            break;            
    }
}

