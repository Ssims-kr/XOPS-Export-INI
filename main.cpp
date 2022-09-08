#include "main.h"

bool SaveFile(int version, const char* filename) {
	WeaponParameter wParam[MAX_WEAPON];
	CharacterParameter cParam[MAX_CHARACTER];
	SmallObjectParameter sParam[MAX_SMALLOBJECT];

	if (version == -1) { return false; }
	if (version == 4) { MessageBox(NULL, L"XOPSOLT16은 지원하지 않습니다.", L"오류", MB_OK); return false; }

	printf("--------------------\n");
	printf("[ 무기 데이터 읽기/쓰기 시작 ]\n");

	FILE *fp;
	fp = fopen(filename, "rb");
	if (fp == nullptr) { return false; }

	// 무기 데이터 읽기
	unsigned int wOffset = 0x00;
	switch (version) {
		case 0: { wOffset = (unsigned int)XOPS096T::WeaponOffset; } break;
		case 1: { wOffset = (unsigned int)XOPS097T::WeaponOffset; } break;
		case 2: { wOffset = (unsigned int)XOPS097FT::WeaponOffset; } break;
		case 3: { wOffset = (unsigned int)XOPS0975T::WeaponOffset; } break;
		//case 4: { wOffset = (unsigned int)XOPSOLT16::WeaponOffset; } break;
		case 5: { wOffset = (unsigned int)XOPSOLT18::WeaponOffset; } break;
		case 6: { wOffset = (unsigned int)XOPSOLT18F::WeaponOffset; } break;
		case 7: { wOffset = (unsigned int)XOPSOLT18F2::WeaponOffset; } break;
		case 8: { wOffset = (unsigned int)XOPSOLT19::WeaponOffset; } break;
		case 9: { wOffset = (unsigned int)XOPSOLT19F::WeaponOffset; } break;
		case 10: { wOffset = (unsigned int)XOPSOLT19F2::WeaponOffset; } break;

		default: { fclose(fp); return false; }
	}

	fseek(fp, wOffset, SEEK_SET);
	short wBuf = 0;
	for (int i = 0; i < MAX_WEAPON; i++) {
		fread(&wBuf, 2, 1, fp);
		wParam[i].Damage = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].Penetration = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].Speed = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].Velocity = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].Ammo = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].Reload = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].Reaction = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].ErrorRangeMin = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].ErrorRangeMax = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].mx = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].my = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].mz = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].flashx = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].flashy = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].flashz = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].yakkyou_px = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].yakkyou_py = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].yakkyou_pz = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].arm = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].mode = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].scope = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].texture = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].model = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].size = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].yakkyou_sx = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].yakkyou_sy = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].sound_id = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].sound_volume = wBuf;
		fread(&wBuf, 2, 1, fp);
		wParam[i].silencer = wBuf;

		// 내보내기
		WriteWeaponINI(wParam[i], i);
	}

	printf("[ 무기 데이터 읽기/쓰기 종료 ]\n");
	printf("--------------------\n");


	printf("--------------------\n");
	printf("[ 캐릭터 데이터 읽기/쓰기 시작 ]\n");

	// 캐릭터 데이터 읽기
	unsigned int cOffset = 0x00;
	switch (version) {
		case 0: { cOffset = (unsigned int)XOPS096T::CharacterOffset; } break;
		case 1: { cOffset = (unsigned int)XOPS097T::CharacterOffset; } break;
		case 2: { cOffset = (unsigned int)XOPS097FT::CharacterOffset; } break;
		case 3: { cOffset = (unsigned int)XOPS0975T::CharacterOffset; } break;
			//case 4: { cOffset = (unsigned int)XOPSOLT16::CharacterOffset; } break;
		case 5: { cOffset = (unsigned int)XOPSOLT18::CharacterOffset; } break;
		case 6: { cOffset = (unsigned int)XOPSOLT18F::CharacterOffset; } break;
		case 7: { cOffset = (unsigned int)XOPSOLT18F2::CharacterOffset; } break;
		case 8: { cOffset = (unsigned int)XOPSOLT19::CharacterOffset; } break;
		case 9: { cOffset = (unsigned int)XOPSOLT19F::CharacterOffset; } break;
		case 10: { cOffset = (unsigned int)XOPSOLT19F2::CharacterOffset; } break;

		default: { fclose(fp); return false; }
	}

	fseek(fp, cOffset, SEEK_SET);
	short cBuf = 0;
	for (int i = 0; i < MAX_CHARACTER; i++) {
		fread(&cBuf, 2, 1, fp);
		cParam[i].texture = cBuf;

		fread(&cBuf, 2, 1, fp);
		cParam[i].up_model = cBuf;

		fread(&cBuf, 2, 1, fp);
		cParam[i].hp = cBuf;

		fread(&cBuf, 2, 1, fp);
		cParam[i].ai_level = cBuf;

		fread(&cBuf, 2, 1, fp);
		cParam[i].secondary_weapon = cBuf;

		fread(&cBuf, 2, 1, fp);
		cParam[i].main_weapon = cBuf;

		fread(&cBuf, 2, 1, fp);
		cParam[i].type = cBuf;

		WriteCharacterINI(cParam[i], i);
	}

	printf("[ 캐릭터 데이터 읽기/쓰기 종료 ]\n");
	printf("--------------------\n");


	printf("--------------------\n");
	printf("[ 소품 데이터 읽기/쓰기 시작 ]\n");

	// 소품 데이터 읽기
	unsigned int sOffset = 0x00;
	switch (version) {
		case 0: { sOffset = (unsigned int)XOPS096T::SmallObjectOffset; } break;
		case 1: { sOffset = (unsigned int)XOPS097T::SmallObjectOffset; } break;
		case 2: { sOffset = (unsigned int)XOPS097FT::SmallObjectOffset; } break;
		case 3: { sOffset = (unsigned int)XOPS0975T::SmallObjectOffset; } break;
			//case 4: { sOffset = (unsigned int)XOPSOLT16::SmallObjectOffset; } break;
		case 5: { sOffset = (unsigned int)XOPSOLT18::SmallObjectOffset; } break;
		case 6: { sOffset = (unsigned int)XOPSOLT18F::SmallObjectOffset; } break;
		case 7: { sOffset = (unsigned int)XOPSOLT18F2::SmallObjectOffset; } break;
		case 8: { sOffset = (unsigned int)XOPSOLT19::SmallObjectOffset; } break;
		case 9: { sOffset = (unsigned int)XOPSOLT19F::SmallObjectOffset; } break;
		case 10: { sOffset = (unsigned int)XOPSOLT19F2::SmallObjectOffset; } break;

		default: { fclose(fp); return false; }
	}

	fseek(fp, sOffset, SEEK_SET);
	char sBuf = 0;
	for (int i = 0; i < MAX_SMALLOBJECT; i++) {
		fread(&sBuf, 1, 1, fp);
		sParam[i].jump = sBuf;
		fread(&sBuf, 1, 1, fp);
		sParam[i].model = sBuf;
		fread(&sBuf, 1, 1, fp);
		sParam[i].texture = sBuf;
		fread(&sBuf, 1, 1, fp);
		sParam[i].range = sBuf;
		fread(&sBuf, 1, 1, fp);
		sParam[i].hp = sBuf;
		fread(&sBuf, 1, 1, fp);
		sParam[i].sound = sBuf;

		WriteSmallObjectINI(sParam[i], i);
	}

	fclose(fp);

	printf("[ 소품 데이터 읽기/쓰기 종료 ]\n");
	printf("--------------------\n");

	return true;
}

int CheckVersion(const char* filename) {
	printf("--------------------\n");
	printf("[ 버전 확인 시작 ]\n");

	FILE *fp;
	fp = fopen(filename, "rb");
	if (fp == nullptr) { return -1; }

	int cnt = 0;

RETRY:
	if (cnt == 0) {
		// Address of Entry Point
		fseek(fp, 0x130, SEEK_SET);
	}
	else if (cnt == 1) {
		// Address of Entry Point
		fseek(fp, 0x120, SEEK_SET);
	}
	else if (cnt == 2) {
		// Address of Entry Point
		fseek(fp, 0x128, SEEK_SET);
	}
	else {
		fclose(fp);

		printf("[ 버전 확인 실패 ]\n");
		printf("--------------------\n");
		return -1;
	}

	unsigned int ep = 0x00;
	fread(&ep, 4, 1, fp);

	int rtn = -1;
	switch (ep) {
		case (unsigned int)XOPS096T::EP: { printf("XOPS096T\n"); rtn = 0; } break;
		case (unsigned int)XOPS097T::EP: { printf("XOPS097T\n"); rtn = 1; } break;
		case (unsigned int)XOPS097FT::EP: { printf("XOPS097FT\n"); rtn = 2; } break;
		case (unsigned int)XOPS0975T::EP: { printf("XOPS0975T\n"); rtn = 3; } break;
		case (unsigned int)XOPSOLT16::EP: { printf("XOPSOLT16\n"); rtn = 4; } break;
		case (unsigned int)XOPSOLT18::EP: { printf("XOPSOLT18\n"); rtn = 5; } break;
		case (unsigned int)XOPSOLT18F::EP: { printf("XOPSOLT18F\n"); rtn = 6; } break;
		case (unsigned int)XOPSOLT18F2::EP: { printf("XOPSOLT18F2\n"); rtn = 7; } break;
		case (unsigned int)XOPSOLT19::EP: { printf("XOPSOLT19\n"); rtn = 8; } break;
		case (unsigned int)XOPSOLT19F::EP: { printf("XOPSOLT19F\n"); rtn = 9; } break;
		case (unsigned int)XOPSOLT19F2::EP: { printf("XOPSOLT19F2\n"); rtn = 10; } break;

		default: { cnt += 1; goto RETRY; } break;
	}

	fclose(fp);

	printf("[ 버전 확인 종료 ]\n");
	printf("--------------------\n");

	return rtn;
}

bool WriteWeaponINI(WeaponParameter& wParam, int num) {
	char filename[MAX_PATH];
	sprintf(filename, "./Weapon/%d.ini", num);

	FILE *fp;
	fp = fopen(filename, "w");
	if (fp == nullptr) { return false; }

	// 설명
	fprintf(fp, ";Name = 무기의 이름\n");
	fprintf(fp, ";Model = 무기 모델 경로\n");
	fprintf(fp, ";Texture = 무기 텍스쳐 경로\n");
	fprintf(fp, ";Attacks = 공격력\n");
	fprintf(fp, ";Penetration = 관통력\n");
	fprintf(fp, ";Blazings = 발사 속도\n");
	fprintf(fp, ";Speed = 탄속\n");
	fprintf(fp, ";NbsMax = 장탄수\n");
	fprintf(fp, ";Reloads = 재장전 시간\n");
	fprintf(fp, ";Reaction = 반동\n");
	fprintf(fp, ";ErrorRangeMin = 오차 범위 최소\n");
	fprintf(fp, ";ErrorRangeMax = 오차 범위 최대\n");
	fprintf(fp, ";MX = 무기의 X 좌표\n");
	fprintf(fp, ";MY = 무기의 Y 좌표\n");
	fprintf(fp, ";MZ = 무기의 Z 좌표\n");
	fprintf(fp, ";FLASHX = 머즐플래시 X 좌표\n");
	fprintf(fp, ";FLASHY = 머즐플래시 Y 좌표\n");
	fprintf(fp, ";FLASHY = 머즐플래시 Z 좌표\n");
	fprintf(fp, ";YAKKYOU_PX = 탄피 X 좌표\n");
	fprintf(fp, ";YAKKYOU_PY = 탄피 Y 좌표\n");
	fprintf(fp, ";YAKKYOU_PZ = 탄피 Z 좌표\n");
	fprintf(fp, ";YAKKYOU_SX = 탄피 이동 X 좌표\n");
	fprintf(fp, ";YAKKYOU_SY = 탄피 이동 Y 좌표\n");
	fprintf(fp, ";BurstCnt = 발사 모드\n");
	fprintf(fp, ";ScopeMode = 스코프 모드\n");
	fprintf(fp, ";Size = 무기의 크기\n");
	fprintf(fp, ";SoundID = 사운드 식별 번호\n");
	fprintf(fp, ";SoundVolume = 사운드 음량\n");
	fprintf(fp, ";Silencer = 소음기 유무\n");
	fprintf(fp, ";WeaponP = 팔 유형\n");
	fprintf(fp, ";ChangeWeaponID = 변경 무기 대상\n");
	fprintf(fp, ";ChangeWeaponCnt = 변경 무기 카운트\n");
	fprintf(fp, ";Pellet = 발사 시 나가는 총알 수\n");
	fprintf(fp, "\n\n");

	// 무기
	fprintf(fp, "[Weapon]\n");
	fprintf(fp, "Name = \"\"\n");
	fprintf(fp, "Model = \"\"\n");
	fprintf(fp, "Texture = \"\"\n");
	fprintf(fp, "Attacks = %d\n", wParam.Damage);
	fprintf(fp, "Penetration = %d\n", wParam.Penetration);
	fprintf(fp, "Blazings = %d\n", wParam.Speed);
	fprintf(fp, "Speed = %d\n", wParam.Velocity);
	fprintf(fp, "NbsMax = %d\n", wParam.Ammo);
	fprintf(fp, "Reloads = %d\n", wParam.Reload);
	fprintf(fp, "Reaction = %d\n", wParam.Reaction);
	fprintf(fp, "ErrorRangeMin = %d\n", wParam.ErrorRangeMin);
	fprintf(fp, "ErrorRangeMax = %d\n", wParam.ErrorRangeMax);
	fprintf(fp, "MX = %f\n", (float)wParam.mx);
	fprintf(fp, "MY = %f\n", (float)wParam.my);
	fprintf(fp, "MZ = %f\n", (float)wParam.mz);
	fprintf(fp, "FLASH_X = %f\n", (float)wParam.flashx);
	fprintf(fp, "FLASH_Y = %f\n", (float)wParam.flashy);
	fprintf(fp, "FLASH_Z = %f\n", (float)wParam.flashz);
	fprintf(fp, "YAKKYOU_PX = %f\n", (float)wParam.yakkyou_px);
	fprintf(fp, "YAKKYOU_PY = %f\n", (float)wParam.yakkyou_py);
	fprintf(fp, "YAKKYOU_PZ = %f\n", (float)wParam.yakkyou_pz);
	fprintf(fp, "YAKKYOU_SX = %f\n", (float)wParam.yakkyou_sx);
	fprintf(fp, "YAKKYOU_SY = %f\n", (float)wParam.yakkyou_sy);
	fprintf(fp, "BurstCnt = %d\n", wParam.mode);
	fprintf(fp, "ScopeMode = %d\n", wParam.scope);
	fprintf(fp, "Size = %f\n", (float)wParam.size * 0.1f);
	fprintf(fp, "SoundID = %d\n", wParam.sound_id);
	fprintf(fp, "SoundVolume = %d\n", wParam.sound_volume);
	fprintf(fp, "Silencer = %s\n", (wParam.silencer == 0) ? "false" : "true");
	fprintf(fp, "WeaponP = %d\n", (wParam.arm == 27) ? 2 : (wParam.arm == 9) ? 1 : 0);
	fprintf(fp, "ChangeWeaponID = -1\n");
	fprintf(fp, "ChangeWeaponCnt = 0\n");
	fprintf(fp, "Pellet = 0\n");

	fclose(fp);

	return true;
}

bool WriteCharacterINI(CharacterParameter& cParam, int num) {
	char filename[MAX_PATH];
	sprintf(filename, "./Character/%d.ini", num);

	FILE *fp;
	fp = fopen(filename, "w");
	if (fp == nullptr) { return false; }

	// 설명
	fprintf(fp, ";Texture = 텍스쳐 식별 번호\n");
	fprintf(fp, ";Model = 모델 식별 번호\n");
	fprintf(fp, ";HP = 체력\n");
	fprintf(fp, ";AILevel = 인공지능 레벨\n");
	fprintf(fp, ";Weapon1 = 주무기\n");
	fprintf(fp, ";Weapon2 = 보조무기\n");
	fprintf(fp, ";Type = 유형\n");
	fprintf(fp, "\n\n");

	// 캐릭터
	int textureNum = 0;
	switch (cParam.texture) {
		case 0: { textureNum = 14; } break;
		case 1: { textureNum = 16; } break;
		case 2: { textureNum = 18; } break;
		case 3: { textureNum = 5; } break;
		case 4: { textureNum = 17; } break;
		case 5: { textureNum = 15; } break;
		case 6: { textureNum = 13; } break;
		case 7: { textureNum = 4; } break;
		case 8: { textureNum = 19; } break;
		case 9: { textureNum = 8; } break;
		case 10: { textureNum = 9; } break;
		case 11: { textureNum = 23; } break;
		case 12: { textureNum = 6; } break;
		case 13: { textureNum = 25; } break;
		case 14: { textureNum = 0; } break;
		case 15: { textureNum = 1; } break;
		case 16: { textureNum = 2; } break;
		case 17: { textureNum = 20; } break;
		case 18: { textureNum = 21; } break;
		case 19: { textureNum = 26; } break;
		case 20: { textureNum = 27; } break;
		case 21: { textureNum = 28; } break;
		case 22: { textureNum = 29; } break;
		case 23: { textureNum = 11; } break;
		case 24: { textureNum = 12; } break;
		case 25: { textureNum = 7; } break;
		case 26: { textureNum = 10; } break;
		case 27: { textureNum = 24; } break;
		case 28: { textureNum = 22; } break;
		case 29: { textureNum = 3; } break;
	}

	int modelNum = 0;
	switch (cParam.up_model) {
		case 0: {modelNum = 0; } break;
		case 31: {modelNum = 1; } break;
		case 33: {modelNum = 2; } break;
		case 35: {modelNum = 3; } break;
		case 36: {modelNum = 4; } break;
		case 38: {modelNum = 5; } break;
	}

	fprintf(fp, "[Character]\n");
	fprintf(fp, "Model = %d\n", modelNum);
	fprintf(fp, "Texture = %d\n", textureNum);
	fprintf(fp, "HP = %d\n", cParam.hp);
	fprintf(fp, "AILevel = %d\n", cParam.ai_level-1);
	fprintf(fp, "Weapon1 = %d\n", cParam.secondary_weapon);
	fprintf(fp, "Weapon2 = %d\n", cParam.main_weapon);
	fprintf(fp, "Type = %d\n", cParam.type);

	fclose(fp);

	return true;
}

bool WriteSmallObjectINI(SmallObjectParameter& sParam, int num) {
	char filename[MAX_PATH];
	sprintf(filename, "./SmallObject/%d.ini", num);

	FILE *fp;
	fp = fopen(filename, "w");
	if (fp == nullptr) { return false; }

	// 설명
	fprintf(fp, ";Model = 모델 경로\n");
	fprintf(fp, ";Texture = 텍스쳐 경로\n");
	fprintf(fp, ";Decide = 판정 범위\n");
	fprintf(fp, ";HP = 체력\n");
	fprintf(fp, ";Sound = 피격음\n");
	fprintf(fp, ";Jump = 튀어오르는 높이\n");
	fprintf(fp, "\n\n");

	// 소품
	fprintf(fp, "[SmallObject]\n");
	fprintf(fp, "Model = \"\"\n");
	fprintf(fp, "Texture = \"\"\n");
	fprintf(fp, "Decide = %d\n", sParam.range);
	fprintf(fp, "HP = %d\n", sParam.hp);
	fprintf(fp, "Sound = %d\n", (sParam.sound == 10) ? 0 : (sParam.sound == 12) ? 1 : 0);
	fprintf(fp, "Jump = %d\n", sParam.jump);

	fclose(fp);

	return true;
}

int main(int argc, char* argv[]) {
	if (argc <= 1) { printf("INI 파일로 내보낼 EXE 파일을 지정해주세요.\n"); return 1; }

	printf("%s\n", argv[0]);
	printf("%s\n", argv[1]);

	// 폴더 생성
	mkdir("Weapon");
	mkdir("Character");
	mkdir("SmallObject");

	if (SaveFile(CheckVersion(argv[1]), argv[1])) {
		printf("내보내기 성공!\n");
	}
	else {
		printf("내보내기 실패!\n");
	}

	return 0;
}
