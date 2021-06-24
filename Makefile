#Melissa Barnes, CS410 DomLetters program with C++, 6/22/2021, Instructor Massey
#Makefile

CPP = g++
CPPFLAGS = -Wall -g -Werror

domletters: domletters.cpp
	$(CPP) $(CPPFLAGS) -o domletters domletters.cpp

clean:
	-rm -f domletters
