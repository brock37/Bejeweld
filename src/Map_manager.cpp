#include "Map_manager.h"

Map_manager::Map_manager(sf::Texture* texture, int nbLignes, int nbColonnes)
{
    Aleatoire();//Initialise RAND
    m_nbLignes= nbLignes;
    m_nbColonnes= nbColonnes;
    m_texture= texture;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize( m_nbLignes * m_nbColonnes * 4 );

    //On creer un tableau de tableau pour avoir un tableau 2D
    m_grille= new int*[m_nbLignes];
    for(int i(0); i < m_nbLignes ; i++)
        m_grille[i]= new int[m_nbColonnes];

    initGrille();

}

Map_manager::~Map_manager()
{
    for(int i(0); i < m_nbLignes ; i++)
       delete[] m_grille[i];
    delete[] m_grille;
}

void Map_manager::afficherMap()
{
    for(int i(0); i < m_nbLignes ; i++)
    {
        for(int j(0); j < m_nbColonnes; j++)
        {
            std::cout << m_grille[j][i] << " ";
        }

        std::cout << std::endl;
    }

}

void Map_manager::dessinerMap(sf::RenderWindow &window)
{
     for(int i(0); i < m_nbLignes ; i++)
    {
        for(int j(0); j < m_nbColonnes; j++)
        {
            sf::Vertex* quad = &m_vertices[(i + j * m_nbColonnes) * 4]; //Recupere un pointeur vers le 1er point du carre

            quad[0].position= sf::Vector2f(i * TAILLE_TILE, j * TAILLE_TILE);
            quad[1].position= sf::Vector2f((i +1) * TAILLE_TILE, j * TAILLE_TILE);
            quad[2].position= sf::Vector2f((i +1) * TAILLE_TILE, (j +1) * TAILLE_TILE);
            quad[3].position= sf::Vector2f(i * TAILLE_TILE, (j +1) * TAILLE_TILE);


            quad[0].texCoords= sf::Vector2f(0,0);
            quad[1].texCoords= sf::Vector2f(TAILLE_TILE,0);
            quad[2].texCoords= sf::Vector2f(TAILLE_TILE,TAILLE_TILE);
            quad[3].texCoords= sf::Vector2f(0,TAILLE_TILE);
            }

        }


    window.draw( m_vertices, m_texture);
}

void Map_manager::remplirAleatoirement(int mini, int maxi)
{
    for(int i(0); i < m_nbLignes ; i++)
    {
        for(int j(0); j < m_nbColonnes; j++)
            m_grille[i][j]= Aleatoire::aleatoire(mini,maxi);
    }
}

void Map_manager::initGrille(int val)
{
    for(int i(0); i < m_nbLignes ; i++)
    {
        for(int j(0); j < m_nbColonnes; j++)
            m_grille[i][j]= val;
    }
}

void Map_manager::remplirParFIchier(std::string filePath)
{
    /*remplir le tableau si le fichier specifie en 1er ligne le meme nombre de colonnes et de lignes
    que le tableau*/
}
