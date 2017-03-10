
/* advint.c - an interpreter for adventure games */
/*
	Copyright (c) 1986, by David Michael Betz
	All rights reserved
*/

#include "advheader.h"

#include "advint.h"
#include "advdbs.h"


/* global variables */
jmp_buf restart;

/* CHANGED TO WORK WITH GLK */
/* Modernize it */
void play(void);
int single(void);

/* GLK Specifics */
winid_t window;
strid_t screen;

extern strid_t *gas_file;

/* main - the main routine */
void glk_main()
{
    char *fname,*lname;
    int rows,cols;

	frefid_t file;

	window = glk_window_open(0, 0, 0, wintype_TextBuffer, WINDOW);
	screen = glk_window_get_stream(window);
	glk_stream_set_current(screen);

#if 0
#ifdef GARGLK
	garglk_set_program_name("AdvSys 1.2");
	garglk_set_program_info(
			"ADVINT v1.2 - Copyright (c) 1986 by David Betz\n"
			"GLK Build v0.1 - Copyright (c) 2000 by Zenki\n"
			"Gargoyle tweaks by Tor Andersson");
#else

#ifdef WINDOWS
    glk_put_string("ADVINT v1.2 - Copyright (c) 1986, by David Betz\n"
		           "GLK Build v0.1 - Copyright (c) 2000  by Zenki\n\n");
#endif
#ifdef UNIX
    glk_put_string("ADVINT v1.2 - Copyright (c) 1986, by David Betz\n"
                   "GLK Build v0.1 - Copyright(c) 2000 by Zenki\n\n");
#endif
#endif
#endif

    fname = NULL;
    lname = NULL;
    rows = 24;
    cols = 80;

    /* initialize terminal i/o */
    trm_init(rows,cols,lname);

	/* Get the file reference. */
	if (!gas_file)
		error("AdvSys: No file given");

	file = gas_file;

/* END OF CHANGES FOR GLK */

    /* initialize the database */
    db_init(file);

    /* play the game */
    play();
}

/* play - the main loop */
void play()
{
    /* establish the restart point */
    setjmp(restart);

    /* execute the initialization code */
    execute(h_init);

    /* turn handling loop */
    for (;;) {

	/* execute the update code */
	execute(h_update);

	/* parse the next input command */
	if (parse()) {
	    if (single())
		while (next() && single())
		    ;
	}

	/* parse error, call the error handling code */
	else
	    execute(h_error);
    }
}

/* single - handle a single action */
int single()
{
    /* execute the before code */
    switch (execute(h_before)) {
    case ABORT:	/* before handler aborted sequence */
	return (FALSE);
    case CHAIN:	/* execute the action handler */
	if (execute(getafield(getvalue(V_ACTION),A_CODE)) == ABORT)
	    return (FALSE);
    case FINISH:/* execute the after code */
	if (execute(h_after) == ABORT)
	    return (FALSE);
	break;
    }
    return (TRUE);
}

/* error - print an error message and exit */
void error(char *msg)
{
    trm_str(msg);
    trm_chr('\n');
    glk_exit();
}
