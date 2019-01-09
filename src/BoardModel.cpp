#include "BoardModel.h"


BoardModel::BoardModel(int nbRows, int nbCols,int nbItemTypes, Texture_manager& texManager):m_nbRows(nbRows) ,m_nbCols(nbCols) ,m_nbItemTypes(nbItemTypes) ,m_textureManager(texManager)
{
    std::srand(std::time(0));
    //ctor
}

BoardModel::~BoardModel()
{
    //dtor
}

void BoardModel::fillGrid()
{

}
