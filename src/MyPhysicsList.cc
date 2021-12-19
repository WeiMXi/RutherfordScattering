#include "MyPhysicsList.hh"

MyPhysicsList::MyPhysicsList()
{
    RegisterPhysics(new G4EmStandardPhysics_option4);
}

MyPhysicsList::~MyPhysicsList() {}
