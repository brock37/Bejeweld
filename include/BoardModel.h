#ifndef BOARDMODEL_H
#define BOARDMODEL_H

/* BoardModel - Represente le plateau de jeux
 * sous forme logique
 */

#include <ctime>
#include <cstdlib>

#include <SFML/System/Vector2.hpp>

#include "Item.h"
#include "Texture_manager.h"
#include "Grid.h"


class BoardModel
{
    public:

         static const int EMPTY_TILE = -1;

        /*Ctor BoradMoadel
        *@param nbRows  nombre de ligne dans la grille
        *@param nbCols  nombre de colonne dans la grille
        *@param nbItemTypes Nombre de type different pour les items
        */
        BoardModel(int nbRows, int nbCols,int nbItemTypes);
        virtual ~BoardModel();

        ///Remplis la grille
        void fillGrid();

        ///Echange 2 items de place
        bool swapItem(int row1, int col1, int row2, int col2);

        ///Fais chuter les items si il n'y a rien en dessous
        void fallenItem();

        ///Verifie si l'item et au debut/fin d'une sequence
        bool isBegingSequence(int i, int j);
        bool isEndingSequence(int i, int j);
        
        const Item& getItem(int i, int j) const;
        
        int getNbRows() const;
        int getNbCols() const;


    protected:

    private:
        ///Dimmension du plateau
        int m_nbRows, m_nbCols;

        ///Nombre de type different d'item
        int m_nbItemTypes;

        //std::vector<Item> m_grid;
        Grid<Item> m_grid;



};

#endif // BOARDMODEL_H
