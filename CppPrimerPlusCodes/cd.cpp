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
    performers = new char [std::strlen(perf) + 1];
    strcpy(performers, perf);
    label = new char [strlen(l) + 1];
    strcpy(label, l);
    selections = sel;
    playtime = pt;
}

Cd::Cd(const Cd & cd)
{
    performers = new char [strlen(cd.performers) + 1];
    strcpy(performers, cd.performers);
    label = new char [strlen(cd.label) + 1];
    strcpy(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
}

Cd::Cd()
{
    performers = new char [strlen("performers") + 1];
    strcpy(performers, "performers");
    label = new char [strlen("label") + 1];
    strcpy(label, "label");
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] label;
    delete [] performers;
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
//     cout << "This is CD operator." << endl;
//     return *this;
    if (&cd == this)
        return *this;
    delete [] performers;
    performers = new char [strlen(cd.performers) + 1];
    strcpy(performers, cd.performers);
    delete [] label;
    label = new char [strlen(cd.label) + 1];
    strcpy(label, cd.label);
    selections = cd.selections;
    playtime = cd.playtime;
    return *this;
}

/*
 *  Class Classic Methods
 */
Classic::Classic(const char * mw, const char * perf, const char * l, 
    int sel, double pt) : Cd(perf, l, sel, pt)
{
    majorWorks = new char [strlen(mw) + 1];
    strcpy(majorWorks, mw);
}

Classic::Classic(const char * mw, const Cd & cd) : Cd(cd)
{
    majorWorks = new char [strlen(mw) + 1];
    strcpy(majorWorks, mw);
}

Classic::Classic(const Classic & c) : Cd(c) // :Cd(c) is very importent
{
    majorWorks = new char [strlen(c.majorWorks) + 1];
    strcpy(majorWorks, c.majorWorks);
}

Classic::Classic() : Cd()
{
    majorWorks = new char [strlen("The Major Works") + 1];
    strcpy(majorWorks, "The Major Works");
}

Classic::~Classic()
{
    delete [] majorWorks;
}

void Classic::report() const
{
    cout << "This Classic CD has those major works: \n"
        << majorWorks << endl;
    Cd::report();
}    

Classic & Classic::operator= (const Classic & c)
{
//     cout << "This is Classic operator\n";
//     return *this;
    if (&c == this)
        return *this;
    Cd::operator=(c);
    delete [] majorWorks;
    majorWorks = new char [strlen(c.majorWorks) + 1];
    strcpy(majorWorks, c.majorWorks);
    return *this;
}

// Classic & Classic::operator= (const Cd & cd)
// {
//     cout << "This is Classic cd operator\n";
//     return *this;
// }