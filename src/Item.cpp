#include "Item.h"

Item::Item()
{
    m_isSelect= false;
    m_rectSelect.setSize(sf::Vector2f(32,32));
    m_rectSelect.setOutlineThickness(2);
}

Item::Item(sf::Texture *texture, unsigned int type)
{
    m_isSelect= false;
    m_sprite.setTexture( *texture);
    m_type= type;

    //m_sprite.setTextureRect(sf::IntRect((type-1) *32,0,32,32));
}

Item::~Item()
{
    //dtor
}

/*Can delete this fonction when inerting from drawable is testing*/
void Item::afficher(sf::RenderWindow &window)
{
    if( m_isSelect)
        window.draw( m_rectSelect);
    window.draw( m_sprite);
}

void Item::setType(int type)
{
    m_type= type;
    //m_sprite.setTextureRect(sf::IntRect((type-1) *32,0,32,32));

}

void Item::select()
{
        m_isSelect= true;
}

void Item::unSelect()
{
    m_isSelect= false;
}

void Item::positionner(sf::Vector2f pos)
{
    m_sprite.setPosition( pos);
    m_rectSelect.setPosition(pos);
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

