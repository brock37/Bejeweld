#include "BoardModel.h"


BoardModel::BoardModel(int nbRows, int nbCols,int nbItemTypes):m_nbRows(nbRows) ,m_nbCols(nbCols) ,m_nbItemTypes(nbItemTypes)
{
    std::srand(std::time(0));
    fillGrid();
    //ctor
}

BoardModel::~BoardModel()
{
    for(int i(0); i < m_nbRows; i++)
    {

        for(int j(0); j < m_nbCols; j++)
        {
            delete m_grid[i][j];
        }
    }
    //dtor
}

void BoardModel::fillGrid()
{
    Texture_manager* t= Texture_manager::Instance();
    //Remplis aleatoirement la grille
    for(int i(0); i < m_nbRows; i++)
    {

        for(int j(0); j < m_nbCols; j++)
        {
            Item* tmpItem= new Item();
            tmpItem->positionner(sf::Vector2f(i*32, j*32));
            tmpItem->setType(std::rand() % m_nbItemTypes);
            tmpItem->setTexture(t->getTexture(tmpItem->getType()+1));

            m_grid[i][j]= tmpItem;
        }
    }
}
