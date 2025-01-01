build: 
	zig cc $(SOURCE) -o ./bin/$(notdir $(basename $(SOURCE))).elf

run: build
	./bin/$(notdir $(basename $(SOURCE))).elf