.PHONY: build

SOURCES = src/main.cpp src/videomode.cpp src/titleScene.cpp src/gameplayScene.cpp src/backgroundTile.cpp

dev:
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

release: clean
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
	cmake --build build

docker:
	docker build . -t spaceinvaders:latest
	docker run -it -p 8080:8080 spaceinvaders:latest

web: clean
	mkdir build
	emcc $(SOURCES) -o build/spaceinvaders.js -DSI_Debug -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["bmp", "gif", "lbm", "pcx", "png", "pnm", "tga", "xcf", "xpm", "xv"]' -s USE_SDL_TTF=2 -s USE_SDL_MIXER=2 -s SDL2_MIXER_FORMATS='["mp3", "ogg", "mod", "mid"]' -Iexternal/tileson/ --preload-file media
	cp internal/index.html build/index.html


clean:
	rm -rf build
