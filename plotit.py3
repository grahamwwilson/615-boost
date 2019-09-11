#
# Use pyroot for simple ROOT things
# May need to be careful about whether 
# we use python2 or python3.
# On my laptop, pyroot works with python2 
# In the computer lab, it seems to work with python3.
#
import ROOT

# Initialize output histogram file
f = ROOT.TFile("histos_gaussian.root", "recreate");
# Book histogram
h1 = ROOT.TH1D("h1","Normal distribution",200,-8.0,8.0)

with open("normal.dat") as input_file:
   for line in input_file:
       h1.Fill(float(line))

h1.Print()
print("Mean = ",h1.GetMean()," +- ",h1.GetMeanError())
print("RMS  = ",h1.GetRMS(), " +- ",h1.GetRMSError())
c1 = ROOT.TCanvas("c1","c1")
h1.Draw()
c1.Print("h1.pdf")
f.Write()
