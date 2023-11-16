#ifndef GUARD_EMOTIONS_H_
#define GUARD_EMOTIONS_H_

//Face positions
#define FS_LEFT 0
#define FS_RIGHT 1

//Face emotions
#define FSE_NORMAL 0
#define FSE_LAUGHING 1
#define FSE_WORRIED 2
#define FSE_ANGRY 3
#define FSE_CRAZY 4
#define FSE_HAPPY 5
#define FSE_SHOCKED 6
#define FSE_SURPRISED 7
#define FSE_WINK 8
#define FSE_SAD 9
#define FSE_SHADOW 1

#define FSN_HIDE 0
#define FSN_SHOW 1
#define FSN_UNDISCOVERED 2

#define FSE_COUNT FSE_SAD+1

//Face indices
#define FS_PROF 0
#define FS_TYLER 1
#define FS_ROSE 2
#define FS_RAKAZ 3
#define FS_KOJIRO 4
#define FS_DAZ 5
#define FS_ZAGAN 6
#define FS_MOM 7
#define FS_PRESIDENT 8

//Special Face indices for genderized player/rival
#define FS_PLAYER 0xFE
#define FS_RIVAL 0xFF

//Special Face Index that does not get displayed (to use with unimplemented face sprites)
#define FS_NULL 0xFD 

#define FDEL_LEFT 0
#define FDEL_RIGHT 1
#define FDEL_BOTH 2

#endif
