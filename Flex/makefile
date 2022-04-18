
flexample: main.o flexample.o
	g++ -o $@ $^

%.o: %.cpp 
	g++ -o $@ -c $<

%.cpp: %.l
	flex -o $@ -i $<

clean:
	rm -rf *.o flexample