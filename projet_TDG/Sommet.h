#ifndef SOMMET_H
#define SOMMET_H

#include <iostream>

class Sommet
{
    private:
        std::string m_name;

    public:

        Sommet();
        Sommet(std::string name);

        virtual ~Sommet();

        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }

};

#endif // SOMMET_H
