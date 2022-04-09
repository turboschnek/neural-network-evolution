CC = gcc
CFLAGS = -Wall -g -O3
LIBS= -lm

OBJFILES= main.o perceptron.o

SRCDIR= src
BINDIR= bin
BINNAME= perceptron

default: build clean

build: makedir $(OBJFILES)
	$(CC) $(CFLAGS) $(LIBS) $(OBJFILES) -o $(BINDIR)/$(BINNAME)

%.o : $(SRCDIR)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

makedir:
	rm -rf $(BINDIR)
	mkdir $(BINDIR)

clean:
	rm -f $(OBJFILES)

run:
	cd $(BINDIR); ./$(BINNAME)