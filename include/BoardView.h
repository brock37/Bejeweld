#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <SFML/Graphics/Drawable.hpp>

#include "BoardModel.h"

/**
 * @todo write docs
 */
class BoardView : public sf::Drawable
{
public:
    
    static const int TILE_SIZE;
    static const int TILE_NONE_FOUND;
    /**
     * Default constructor
     */
    BoardView(const BoardModel& model);

    /**
     * Destructor
     */
    ~BoardView();
    
    int getTileColumbyX(int x);
    int getTileRowByY(int y);

protected:
    /**
     * @todo write docs
     *
     * @param target TODO
     * @param states TODO
     * @return TODO
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
    
private:
    const BoardModel& m_boardModel;

};

#endif // BOARDVIEW_H
