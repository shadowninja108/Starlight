# TODO (Khangaroo): Make this process a lot less hacky (no, export did not work)
# See MakefileNSO

.PHONY: all clean starlight send

S2VER ?= 310
S2VERSTR ?= 3.1.0
S2ROMTYPE ?= US

all: starlight

starlight:
	$(MAKE) all -f MakefileNSO S2VER=$(S2VER) S2VERSTR=$(S2VERSTR)
	$(MAKE) starlight_patch_$(S2VER)/*.ips

starlight_patch_$(S2VER)/*.ips: patches/*.slpatch patches/configs/$(S2VER).config patches/maps/$(S2VER)/*.map \
								build$(S2VER)/starlight310.map scripts/genPatch.py
	@rm -f starlight_patch_$(S2VER)/*.ips
	python3 scripts/genPatch.py $(S2VER)

send: all
	python3 scripts/sendPatch.py $(IP) $(S2ROMTYPE) $(S2VER)

clean:
	$(MAKE) clean -f MakefileNSO
	@rm -fr starlight_patch_*
