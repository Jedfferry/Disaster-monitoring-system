
all: lib app


lib:
	arm-linux-g++ -fPIC -shared   graphic.cpp  button.cpp  -o libgraphic.so


app:
	arm-linux-g++ project.cpp  -I. -L. -lgraphic  -o project -lpthread


clean:
	rm   project  *.o  *.so

