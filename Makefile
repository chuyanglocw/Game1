cxx_std = -std=c++20
cpps = $(wildcard src/*.cpp)
objs = $(patsubst src/%.cpp,objs/%.o,$(cpps))

include_dirs = -Iinclude/SDL2 -Iinclude/ZYXZ

libs = -lSDL2 -lSDL2_image -lSDL2_ttf

libs_dir = -Lbin

objs/%.o : src/%.cpp
	g++ $(cxx_std) -c $< -o $@ $(include_dirs) -fPIC

compile : $(objs)

#TODO：发布时请在末尾添加 -mwindows 以去除控制台
bin/main : $(objs)
	g++ $(cxx_std) -o $@ $(libs) $(libs_dir) $^

run : bin/main
	@$<

clean :
	rm -f bin/main objs/*.o

.PHONY: run clean