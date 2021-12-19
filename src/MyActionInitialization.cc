#include "MyActionInitialization.hh"

MyActionInitialization::MyActionInitialization() {}
MyActionInitialization::~MyActionInitialization() {}

void MyActionInitialization::Build() const
{
    SetUserAction(new MyRunAction());
    SetUserAction(new MyPrimaryGeneratorAction());
}
