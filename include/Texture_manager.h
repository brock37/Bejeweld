#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Texture_manager
{

    public:
        static	Texture_manager& Instances(){return m_instance;};

        /** Default constructor */
        Texture_manager();
        /** Default destructor */
        ~Texture_manager();
        int ajouterTexture(std::string str);
        sf::Texture* getTexture(unsigned int index);
        int nombreTexture() {return m_listeTexture.size();}

    protected:
    private:
        static Texture_manager m_instance;
        std::vector<sf::Texture*> m_listeTexture;
};

#endif // TEXTURE_MANAGER_H
