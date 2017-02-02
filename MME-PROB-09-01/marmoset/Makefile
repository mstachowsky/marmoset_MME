LDFLAGS = -g
CFLAGS = -Wno-write-strings -Wall -g -Werror
CC = g++

PUBLIC_TESTS = description_sample.py
RELEASE_TESTS =
SECRET_TESTS =
ALL_TESTS = $(PUBLIC_TESTS) $(RELEASE_TESTS) $(SECRET_TESTS)


EXE = circle_intersection

all:	clean $(ALL_TESTS) circle_intersection
	chmod +x $(ALL_TESTS) circle_intersection

clean:
	/bin/rm -rf *.o $(EXE)

circle_intersection.o: circle_intersection.cpp
	$(CC) -c $(LDFLAGS) $<

# g++ <$^:all prereqs> -o <$@:target> <flags>
circle_intersection: circle_intersection.o
	$(CC) $^ -o $@ $(CFLAGS)

check:	circle_intersection.o
	echo $<
	echo $@
	echo "public: $(PUBLIC_TESTS)"
	echo "release: $(RELEASE_TESTS)"
