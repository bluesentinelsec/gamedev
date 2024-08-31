.PHONY: build

macos_release: clean
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
	cmake --build build
	mkdir -p build/Pong.app/Contents/Frameworks/
	mkdir -p build/Pong.app/Contents/Resources/
	cp media/macos/macos.entitlements build/
	cp media/macos/Icon.icns build/Pong.app/Contents/Resources/Icon.icns
	cp /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-system.2.6.1.dylib build/Pong.app/Contents/Frameworks/
	cp /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-graphics.2.6.1.dylib build/Pong.app/Contents/Frameworks/
	cp /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-window.2.6.1.dylib build/Pong.app/Contents/Frameworks/
	cp /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-audio.2.6.1.dylib build/Pong.app/Contents/Frameworks/
	cp /opt/homebrew/Cellar/sfml/2.6.1/lib/libsfml-network.2.6.1.dylib build/Pong.app/Contents/Frameworks/
	./scripts/sign.sh

clean:
	rm -rf build
