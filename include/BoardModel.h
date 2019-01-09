#ifndef BOARDMODEL_H
#define BOARDMODEL_H

/* BoardModel - Represente le plateau de jeux
 * sous forme logique
 */

#include <SFML/System/Vector2.hpp>

#include "Item.h"
#include "Texture_manager.h"


class BoardModel
{
    public:
        BoardModel(Texture_manager& texManager);
        virtual ~BoardModel();

        ///Remplis la grille
        void fillGrid();

        ///Echange 2 items de place
        void swapItem(sf::Vector2i pos1, sf::Vector2i pos2);

        ///Fais chuter les items si il n'y a rien en dessous
        void fallenItem();

        ///Verifie si l'item et au debut/fin d'une sequence
        bool isBegingSequence();
        bool isEndingSequence();


    protected:

    private:
        Texture_manager& m_textureManager;
        std::vector<std::vector<Item> > grid;
};

#endif // BOARDMODEL_H
