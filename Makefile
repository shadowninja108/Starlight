# TODO (Khangaroo): Make this process a lot less hacky (no, export did not work)
# See Makefile2

.PHONY: all clean 100 310

100:
	$(MAKE) all -f Makefile2 S2VER=100 S2VERSTR=1.0.0

310:
	$(MAKE) all -f Makefile2 S2VER=310 S2VERSTR=3.1.0

clean:
	$(MAKE) clean -f Makefile2

all: 310