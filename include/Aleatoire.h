#ifndef ALEATOIRE_H
#define ALEATOIRE_H

#include <ctime>
#include <cstdlib>

class Aleatoire
{
    public:
        /** Default constructor */
        Aleatoire();
        /** Default destructor */
        virtual ~Aleatoire();
        static int  aleatoire(int mini, int maxi);
    protected:
    private:
};

#endif // ALEATOIRE_H
