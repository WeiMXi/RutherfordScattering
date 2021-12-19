#include "MyPrimaryGeneratorAction.hh"

MyPrimaryGeneratorAction::MyPrimaryGeneratorAction()
{
    G4int nParticle = 1;
    fParticleGun = new G4ParticleGun(nParticle);

    auto *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "alpha";
    G4ParticleDefinition *particle = particleTable->FindParticle(particleName);

    G4ThreeVector momentumDirection(-1., 0., 0.);
    G4double energy = 5. * MeV;

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleMomentumDirection(momentumDirection);
    fParticleGun->SetParticleEnergy(energy);
}
MyPrimaryGeneratorAction::~MyPrimaryGeneratorAction()
{
    delete fParticleGun;
}

void MyPrimaryGeneratorAction::GeneratePrimaries(G4Event *anEvent)
{
    G4double gunPositionX = 1 * m - 1 * mm;
    G4double gunPositionYZ = 1 * mm * (G4UniformRand() - 0.5);
    fParticleGun->SetParticlePosition(G4ThreeVector(gunPositionX, gunPositionYZ, gunPositionYZ));

    fParticleGun->GeneratePrimaryVertex(anEvent);
}
