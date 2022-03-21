LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: thegame

Fonts.o: Fonts.cpp
	g++ -c "Fonts.cpp" -o Fonts.o

Game.o: Game.cpp
	g++ -c "Game.cpp" -o Game.o

GameMap.o: GameMap.o
	g++ -c "GameMap.cpp" -o GameMap.o

Intro_to_Krusty_Krab.o: Intro_to_Krusty_Krab.o
	g++ -c "Intro_to_Krusty_Krab.cpp" -o Intro_to_Krusty_Krab.o

KrustyKrab.o: KrustyKrab.o
	g++ -c "KrustyKrab.cpp" -o KrustyKrab.o

main.o: main.o
	g++ -c "main.cpp" -o main.o

MainMenu.o: MainMenu.o
	g++ -c "MainMenu.cpp" -o MainMenu.o

OptionsScrene.o: OptionsScrene.o 
	g++ -c "OptionsScrene.cpp" -o OptionsScrene.o 

Player.o: Player.o 
	g++ -c "Player.cpp" -o Player.o 

SpriteMovements.o: SpriteMovements.o 
	g++ -c "SpriteMovements.cpp" -o SpriteMovements.o 

Styles.o: Styles.o 
	g++ -c "Styles.cpp" -o Styles.o 

WinningScreen.o: WinningScreen.o 
	g++ -c "WinningScreen.cpp" -o WinningScreen.o 

thegame: Fonts.o Game.o GameMap.o Intro_to_Krusty_Krab.o KrustyKrab.o main.o MainMenu.o OptionsScrene.o Player.o SpriteMovements.o Styles.o WinningScreen.o 
	@echo "** Building the game **"
	g++ -o thegame Fonts.o Game.o GameMap.o Intro_to_Krusty_Krab.o KrustyKrab.o main.o MainMenu.o OptionsScrene.o Player.o SpriteMovements.o Styles.o WinningScreen.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f thegame *.o

install:
	@echo "** Installing..."
	cp thegame /usr/bin

uninstall:
	@echo "** Uninstalling..."
	rm -f /usr/bin/thegame
