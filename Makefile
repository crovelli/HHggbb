# $Id: Makefile,v 1.3 2013/05/23 10:12:38 crovelli Exp $
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

BINFILES = $(wildcard *.cpp)

PROGRAMS = $(patsubst %.cpp,%,$(BINFILES))


# --- External configuration ---------------------------------
CC         = g++ -Wall
CCFLAGS    =  -g 
MFLAGS     = -MM
INCLUDES   =
WORKDIR    = $(PWD)
LIBDIR     = $(WORKDIR)
OBJDIR=$(WORKDIR)/objects/
# -------------------------------------------------------------

ROOFIT_INCLUDE := $(shell cd $(CMSSW_BASE); scram tool info roofitcore | grep INCLUDE= | sed 's|INCLUDE=||')
ROOFIT_LIBDIR := $(shell cd $(CMSSW_BASE); scram tool info roofitcore | grep LIBDIR= | sed 's|LIBDIR=||')
ROOFIT_LIBS := $(shell cd $(CMSSW_BASE); scram tool info roofitcore | grep LIB= | sed 's|LIB=||')
ROOFIT_LIBS += $(shell cd $(CMSSW_BASE); scram tool info roofit | grep LIB= | sed 's|LIB=||') 


INCLUDES += -I.  -I.. -I$(ROOTSYS)/include  -I$(ROOFIT_INCLUDE)/ -I$(CMSSW_BASE)/src -I$(CMSSW_BASE)/src/CommonTools -I$(CMSSW_BASE)/src/
ROOTSYS  ?= ERROR_RootSysIsNotDefined

EXTRALIBS  :=  -L$(ROOTSYS)/lib -L$(ROOFIT_LIBDIR)/ -lHtml -lMathCore -lGenVector -lMinuit -lEG -lRooFitCore -lRooFit -lRIO -lTMVA

# CC files excluding the binaries
CCFILES=$(filter-out $(BINFILES),$(wildcard *.cc))

# List of all object files to build
OLIST = $(OBJDIR)/RedNtpFinalizer.o $(OBJDIR)/AnalysisJet.o $(OBJDIR)/BTagSFUtil.o $(OBJDIR)/SFlightFuncs.o $(OBJDIR)/MistagFuncs.o 
OLIST += $(OBJDIR)/DrawBase.o $(OBJDIR)/fitTools.o
OLIST += $(OBJDIR)/TAbsFitParticle.o $(OBJDIR)/TAbsFitConstraint.o $(OBJDIR)/TFitConstraintM.o $(OBJDIR)/TFitParticleEtEtaPhi.o $(OBJDIR)/TKinFitter.o $(OBJDIR)/DiJetKinFitter.o
OLIST += $(OBJDIR)/HelicityLikelihoodDiscriminant.o $(OBJDIR)/RooPentaSpinTwo.o $(OBJDIR)/RooBphione.o $(OBJDIR)/RooBtheta.o $(OBJDIR)/RooBkg2l2jHL.o $(OBJDIR)/RooSpinZero5DV2.o $(OBJDIR)/RooBkgd2L2JV2.o 
OLIST +=$(patsubst %.cc,$(OBJDIR)/%.o,$(notdir $(CCFILES)))

$(OBJDIR)/RedNtpFinalizer.o: $(CMSSW_BASE)/src/CommonTools/RedNtpFinalizer.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/AnalysisJet.o: $(CMSSW_BASE)/src/CommonTools/AnalysisJet.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/BTagSFUtil.o: $(CMSSW_BASE)/src/BTagSFUtil/src/BTagSFUtil.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/SFlightFuncs.o: $(CMSSW_BASE)/src/BTagSFUtil/src/SFlightFuncs.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/MistagFuncs.o: $(CMSSW_BASE)/src/BTagSFUtil/src/MistagFuncs.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/DrawBase.o: $(CMSSW_BASE)/src/CommonTools/DrawBase.C
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/fitTools.o: $(CMSSW_BASE)/src/CommonTools/fitTools.C
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)


$(OBJDIR)/DiJetKinFitter.o: $(CMSSW_BASE)/src/KinematicFit/DiJetKinFitter.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/TAbsFitParticle.o: $(CMSSW_BASE)/src/KinematicFit/TAbsFitParticle.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/TAbsFitConstraint.o: $(CMSSW_BASE)/src/KinematicFit/TAbsFitConstraint.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/TFitConstraintM.o: $(CMSSW_BASE)/src/KinematicFit/TFitConstraintM.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/TFitParticleEtEtaPhi.o: $(CMSSW_BASE)/src/KinematicFit/TFitParticleEtEtaPhi.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/TKinFitter.o: $(CMSSW_BASE)/src/KinematicFit/TKinFitter.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/HelicityLikelihoodDiscriminant.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/HelicityLikelihoodDiscriminant.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/RooPentaSpinTwo.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/PDFs/RooPentaSpinTwo.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/RooBphione.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/PDFs/RooBphione.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/RooBtheta.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/PDFs/RooBtheta.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/RooBkg2l2jHL.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/PDFs/RooBkg2l2jHL.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/RooSpinZero5DV2.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/PDFs/RooSpinZero5DV2.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR)/RooBkgd2L2JV2.o: $(CMSSW_BASE)/src/HelicityLikelihoodDiscriminant/PDFs/RooBkgd2L2JV2.cc
	@echo "Compiling $<"
	mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)

# Implicit rule to compile all classes
$(OBJDIR)/%.o : %.cc
	@echo "Compiling $<"
	@mkdir -p $(OBJDIR)
	@$(CC) $(CCFLAGS) -c $< -o $@ $(INCLUDES)


$(PROGRAMS) : $(OLIST) $(BINFILES)
	@echo "Linking $@"
	@$(CC) $(CCFLAGS)  $(INCLUDES) $(OLIST) \
	$(ROOTLIBS) $(EXTRALIBS) -o $(WORKDIR)/$@  $(patsubst %,%.cpp,$@)

default : analysis 

all : ${PROGRAMS}

clean:
	rm -Rf $(OBJDIR)/*.o
	rm drawRadion
	rm finalize2012_radion
	rm finalize2012_radion_commonNtp

#.PHONY : shlib lib default clean
