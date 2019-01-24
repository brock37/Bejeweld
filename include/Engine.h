#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "Texture_manager.h"
#include "Cscreen.h"
#include "GameScreen.h"
/* Engine - Charge SFML
 * Est chargé de gerer le screen a afficher
 * Initialise les ressources global
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
    int m_screen;
    sf::RenderWindow m_window;
    //Texture_manager* m_textureManager;

    std::vector<Cscreen*> m_Screens;

    //Not use anymore
    GameScreen m_gameScreen;
};


#endif // ENGINE_H
