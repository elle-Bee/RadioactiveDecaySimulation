#include "RunAction.hh"
#include "Run.hh"
#include "PrimaryGeneratorAction.hh"
#include "HistoManager.hh"

#include "G4Run.hh"
#include "G4UnitsTable.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include <iomanip>

RunAction::RunAction(PrimaryGeneratorAction* kin)
:G4UserRunAction(),
 fPrimary(kin), fRun(0), fHistoManager(0)
{
  fHistoManager = new HistoManager();
}

RunAction::~RunAction()
{ 
  delete fHistoManager;
}

G4Run* RunAction::GenerateRun()
{ 
  fRun = new Run();
  return fRun;
}

void RunAction::BeginOfRunAction(const G4Run*)
{ 
  // keep run condition
  if (fPrimary) { 
    G4ParticleDefinition* particle 
      = fPrimary->GetParticleGun()->GetParticleDefinition();
    G4double energy = fPrimary->GetParticleGun()->GetParticleEnergy();
    fRun->SetPrimary(particle, energy);
  }    
      
  //histograms
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->IsActive() ) {
    analysisManager->OpenFile();
  }
}

void RunAction::EndOfRunAction(const G4Run*)
{
 if (isMaster) fRun->EndOfRun();
            
 //save histograms
 G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
 if ( analysisManager->IsActive() ) {
  analysisManager->Write();
  analysisManager->CloseFile();
 } 
}
