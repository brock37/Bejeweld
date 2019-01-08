#include <SFML/Graphics.hpp>
#include "BanniereRessources.h"
#include "Texture_manager.h"
#include "Map_manager.h"
#include "Aleatoire.h"
#include "Item.h"
#include <iostream>

void descendreColonne(int colonne)
{

}

bool verifierVerticalement(sf::Vector2i pos, Item tableau[8][8])
{
    /*on regarde si les case adjacentes verticalement sont du meme type*/
    for (int i(pos.x); i < 8; i++)
    {
        for (int j(pos.y); j < 7; j++)
        {
            if(tableau[i][j].getType()== tableau[i][j+1].getType())
            {
                tableau[i][j].setType(0);
                tableau[i][j+1].setType(0);
                return true;
            }
        }
    }
    return false;

    /*if(tableau[pos.x][pos.y].getType()== tableau[pos.x][pos.y+1].getType() &&
        tableau[pos.x][pos.y].getType()== tableau[pos.x][pos.y-1].getType())
    {
        tableau[pos.x][pos.y].setType(0);
        tableau[pos.x][pos.y+1].setType(0);
        tableau[pos.x][pos.y-1].setType(0);
        return true;
    }

    return false;*/
}

bool verifierHorizontalement(sf::Vector2i pos, Item tableau[8][8])
{
    /*on regarde si les case adjacentes horizontalement sont du meme type*/

    if(tableau[pos.x][pos.y].getType()== tableau[pos.x+1][pos.y].getType() &&
        tableau[pos.x][pos.y].getType()== tableau[pos.x-1][pos.y].getType())
    {
        tableau[pos.x][pos.y].setType(0);
        tableau[pos.x+1][pos.y].setType(0);
        tableau[pos.x-1][pos.y].setType(0);
        return true;
    }

    return false;
}

int swapItem(sf::Vector2i pos1, sf::Vector2i pos2, Item tableau[8][8])
{
    int tmp= tableau[pos1.x][pos1.y].getType();
    tableau[pos1.x][pos1.y].setType(tableau[pos2.x][pos2.y].getType() );
    tableau[pos2.x][pos2.y].setType(tmp );
    return 1;
}


int main()
{
    bool select= false;
    sf::Vector2i dernierPosition(5,5), positionVerif(0,0);
    sf::RenderWindow window(sf::VideoMode(500, 400), "Bejeweld");

    //Ajout des textures au texture manager
    Texture_manager texture;
    texture.ajouterTexture("ressources/Images/background.png");
    texture.ajouterTexture("ressources/Images/tileset.png");
    texture.ajouterTexture("ressources/Images/food.png");
    texture.ajouterTexture("ressources/Images/wood.png");
    texture.ajouterTexture("ressources/Images/gold.png");

    //Creation du background de la grille
    Map_manager grille(texture.getTexture(0), 8,8);
    grille.initGrille();

    //Creation de la grille d'item
    Item grilleItem[8][8];
    for( int i(0); i < 8; i++)
    {
        for( int j(0); j < 8; j++)
        {
            //grilleItem[i][j].setTexture(texture.getTexture(1));
            grilleItem[i][j].positionner(sf::Vector2f(i*32,j*32));
            grilleItem[i][j].setType(Aleatoire::aleatoire(1,3));
            switch (grilleItem[i][j].getType())
            {
            case 1:
                grilleItem[i][j].setTexture(texture.getTexture(2));
                break;

            case 2:
                grilleItem[i][j].setTexture(texture.getTexture(3));
                break;

            case 3:
                grilleItem[i][j].setTexture(texture.getTexture(4));
                break;

            default:
                grilleItem[i][j].setTexture(texture.getTexture(1));
                break;
            }
            //std::cout << grilleItem[i][j].getType();
        }
        //std::cout << std::endl;
    }

    for( int i(0); i < 8; i++)
    {
        for( int j(0); j < 8; j++)
        {
            std::cout << grilleItem[j][i].getType();
        }
        std::cout << std::endl;
    }

    BanniereRessources banniere( sf::Vector2f(window.getSize().x,50), sf::Vector2f(0, window.getSize().y- 50), texture);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::MouseButtonReleased)
            {

                sf::Vector2i localPosition = sf::Mouse::getPosition(window);

                /*Si on clique dans la grille*/
                if((localPosition.x > 0 && localPosition.x <  8*32) &&
                    ( localPosition.y > 0 && localPosition.y < 8*32))
                {
                    //On verifie si il y a une case selectionner
                    for( int i(0); i < 8; i++)
                    {
                        for( int j(0); j < 8; j++)
                        {
                            if( grilleItem[i][j].isSelect() == true)
                            {
                                select= true;
                            }
                        }
                    }


                    //On calcul la position dans le tableau d'item
                    sf::Vector2i positionGrille(localPosition.x/32,localPosition.y/32);
                    std::cout << positionGrille.x << " " << positionGrille.y << std::endl;
                    std::cout << dernierPosition.x << " " << dernierPosition.y << std::endl;
                    std::cout << select <<std::endl;

                    //Si la case n'est pas encore selectionner et aucune case selectionner on la selectionne
                    if(grilleItem[positionGrille.x][positionGrille.y].isSelect() == false && select == false)
                    {
                        grilleItem[positionGrille.x][positionGrille.y].select();
                        dernierPosition.x= positionGrille.x;
                        dernierPosition.y= positionGrille.y;
                        std::cout << "Element selectionner :" <<grilleItem[positionGrille.x][positionGrille.y].getType() <<std::endl;

                    }
                    //sinon si une case est deja selectionner et qu'on a clique sur une case adjacente on l'echange
                    else if( select == true &&(
                            (dernierPosition.x == positionGrille.x+1 && dernierPosition.y == positionGrille.y ) ||
                            (dernierPosition.x == positionGrille.x-1 && dernierPosition.y == positionGrille.y ) ||
                            (dernierPosition.x == positionGrille.x && dernierPosition.y+1 == positionGrille.y ) ||
                            (dernierPosition.x == positionGrille.x && dernierPosition.y-1 == positionGrille.y ))
                           )
                    {
                        swapItem(sf::Vector2i(positionGrille.x, positionGrille.y),
                                 sf::Vector2i(dernierPosition.x,dernierPosition.y),
                                 grilleItem);

                        grilleItem[dernierPosition.x][dernierPosition.y].unSelect();
                        select= false;
                    }
                    else
                    {
                        grilleItem[dernierPosition.x][dernierPosition.y].unSelect();
                        grilleItem[positionGrille.x][positionGrille.y].select();
                        dernierPosition.x= positionGrille.x;
                        dernierPosition.y= positionGrille.y;
                        std::cout << "Element selectionner :" <<grilleItem[positionGrille.x][positionGrille.y].getType() <<std::endl;
                    }
                }
            }


        }
        /*Pour chaque case on verifie verticalement est horizontalement*/
        for( int i(0); i < 8; i++)
        {
            for( int j(0); j < 8; j++)
            {
                positionVerif.x=i;
                positionVerif.y=j;
                verifierVerticalement( positionVerif, grilleItem);
                //verifierHorizontalement( positionVerif, grilleItem);

            }
        }
        window.clear();
        grille.dessinerMap( window);
        banniere.afficher( window);

        for( int i(0); i < 8; i++)
            for( int j(0); j < 8; j++)
                grilleItem[i][j].afficher( window);



        window.display();
    }

    return 0;
}
