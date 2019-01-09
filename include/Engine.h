#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "Texture_manager.h"
/* Engine - Charge SFML
 * Est chargé de gerer l'affichage de l'ecran
 */

 using std::string;

class Engine
{
    public:
    static const string WINDOW_TITLE;

        ///Ctr initialise SFML - icone - titre
        Engine();
        virtual ~Engine();

        /// Fonction principal - lance le game loop
        void runEngine();

    protected:

    private:
    sf::RenderWindow m_window;
    Texture_manager m_textureManager;
};


#endif // ENGINE_H
