#include "Texture_manager.h"

Texture_manager* Texture_manager::m_instance= NULL;


Texture_manager::Texture_manager()
{
    //ctor
}

Texture_manager::~Texture_manager()
{
    for(std::vector<sf::Texture*>::iterator i= m_listeTexture.begin(); i != m_listeTexture.end(); i++)
    {
        std::cout << "Destruction de la texture a l'adresse" << *i << std::endl;
        delete *i;
    }
}

int Texture_manager::ajouterTexture(std::string str)
{
    sf::Texture *nouvelleTexture= new sf::Texture;
    if(!nouvelleTexture->loadFromFile(str))
    {
        delete nouvelleTexture;
        return -1;
    }
    else
    {
        m_listeTexture.push_back( nouvelleTexture);
    }


    return 0;
}

sf::Texture* Texture_manager::getTexture(unsigned int index)
{
    if( index >= m_listeTexture.size())
        return 0;
    return m_listeTexture[index];
}

Texture_manager* Texture_manager::Instance()
{
    if(m_instance == NULL)
    {
        std::cout << "Cr�ation de l'instance TextureManager" << std::endl;
        m_instance= new Texture_manager();
    }
    else
    {
        std::cout << "Singleton deja creer" << std::endl;
    }
    return m_instance;
}

