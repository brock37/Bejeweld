#include "BoardView.h"

const int BoardView::TileSize= 32;

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
    return x / TileSize;
}

int BoardView::getTileRowByY(int y)
{
    return y / TileSize;
}

