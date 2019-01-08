#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#define TAILLE_TILE 32

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Aleatoire.h"

class Map_manager
{
    public:
        /** Default constructor */
        Map_manager(sf::Texture* texture, int nbLignes=0, int nbColonnes=0 );
        /** Default destructor */
        ~Map_manager();
        void afficherMap();
        void dessinerMap(sf::RenderWindow &window);
        void initGrille(int val=0);
        void remplirAleatoirement(int mini, int maxi);
        void remplirParFIchier(std::string filePath);

    protected:
    private:
        int** m_grille;
        int m_nbLignes;
        int m_nbColonnes;
        sf::VertexArray m_vertices;
        sf::Texture *m_texture;
};

#endif // MAP_MANAGER_H
