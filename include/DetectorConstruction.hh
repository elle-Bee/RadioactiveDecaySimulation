#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"



class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
   ~DetectorConstruction();

    virtual     
    G4VPhysicalVolume* Construct();
                        
    G4double GetWorldSize() {return fWorldSize;}; 

  private:
  
    G4double fWorldSize;
};


#endif

