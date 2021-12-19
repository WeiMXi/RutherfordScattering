#include "MySensitiveDetector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name) {}
MySensitiveDetector::~MySensitiveDetector() {}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *)
{
    G4Track *track = aStep->GetTrack();
    track->SetTrackStatus(fStopAndKill);

    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4ThreeVector particlePosition = preStepPoint->GetPosition();
    //G4cout << "particle position: " << particlePosition << G4endl;

    auto *analysismanager = G4AnalysisManager::Instance();
    analysismanager->FillNtupleDColumn(0, particlePosition[0]);
    analysismanager->FillNtupleDColumn(1, particlePosition[1]);
    analysismanager->FillNtupleDColumn(2, particlePosition[2]);
    analysismanager->AddNtupleRow(0);

    return true;
}
