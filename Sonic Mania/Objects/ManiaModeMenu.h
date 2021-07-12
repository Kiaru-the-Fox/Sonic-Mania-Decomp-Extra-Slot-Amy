#ifndef OBJ_MANIAMODEMENU_H
#define OBJ_MANIAMODEMENU_H

#include "../SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    int field_4;
    Entity *saveSelectMenu;
    Entity *noSaveMenu;
    Entity *secretsMenu;
    int field_14;
    Entity *encoreSaveSelect;
    int field_1C;
    Entity *noSaveMenuEncore;
    int field_24;
    int field_28;
} ObjectManiaModeMenu;

// Entity Class
typedef struct {
	RSDK_ENTITY
} EntityManiaModeMenu;

// Object Struct
extern ObjectManiaModeMenu *ManiaModeMenu;

// Standard Entity Events
void ManiaModeMenu_Update(void);
void ManiaModeMenu_LateUpdate(void);
void ManiaModeMenu_StaticUpdate(void);
void ManiaModeMenu_Draw(void);
void ManiaModeMenu_Create(void* data);
void ManiaModeMenu_StageLoad(void);
void ManiaModeMenu_EditorDraw(void);
void ManiaModeMenu_EditorLoad(void);
void ManiaModeMenu_Serialize(void);

// Extra Entity Functions


#endif //!OBJ_MANIAMODEMENU_H
