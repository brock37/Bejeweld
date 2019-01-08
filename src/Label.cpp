#include "Label.h"

Label::Label(sf::Vector2f position, sf::Font *font, sf::Texture* texture)
{
    //Place l'icone
    m_texture= texture;
    m_icone.setTexture( *m_texture);
    m_icone.setTextureRect( sf::IntRect(0,0,32,32));
    m_icone.setPosition( position.x, position.y ); //Decalage pour l'aligne au texte

    //place le texte
    m_texteIcone.setFont( *font);
    m_texteIcone.setCharacterSize(25);
    m_texteIcone.setString("0");
    m_texteIcone.setPosition( position.x + 32 , position.y);

}

Label::~Label()
{
    //dtor
}


void Label::afficher( sf::RenderWindow &window)
{
    window.draw( m_icone);
    window.draw( m_texteIcone);
}
