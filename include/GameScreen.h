#ifndef GAMESCREEN_H
#define GAMESCREEN_H

/* GameScreen - gerer les input et l'affichage du jeux
*/

#include "Texture_manager.h"
#include "Cscreen.h"
#include "BoardView.h"
#include "BoardModel.h"




class GameScreen : public Cscreen
{
    public:
        GameScreen();
        virtual ~GameScreen();

        virtual int Run (sf::RenderWindow &App);

    protected:

    private:
        BoardModel m_boardModel;
        BoardView m_boardView;
};

#endif // GAMESCREEN_H
