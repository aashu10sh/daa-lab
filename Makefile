run: build
	./bin/$(notdir $(basename $(SOURCE))).exe
build: 
	gcc $(SOURCE) -o ./bin/$(notdir $(basename $(SOURCE))).exe
