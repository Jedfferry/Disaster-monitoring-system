
all: lib app


lib:
	arm-linux-gcc -fPIC -shared   graphic.c  -o libgraphic.so


app:
	arm-linux-gcc project.c  -I. -L. -lgraphic  -o project -lpthread


clean:
	rm   project

