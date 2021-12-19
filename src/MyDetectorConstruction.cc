#include "MyDetectorConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction() {}
MyDetectorConstruction::~MyDetectorConstruction() {}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();
    G4double z = 1.;
    G4double massOfMole = 1.008 * g / mole;
    G4double density = 1.e-25 * g / cm3;
    G4double temperature = 2.73 * kelvin;
    G4double pressure = 3.e-18 * pascal;
    auto *vacuum = new G4Material("galactic", z, massOfMole, density, kStateGas, temperature, pressure);

    G4double worldSize = 2 * m + 2 * 1 * mm;
    G4Material *worldMaterial = vacuum;

    auto *solidWorld = new G4Box("solidWorld", 0.5 * worldSize, 0.5 * worldSize, 0.5 * worldSize);
    auto *logicWorld = new G4LogicalVolume(solidWorld, worldMaterial, "logicWorld");
    auto *physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "physWorld", 0, false, 0, true);

    G4double foilSizeX = 1. * um;
    G4double foilSizeYZ = 0.1 * m;
    G4Material *foilMaterial = nist->FindOrBuildMaterial("G4_Au");

    auto *solidFoil = new G4Box("solidFoil", 0.5 * foilSizeX, 0.5 * foilSizeYZ, 0.5 * foilSizeYZ);
    auto *logicFoil = new G4LogicalVolume(solidFoil, foilMaterial, "logicFoil");
    new G4PVPlacement(0, G4ThreeVector(), logicFoil, "physFoil", logicWorld, false, 0, true);

    G4double detectorRmin = 1 * m;
    G4double detectorRmax = 1 * m + 1 * mm;
    G4Material *detectorMaterial = vacuum;

    auto *solidDetector = new G4Sphere("solidDetector", detectorRmin, detectorRmax, 0, 2 * M_PI * rad, 0, 2 * M_PI * rad);
    logicDetector = new G4LogicalVolume(solidDetector, detectorMaterial, "logicDetector");
    new G4PVPlacement(0, G4ThreeVector(), logicDetector, "physDetector", logicWorld, 0, true);

    return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
    logicDetector->SetSensitiveDetector(new MySensitiveDetector("SensitiveDetector"));
}
