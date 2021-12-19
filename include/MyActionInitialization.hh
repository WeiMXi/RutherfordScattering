#ifndef MYACTIONINITIALIZATION_HH
#define MYACTIONINITIALIZATION_HH

#include "G4VUserActionInitialization.hh"
#include "MyPrimaryGeneratorAction.hh"
#include "MyRunAction.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
    MyActionInitialization();
    virtual ~MyActionInitialization();

    virtual void Build() const;
};

#endif
