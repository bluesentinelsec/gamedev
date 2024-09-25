.PHONY: build

dev:
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

release: clean
	cmake -B build -S . -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Release
	cmake --build build

clean:
	rm -rf build
