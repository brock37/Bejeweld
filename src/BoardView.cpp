#include "BoardView.h"

const int BoardView::TILE_SIZE= 32;
const int BoardView::TILE_NONE_FOUND=-1;

BoardView::BoardView(const BoardModel& model)
: m_boardModel(model)
{
    std::cout << "Create BoardView" << std::endl;
}

BoardView::~BoardView()
{

}

void BoardView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(int i(0); i < m_boardModel.getNbRows(); i++)
    {
        for(int j(0); j < m_boardModel.getNbCols(); j++)
        {
            m_boardModel.getItem(i,j).draw(target, states);
        }
    }

}


int BoardView::getTileColumbyX(int x)
{
    if( x <= 0 || x >= m_boardModel.getNbCols() * TILE_SIZE)
        return TILE_NONE_FOUND;
    return x / TILE_SIZE;
}

int BoardView::getTileRowByY(int y)
{
    if( y <=0 || y >= m_boardModel.getNbRows() * TILE_SIZE)
        return TILE_NONE_FOUND;
    return y / TILE_SIZE;
}

bool BoardView::isTileAtCoordinate(int x, int y)
{
    return !( getTileColumbyX(x) == TILE_NONE_FOUND || getTileRowByY(y) == TILE_NONE_FOUND);
}
