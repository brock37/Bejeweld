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
        enum BoardState{UNITIALIZED, READY, SELECT1, WAIT_SELECT2, SELECT2};
        GameScreen();
        virtual ~GameScreen();

        virtual int Run (sf::RenderWindow &App);

    protected:

    private:
        BoardModel m_boardModel;
        BoardView m_boardView;
        BoardState m_boardState;
};

#endif // GAMESCREEN_H
