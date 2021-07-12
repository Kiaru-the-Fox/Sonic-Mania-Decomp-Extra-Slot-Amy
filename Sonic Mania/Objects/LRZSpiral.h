#ifndef OBJ_LRZSPIRAL_H
#define OBJ_LRZSPIRAL_H

#include "../SonicMania.h"

// Object Class
typedef struct {
    RSDK_OBJECT
    int array1[128]; //= { 0, 65536, 131072, 196608, 262144, 327680, 393216, 458752, 524288, 589824, 655360, 786432, 851968, 983040, 1048576, 1179648,
                     //1245184, 1245184, 1310720, 1310720, 1441792, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328,
                     //1507328, 1507328, 1572864, 1572864, 1572864, 1572864, 1638400, 1769472, 1835008, 1966080, 2031616, 2162688, 2228224, 2359296,
                     //2424832, 2555904, 2621440, 2752512, 2818048, 2949120, 3014656, 3145728, 3211264, 3342336, 3407872, 3538944, 3604480, 3735552,
                     //3801088, 3932160, 3997696, 4128768, 4194304, 4325376, 4390912, 4521984, 4587520, 4718592, 4784128, 4915200, 4980736, 5111808,
                     //5177344, 5308416, 5373952, 5505024, 5570560, 5701632, 5767168, 5898240, 5963776, 6094848, 6160384, 6291456, 6291456, 6291456,
                     //6291456, 6291456, 6291456, 6291456, 6291456, 6291456, 6291456, 6291456, 6291456, 6291456, 6291456, 6356992, 6422528, 6488064,
                     //6553600, 6619136, 6684672, 6750208, 6815744, 6881280, 6946816, 7012352, 7077888, 7143424, 7208960, 7274496, 7340032, 7405568,
                     //7471104, 7536640, 7602176, 7667712, 7733248, 7798784, 7864320, 7929856, 7995392, 8060928, 8126464, 8192000, 8257536, 8323072 };
    int array2[64]; //= { 0, 65536, 131072, 196608, 262144, 327680, 393216, 458752, 524288, 589824, 655360, 786432, 851968, 983040, 1048576, 1179648,
                    //1245184, 1245184, 1310720, 1310720, 1441792, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328, 1507328,
                    //1507328, 1507328, 1572864, 1572864, 1572864, 1572864, 1638400, 1638400, 1638400, 1703936, 1703936, 1703936, 1769472, 1769472,
                    //1769472, 1835008, 1835008, 1835008, 1900544, 1900544, 1900544, 1900544, 1966080, 1966080, 1966080, 2031616, 2031616, 2031616,
                    //2097152, 2097152, 2097152, 2162688, 2162688, 2162688 };
    Animator animator;
    ushort aniFrames;
} ObjectLRZSpiral;

// Entity Class
typedef struct {
    RSDK_ENTITY
    StateMachine(state);
    byte type;
    int height;
    int radius;
    byte activePlayers;
    int playerVelocity[4];
    Hitbox hitbox;
} EntityLRZSpiral;

// Object Struct
extern ObjectLRZSpiral *LRZSpiral;

// Standard Entity Events
void LRZSpiral_Update(void);
void LRZSpiral_LateUpdate(void);
void LRZSpiral_StaticUpdate(void);
void LRZSpiral_Draw(void);
void LRZSpiral_Create(void* data);
void LRZSpiral_StageLoad(void);
void LRZSpiral_EditorDraw(void);
void LRZSpiral_EditorLoad(void);
void LRZSpiral_Serialize(void);

// Extra Entity Functions
void LRZSpiral_Unknown1(void *p);
void LRZSpiral_Unknown2(void);
void LRZSpiral_Unknown3(void);
void LRZSpiral_Unknown4(void);


#endif //!OBJ_LRZSPIRAL_H
