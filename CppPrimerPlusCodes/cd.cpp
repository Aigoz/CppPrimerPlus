//cd.cpp -- for Chapter13 Exercise1
#include "cd.h"
#include "Headers.h"

using std::cout;
using std::endl;

/*
 *  Class Cd Methods
 */
Cd::Cd(const char * perf, const char * l, int sel, double pt)
{
    std::strncpy(performers, perf, 49);
    performers[49] = '\0';
    std::strncpy(label, l, 19);
    label[19] = '\0';
    selections = sel;
    playtime = pt;
}

// Cd::Cd(const Cd & cd)

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{

}

void Cd::report() const
{
    cout << "CD's Label: " << label
        << "\nPerformers: " << performers
        << "\nselections: " << selections
        << "\nplaytime: " << playtime << endl;
}

Cd & Cd::operator= (const Cd & cd)
{
    cout << "This is CD operator." << endl;
    return *this;
}

/*
 *  Class Classic Methods
 */
Classic::Classic(const char * mw, const char * perf, const char * l, 
    int sel, double pt) : Cd(perf, l, sel, pt)
{
    std::strncpy(majorWorks, mw, 49);
    majorWorks[49] = '\0';
}

Classic::Classic(const char * mv, const Cd & cd) : Cd(cd)
{
    std::strncpy(majorWorks, mv, 49);
    majorWorks[49] = '\0';
}

Classic::Classic() : Cd()
{
    majorWorks[0] = '\0';
}

Classic::~Classic()
{

}

void Classic::report() const
{
    cout << "This Classic CD has those major works: \n"
        << majorWorks << endl;
    Cd::report();
}    

Classic & Classic::operator= (const Classic & c)
{
    cout << "This is Classic operator\n";
    return *this;
}

Classic & Classic::operator= (const Cd & cd)
{
    cout << "This is Classic cd operator\n";
    return *this;
}