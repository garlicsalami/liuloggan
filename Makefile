CCC = g++ -std=c++11 -Wall -Wextra
FLAGS = -lSDL2 -lSDL2_image
FILES = main.cpp object.cpp game.cpp graphics.cpp player.cpp bomb.cpp
TARGET = liuloggan

all: level1

level1:
	$(CCC) -DLEVEL1 $(FILES) -o $(TARGET) $(FLAGS)

level2:
	$(CCC) -DLEVEL2 $(FILES) -o $(TARGET) $(FLAGS)

level3:
	$(CCC) -DLEVEL3 $(FILES) -o $(TARGET) $(FLAGS)

level4:
	$(CCC) -DLEVEL4 $(FILES) -o $(TARGET) $(FLAGS)

clean:
	rm $(TARGET)
