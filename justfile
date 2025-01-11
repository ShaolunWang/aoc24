hi:
	echo "hi"
clean:
	rm -rf build/*
config:
	mkdir -p build && cd build && cmake -G Ninja ../
build dayx:
	cd build && cmake --build . --target {{dayx}}
all dayx:
	just config && just build {{dayx}}
