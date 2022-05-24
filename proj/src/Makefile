# name of the program (Minix service)
PROG=proj

# source code files to be compiled
SRCS = proj.c utils.c video/video.c keyboard/kbc.c timer/timer.c

CFLAGS += -pedantic

DPADD += ${LIBLCF}
LDADD += -llcf

video/video.o: video/video.c video/video.h
		cc $(CFLAGS) -o video/video.o -c video/video.c 
keyboard/kbc.o: keyboard/kbc.c keyboard/kbc.h
		cc $(CFLAGS) -o keyboard/kbc.o -c keyboard/kbc.c 
timer/timer.o: timer/timer.c timer/timer.h
		cc $(CFLAGS) -o timer/timer.o -c timer/timer.c 

# include LCOM's makefile that does all the "heavy lifting"
.include <minix.lcom.mk>
