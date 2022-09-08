#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <direct.h>

#define MAX_WEAPON 23				// 최대 무기 개수
#define MAX_CHARACTER 43			// 최대 캐릭터 수
#define MAX_SMALLOBJECT 12			// 최대 소품 수(추가 소품 제외)

enum class XOPS096T : unsigned int {			// XOPS096과 동일
	EP = 0x4FCD8,
	WeaponOffset = 0x5D32C,
	CharacterOffset = 0x5D864,
	SmallObjectOffset = 0x65E73,
};

enum class XOPS097T : unsigned int {
	EP = 0x505D8,
	WeaponOffset = 0x5E32C,
	CharacterOffset = 0x5E864,
	SmallObjectOffset = 0x66E73,
};

enum class XOPS097FT : unsigned int {
	EP = 0x50698,
	WeaponOffset = 0x5E32C,
	CharacterOffset = 0x5E864,
	SmallObjectOffset = 0x66E73,
};

enum class XOPS0975T : unsigned int {
	EP = 0x543B3,
	WeaponOffset = 0x77FB0,
	CharacterOffset = 0x784E8,
	SmallObjectOffset = 0x846E7,
};

enum class XOPSOLT16 : unsigned int {
	EP = 0x54F26,
};

enum class XOPSOLT18 : unsigned int {
	EP = 0x57348,
	WeaponOffset = 0x6540C,
	CharacterOffset = 0x65944,
	SmallObjectOffset = 0x65BB3,
};

enum class XOPSOLT18F : unsigned int {
	EP = 0x57648,
	WeaponOffset = 0x6540C,
	CharacterOffset = 0x65944,
	SmallObjectOffset = 0x65BB3,
};

enum class XOPSOLT18F2 : unsigned int {
	EP = 0x57F48,
	WeaponOffset = 0x6640C,
	CharacterOffset = 0x66944,
	SmallObjectOffset = 0x66BB3,
};

enum class XOPSOLT19 : unsigned int {
	EP = 0x588C8,
	WeaponOffset = 0x6641C,
	CharacterOffset = 0x66954,
	SmallObjectOffset = 0x66BC3,
};

enum class XOPSOLT19F : unsigned int {
	EP = 0x5D57A,
	WeaponOffset = 0x777E8,
	CharacterOffset = 0x77D20,
	SmallObjectOffset = 0x77F8F,
};

enum class XOPSOLT19F2 : unsigned int {
	EP = 0x5D5BA,
	WeaponOffset = 0x777E8,
	CharacterOffset = 0x77D20,
	SmallObjectOffset = 0x77F8F,
};

typedef struct {
	short Damage;
	short Penetration;
	short Speed;
	short Velocity;
	short Ammo;
	short Reload;
	short Reaction;
	short ErrorRangeMin;
	short ErrorRangeMax;
	short mx;
	short my;
	short mz;
	short flashx;
	short flashy;
	short flashz;
	short yakkyou_px;
	short yakkyou_py;
	short yakkyou_pz;
	short arm;
	short mode;
	short scope;
	short texture;
	short model;
	short size;
	short yakkyou_sx;
	short yakkyou_sy;
	short sound_id;
	short sound_volume;
	short silencer;
} WeaponParameter;

typedef struct {
	short texture;
	short ai_level;
	short secondary_weapon;
	short main_weapon;
	short type;
	short up_model;
	short hp;
} CharacterParameter;

typedef struct {
	char jump;
	char model;
	char texture;
	char range;
	char hp;
	char sound;
} SmallObjectParameter;

bool SaveFile(int version, const  char* filename);
bool WriteWeaponINI(WeaponParameter& wParam, int num);
bool WriteCharacterINI(CharacterParameter& cParam, int num);
bool WriteSmallObjectINI(SmallObjectParameter& cParam, int num);

int CheckVersion(const char* filename);
