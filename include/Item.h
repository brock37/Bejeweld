#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
{
    public:
        /** Default constructor */
        Item();
        Item(sf::Texture *texture,unsigned int type);
        /** Default destructor */
        ~Item();
        void afficher(sf::RenderWindow &window);
        void setTexture(const sf::Texture* texture){ m_sprite.setTexture( *texture);}
        const sf::Texture* getTexture(){return m_sprite.getTexture(); }
        void positionner(sf::Vector2f pos);
        void setType(int type);
        int getType(){return m_type;}
        void select();
        void unSelect();
        bool isSelect(){return m_isSelect;}
    protected:
    private:
        sf::Sprite m_sprite;
        sf::IntRect m_textureRect;
        sf::RectangleShape m_rectSelect;
        int m_type;
        bool m_isSelect;
};

#endif // ITEM_H
