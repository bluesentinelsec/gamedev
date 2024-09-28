.PHONY: build

SOURCES = src/main.cpp src/videomode.cpp

dev:
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

release: clean
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
	cmake --build build

web: clean
	mkdir build
	emcc $(SOURCES) -o build/spaceinvaders.html -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s SDL2_IMAGE_FORMATS='["png","jpg"]' -s USE_SDL_TTF=2 -s USE_FREETYPE=1 -s USE_SDL_MIXER=2 -s SDL2_MIXER_FORMATS='["mp3"]' -Iexternal/tileson/ --preload-file media


clean:
	rm -rf build
