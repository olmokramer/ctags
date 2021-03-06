/*
*
*   Copyright (c) 2017, Red Hat, Inc.
*   Copyright (c) 2017, Masatake YAMATO
*
*   This source code is released for free distribution under the terms of the
*   GNU General Public License version 2 or (at your option) any later version.
*
*   Facility for delayed memory releasing, insptired from AutoreleasePool
*   of OpenStep.
*/

#ifndef CTAGS_MAIN_TRASH_H
#define CTAGS_MAIN_TRASH_H

typedef void (* TrashBoxDestroyItemProc) (void *);
typedef struct sTrashBox TrashBox;

extern TrashBox* trashBoxNew       (void);
extern TrashBox* trashBoxStack     (TrashBox* trash_box);
extern void      trashBoxDelete    (TrashBox* trash_box);
extern void*     trashBoxPut       (TrashBox* trash_box, void* item, TrashBoxDestroyItemProc destroy);
extern TrashBoxDestroyItemProc trashBoxTakeBack  (TrashBox* trash_box, void* item);
extern void      trashBoxFree      (TrashBox* trash_box, void* item);
extern void      trashBoxMakeEmpty (TrashBox* trash_box);

#define TRASH_BOX(PTR,PROC) trashBoxPut(NULL,PTR,(TrashBoxDestroyItemProc)PROC)
#define TRASH_BOX_TAKE_BACK(PTR) trashBoxTakeBack(NULL,PTR)
extern void initDefaultTrashBox (void);
extern void finiDefaultTrashBox  (void);

#endif /* CTAGS_MAIN_TRASH_H */
