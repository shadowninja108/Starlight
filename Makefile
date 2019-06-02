# TODO (Khangaroo): Make this process a lot less hacky (no, export did not work)
# See MakefileNSO

.PHONY: all clean 100 310 starlight

all: 310

100:
	$(MAKE) starlight S2VER=100 S2VERSTR=1.0.0

310:
	$(MAKE) starlight S2VER=310 S2VERSTR=3.1.0

starlight:
	$(MAKE) all -f MakefileNSO S2VER=$(S2VER) S2VERSTR=$(S2VERSTR)
	$(MAKE) starlight_patch_$(S2VER)/*.ips S2VER=$(S2VER)

starlight_patch_$(S2VER)/*.ips: patches/*.slpatch patches/configs/$(S2VER).config scripts/genPatch.py
	@rm -f starlight_patch_$(S2VER)/*.ips
	python3 scripts/genPatch.py $(S2VER)

clean:
	$(MAKE) clean -f MakefileNSO
	@rm -fr starlight_patch_*
