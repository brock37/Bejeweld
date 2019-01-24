#include "BoardModel.h"


#include <iostream>



BoardModel::BoardModel(int nbRows, int nbCols,int nbItemTypes)
: m_nbRows(nbRows) ,
  m_nbCols(nbCols) ,
  m_nbItemTypes(nbItemTypes),
  m_grid(m_nbRows, m_nbCols)
{
    std::cout << "Create BoardModel" << std::endl;
    std::srand(std::time(0));


    fillGrid();

    std::cout << "Grid Engine :" << std::endl;
    for(int i(0); i < m_nbRows; i++)
    {
        for(int j(0); j < m_nbCols; j++)
        {
            std::cout << m_grid[i][j].getType();
        }
        std::cout << std::endl;
    }
    std::cout << "Grid Engine END" <<std::endl;
    //ctor
}

BoardModel::~BoardModel()
{
//    for(int i(0); i < m_nbRows; i++)
//    {
//
//        for(int j(0); j < m_nbCols; j++)
//        {
//            delete m_grid[i + j * m_nbCols];
//        }
//    }
    //dtor
}

void BoardModel::fillGrid()
{
    Texture_manager* t= Texture_manager::Instance();
    sf::Texture* tex= NULL;
    //tex->loadFromFile("ressources/Images/tileset.png");

    //Remplis aleatoirement la grille
    for(int i(0); i < m_nbRows; i++)
    {
        for(int j(0); j < m_nbCols; j++)
        {
            /*Item tmpItem;
            tmpItem.positionner(sf::Vector2f(i*32, j*32));
            int type=std::rand() % m_nbItemTypes;
            tmpItem.setType(type);
            tex=t->getTexture(type);
            tmpItem.setTexture( tex);
            //tmpItem.setTexture(t->getTexture(type));
            m_grid.push_back(tmpItem);*/

            //m_grid[i][j]= std::rand() % m_nbItemTypes;

            m_grid[i][j].positionner(sf::Vector2f(i*32, j*32));
            int type= std::rand() % m_nbItemTypes;
            m_grid[i][j].setType(type);
            tex=t->getTexture(type);
            m_grid[i][j].setTexture(tex);

        }
    }

    /*On vérifie si il n'y a pas d'item identique a
    l'initialistaion*/
    bool boardReady= false;
    while(!boardReady)
    {
        boardReady= true;
        for(int i(0); i < m_nbRows; i++)
        {
            for(int j(0); j < m_nbCols; j++)
            {
                if(isBegingSequence(i,j))
                {
                    boardReady=false;
                    int type= std::rand() % m_nbItemTypes;
                    m_grid[i][j].setType(type);
                    tex=t->getTexture(type);
                    m_grid[i][j].setTexture(tex);
                    
                }
            }
        }
    }

}

bool BoardModel::isBegingSequence(int i, int j)
{
    return ((i >= 0 && i < m_nbRows-2 && m_grid[i][j].getType() == m_grid[i+1][j].getType() && m_grid[i][j].getType()== m_grid[i+2][j].getType()) ||
              (j >=0 && j < m_nbCols-2 && m_grid[i][j].getType() == m_grid[i][j+1].getType() && m_grid[i][j].getType()== m_grid[i][j+2].getType()));

/*    return ((i >= 0 && i < m_nbRows-2 && m_grid[i][j] == m_grid[i+1][j] && m_grid[i][j] == m_grid[i+2][j] ) ||
            (j >=0 && j < m_nbCols-2 && m_grid[i][j] == m_grid[i][j+1] && m_grid[i][j] == m_grid[i][j+2] ));*/
}

bool BoardModel::isEndingSequence(int i, int j)
{
    return ((i < m_nbRows && i < 2 && m_grid[i][j].getType() == m_grid[i-1][j].getType() && m_grid[i][j].getType()== m_grid[i-2][j].getType()) ||
            (j < m_nbCols && j < 2 && m_grid[i][j].getType() == m_grid[i][j-1].getType() && m_grid[i][j].getType()== m_grid[i][j-2].getType()));
}

const Item& BoardModel::getItem(int i, int j) const
{
    return m_grid[i][j];
}

int BoardModel::getNbRows() const
{
    return m_nbRows;
}

int BoardModel::getNbCols() const
{
    return m_nbCols;
}
