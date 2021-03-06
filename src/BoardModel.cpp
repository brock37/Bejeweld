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

    printGrid();
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

void BoardModel::fillGrid(bool debug)
{
    Texture_manager* t= Texture_manager::Instance();
    sf::Texture* tex= NULL;
    //tex->loadFromFile("ressources/Images/tileset.png");

    if(!debug)
    {
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
    else{
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
                        int type= 0;
                        m_grid[i][j].setType(type);
                        tex=t->getTexture(type);
                        m_grid[i][j].setTexture(tex);

                    }
                }
    }

}

bool BoardModel::swapItem(int row1, int col1, int row2, int col2)
{
    if((row1 == row2 && ((col1==col2-1)||(col1==col2+1))) ||
       (col1 == col2 && ((row1==row2-1)||(row1==row2+1))))
    {
        std::cout << "swap item :" << row1 << "," << col1 << " - " << row2 << "," << col2 << std::endl; 
        if(m_grid[row1][col1].getType() == m_grid[row2][col2].getType())
        {
            std::cout << "SAME TYPE" << std::endl;
            return false;//Si les items sont du meme types pas besoin d'échanger
        }
        sf::Texture *tex1= m_grid[row1][col1].getTexture();
        sf::Texture *tex2= m_grid[row2][col2].getTexture();
        Item tmp=m_grid[row1][col1];
        m_grid[row1][col1]=m_grid[row2][col2];
        m_grid[row2][col2]= tmp;
        m_grid[row1][col1].setTexture(tex1);
        m_grid[row2][col2].setTexture(tex2);
        return true;
    }
    
    
    return false;
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

void BoardModel::setItemSelected(int row, int col)
{
    m_grid[row][col].select();
}

void BoardModel::deselectAllItem()
{
    for(int i(0); i < m_nbRows; i++)
    {
        for(int j(0); j < m_nbCols; j++)
        {
            m_grid[i][j].unSelect();
        }
    }
}



void BoardModel::printGrid()
{
    std::cout << "Grid Engine :" << std::endl;
    for(int i(0); i < m_nbCols; i++)
    {
        for(int j(0); j < m_nbRows; j++)
        {
            std::cout << m_grid[j][i].getType();
        }
        std::cout << std::endl;
    }
    std::cout << "Grid Engine END" <<std::endl;
}
