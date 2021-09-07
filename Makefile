#At the moment not more than that
HEADERS = MAIN.H READER.H ANALYZER.H PRINTER.H

default: MAIN

MAIN.O: MAIN.C $(HEADERS)
    gcc -c MAIN.C -o MAIN.O

MAIN: MAIN.o
    gcc MAIN.O -o CUT

clean:
    -rm -f MAIN.O
    -rm -f CUT