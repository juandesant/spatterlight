args.o: args.c args.h main.h types.h sysdep.h acode.h
arun.o: arun.c main.h types.h sysdep.h acode.h term.h version.h args.h
chartest.o: chartest.c
debug.o: debug.c types.h sysdep.h acode.h version.h readline.h inter.h \
 main.h parse.h exe.h debug.h
decode.o: decode.c main.h types.h sysdep.h acode.h decode.h
dumpacd.o: dumpacd.c types.h sysdep.h acode.h spa.h
exe.o: exe.c types.h sysdep.h acode.h readline.h main.h parse.h \
 inter.h stack.h decode.h exe.h
genalan.o: genalan.c spa.h
inter.o: inter.c types.h sysdep.h acode.h main.h parse.h exe.h stack.h \
 inter.h
main.o: main.c sysdep.h types.h acode.h main.h readline.h version.h \
 args.h parse.h inter.h rules.h debug.h stack.h exe.h term.h
params.o: params.c types.h sysdep.h acode.h params.h
parse.o: parse.c types.h sysdep.h acode.h readline.h main.h inter.h \
 exe.h term.h debug.h params.h parse.h
readline.o: readline.c readline.h types.h sysdep.h acode.h main.h
reverse.o: reverse.c types.h sysdep.h acode.h main.h reverse.h
rules.o: rules.c types.h sysdep.h acode.h main.h inter.h debug.h exe.h \
 stack.h rules.h
spa.o: spa.c spa.h
stack.o: stack.c types.h sysdep.h acode.h main.h stack.h
sysdep.o: sysdep.c sysdep.h
term.o: term.c main.h types.h sysdep.h acode.h term.h
version.o: version.c version.h
