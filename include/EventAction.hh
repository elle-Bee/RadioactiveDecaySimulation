#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class EventAction : public G4UserEventAction
{
  public:
    EventAction();
   ~EventAction();

  public:
    virtual void BeginOfEventAction(const G4Event*);
    virtual void   EndOfEventAction(const G4Event*);
    
    void AddDecayChain(G4String val) {fDecayChain += val;};
    void AddEvisible(G4double val)   {fEvisTot    += val;};
    
  private:
    G4String        fDecayChain;                   
    G4double        fEvisTot;
};

#endif

    
