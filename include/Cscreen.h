#ifndef CSCREEN_H
#define CSCREEN_H

#include <SFML/Graphics.hpp>


class Cscreen
{
    public:
        Cscreen();
        virtual ~Cscreen();
        virtual int Run (sf::RenderWindow &App) = 0;

    protected:

    private:
};

#endif // CSCREEN_H
