#ifndef GAMESCREEN_H
#define GAMESCREEN_H

/* GameScreen - gerer les input et l'affichage du jeux
*/

#include "Cscreen.h"


class GameScreen : public Cscreen
{
    public:
        GameScreen();
        virtual ~GameScreen();

        virtual int Run (sf::RenderWindow &App);

    protected:

    private:
};

#endif // GAMESCREEN_H
