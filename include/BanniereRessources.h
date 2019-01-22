#ifndef BANNIERERESSOURCES_H
#define BANNIERERESSOURCES_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Label.h"
#include "Texture_manager.h"

class BanniereRessources
{
    public:
        /** Default constructor */
        BanniereRessources(sf::Vector2f taille, sf::Vector2f position ,
                            Texture_manager &textureManager);
        /** Default destructor */
        ~BanniereRessources();
        void afficher( sf::RenderWindow &window);
        void update();
    protected:
    private:

        sf::Font* m_font;
        sf::RectangleShape m_background;
        std::vector<Label*> m_listeLabel;

};

#endif // BANNIERERESSOURCES_H
