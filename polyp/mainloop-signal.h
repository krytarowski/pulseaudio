#ifndef foomainloopsignalhfoo
#define foomainloopsignalhfoo

/* $Id$ */

/***
  This file is part of polypaudio.
 
  polypaudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 2 of the License,
  or (at your option) any later version.
 
  polypaudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with polypaudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include "mainloop-api.h"
#include "cdecl.h"

PA_C_DECL_BEGIN

/** \file
 * UNIX signal support for main loops. In contrast to other
 * main loop event sources such as timer and IO events, UNIX signal
 * support requires modification of the global process
 * environment. Due to this the generic main loop abstraction layer as
 * defined in \ref mainloop-api.h doesn't have direct support for UNIX
 * signals. However, you may hook signal support into an abstract main loop via the routines defined herein.
 */

/** Initialize the UNIX signal subsystem and bind it to the specified main loop */
int pa_signal_init(struct pa_mainloop_api *api);

/** Cleanup the signal subsystem */
void pa_signal_done(void);

/** \struct pa_signal_event
 * An opaque UNIX signal event source object */
struct pa_signal_event;

/** Create a new UNIX signal event source object */
struct pa_signal_event* pa_signal_new(int signal, void (*callback) (struct pa_mainloop_api *api, struct pa_signal_event*e, int signal, void *userdata), void *userdata);

/** Free a UNIX signal event source object */
void pa_signal_free(struct pa_signal_event *e);

/** Set a function that is called when the signal event source is destroyed. Use this to free the userdata argument if required */
void pa_signal_set_destroy(struct pa_signal_event *e, void (*callback) (struct pa_mainloop_api *api, struct pa_signal_event*e, void *userdata));

PA_C_DECL_END

#endif
