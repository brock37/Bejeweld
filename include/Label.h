#ifndef LABEL_H
#define LABEL_H

#include <SFML/Graphics.hpp>

class Label
{
    public:
        /** Default constructor */
        Label(sf::Vector2f position, sf::Font *font, sf::Texture* texture);
        /** Default destructor */
        ~Label();
        void setFont(sf::Font &font){ m_texteIcone.setFont(font);}
        void afficher( sf::RenderWindow &window);
    protected:
    private:
        sf::Texture *m_texture;
        sf::Vector2f m_position;
        sf::Sprite m_icone;
        sf::Text m_texteIcone;
};

#endif // LABEL_H
