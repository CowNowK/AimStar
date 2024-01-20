#pragma once
#include "..\Language.h"
namespace Lang
{
	// Translated by @Hazetick
	// @Hazetick: The translation could be slightly different than it should be
	inline void Polish()
	{
		Global.Author = u8"Hazetick";
		Global.Date = u8"2023/11/29";

		Global.SwitchButton = u8"Włącz";
		Global.FeatureSettings = u8"Ustawienia";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Zaokrąglenie Boxa";
		ESPtext.FilledBox = u8"Wypełniony Box";
		ESPtext.FilledAlpha = u8"Przezroczystość Wypełnionego Boxa";
		ESPtext.Skeleton = u8"Szkielet";
		ESPtext.HeadBox = u8"Box Głowy";
		ESPtext.EyeRay = u8"Promień Oka";
		ESPtext.HealthBar = u8"Pasek Życia";
		ESPtext.Weapon = u8"Broń";
		ESPtext.Distance = u8"Dystans";
		ESPtext.PlayerName = u8"Imię Gracza";
		ESPtext.SnapLine = u8"Linia Łapania";
		ESPtext.LinePosList = u8"Lista Pozycji Linii";
		ESPtext.VisCheck = u8"Sprawdzenie Widoczności";
		ESPtext.Preview = u8"Okno Podglądu";
		ESPtext.CollapseHead = u8"SeksownyESP";
		ESPtext.Penis = u8"Pokaż Penis";
		ESPtext.PenisLength = u8"Długość Penisa";
		ESPtext.PenisSize = u8"Rozmiar Penisa";
		ESPtext.MultiColor = u8"Wielokolorowy";
		ESPtext.MultiColTip = u8"Działa tylko wtedy, gdy pudełko nie ma zaokrąglonych rogów.";
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
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Klawisz";
		AimbotText.Toggle = u8"Tryb Przełączania";
		AimbotText.DrawFov = u8"Rysuj FOV";
		AimbotText.VisCheck = u8"Tylko Widoczne";
		AimbotText.JumpCheck = u8"Tylko na Ziemi";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Gładkość";
		AimbotText.BoneList = u8"Kości";
		AimbotText.Tip = u8"Aimbot nie będzie działał, gdy menu jest otwarte";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Styl";
		RadarText.CustomCheck = u8"Niesterowane";
		RadarText.CrossLine = u8"Linia Przekreślająca";
		RadarText.SizeSlider = u8"Rozmiar Punktu";
		RadarText.ProportionSlider = u8"Proporcje";
		RadarText.RangeSlider = u8"Zasięg";
		RadarText.AlphaSlider = u8"Przezroczystość Tła Okna";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Klawisz";
		TriggerText.Toggle = u8"Zawsze Aktywny";
		TriggerText.DelaySlider = u8"Opóźnienie Strzału";
		TriggerText.FakeShotSlider = u8"Czas Trwania Strzału";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Celowniki";
		CrosshairsText.PresetList = u8"Ustawienia Wstępne";
		CrosshairsText.ColorEditor = u8"Kolor Celownika";
		CrosshairsText.Dot = u8"Kropka Środkowa";
		CrosshairsText.DotSizeSlider = u8"Rozmiar Kropki";
		CrosshairsText.Outline = u8"Kontur";
		CrosshairsText.Crossline = u8"Linia Przekreślająca";
		CrosshairsText.hLengthSlider = u8"Długość Pozioma";
		CrosshairsText.vLengthSilder = u8"Długość Pionowa";
		CrosshairsText.GapSlider = u8"Przerwa";
		CrosshairsText.ThicknessSlider = u8"Grubość";
		CrosshairsText.tStyle = u8"Styl T";
		CrosshairsText.Circle = u8"Okrąg";
		CrosshairsText.RadiusSlider = u8"Promień Okręgu";
		CrosshairsText.TargetCheck = u8"Celowanie Celownikiem";
		CrosshairsText.TeamCheck = u8"Sprawdzanie Drużyny";

		// Misc
		MiscText.FeatureName = u8" Różne";
		MiscText.ThemeList = u8"Motyw";
		MiscText.StyleList = u8"Styl";
		MiscText.HeadshotLine = u8"Linia Headshot";
		MiscText.SpecCheck = u8"Czituj w Widoku Spec";
		MiscText.NoFlash = u8"Brak Ślepący";
		MiscText.HitSound = u8"Dźwięk Trafienia";
		MiscText.bmbTimer = u8"Minutnik Bomby";
		MiscText.SpecList = u8"Lista Widzów";
		MiscText.Bhop = u8"Bunny Hop";
		MiscText.Watermark = u8"Znak Wodny";
		MiscText.CheatList = u8"Lista Czitów";
		MiscText.TeamCheck = u8"Sprawdzanie Drużyny";
		MiscText.AntiRecord = u8"Ominięcie OBS";

		MiscText.LanguageList = u8"Język";

		// Config Menu
		ConfigText.FeatureName = u8" Konfiguracja";
		ConfigText.Load = u8"Wczytaj Wybrane";
		ConfigText.Save = u8"Zapisz Wybrane";
		ConfigText.Delete = u8"Usuń Wybrane";
		ConfigText.Reset = u8"Resetuj Konfig";
		ConfigText.Create = u8"Utwórz Konfig";
		ConfigText.OpenFolder = u8"Otwórz Folder";
		ConfigText.SeparateLine = u8"Oddziel Linia";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" PRZECZYTAJ";
		ReadMeText.LastUpdate = u8"Ostatnia Aktualizacja: ";
		ReadMeText.SourceButton = u8"Kod Źródłowy";
		ReadMeText.DiscordButton = u8"Dołącz do Discorda";
		ReadMeText.OffsetsTitle = u8"Przesunięcia:";
	}
}