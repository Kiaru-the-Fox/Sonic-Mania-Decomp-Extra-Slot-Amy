// ---------------------------------------------------------------------
// RSDK Project: Sonic Mania
// Object Description: UIPicture Object
// Object Author: Christian Whitehead/Simon Thomley/Hunter Bridges
// Decompiled by: Rubberduckycooly & RMGRich
// ---------------------------------------------------------------------

#include "Game.h"

ObjectUIPicture *UIPicture;

void UIPicture_Update(void)
{
    RSDK_THIS(UIPicture);

    RSDK.ProcessAnimation(&self->animator);
}

void UIPicture_LateUpdate(void) {}

void UIPicture_StaticUpdate(void) {}

void UIPicture_Draw(void)
{
    RSDK_THIS(UIPicture);

    // Bug Details:
    // This should use zoneID in the CopyPalette params right?
    // using zonePalette would just be 0 or 1 instead of 0-12 or so that you'd expect...

    if (self->zonePalette)
        RSDK.CopyPalette((self->zonePalette >> 3) + 1, 32 * self->zonePalette, 0, 224, 32);

    RSDK.DrawSprite(&self->animator, NULL, false);
}

void UIPicture_Create(void *data)
{
    RSDK_THIS(UIPicture);

    RSDK.SetSpriteAnimation(UIPicture->aniFrames, self->listID, &self->animator, true, self->frameID);

    if (!SceneInfo->inEditor) {
        if (RSDK.CheckStageFolder("Menu")) {
            self->active    = ACTIVE_BOUNDS;
            self->visible   = true;
            self->drawOrder = 2;
        }
        // Uncomment this to fix the "Thanks for playing screen"
        // Not sure what happened, but sometime during dev this must've been shuffled around
        // setting it to ACTIVE_NORMAL fixes the sonic ball sprites
        // setting the draw order to 8 fixes the thanks for playing sprite
        // else if (RSDK.CheckStageFolder("Thanks")) {
        //     self->active    = ACTIVE_NORMAL;
        //     self->visible   = true;
        //     self->drawOrder = 8;
        // }
        else {
            if (RSDK.CheckStageFolder("Logos") || RSDK.CheckStageFolder("LSelect") || RSDK.CheckStageFolder("Summary"))
                self->active = ACTIVE_NORMAL;
            self->visible   = true;
            self->drawOrder = 2;
        }
    }
}

void UIPicture_StageLoad(void)
{
    if (RSDK.CheckStageFolder("Menu"))
        UIPicture->aniFrames = RSDK.LoadSpriteAnimation("UI/Picture.bin", SCOPE_STAGE);
    else if (RSDK.CheckStageFolder("Logos"))
        UIPicture->aniFrames = RSDK.LoadSpriteAnimation("Logos/Logos.bin", SCOPE_STAGE);
}

#if RETRO_INCLUDE_EDITOR
void UIPicture_EditorDraw(void)
{
    RSDK_THIS(UIPicture);

    RSDK.SetSpriteAnimation(UIPicture->aniFrames, self->listID, &self->animator, true, self->frameID);

    RSDK.DrawSprite(&self->animator, NULL, false);
}

void UIPicture_EditorLoad(void)
{
    if (RSDK.CheckStageFolder("Menu"))
        UIPicture->aniFrames = RSDK.LoadSpriteAnimation("UI/Picture.bin", SCOPE_STAGE);
    else if (RSDK.CheckStageFolder("Logos"))
        UIPicture->aniFrames = RSDK.LoadSpriteAnimation("Logos/Logos.bin", SCOPE_STAGE);

    // Never used afaik
    RSDK_ACTIVE_VAR(UIPicture, tag);
    RSDK_ENUM_VAR("(Unused)", 0);

    // Also never used (afaik, see notes in UIPicture_Draw)
    RSDK_ACTIVE_VAR(UIPicture, zoneID);
    RSDK_ENUM_VAR("(Unused)", 0);
}
#endif

void UIPicture_Serialize(void)
{
    RSDK_EDITABLE_VAR(UIPicture, VAR_ENUM, listID);
    RSDK_EDITABLE_VAR(UIPicture, VAR_ENUM, frameID);
    RSDK_EDITABLE_VAR(UIPicture, VAR_ENUM, tag);
    RSDK_EDITABLE_VAR(UIPicture, VAR_BOOL, zonePalette);
    RSDK_EDITABLE_VAR(UIPicture, VAR_UINT8, zoneID);
}