.SILENT:

CPPFLAGS = -Iinclude #-D_GLIBCXX_DEBUG -D_GLIBCXX_CONCEPT_CHECKS
CXXFLAGS = -fPIC -O0 #-ggdb3 -fstack-protector-all -O3 -fno-inline
CFLAGS = ${CXXFLAGS}
YFLAGS = -d

JITSRC = $(shell find src -name "*.[Ccyl]" | sed -e 's/\.[Ccyl]//g' | sort | uniq)
TESTS = $(shell find test -name "*.C")
HDRS = $(shell find include -name "*.h")

export LD_LIBRARY_PATH := ${CURDIR}

rasm: main.o libjit.so
	echo "  LD  $@"
	${LINK.C} $< -o $@ -ljit -L.

all: libjit.so ${TESTS:.C=} rasm
	${MAKE} ${TESTS:.C=.out}

test/%.out: test/% libjit.so
	echo "=> $<"
	$< > $@
	diff $@ $<.ok

clean:
	echo "Cleaning..."
	${RM} ${TESTS:.C=}
	${RM} ${TESTS:.C=.out}
	${RM} ${JITSRC:=.o}
	${RM} libjit.so rasm
	${RM} src/assembler/parser.h src/assembler/parser.C src/assembler/scanner.C

libjit.so: ${JITSRC:=.o}
	echo "  LD  $@"
	${LINK.C} -shared $+ -o $@

test/%: test/%.o ${HDRS}
	echo "  LD  $@"
	${LINK.C} $< -ljit -L. -o $@

%.o: %.C ${HDRS}
	echo "  CXX  $@"
	${COMPILE.C} $< -o $@

%.o: %.c ${HDRS}
	echo "  CC   $@"
	${COMPILE.c} $< -o $@

%.C: %.y
	echo "  YACC  $@"
	${YACC.y} $<
	mv y.tab.c $@
	mv y.tab.h ${@:.C=.h}

%.C: %.l
	echo "  LEX  $@"
	${LEX.l} $< > $@

src/assembler/yymsg.h: merr snippets.pm
	./$<

src/assembler/yyerror.o: src/assembler/yymsg.h
src/assembler/parser.o: src/assembler/parser.C
src/assembler/scanner.o: src/assembler/scanner.C src/assembler/parser.C src/assembler/parser.h
src/assembler/yyerror.o: src/assembler/parser.h
src/assembler/compiler.o: src/assembler/deserialiser.h
src/assembler/visitors/machine.o: src/assembler/visitors/instruction.h
src/rio/io/hbinreader.o: src/rio/io/binreader_common.h
src/rio/io/nbinreader.o: src/rio/io/binreader_common.h
