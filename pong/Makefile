.PHONY: build

dev:
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
	cmake --build build

run: dev
	cd build && ./Pong


release_macos_arm64: clean
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Pong_Release
	cmake --build build
	mkdir -p build/Pong.app/Contents/Frameworks/
	mkdir -p build/Pong.app/Contents/Resources/
	cp media/macos/macos.entitlements build/
	cp media/macos/Icon.icns build/Pong.app/Contents/Resources/Icon.icns
	cp -R lib/SFML-2.6.1-macOS-clang-arm64/ build/Pong.app/Contents/Frameworks/
	./scripts/sign.sh
	cd build && sudo python3 -m http.server --bind 0.0.0.0 80

clean:
	rm -rf build
