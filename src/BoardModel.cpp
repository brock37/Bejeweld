#include "BoardModel.h"


BoardModel::BoardModel(int nbRows, int nbCols,int nbItemTypes):m_nbRows(nbRows) ,m_nbCols(nbCols) ,m_nbItemTypes(nbItemTypes)
{
    std::srand(std::time(0));
    fillGrid();
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
    sf::Texture* tex= new sf::Texture;
    //tex->loadFromFile("ressources/Images/tileset.png");

    //Remplis aleatoirement la grille
    for(int i(0); i < m_nbRows; i++)
    {
        for(int j(0); j < m_nbCols; j++)
        {
            Item tmpItem;
            tmpItem.positionner(sf::Vector2f(i*32, j*32));
            int type=std::rand() % m_nbItemTypes;
            tmpItem.setType(type);
            //tex=t->getTexture(type);
            tmpItem.setTexture( tex);
            //tmpItem.setTexture(t->getTexture(type));
            m_grid.push_back(tmpItem);
        }
    }
}
