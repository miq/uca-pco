/* Copyright (C) 2011, 2012 Matthias Vogelgesang <matthias.vogelgesang@kit.edu>
   (Karlsruhe Institute of Technology)

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published by the
   Free Software Foundation; either version 2.1 of the License, or (at your
   option) any later version.

   This library is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
   details.

   You should have received a copy of the GNU Lesser General Public License along
   with this library; if not, write to the Free Software Foundation, Inc., 51
   Franklin St, Fifth Floor, Boston, MA 02110, USA */

#ifndef __UCA_PCO_CAMERA_H
#define __UCA_PCO_CAMERA_H

#include <glib-object.h>
#include <uca/uca-camera.h>

G_BEGIN_DECLS

#define UCA_TYPE_PCO_CAMERA             (uca_pco_camera_get_type())
#define UCA_PCO_CAMERA(obj)             (G_TYPE_CHECK_INSTANCE_CAST((obj), UCA_TYPE_PCO_CAMERA, UcaPcoCamera))
#define UCA_IS_PCO_CAMERA(obj)          (G_TYPE_CHECK_INSTANCE_TYPE((obj), UCA_TYPE_PCO_CAMERA))
#define UCA_PCO_CAMERA_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST((klass), UCA_TYPE_PCO_CAMERA, UcaPcoCameraClass))
#define UCA_IS_PCO_CAMERA_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE((klass), UCA_TYPE_PCO_CAMERA))
#define UCA_PCO_CAMERA_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS((obj), UCA_TYPE_PCO_CAMERA, UcaPcoCameraClass))

#define UCA_PCO_CAMERA_ERROR uca_pco_camera_error_quark()
typedef enum {
    UCA_PCO_CAMERA_ERROR_LIBPCO_INIT,
    UCA_PCO_CAMERA_ERROR_LIBPCO_GENERAL,
    UCA_PCO_CAMERA_ERROR_UNSUPPORTED,
    UCA_PCO_CAMERA_ERROR_FG_INIT,
    UCA_PCO_CAMERA_ERROR_FG_GENERAL,
    UCA_PCO_CAMERA_ERROR_FG_ACQUISITION
} UcaPcoCameraError;

typedef struct _UcaPcoCamera           UcaPcoCamera;
typedef struct _UcaPcoCameraClass      UcaPcoCameraClass;
typedef struct _UcaPcoCameraPrivate    UcaPcoCameraPrivate;

typedef enum {
    UCA_PCO_CAMERA_RECORD_MODE_SEQUENCE,
    UCA_PCO_CAMERA_RECORD_MODE_RING_BUFFER,
} UcaPcoCameraRecordMode;

typedef enum {
    UCA_PCO_CAMERA_STORAGE_MODE_RECORDER,
    UCA_PCO_CAMERA_STORAGE_MODE_FIFO_BUFFER,
} UcaPcoCameraStorageMode;

typedef enum {
    UCA_PCO_CAMERA_ACQUIRE_MODE_AUTO,
    UCA_PCO_CAMERA_ACQUIRE_MODE_EXTERNAL
} UcaPcoCameraAcquireMode;

typedef enum {
    UCA_PCO_CAMERA_TIMESTAMP_NONE,
    UCA_PCO_CAMERA_TIMESTAMP_BINARY,
    UCA_PCO_CAMERA_TIMESTAMP_BOTH,
    UCA_PCO_CAMERA_TIMESTAMP_ASCII
} UcaPcoCameraTimestamp;

/**
 * UcaPcoCamera:
 *
 * Creates #UcaPcoCamera instances by loading corresponding shared objects. The
 * contents of the #UcaPcoCamera structure are private and should only be
 * accessed via the provided API.
 */
struct _UcaPcoCamera {
    /*< private >*/
    UcaCamera parent;

    UcaPcoCameraPrivate *priv;
};

/**
 * UcaPcoCameraClass:
 *
 * #UcaPcoCamera class
 */
struct _UcaPcoCameraClass {
    /*< private >*/
    UcaCameraClass parent;
};

GType uca_pco_camera_get_type(void);

G_END_DECLS

#endif
