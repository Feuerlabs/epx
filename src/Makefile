
MODULES = \
	epx \
	epx_gc \
	epx_rect \
	epx_app \
	epx_sup \
	epx_font \
	epx_backend \
	epx_image \
	epx_image_png \
	epx_image_jpeg \
	epx_image_bmp \
	epx_exif \
	epx_dct \
	epx_huffman \
	epx_view \
	epx_test


#	epx_image_gif \
#	epx_image_tiff \


EBIN = ../ebin
ERLC = erlc

include ../vsn.mk
VSN=$(EPX_VSN)

APP_FILE= epx.app
APP_SRC= $(APP_FILE).src
APP_TARGET= $(EBIN)/$(APP_FILE)

override ERLC_FLAGS = -W 


OBJS = $(MODULES:%=$(EBIN)/%.beam)

TARGET_FILES = $(OBJS) $(APP_TARGET)

debug: ERLC_FLAGS += -Ddebug 

all: $(TARGET_FILES)

debug: all

release: all

depend:
	edep -MM -o ../ebin $(ERLC_FLAGS) $(MODULES:%=%.erl) > depend.mk

dialyze:
	dialyzer --src -o dia.out $(ERLC_FLAGS) -c $(MODULES:%=%.erl) 

clean:
	rm -f $(OBJS)

$(APP_TARGET): $(APP_SRC) ../vsn.mk
	sed -e 's;%VSN%;$(VSN);'  $< > $@

-include depend.mk

$(EBIN)/%.beam:	%.erl
	$(ERLC) $(ERLC_FLAGS) -o $(EBIN) $<