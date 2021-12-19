void RuScatAna()
{   
    auto *inFile = new TFile("./build/out.root");
    auto *myTree = (TTree *)inFile->Get("Hits");

    double x, y, z;
    myTree->SetBranchAddress("x", &x);
    myTree->SetBranchAddress("y", &y);
    myTree->SetBranchAddress("z", &z);

    auto *histogramI = new TH1F("histogram I", "Angle Distribution; Angle(^{o}); Counts", 1e3, 0, 90);
    auto *histogramII = new TH1F("histogram II", "Angle Distribution; Angle(^{o}); Counts", 1e3, 90, 180); 

    int entries = myTree->GetEntries();
    int count = 0;
    for (int i = 0; i < entries; i++)
    {
        myTree->GetEntry(i);
        TVector3 u(x, y, z);
        TVector3 v(-1, 0, 0);
        double a = u.Angle(v) / TMath::Pi() * 180;
        
        if (a < 90)
        {   
            histogramI->Fill(a);
        }
        else
        {
            histogramII->Fill(a);
            count++;
        }
    }

    auto *canvasI = new TCanvas();
    histogramI->Draw();
    auto *canvasII = new TCanvas();
    histogramII->Draw();
    cout << "angle > 90 counts: " << count << endl;
}
