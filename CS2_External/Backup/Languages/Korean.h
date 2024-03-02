#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Korean()
	{
		Global.Author = u8"TRINITRAMIN";
		Global.Date = u8"2023/11/25";

		Global.SwitchButton = u8"할 수 있게 하다";
		Global.FeatureSettings = u8"설정";

		// ESP
		ESPtext.FeatureName = u8" 이에스피 ";
		ESPtext.Box = u8"박스";
		ESPtext.BoxRounding = u8"박스 랜더링";
		ESPtext.FilledBox = u8"채워진 상자";
		ESPtext.FilledAlpha = u8"채워진 상자 알파";
		ESPtext.Skeleton = u8"해골";
		ESPtext.HeadBox = u8"머리 ";
		ESPtext.EyeRay = u8"아이 레이";
		ESPtext.HealthBar = u8"채력 줄";
		ESPtext.Weapon = u8"무기";
		ESPtext.Distance = u8"거리";
		ESPtext.PlayerName = u8"이름";
		ESPtext.SnapLine = u8"스냅라인";
		ESPtext.LinePosList = u8"라인포스";
		ESPtext.VisCheck = u8"벽뒤 구분";
		ESPtext.Preview = u8"esp미리보기";
		ESPtext.CollapseHead = u8"섹시ESP";
		ESPtext.Penis = u8"그곳을 보여주세요";
		ESPtext.PenisLength = u8"길이";
		ESPtext.PenisSize = u8"크기";
		ESPtext.MultiColor = u8"멀티 컬러";
		ESPtext.MultiColTip = u8"상자의 모서리가 둥글지 않은 경우에만 작동합니다.";
		ESPtext.Outline = u8"Outline";
		ESPtext.BoxType = u8"Box Type:";
		ESPtext.HealthNum = u8"Health Number";
		ESPtext.Ammo = u8"Ammo";

		ESPtext.BoxType_Normal = u8"Normal";
		ESPtext.BoxType_Edge = u8"Dynamic";
		ESPtext.BoxType_Corner = u8"Corner";
		ESPtext.LinePos_1 = u8"Top";
		ESPtext.LinePos_2 = u8"Center";
		ESPtext.LinePos_3 = u8"Bottom";

		// Aimbot
		AimbotText.FeatureName = u8"에임봇";
		AimbotText.HotKeyList = u8"키";
		AimbotText.Toggle = u8"껏다 키기";
		AimbotText.DrawFov = u8"FOV 그리기";
		AimbotText.VisCheck = u8"보이는 것만";
		AimbotText.JumpCheck = u8"지상에서만";
		AimbotText.SmoothSlider = u8"매끄러운";
		AimbotText.BoneList = u8"뼈";
		AimbotText.Tip = u8"메뉴가 열려 있는 동안에는 Aimbot이 작동하지 않습니다.";

		// Radar
		RadarText.FeatureName = u8" 레이더";
		RadarText.StyleList = u8"스타일";
		RadarText.CustomCheck = u8"커스텀";
		RadarText.CrossLine = u8"Cross 라인";
		RadarText.SizeSlider = u8"포인트 크기";
		RadarText.ProportionSlider = u8"비율";
		RadarText.RangeSlider = u8"범위";
		RadarText.AlphaSlider = u8"창 배경 알파";

		// Triggerbot
		TriggerText.FeatureName = u8" 트리거봇";
		TriggerText.HotKeyList = u8"핫키";
		TriggerText.Toggle = u8"항상 활성";
		TriggerText.DelaySlider = u8"샷 딜레이";
		TriggerText.FakeShotSlider = u8"촬영 시간";

		// Crosshairs
		CrosshairsText.FeatureName = u8" 십자선";
		CrosshairsText.PresetList = u8"사전 설정";
		CrosshairsText.ColorEditor = u8"십자선 색상";
		CrosshairsText.Dot = u8"센터 도트";
		CrosshairsText.DotSizeSlider = u8"도트 크기";
		CrosshairsText.Outline = u8"개요";
		CrosshairsText.Crossline = u8"크로스 라인";
		CrosshairsText.hLengthSlider = u8"가로 길이";
		CrosshairsText.vLengthSilder = u8"수직 길이";
		CrosshairsText.GapSlider = u8"갭";
		CrosshairsText.ThicknessSlider = u8"두께";
		CrosshairsText.tStyle = u8"T 스타일";
		CrosshairsText.Circle = u8"원";
		CrosshairsText.RadiusSlider = u8"원 반경";
		CrosshairsText.TargetCheck = u8"십자선 타겟팅";
		CrosshairsText.TeamCheck = u8"팀체크";

		// Misc
		MiscText.FeatureName = u8" 기타";
		MiscText.ThemeList = u8"주제";
		MiscText.StyleList = u8"스타일";
		MiscText.HeadshotLine = u8"헤드샷 라인";
		MiscText.SpecCheck = u8"사양 속 치트";
		MiscText.NoFlash = u8"No 플래시";
		MiscText.HitSound = u8"히트 사운드";
		MiscText.bmbTimer = u8"폭탄 타이머";
		MiscText.SpecList = u8"사양 목록";
		MiscText.Bhop = u8"버니홉";
		MiscText.Watermark = u8"양수표";
		MiscText.CheatList = u8"치트 목록";
		MiscText.TeamCheck = u8"팀체크";
		MiscText.AntiRecord = u8"방속 우회 ";

		MiscText.LanguageList = u8"언어";

		// Config Menu
		ConfigText.FeatureName = u8" 구성";
		ConfigText.Load = u8"선택 항목 로드";
		ConfigText.Save = u8"선택 항목 저장";
		ConfigText.Delete = u8"선택된 것을 지워 라";
		ConfigText.Reset = u8"구성 재설정";
		ConfigText.Create = u8"구성 만들기";
		ConfigText.OpenFolder = u8"폴더 열기 ";
		ConfigText.SeparateLine = u8"구성 저장";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" 주의상황 ";
		ReadMeText.LastUpdate = u8"마지막 업데이트: ";
		ReadMeText.SourceButton = u8" 소스 코드";
		ReadMeText.DiscordButton = u8" 디스코드에 참여하세요";
		ReadMeText.OffsetsTitle = u8"오프셋:";
	}
}