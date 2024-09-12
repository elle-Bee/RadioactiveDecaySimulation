{
  gROOT->Reset();
  
  // Draw histos filled by Geant4 simulation 
  //   
  ////TFile f("run1.root");
  TFile f("Ni60.root");      
  TCanvas* c1 = new TCanvas("c1", "  ");
  
  c1->SetLogy(1);
  c1->cd();
  c1->Update();
  
  TH1D* hist8 = (TH1D*)f.Get("8");
  hist8->Draw("HIST");        
}  
