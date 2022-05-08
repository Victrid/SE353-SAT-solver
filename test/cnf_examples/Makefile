# All testfiles from SATLIB

all: uf20-91 uf50-218 uuf50-218 uf250-1065 uuf250-1065

uf20-91.tar.gz:
	wget https://www.cs.ubc.ca/~hoos/SATLIB/Benchmarks/SAT/RND3SAT/uf20-91.tar.gz

uf20-91: uf20-91.tar.gz
	mkdir uf20-91
	tar xf uf20-91.tar.gz -C uf20-91
	
uf50-218.tar.gz:
	wget https://www.cs.ubc.ca/~hoos/SATLIB/Benchmarks/SAT/RND3SAT/uf50-218.tar.gz

uf50-218: uf50-218.tar.gz
	mkdir uf50-218
	tar xf uf50-218.tar.gz -C uf50-218

uuf50-218.tar.gz:	
	wget https://www.cs.ubc.ca/~hoos/SATLIB/Benchmarks/SAT/RND3SAT/uuf50-218.tar.gz
	
uuf50-218: uuf50-218.tar.gz
	mkdir uuf50-218
	tar xf uuf50-218.tar.gz --strip-components=1 -C uuf50-218

clean:
	rm -rf uf20-91.tar.gz uf20-91 uf50-218.tar.gz uf50-218 uuf50-218.tar.gz uuf50-218
