# 615-boost
Compile in straightforward way
g++ -o test-errfinv test-errfinv.cpp

# On CRC cluster may need to use BOOSTINCLUDE env variable 
# after doing module load boost

g++ -I $BOOSTINCLUDE test-errfinv.cpp -o test-errfinv

python2 plotit.py2
or 
python3 plotit.py3

or you can try your luck with using the right version 
with plotit.py
