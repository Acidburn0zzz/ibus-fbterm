/* -*- mode: C; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/* vim:set et sts=4: */
/*
 * Copyright (C) 2015 Takao Fujiwara <takao.fujiwara1@gmail.com>
 * Copyright (C) 2015 Red Hat, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __FB_IO_OBJECT_H_
#define __FB_IO_OBJECT_H_

#include <glib-object.h>
#include <ibus.h>


/*
 * Type macros.
 */

/* define GOBJECT macros */
#define FB_TYPE_IO                              (fb_io_get_type ())
#define FB_IO(o)                                (G_TYPE_CHECK_INSTANCE_CAST ((o), FB_TYPE_IO, FbIo))
#define FB_IO_CLASS(k)                          (G_TYPE_CHECK_CLASS_CAST ((k), FB_TYPE_IO, FbIoClass))
#define FB_IS_IO(o)                             (G_TYPE_CHECK_INSTANCE_TYPE ((o), FB_TYPE_IO))
#define FB_IS_IO_CLASS(k)                       (G_TYPE_CHECK_CLASS_TYPE ((k), FB_TYPE_IO))
#define FB_IO_GET_CLASS(o)                      (G_TYPE_INSTANCE_GET_CLASS ((o), FB_TYPE_IO, FbIoClass))


G_BEGIN_DECLS
typedef struct _FbIo FbIo;
typedef struct _FbIoPrivate FbIoPrivate;
typedef struct _FbIoClass FbIoClass;

/**
 * FbIo:
 *
 * <structname>FbIo</structname> provides an IO structure
 * related with the frame buffer.
 */
struct _FbIo {
    IBusObject parent; 
    FbIoPrivate *priv;
};

struct _FbIoClass {
    IBusObjectClass parent;

    /**
     * FbIoClass::ready_read:
     * @io: A #FbIo.
     * @buff: A read buffer
     * @length: A length of the buffer.
     *
     * The ::ready_read class method is to read
     * sequences from the frame buffer.
     */

    void (* ready_read)     (FbIo        *io,
                             const gchar *buff,
                             guint        length);

    gpointer dummy[5];
};

GType            fb_io_get_type                  (void);

/**
 * fb_io_new:
 *
 * Creates  a new #FbIo.
 *
 * Returns: A newly allocated #FbIo
 */
FbIo            *fb_io_new                         (void);

int              fb_io_get_fd                      (FbIo        *io);
void             fb_io_set_fd                      (FbIo        *io,
                                                    int          fd);
void             fb_io_write                       (FbIo        *io,
                                                    const gchar *buff,
                                                    guint        length);
G_END_DECLS
#endif
