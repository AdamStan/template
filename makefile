testmap.out: testmap.cpp map_template.h employee.h
	g++ -g -Wall -pedantic $^ -o $@

.PHONY: clean

clean:
	-rm testmap.out