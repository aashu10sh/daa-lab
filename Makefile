run: build
	./bin/$(notdir $(basename $(SOURCE))).exe
build: 
	zig cc $(SOURCE) -o ./bin/$(notdir $(basename $(SOURCE))).exe
