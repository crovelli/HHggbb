#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include "CommonTools/DrawBase.h"
#include "CommonTools/fitTools.h"
#include "cl95cms.C"

bool separate_signals = false;

void printYields( DrawBase* db, const std::string& suffix, bool doUL=false );

int main(int argc, char* argv[]) {

  if(  argc != 2 && argc != 3 ) {
    std::cout << "USAGE: ./drawRadion [(string)selType] [bTaggerType=\"JP\"]" << std::endl;
    exit(23);
  }

  std::string selType(argv[1]);

  std::string bTaggerType = "JP";
  if( argc>=3 ) {
    std::string bTaggerType_str(argv[2]);
    bTaggerType = bTaggerType_str;
  }


  DrawBase* db_nostack = new DrawBase("Radion_nostack");
  DrawBase* db_stack   = new DrawBase("Radion_stack");

  db_nostack->set_lumiOnRightSide();
  db_stack->set_lumiOnRightSide();

  db_nostack->set_shapeNormalization();

  db_stack->set_lumiNormalization(30000.);
  db_stack->set_noStack(false);

  std::string outputdir_str = "RadionPlots_MConly_" + selType + "_" + bTaggerType;
  db_nostack->set_outputdir(outputdir_str);
  db_stack->set_outputdir(outputdir_str);

  int signalFillColor = 46;

  // only for shape comparisons
  std::string RadionFileName = "finalizedTrees_Radion_presel/Radion_";
  RadionFileName += "Radion_M-300_madgraph";
  RadionFileName += "_" + selType;
  RadionFileName += "_" + bTaggerType;
  RadionFileName += ".root";
  TFile* RadionFile = TFile::Open(RadionFileName.c_str());
  db_nostack->add_mcFile( RadionFile, "Radion", "Radion (300)", signalFillColor, 0);
  db_stack->add_mcFile( RadionFile, "Radion", "Radion (300)", signalFillColor, 0);

  std::string HToGGFileName = "finalizedTrees_Radion_presel/Radion_";
  HToGGFileName += "HToGG_M-125_8TeV-pythia6";
  HToGGFileName += "_" + selType;
  HToGGFileName += "_" + bTaggerType;
  HToGGFileName += ".root";
  TFile* HToGGFile = TFile::Open(HToGGFileName.c_str());
  // db_nostack->add_mcFile( HToGGFile, "HToGG", "H (125)", 29);
  db_stack->add_mcFile( HToGGFile, "HToGG", "H (125)", 29);

  /*
  std::string HglugluToGGFileName = "finalizedTrees_Radion_presel/Radion_";
  HglugluToGGFileName += "GluGluToHToGG_M-125_8TeV-powheg-pythia6_Summer12-PU_S7_START52_V9-v1";
  HglugluToGGFileName += "_" + selType;
  HglugluToGGFileName += "_" + bTaggerType;
  HglugluToGGFileName += ".root";
  TFile* HglugluToGGFile = TFile::Open(HglugluToGGFileName.c_str());
  db_nostack->add_mcFile( HglugluToGGFile, "HToGG gluglu", "H (125), gluglu", 30);
  db_stack->add_mcFile( HglugluToGGFile, "HToGG gluglu", "H (125), gluglu", 30);

  std::string HvbfToGGFileName = "finalizedTrees_Radion_presel/Radion_";
  HvbfToGGFileName += "VBF_HToGG_M-125_8TeV-powheg-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1";
  HvbfToGGFileName += "_" + selType;
  HvbfToGGFileName += "_" + bTaggerType;
  HvbfToGGFileName += ".root";
  TFile* HvbfToGGFile = TFile::Open(HvbfToGGFileName.c_str());
  db_nostack->add_mcFile( HvbfToGGFile, "HToGG vbf", "H (125), vbf", 30);
  db_stack->add_mcFile( HvbfToGGFile, "HToGG vbf", "H (125), vbf", 30);
  */

  std::string HvhToGGFileName = "finalizedTrees_Radion_presel/Radion_";
  HvhToGGFileName += "WH_ZH_HToGG_M-125_8TeV-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1";
  HvhToGGFileName += "_" + selType;
  HvhToGGFileName += "_" + bTaggerType;
  HvhToGGFileName += ".root";
  TFile* HvhToGGFile = TFile::Open(HvhToGGFileName.c_str());
  db_nostack->add_mcFile( HvhToGGFile, "HToGG VH", "H (125), VH", 38);
  // db_stack->add_mcFile( HvhToGGFile, "HToGG VH", "H (125), VH", 38);

  /*
  std::string HtthToGGFileName = "finalizedTrees_Radion_presel/Radion_";
  HtthToGGFileName += "TTH_HToGG_M-125_8TeV-pythia6_Summer12_DR53X-PU_S10_START53_V7A-v1";
  HtthToGGFileName += "_" + selType;
  HtthToGGFileName += "_" + bTaggerType;
  HtthToGGFileName += ".root";
  TFile* HtthToGGFile = TFile::Open(HtthToGGFileName.c_str());
  db_nostack->add_mcFile( HtthToGGFile, "HToGG TTH", "H (125), ttH", 30);
  db_stack->add_mcFile( HtthToGGFile, "HToGG TTH", "H (125), ttH", 30);
  */

  std::string DiPhotonFileName = "finalizedTrees_Radion_presel/Radion_";
  DiPhotonFileName += "DiPhoton_8TeV-pythia6";
  DiPhotonFileName += "_" + selType;
  DiPhotonFileName += "_" + bTaggerType;
  DiPhotonFileName += ".root";
  TFile* DiPhotonFile = TFile::Open(DiPhotonFileName.c_str());
  db_nostack->add_mcFile( DiPhotonFile, "DiPhoton", "Diphoton", 31);
  db_stack->add_mcFile( DiPhotonFile, "DiPhoton", "Diphoton", 31);

  std::string GammaJetFileName = "finalizedTrees_Radion_presel/Radion_";
  GammaJetFileName += "GJet_doubleEMEnriched_TuneZ2star_8TeV-pythia6";
  GammaJetFileName += "_" + selType;
  GammaJetFileName += "_" + bTaggerType;
  GammaJetFileName += ".root";
  TFile* GammaJetFile = TFile::Open(GammaJetFileName.c_str());
  // db_nostack->add_mcFile( GammaJetFile, "GammaJet", "#gamma + Jet", 37);
  db_stack->add_mcFile( GammaJetFile, "GammaJet", "#gamma + Jet", 37);

  std::string DiBosonFileName = "finalizedTrees_Radion_presel/Radion_";
  DiBosonFileName += "VV_8TeV";
  DiBosonFileName += "_" + selType;
  DiBosonFileName += "_" + bTaggerType;
  DiBosonFileName += ".root";
  TFile* DiBosonFile = TFile::Open(DiBosonFileName.c_str());
  // db_nostack->add_mcFile( DiBosonFile, "DiBoson", "Diboson", 38);
  db_stack->add_mcFile( DiBosonFile, "DiBoson", "Diboson", 38);

  std::string BosonFileName = "finalizedTrees_Radion_presel/Radion_";
  BosonFileName += "V_8TeV";
  BosonFileName += "_" + selType;
  BosonFileName += "_" + bTaggerType;
  BosonFileName += ".root";
  TFile* BosonFile = TFile::Open(BosonFileName.c_str());
  // db_nostack->add_mcFile( BosonFile, "Bosons", "boson", 39);
  db_stack->add_mcFile( BosonFile, "Bosons", "boson", 39);

  std::string TriBosonFileName = "finalizedTrees_Radion_presel/Radion_";
  TriBosonFileName += "VGG_8TeV";
  TriBosonFileName += "_" + selType;
  TriBosonFileName += "_" + bTaggerType;
  TriBosonFileName += ".root";
  TFile* TriBosonFile = TFile::Open(TriBosonFileName.c_str());
  // db_nostack->add_mcFile( TriBosonFile, "TriBoson", "V + #gamma#gamma", 40);
  db_stack->add_mcFile( TriBosonFile, "TriBoson", "V + #gamma#gamma", 40);

  std::string TTFileName = "finalizedTrees_Radion_presel/Radion_";
  TTFileName += "TT_8TeV";
  TTFileName += "_" + selType;
  TTFileName += "_" + bTaggerType;
  TTFileName += ".root";
  TFile* TTFile = TFile::Open(TTFileName.c_str());
  // db_nostack->add_mcFile( TTFile, "TT", "Top", 44);
  db_stack->add_mcFile( TTFile, "TT", "Top", 44);

  std::string QCDFileName = "finalizedTrees_Radion_presel/Radion_";
  QCDFileName += "QCD_doubleEMEnriched_TuneZ2star_8TeV-pythia6";
  QCDFileName += "_" + selType;
  QCDFileName += "_" + bTaggerType;
  QCDFileName += ".root";
  TFile* QCDFile = TFile::Open(QCDFileName.c_str());
  // db_nostack->add_mcFile( QCDFile, "QCD", "QCD", 41);
  db_stack->add_mcFile( QCDFile, "QCD", "QCD", 41);

  bool log = true;

  db_nostack->drawHisto("njets", "Number of Jets", "", "Events");
  db_nostack->drawHisto("nbjets_loose",  "Number of b-Jets (Loose)",  "", "Events");
  db_nostack->drawHisto("nbjets_medium", "Number of b-Jets (Medium)", "", "Events");
  db_nostack->drawHisto("nbjets_tight",  "Number of b-Jets (Tight)",  "", "Events");

  db_nostack->drawHisto("ptphot0", "Lead Photon p_{T}",    "GeV");
  db_nostack->drawHisto("ptphot1", "Sublead Photon p_{T}", "GeV");

  db_nostack->drawHisto("ptjet0",  "Lead Jet p_{T}",       "GeV");
  db_nostack->drawHisto("ptjet1",  "Sublead Jet p_{T}",    "GeV");
  db_nostack->drawHisto("etajet0", "Lead Jet eta",         "");
  db_nostack->drawHisto("etajet1", "Sublead Jet eta",      "");
  db_nostack->drawHisto("ptjet1",  "Sublead Jet eta",      "");

  db_nostack->set_rebin(4);
  db_nostack->drawHisto("mjj_preselJ", "Dijet Mass after photon and jets preselection", "GeV");
  db_nostack->drawHisto("mjj_0btag",   "Dijet Mass", "GeV");
  db_nostack->drawHisto("mjj_1btag",   "Dijet Mass", "GeV");
  db_nostack->drawHisto("mjj_2btag",   "Dijet Mass", "GeV");

  db_nostack->set_rebin(1);
  db_nostack->drawHisto("mgg_preselG", "DiPhoton Invariant Mass after photon presel", "GeV");
  db_nostack->drawHisto("mgg_preselG", "DiPhoton Invariant Mass after photon presel", "GeV");

  db_nostack->set_rebin(4);
  db_nostack->drawHisto("mggjj",       "4body Mass", "GeV");
  db_nostack->drawHisto("mggjj_0btag", "4body Mass", "GeV");
  db_nostack->drawHisto("mggjj_1btag", "4body Mass", "GeV");
  db_nostack->drawHisto("mggjj_2btag", "4body Mass", "GeV");

  db_nostack->set_rebin(2);
  db_nostack->drawHisto("ptDiphot",  "Diphoton p_{T}", "GeV");
  db_nostack->drawHisto("etaDiphot", "Diphoton eta", "");
  db_nostack->drawHisto("deltaPhi", "#Delta#Phi(dijet-diphoton)", "rad");
  db_nostack->drawHisto("deltaEta", "#Delta#Eta(dijet-diphoton)", "");
  db_nostack->drawHisto("ptDijet",  "Dijet p_{T}", "GeV");
  db_nostack->drawHisto("etaDijet", "Dijet eta", "");
  db_nostack->drawHisto("ptRatio",  "Dijet p_{T} / Diphoton p_{T}");
  db_nostack->drawHisto("ptDifference", "Dijet p_{T} - Diphoton p_{T}", "GeV");
  db_nostack->drawHisto("zeppen", "Zeppenfeld Variable");

  db_nostack->set_rebin();
  db_nostack->drawHisto("deltaPhiJets", "Jet-Jet #Delta#phi", "rad");
  db_nostack->drawHisto("deltaEtaJets", "Jet-Jet #Delta#eta");
  db_nostack->drawHisto("deltaFabsEtaJets", "Jet-Jet #Delta|#eta|");

  db_nostack->set_rebin();
  db_nostack->drawHisto("deltaEtaDiphot", "Gamma Gamma #Delta#eta");

  db_nostack->set_rebin(2);
  db_nostack->drawHisto("deltaPhi_kinfit", "#Delta#Phi(dijet-diphoton)", "rad");
  db_nostack->drawHisto("ptDijet_kinfit", "Dijet p_{T}", "GeV");
  db_nostack->drawHisto("ptRatio_kinfit", "Dijet p_{T} / Diphoton p_{T}");
  db_nostack->drawHisto("ptDifference_kinfit", "Dijet p_{T} - Diphoton p_{T}", "GeV");
  db_nostack->drawHisto("zeppen_kinfit", "Zeppenfeld Variable");

  db_nostack->set_rebin();
  db_nostack->drawHisto("deltaEtaJets_kinfit", "Jet-Jet #Delta#eta");
  db_nostack->drawHisto("deltaFabsEtaJets_kinfit", "Jet-Jet #Delta|#eta|");

  db_nostack->drawHisto("cosTheta1");
  db_nostack->drawHisto("cosTheta2");
  db_nostack->drawHisto("cosThetaStar");
  db_nostack->drawHisto("helphi");
  db_nostack->drawHisto("helphi1");

  db_nostack->drawHisto("cosThetaStar_jets");
  db_nostack->drawHisto("helicityAngle_V");

  db_nostack->set_rebin(20);
  db_nostack->drawHisto("mVstar", "V* Mass", "GeV");
  db_nostack->set_rebin(5);
  db_nostack->set_xAxisMax(200);
  db_nostack->drawHisto("ptVstar", "V* p_{T}", "GeV");
  db_nostack->set_xAxisMax();
  db_nostack->drawHisto("etaVstar", "V* #eta");
  db_nostack->drawHisto("phiVstar", "V* #phi", "rad");

  db_nostack->drawHisto("mVstar_kinfit", "V* Mass", "GeV");
  db_nostack->drawHisto("ptVstar_kinfit", "V* p_{T}", "GeV");
  db_nostack->drawHisto("etaVstar_kinfit", "V* #eta");
  db_nostack->drawHisto("phiVstar_kinfit", "V* #phi", "rad");

  db_nostack->set_rebin(40);
  db_nostack->drawHisto("kinfit_chiSquareProbH", "KinFit #chi^{2} Prob");

  db_nostack->set_rebin(1);
  db_nostack->set_legendTitle( "0 b-tag Category (EBEB)" );
  db_nostack->drawHisto("mgg_0btag_ebeb", "DiPhoton Invariant Mass", "GeV");
  db_nostack->set_legendTitle( "1 b-tag Category (EBEB)" );
  db_nostack->drawHisto("mgg_1btag_ebeb", "DiPhoton Invariant Mass", "GeV");
  db_nostack->set_legendTitle( "2 b-tag Category (EBEB)" );
  db_nostack->drawHisto("mgg_2btag_ebeb", "DiPhoton Invariant Mass", "GeV");

  db_nostack->set_legendTitle( "0 b-tag Category (!EBEB)" );
  db_nostack->drawHisto("mgg_0btag_nebeb", "DiPhoton Invariant Mass", "GeV");
  db_nostack->set_legendTitle( "1 b-tag Category (!EBEB)" );
  db_nostack->drawHisto("mgg_1btag_nebeb", "DiPhoton Invariant Mass", "GeV");
  db_nostack->set_legendTitle( "2 b-tag Category (!EBEB)" );
  db_nostack->drawHisto("mgg_2btag_nebeb", "DiPhoton Invariant Mass", "GeV");


  bool doUL = (selType == "default" );  // chiara
  // bool doUL = (selType == "pippo" );  // chiara

  // final
  db_stack->drawHisto("mggjj", "DiPhoton+DiJets Invariant Mass", "GeV");
  printYields( db_stack, "incl", doUL );

  db_stack->set_legendTitle( "0 b-tag Category" );
  db_stack->drawHisto("mggjj_0btag", "DiPhoton+DiJets Invariant Mass", "GeV");
  printYields( db_stack, "0tag", doUL );

  db_stack->set_legendTitle( "1 b-tag Category" );
  db_stack->drawHisto("mggjj_1btag", "DiPhoton+DiJets Invariant Mass", "GeV");
  printYields( db_stack, "1tag", doUL );

  db_stack->set_legendTitle( "2 b-tag Category" );
  db_stack->drawHisto("mggjj_2btag", "DiPhoton+DiJets Invariant Mass", "GeV");
  printYields( db_stack, "2tag", doUL );
  return 0;
}

void printYields( DrawBase* db, const std::string& suffix, bool doUL ) {

  std::string yieldsFileName = db->get_outputdir() + "/yields_" + suffix + ".txt";
  cout << "Preparing file with yields: " << yieldsFileName << endl;
  ofstream yieldsFile(yieldsFileName.c_str());

  float xMin = 250.;  // chiara, da cambiare con la massa
  float xMax = 350.;
  std::vector<TH1D*> histos = db->get_lastHistos_mc();
  int binXmin = histos[0]->FindBin(xMin);
  int binXmax = histos[0]->FindBin(xMax) -1;
  std::cout <<  "Considering binXmin = " << binXmin << ", binXmax = " << binXmax << std::endl;
  
  bool foundSignal = false;
  float signal  = 0.;
  float totalBG = 0.;
  float totalBG_ave = 0.;

  yieldsFile << std::endl << "Yields (@ 30 fb-1): " << std::endl;
  for( unsigned int ii=0; ii<histos.size(); ++ii ) {
    yieldsFile << db->get_mcFile(ii).datasetName << " " << histos[ii]->Integral(binXmin, binXmax) << std::endl;
    if( db->get_mcFile(ii).datasetName != "Radion" ) {  
      totalBG += histos[ii]->Integral(binXmin, binXmax);
      totalBG_ave += histos[ii]->Integral(1, histos[ii]->GetNbinsX());
    } else {
      foundSignal = true;
      signal = histos[ii]->Integral(binXmin, binXmax);
    }
  }

  totalBG_ave *= (100.)/(histos[0]->GetXaxis()->GetXmax()-histos[0]->GetXaxis()->GetXmin());  // chiara?

  yieldsFile << "Total BG: "     << totalBG << " (averaged: " << totalBG_ave << ")" << std::endl;
  yieldsFile << "Total Signal: " << signal  << std::endl;

  float signal_xsec = 0.000271;   // chiara, questo x 300 GeV
  float total_signal = signal_xsec*db->get_lumi();
  float effS = signal/total_signal;
  yieldsFile << "Signal efficiency: " << effS << std::endl;

  if( !foundSignal ) std::cout << "WARNING!!! DIDN'T FIND SIGNAL!" << std::endl;  
  
  if( doUL && foundSignal ) {
    float ul = CLA( db->get_lumi(), 0., effS, 0., totalBG, 0. );
    float ul_bgave = CLA( db->get_lumi(), 0., effS, 0., totalBG_ave, 0. );
    yieldsFile << std::endl << "No error on BG:" << std::endl;
    yieldsFile << "UL: " << ul << "    (average BG): " << ul_bgave << std::endl;
    yieldsFile << "UL/SM: " << ul/signal_xsec << "    (average BG): " << ul_bgave/signal_xsec << std::endl;
    // float ul_bgerr = CLA( db->get_lumi(), 0., effS, 0., totalBG, 0.05*totalBG );
    // yieldsFile << std::endl << "5\% error on BG:" << std::endl;
    // yieldsFile << "UL: " << ul_bgerr << std::endl;
    // yieldsFile << "UL/SM: " << ul_bgerr/signal_xsec << std::endl;
  }
}

