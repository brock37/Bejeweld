#include "BanniereRessources.h"

BanniereRessources::BanniereRessources(sf::Vector2f taille, sf::Vector2f position,
                                        Texture_manager &textureManager)
{
    //initialisation du backgroung de la banniere
    m_background.setSize( taille);
    m_background.setPosition( position);
    m_background.setFillColor( sf::Color(177,190,90));

    //Chargement de la police
    m_font= new sf::Font;
    m_font->loadFromFile("ressources/arial.ttf");

    //mise en place des label
    m_listeLabel.push_back( new Label( sf::Vector2f(0, position.y +10 ), m_font, textureManager.getTexture(2)));
    m_listeLabel.push_back( new Label( sf::Vector2f(150, position.y +10 ), m_font, textureManager.getTexture(3)));
    m_listeLabel.push_back( new Label( sf::Vector2f(300, position.y +10 ), m_font, textureManager.getTexture(4)));


}

BanniereRessources::~BanniereRessources()
{
    delete m_font;
    for( unsigned int i(0); i < m_listeLabel.size(); i++)
        delete m_listeLabel[i];
}

void BanniereRessources::afficher( sf::RenderWindow &window)
{
    window.draw( m_background);
    for( unsigned int i(0); i < m_listeLabel.size(); i++)
        m_listeLabel[i]->afficher( window);
}

void BanniereRessources::update()
{

}
