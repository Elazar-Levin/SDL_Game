OBJS = *.cpp
OBJ_NAME = game

all : $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -lSDL2_ttf -o $(OBJ_NAME) 
