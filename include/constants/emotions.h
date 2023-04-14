#ifndef GUARD_EMOTIONS_H_
#define GUARD_EMOTIONS_H_

//Face positions
#define FS_LEFT 0
#define FS_RIGHT 1

//Face emotions
#define FSE_NORMAL 0
#define FSE_LAUGHING 1
#define FSE_WORRIED 2
#define FSE_SHADOW 1

#define FSN_HIDE 0
#define FSN_SHOW 1
#define FSN_UNDISCOVERED 2

#define FSE_COUNT FSE_WORRIED+1

//Face indices
#define FS_PROF 0
#define FS_TYLER 1
#define FS_ROSE 2

//Special Face indices for genderized player/rival
#define FS_PLAYER 0xFE
#define FS_RIVAL 0xFF

//Special Face Index that does not get displayed (to use with unimplemented face sprites)
#define FS_NULL 0xFD 

#define FDEL_LEFT 0
#define FDEL_RIGHT 1
#define FDEL_BOTH 2

#endif
