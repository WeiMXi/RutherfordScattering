#include "MyRunAction.hh"

MyRunAction::MyRunAction() {}
MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run *)
{
    auto *analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("out.root");

    analysisManager->CreateNtuple("Hits", "Hits");
    analysisManager->CreateNtupleDColumn("x");
    analysisManager->CreateNtupleDColumn("y");
    analysisManager->CreateNtupleDColumn("z");
    analysisManager->FinishNtuple(0);
}

void MyRunAction::EndOfRunAction(const G4Run *)
{
    auto *analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
