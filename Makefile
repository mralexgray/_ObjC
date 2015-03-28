
CC=clang

docs: _ObjC.h
	 headerdoc2html -p _ObjC.h -o docs

clean:
	rm -r docs

