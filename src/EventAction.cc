#include "EventAction.hh"
#include "HistoManager.hh"
#include "Run.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

#include <iomanip>

EventAction::EventAction()
:G4UserEventAction(),
 fDecayChain(),fEvisTot(0.)
{
  // Set default print level 
  G4RunManager::GetRunManager()->SetPrintProgress(0);
}


EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{
 fDecayChain = " ";
 fEvisTot = 0.;
}


void EventAction::EndOfEventAction(const G4Event* evt)
{
 G4int evtNb = evt->GetEventID(); 
 G4int printProgress = G4RunManager::GetRunManager()->GetPrintProgress();

 //total visible energy
 G4AnalysisManager::Instance()->FillH1(9, fEvisTot);
 Run* run 
  = static_cast<Run*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
 run->EvisEvent(fEvisTot);
}
