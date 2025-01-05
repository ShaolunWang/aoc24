hi:
	echo "hi"
clean:
	rm -rf build/*
config:
	cd build && cmake -G Ninja ../
build dayx:
	cd build && cmake --build . --target {{dayx}}

