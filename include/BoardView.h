#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <SFML/Graphics/Drawable.hpp>

/**
 * @todo write docs
 */
class BoardView :  sf::Drawable
{
public:
    /**
     * Default constructor
     */
    BoardView();

    /**
     * Destructor
     */
    ~BoardView();

protected:
    /**
     * @todo write docs
     *
     * @param target TODO
     * @param states TODO
     * @return TODO
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

};

#endif // BOARDVIEW_H
