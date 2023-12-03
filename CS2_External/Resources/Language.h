#pragma once
#include "..\Font\IconsFontAwesome5.h"

namespace Lang
{
	struct
	{
		const char* SwitchButton;
		const char* FeatureSettings;
	} Global;

	struct
	{
		const char* FeatureName;
		const char* Box;
		const char* BoxRounding;
		const char* FilledBox;
		const char* FilledAlpha;
		const char* Skeleton;
		const char* HeadBox;
		const char* EyeRay;
		const char* HealthBar;
		const char* Weapon;
		const char* Distance;
		const char* PlayerName;
		const char* SnapLine;
		const char* LinePosList;
		const char* VisCheck;
		const char* Preview;
		const char* CollapseHead;
		const char* Penis;
		const char* PenisLength;
		const char* PenisSize;
		const char* MultiColor;
		const char* MultiColTip;

		const char* BoxType_Normal;
		const char* BoxType_Edge;
		const char* BoxType_Corner1;
		const char* BoxType_Corner2;
		const char* BarType_Top;
		const char* BarType_Vertical;
		const char* HeadBoxType_Normal;
		const char* HeadBoxType_Flat;
		const char* LinePos_1;
		const char* LinePos_2;
		const char* LinePos_3;
	} ESPtext;

	struct
	{
		const char* FeatureName;
		const char* HotKeyList;
		const char* Toggle;
		const char* DrawFov;
		const char* VisCheck;
		const char* JumpCheck;
		const char* FovSlider;
		const char* SmoothSlider;
		const char* BoneList;
		const char* Tip;

		const char* Bone_1;
		const char* Bone_2;
		const char* Bone_3;
		const char* Bone_4;
	} AimbotText;

	struct
	{
		const char* FeatureName;
	} GlowText;

	struct
	{
		const char* FeatureName;
		const char* StyleList;
		const char* CustomCheck;
		const char* CrossLine;
		const char* SizeSlider;
		const char* ProportionSlider;
		const char* RangeSlider;
		const char* AlphaSlider;

		const char* Style_1;
		const char* Style_2;
		const char* Style_3;
	} RadarText;

	struct
	{
		const char* FeatureName;
		const char* HotKeyList;
		const char* Toggle;
		const char* DelaySlider;
		const char* FakeShotSlider;
	} TriggerText;

	struct
	{
		const char* FeatureName;
		const char* PresetList;
		const char* ColorEditor;
		const char* Dot;
		const char* DotSizeSlider;
		const char* Outline;
		const char* Crossline;
		const char* hLengthSlider;
		const char* vLengthSilder;
		const char* GapSlider;
		const char* ThicknessSlider;
		const char* tStyle;
		const char* Circle;
		const char* RadiusSlider;
		const char* TargetCheck;
		const char* TeamCheck;
	} CrosshairsText;

	struct
	{
		const char* FeatureName;
		const char* ThemeList;
		const char* StyleList;
		const char* HeadshotLine;
		const char* SpecCheck;
		const char* NoFlash;
		const char* HitSound;
		const char* bmbTimer;
		const char* SpecList;
		const char* Bhop;
		const char* Watermark;
		const char* CheatList;
		const char* TeamCheck;
		const char* AntiRecord;

		const char* LanguageList;
	} MiscText;

	struct
	{
		const char* FeatureName;
		const char* Load;
		const char* Save;
		const char* Delete;
		const char* Reset;
		const char* Create;
		const char* OpenFolder;
		const char* SeparateLine;
	} ConfigText;

	struct
	{
		const char* FeatureName;
		const char* LastUpdate;
		const char* SourceButton;
		const char* DiscordButton;
		const char* OffsetsTitle;
	} ReadMeText;

	inline void English()
	{
		Global.SwitchButton = u8"Enable";
		Global.FeatureSettings = u8"Settings";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Box Rounding";
		ESPtext.FilledBox = u8"Filled Box";
		ESPtext.FilledAlpha = u8"Filled Box Alpha";
		ESPtext.Skeleton = u8"Skeleton";
		ESPtext.HeadBox = u8"Head Box";
		ESPtext.EyeRay = u8"Eye Ray";
		ESPtext.HealthBar = u8"Health Bar";
		ESPtext.Weapon = u8"Weapon";
		ESPtext.Distance = u8"Distance";
		ESPtext.PlayerName = u8"Name";
		ESPtext.SnapLine = u8"SnapLine";
		ESPtext.LinePosList = u8"LinePos";
		ESPtext.VisCheck = u8"Visible Check";
		ESPtext.Preview = u8"Preview Window";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Show Penis";
		ESPtext.PenisLength = u8"Length";
		ESPtext.PenisSize = u8"Size";
		ESPtext.MultiColor = u8"Multi-Color";
		ESPtext.MultiColTip = u8"Only work when the box has non-rounded corners.";

		// Aimbot
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Key";
		AimbotText.Toggle = u8"Toggle Mode";
		AimbotText.DrawFov = u8"Draw Fov";
		AimbotText.VisCheck = u8"Visible Only";
		AimbotText.JumpCheck = u8"On Ground Only";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Smooth";
		AimbotText.BoneList = u8"Bone";
		AimbotText.Tip = u8"Aimbot will not work while the menu is opened";

		// Glow
		GlowText.FeatureName = u8" Glow";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Custom";
		RadarText.CrossLine = u8"Cross Line";
		RadarText.SizeSlider = u8"Point Size";
		RadarText.ProportionSlider = u8"Proportion";
		RadarText.RangeSlider = u8"Range";
		RadarText.AlphaSlider = u8"Window Background Alpha";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"HotKey";
		TriggerText.Toggle = u8"Always Active";
		TriggerText.DelaySlider = u8"Shot Delay";
		TriggerText.FakeShotSlider = u8"Shot Duration";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Presets";
		CrosshairsText.ColorEditor = u8"Crosshairs Color";
		CrosshairsText.Dot = u8"Center Dot";
		CrosshairsText.DotSizeSlider = u8"Dot Size";
		CrosshairsText.Outline = u8"Outline";
		CrosshairsText.Crossline = u8"Cross Line";
		CrosshairsText.hLengthSlider = u8"Horizontal Length";
		CrosshairsText.vLengthSilder = u8"Vertical Length";
		CrosshairsText.GapSlider = u8"Gap";
		CrosshairsText.ThicknessSlider = u8"Thickness";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Circle";
		CrosshairsText.RadiusSlider = u8"Circle Radius";
		CrosshairsText.TargetCheck = u8"Targeting Crosshairs";
		CrosshairsText.TeamCheck = u8"TeamCheck";

		// Misc
		MiscText.FeatureName = u8" Misc";
		MiscText.ThemeList = u8"Theme";
		MiscText.StyleList = u8"Style";
		MiscText.HeadshotLine = u8"Headshot Line";
		MiscText.SpecCheck = u8"Cheat in Spec";
		MiscText.NoFlash = u8"No Flash";
		MiscText.HitSound = u8"Hit Sound";
		MiscText.bmbTimer = u8"Bomb Timer";
		MiscText.SpecList = u8"Spec List";
		MiscText.Bhop = u8"Bunny Hop";
		MiscText.Watermark = u8"Watermark";
		MiscText.CheatList = u8"Cheat List";
		MiscText.TeamCheck = u8"TeamCheck";
		MiscText.AntiRecord = u8"Bypass OBS";

		MiscText.LanguageList = u8"Language";

		// Config Menu
		ConfigText.FeatureName = u8" Config";
		ConfigText.Load = u8"Load Selected";
		ConfigText.Save = u8"Save Selected";
		ConfigText.Delete = u8"Delete Selected";
		ConfigText.Reset = u8"Reset Config";
		ConfigText.Create = u8"Create Config";
		ConfigText.OpenFolder = u8"Open Folder";
		ConfigText.SeparateLine = u8"Save Config";

		// Readme Menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Last update: ";
		ReadMeText.SourceButton = u8" Source Code";
		ReadMeText.DiscordButton = u8" Join Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}

	// Translated by @styx
	inline void German()
	{
		Global.SwitchButton = u8"Aktivieren";
		Global.FeatureSettings = u8"Settings";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Kasten rundung";
		ESPtext.FilledBox = u8"Gefüllte Kiste";
		ESPtext.FilledAlpha = u8"Gefülltes Feld Alpha";
		ESPtext.Skeleton = u8"Skelett";
		ESPtext.HeadBox = u8"Kopf kasten";
		ESPtext.EyeRay = u8"Auge Strahl";
		ESPtext.HealthBar = u8"Gesundheitsbar";
		ESPtext.Weapon = u8"Waffe";
		ESPtext.Distance = u8"Distanz";
		ESPtext.PlayerName = u8"Name";
		ESPtext.SnapLine = u8"Schnapp Linie";
		ESPtext.LinePosList = u8"Linie Pos";
		ESPtext.VisCheck = u8"Sichtbarer Scheck";
		ESPtext.Preview = u8"Vorschaufenster";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Penis Zeigen";
		ESPtext.PenisLength = u8"Länge";
		ESPtext.PenisSize = u8"Größe";

		// Aimbot
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Key";
		AimbotText.Toggle = u8"Toggle Modus";
		AimbotText.DrawFov = u8"Draw Fov";
		AimbotText.VisCheck = u8"Nur sichtbar";
		AimbotText.JumpCheck = u8"Nur am Boden";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Smooth";
		AimbotText.BoneList = u8"Bone";
		AimbotText.Tip = u8"Aimbot funktioniert nicht, während das menü geöffnet ist.";

		// Glow
		GlowText.FeatureName = u8" Glow";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Custom";
		RadarText.CrossLine = u8"Cross Line";
		RadarText.SizeSlider = u8"Punktgröße";
		RadarText.ProportionSlider = u8"Proportion";
		RadarText.RangeSlider = u8"Range";
		RadarText.AlphaSlider = u8"Fensterhintergrund Alpha";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"HotKey";
		TriggerText.Toggle = u8"Immer aktiv";
		TriggerText.DelaySlider = u8"Shot Delay";
		TriggerText.FakeShotSlider = u8"Shot Duration";

		// Crosshair
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Presets";
		CrosshairsText.ColorEditor = u8"Crosshairs Color";
		CrosshairsText.Dot = u8"Center Dot";
		CrosshairsText.DotSizeSlider = u8"Punktgröße";
		CrosshairsText.Outline = u8"Outline";
		CrosshairsText.Crossline = u8"Cross Line";
		CrosshairsText.hLengthSlider = u8"Horizontale Länge";
		CrosshairsText.vLengthSilder = u8"Vertikale Länge";
		CrosshairsText.GapSlider = u8"Gap";
		CrosshairsText.ThicknessSlider = u8"Thickness";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Circle";
		CrosshairsText.RadiusSlider = u8"Kreisradius";
		CrosshairsText.TargetCheck = u8"Ziel Fadenkreuz";
		CrosshairsText.TeamCheck = u8"TeamCheck";

		// Misc
		MiscText.FeatureName = u8" Misc";
		MiscText.ThemeList = u8"Theme";
		MiscText.StyleList = u8"Style";
		MiscText.HeadshotLine = u8"Headshot Line";
		MiscText.SpecCheck = u8"Cheat in Spec";
		MiscText.NoFlash = u8"Kein Flash";
		MiscText.HitSound = u8"Hit Sound";
		MiscText.bmbTimer = u8"Bomben-Timer";
		MiscText.SpecList = u8"Spec List";
		MiscText.Bhop = u8"Bunny Hop";
		MiscText.Watermark = u8"Watermark";
		MiscText.CheatList = u8"Cheat Liste";
		MiscText.TeamCheck = u8"TeamCheck";
		MiscText.AntiRecord = u8"OBS umgehen";

		MiscText.LanguageList = u8"Sprache";

		// Config Menu
		ConfigText.FeatureName = u8" Config";
		ConfigText.Load = u8"Ausgewählte laden";
		ConfigText.Save = u8"Ausgewählte speichern";
		ConfigText.Delete = u8"Ausgewählte löschen";
		ConfigText.Reset = u8"Konfiguration zurücksetzen";
		ConfigText.Create = u8"Konfiguration erstellen";
		ConfigText.OpenFolder = u8"Ordner öffnen";
		ConfigText.SeparateLine = u8"Konfiguration speichern";

		// Readme menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Letzte Aktualisierung: ";
		ReadMeText.SourceButton = u8" Quellcode";
		ReadMeText.DiscordButton = u8" Discord beitreten";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}

	// Translated by @Hazetick
	// @Hazetick: The translation could be slightly different than it should be
	inline void Polish()
	{
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

		// Glow
		GlowText.FeatureName = u8" Podświetlenie";

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

		// Readme Menu
		ReadMeText.FeatureName = u8" PRZECZYTAJ";
		ReadMeText.LastUpdate = u8"Ostatnia Aktualizacja: ";
		ReadMeText.SourceButton = u8"Kod Źródłowy";
		ReadMeText.DiscordButton = u8"Dołącz do Discorda";
		ReadMeText.OffsetsTitle = u8"Przesunięcia:";
	}

	// Translated by @gScream.
	inline void Russian()
	{
		Global.SwitchButton = u8"Включить";
		Global.FeatureSettings = u8"Настройки";

		// ESP
		ESPtext.FeatureName = u8" ESP (WH)";
		ESPtext.Box = u8"Обводка";
		ESPtext.BoxRounding = u8"Округление обводки";
		ESPtext.FilledBox = u8"Заполненная обводка";
		ESPtext.FilledAlpha = u8"Прозрачность заполненной обводки";
		ESPtext.Skeleton = u8"Скелет цели";
		ESPtext.HeadBox = u8"Бокс головы цели";
		ESPtext.EyeRay = u8"Направление зрения цели";
		ESPtext.HealthBar = u8"Полоска здоровья цели";
		ESPtext.Weapon = u8"Оружие цели";
		ESPtext.Distance = u8"Дистанция до цели";
		ESPtext.PlayerName = u8"Имя цели";
		ESPtext.SnapLine = u8"Линия к противнику";
		ESPtext.LinePosList = u8"Позиция линии";
		ESPtext.VisCheck = u8"Только если цель в поле зрения";
		ESPtext.Preview = u8"Отобразить предпросмотр WH";
		ESPtext.CollapseHead = u8"Секс WH";
		ESPtext.Penis = u8"Показать пенис";
		ESPtext.PenisLength = u8"Длина";
		ESPtext.PenisSize = u8"Размер";
		ESPtext.MultiColor = u8"Мульти-цвет";
		ESPtext.MultiColTip = u8"Работает только когда обводка не имеет закругленные края.";

		// Aimbot
		AimbotText.FeatureName = u8" Аимбот";
		AimbotText.HotKeyList = u8"Горячая клавиша";
		AimbotText.Toggle = u8"Режим переключения";
		AimbotText.DrawFov = u8"Отобразить поле зрение";
		AimbotText.VisCheck = u8"Только если цель в поле зрения";
		AimbotText.JumpCheck = u8"Только на земле ";
		AimbotText.FovSlider = u8"Радиус поля зрения";
		AimbotText.SmoothSlider = u8"Сглаживание";
		AimbotText.BoneList = u8"Скелет";
		AimbotText.Tip = u8"Для работы Аимбота нужно закрыть меню (Insert)";

		// Glow
		GlowText.FeatureName = u8" Свечение";

		// Radar
		RadarText.FeatureName = u8" Радар";
		RadarText.StyleList = u8"Стиль";
		RadarText.CustomCheck = u8"Кастомный";
		RadarText.CrossLine = u8"Перекрестье";
		RadarText.SizeSlider = u8"Размер точки";
		RadarText.ProportionSlider = u8"Пропорции";
		RadarText.RangeSlider = u8"Радиус";
		RadarText.AlphaSlider = u8"Прозрачность радара";

		// Triggerbot
		TriggerText.FeatureName = u8" Триггербот";
		TriggerText.HotKeyList = u8"Горячая клавиша";
		TriggerText.Toggle = u8"Всегда активен";
		TriggerText.DelaySlider = u8"Задержка перед выстрелом";
		TriggerText.FakeShotSlider = u8"Продолжительность выстрела";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Прицелы";
		CrosshairsText.PresetList = u8"Пресеты";
		CrosshairsText.ColorEditor = u8"Цвета прицела";
		CrosshairsText.Dot = u8"Точка в центре";
		CrosshairsText.DotSizeSlider = u8"Размер точки";
		CrosshairsText.Outline = u8"Контур";
		CrosshairsText.Crossline = u8"Перекрестье";
		CrosshairsText.hLengthSlider = u8"Горизонтальная длина";
		CrosshairsText.vLengthSilder = u8"Вертикальная длина";
		CrosshairsText.GapSlider = u8"Пробел";
		CrosshairsText.ThicknessSlider = u8"Широта";
		CrosshairsText.tStyle = u8"Прицел в стиле буквы Т";
		CrosshairsText.Circle = u8"Круг";
		CrosshairsText.RadiusSlider = u8"Радиус круга";
		CrosshairsText.TargetCheck = u8"Нацеливание прицела";
		CrosshairsText.TeamCheck = u8"Режим своих напарников";

		// Misc
		MiscText.FeatureName = u8" Дополнительно";
		MiscText.ThemeList = u8"Тема";
		MiscText.StyleList = u8"Стиль";
		MiscText.HeadshotLine = u8"Высотная линия головы";
		MiscText.SpecCheck = u8"Отображение при наблюдении";
		MiscText.NoFlash = u8"Анти-слепота";
		MiscText.HitSound = u8"Звук попадания";
		MiscText.bmbTimer = u8"Таймер до взрыва C4";
		MiscText.SpecList = u8"Список наблюдателей";
		MiscText.Bhop = u8"Бхоп";
		MiscText.Watermark = u8"Водяной знак";
		MiscText.CheatList = u8"Список активных читов";
		MiscText.TeamCheck = u8"Режим своих напарников";
		MiscText.AntiRecord = u8"Обход записи/демонстрации";

		MiscText.LanguageList = u8"Язык";

		// Config Menu
		ConfigText.FeatureName = u8" Конфигурация";
		ConfigText.Load = u8"Загрузить выделенное";
		ConfigText.Save = u8"Сохранить выделенное";
		ConfigText.Delete = u8"Удалить выделенное";
		ConfigText.Reset = u8"Восстановить стандартные настройки";
		ConfigText.Create = u8"Создать конфигурацию";
		ConfigText.OpenFolder = u8"Открыть папку с конфигурациями";
		ConfigText.SeparateLine = u8"Сохранить конфигурацию";

		// Readme Menu
		ReadMeText.FeatureName = u8" ОТКРОЙ";
		ReadMeText.LastUpdate = u8"Последнее обновление: ";
		ReadMeText.SourceButton = u8" Исходный код";
		ReadMeText.DiscordButton = u8" Присоединиться к дискорд серверу";
		ReadMeText.OffsetsTitle = u8"Оффсеты:";
	}

	// Translated by @5mmod
	inline void Danish()
	{
		Global.SwitchButton = u8"Slå til";
		Global.FeatureSettings = u8"Indstillinger";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Boks";
		ESPtext.BoxRounding = u8"Boks Runding";
		ESPtext.FilledBox = u8"Fyldet Boks";
		ESPtext.FilledAlpha = u8"Fyldet Boks Alfa";
		ESPtext.Skeleton = u8"Skelet";
		ESPtext.HeadBox = u8"Hoved Boks";
		ESPtext.EyeRay = u8"Øjenståle";
		ESPtext.HealthBar = u8"Liv Bar";
		ESPtext.Weapon = u8"Våben";
		ESPtext.Distance = u8"Distance";
		ESPtext.PlayerName = u8"Navn";
		ESPtext.SnapLine = u8"SnapLinje";
		ESPtext.LinePosList = u8"LinjePos";
		ESPtext.VisCheck = u8"Synlig Tjek";
		ESPtext.Preview = u8"Visnings Vindue";
		ESPtext.CollapseHead = u8"Sexet ESP";
		ESPtext.Penis = u8"Vis Pik";
		ESPtext.PenisLength = u8"Længde";
		ESPtext.PenisSize = u8"Størrelse";
		ESPtext.MultiColor = u8"Multi-farvet";
		ESPtext.MultiColTip = u8"Virker kun, når boksen ikke har afrundede hjørner.";


		// Aimbot
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Nøgle";
		AimbotText.Toggle = u8"Skift tilstand";
		AimbotText.DrawFov = u8"Tegn Fov";
		AimbotText.VisCheck = u8"Synlig Kun";
		AimbotText.JumpCheck = u8"På jorden kun";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Glat";
		AimbotText.BoneList = u8"Knogle";
		AimbotText.Tip = u8"Aimbot vil ikke virke i mens menuen er åbent";

		// Glow
		GlowText.FeatureName = u8" Glød";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Stil";
		RadarText.CustomCheck = u8"Brugerdefineret";
		RadarText.CrossLine = u8"Krydslinje";
		RadarText.SizeSlider = u8"Point Størrelse";
		RadarText.ProportionSlider = u8"Del";
		RadarText.RangeSlider = u8"Afstand";
		RadarText.AlphaSlider = u8"Vindue Bagground Alfa";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"HotNøgle";
		TriggerText.Toggle = u8"Altid Aktiv";
		TriggerText.DelaySlider = u8"Skud forsinkelse";
		TriggerText.FakeShotSlider = u8"Skud Varighed";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Crosshairs";
		CrosshairsText.PresetList = u8"Forudindstillinger";
		CrosshairsText.ColorEditor = u8"Crosshairs Farvet";
		CrosshairsText.Dot = u8"Centrum Prik";
		CrosshairsText.DotSizeSlider = u8"Prik Størrelse";
		CrosshairsText.Outline = u8"Udelinje";
		CrosshairsText.Crossline = u8"Kryds Linje";
		CrosshairsText.hLengthSlider = u8"Vandret Længte";
		CrosshairsText.vLengthSilder = u8"Lodret Længte";
		CrosshairsText.GapSlider = u8"Mellemrum";
		CrosshairsText.ThicknessSlider = u8"Tykhed";
		CrosshairsText.tStyle = u8"T Stil";
		CrosshairsText.Circle = u8"Cirkel";
		CrosshairsText.RadiusSlider = u8"Cirkel Radius";
		CrosshairsText.TargetCheck = u8"Rettet Mod Crosshairs";
		CrosshairsText.TeamCheck = u8"Holdtjek";

		// Misc
		MiscText.FeatureName = u8" Diverse";
		MiscText.ThemeList = u8"Tema";
		MiscText.StyleList = u8"Stil";
		MiscText.HeadshotLine = u8"Hovedskud Linje";
		MiscText.SpecCheck = u8"Snyd i Spec";
		MiscText.NoFlash = u8"Ingen Flash";
		MiscText.HitSound = u8"Skud Lyd";
		MiscText.bmbTimer = u8"Bombe Timer";
		MiscText.SpecList = u8"Spec Liste";
		MiscText.Bhop = u8"Kanin Hop";
		MiscText.Watermark = u8"Vandmærke";
		MiscText.CheatList = u8"Snyd Liste";
		MiscText.TeamCheck = u8"HoldTjek";
		MiscText.AntiRecord = u8"Bypass OBS";

		MiscText.LanguageList = u8"Sprog";

		// Config Menu
		ConfigText.FeatureName = u8" Config";
		ConfigText.Load = u8"Load Valgt";
		ConfigText.Save = u8"Gem Valgt";
		ConfigText.Delete = u8"Slet Valgt";
		ConfigText.Reset = u8"Nulstil Config";
		ConfigText.Create = u8"Lav Config";
		ConfigText.OpenFolder = u8"Åben Mappe";
		ConfigText.SeparateLine = u8"Gem Config";

		// Readme Menu
		ReadMeText.FeatureName = u8" LÆSMIG";
		ReadMeText.LastUpdate = u8"Sidste opdatering: ";
		ReadMeText.SourceButton = u8" Source Code";
		ReadMeText.DiscordButton = u8" Join Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}

	// Translated by @vsantos1
	inline void Portuguese()
	{
		Global.SwitchButton = u8"Ativar";
		Global.FeatureSettings = u8"Definições";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Borda da Caixa";
		ESPtext.FilledBox = u8"Preenchimento da Caixa";
		ESPtext.FilledAlpha = u8"Preenchimento da Caixa Alfa";
		ESPtext.Skeleton = u8"Esqueleto";
		ESPtext.HeadBox = u8"Caixa na CabeÃ§a";
		ESPtext.EyeRay = u8"Mirando em";
		ESPtext.HealthBar = u8"Barra de Vida";
		ESPtext.Weapon = u8"Arma";
		ESPtext.Distance = u8"Distancia";
		ESPtext.PlayerName = u8"Nome";
		ESPtext.SnapLine = u8"Linha de Distancia";
		ESPtext.LinePosList = u8"Linha de Posicao";
		ESPtext.VisCheck = u8"Apenas Visiveis";
		ESPtext.Preview = u8"Janela de Visualizacao";
		ESPtext.CollapseHead = u8"ESP Sensual";
		ESPtext.Penis = u8"Mostrar Penis";
		ESPtext.PenisLength = u8"Comprimento";
		ESPtext.PenisSize = u8"Tamanho";
		ESPtext.MultiColor = u8"Multicolorido";
		ESPtext.MultiColTip = u8"Só funciona quando a caixa tem cantos não arredondados.";

		// Aimbot
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Tecla";
		AimbotText.Toggle = u8"Modo Alternado";
		AimbotText.DrawFov = u8"Desenhar Campo de Visao";
		AimbotText.VisCheck = u8"Apenas Visiveis";
		AimbotText.JumpCheck = u8"Apenas no Chao";
		AimbotText.FovSlider = u8"Campo de Visao";
		AimbotText.SmoothSlider = u8"Suavidade";
		AimbotText.BoneList = u8"Target";
		AimbotText.Tip = u8"Aimbot nao funcionara com menu aberto";

		// Glow
		GlowText.FeatureName = u8" Glow";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Estilo";
		RadarText.CustomCheck = u8"Customizado";
		RadarText.CrossLine = u8"Linha cruzada";
		RadarText.SizeSlider = u8"Tamanho do Ponto";
		RadarText.ProportionSlider = u8"Proporcao";
		RadarText.RangeSlider = u8"Alcance";
		RadarText.AlphaSlider = u8"Fundo da Janela Alfa";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Tecla";
		TriggerText.Toggle = u8"Sempre ativo";
		TriggerText.DelaySlider = u8"Tempo de Disparo";
		TriggerText.FakeShotSlider = u8"Duracao de Disparo";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Miras";
		CrosshairsText.PresetList = u8"Predefinidos";
		CrosshairsText.ColorEditor = u8"Cores da Mira";
		CrosshairsText.Dot = u8"Ponto Central";
		CrosshairsText.DotSizeSlider = u8"Tamanho do Ponto";
		CrosshairsText.Outline = u8"Contorno";
		CrosshairsText.Crossline = u8"Linhas Cruzadas";
		CrosshairsText.hLengthSlider = u8"Comprimento Horizontal";
		CrosshairsText.vLengthSilder = u8"Comprimento Vertical";
		CrosshairsText.GapSlider = u8"Espacamento";
		CrosshairsText.ThicknessSlider = u8"Largura";
		CrosshairsText.tStyle = u8"T Estilo";
		CrosshairsText.Circle = u8"Circulo";
		CrosshairsText.RadiusSlider = u8"Raio do Circulo";
		CrosshairsText.TargetCheck = u8"Verificacao de Alvo";
		CrosshairsText.TeamCheck = u8"Apenas Inimigos";

		// Misc
		MiscText.FeatureName = u8" Diversos";
		MiscText.ThemeList = u8"Tema";
		MiscText.StyleList = u8"Estilo";
		MiscText.HeadshotLine = u8"Linha de Headshot";
		MiscText.SpecCheck = u8"Funcionar no Espectador";
		MiscText.NoFlash = u8"Remover Flashbang";
		MiscText.HitSound = u8"Som de Acerto";
		MiscText.bmbTimer = u8"Temporizador da Bomba";
		MiscText.SpecList = u8"Lista de Espectadores";
		MiscText.Bhop = u8"Bunny hop";
		MiscText.Watermark = u8"Marca dagua";
		MiscText.CheatList = u8"Lista de Trapacas";
		MiscText.TeamCheck = u8"Apenas Inimigos";
		MiscText.AntiRecord = u8"Anti-OBS";

		MiscText.LanguageList = u8"Linguagem";

		// Config Menu
		ConfigText.FeatureName = u8" Configuracao";
		ConfigText.Load = u8"Carregar Selecionada";
		ConfigText.Save = u8"Salvar Selecionada";
		ConfigText.Delete = u8"Deletar Selecionada";
		ConfigText.Reset = u8"Reseta Configuracao";
		ConfigText.Create = u8"Criar Configuracao";
		ConfigText.OpenFolder = u8"Abrir Pasta";
		ConfigText.SeparateLine = u8"Salvar Configuracao";

		// Readme Menu
		ReadMeText.FeatureName = u8" LEIAME";
		ReadMeText.LastUpdate = u8"Ultima Atualizacao: ";
		ReadMeText.SourceButton = u8" Codigo Fonte";
		ReadMeText.DiscordButton = u8" Entre no Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}

	// Translated by @faster_bbc
	inline void Slovak()
	{
		Global.SwitchButton = u8"Zapnúť";
		Global.FeatureSettings = u8"Nastavenia";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Box";
		ESPtext.BoxRounding = u8"Zaoblenie Boxu";
		ESPtext.FilledBox = u8"Vyplnený box";
		ESPtext.FilledAlpha = u8"Prehliadnosť vyplneného boxu";
		ESPtext.Skeleton = u8"Kostra";
		ESPtext.HeadBox = u8"Box na hlavu";
		ESPtext.EyeRay = u8"Čiara videnia hráča";
		ESPtext.HealthBar = u8"Hrubá čiara života";
		ESPtext.Weapon = u8"Zbraň";
		ESPtext.Distance = u8"Zdialenosť";
		ESPtext.PlayerName = u8"Meno";
		ESPtext.SnapLine = u8"Čiara ku hráčovy";
		ESPtext.LinePosList = u8"Lokácia čiary";
		ESPtext.VisCheck = u8"Skontrolovať viditelnosť";
		ESPtext.Preview = u8"Náhľad";
		ESPtext.CollapseHead = u8"Sex ESP";
		ESPtext.Penis = u8"Penis/Pipik/Bakuľa";
		ESPtext.PenisLength = u8"Dĺžka";
		ESPtext.PenisSize = u8"Velkosť";
		ESPtext.MultiColor = u8"Viacfarebné";
		ESPtext.MultiColTip = u8"Funguje len vtedy, keď má rámček nezaoblené rohy.";

		// Aimbot
		AimbotText.FeatureName = u8" Aimbo";
		AimbotText.HotKeyList = u8"Tlačítko";
		AimbotText.Toggle = u8"Prepínaci mód";
		AimbotText.DrawFov = u8"Ukázať FOV";
		AimbotText.VisCheck = u8"Skontrolovať viditelnosť";
		AimbotText.JumpCheck = u8"Iba na zemy";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"Hladkosť";
		AimbotText.BoneList = u8"Kosť";
		AimbotText.Tip = u8"Aimbot nebude fungovať pokiaľ je menu otvorené";

		// Glow
		GlowText.FeatureName = u8" Žiarenie";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Štýl";
		RadarText.CustomCheck = u8"Vlastné";
		RadarText.CrossLine = u8"Kríž";
		RadarText.SizeSlider = u8"Velkosť bodky";
		RadarText.ProportionSlider = u8"Proporcia";
		RadarText.RangeSlider = u8"Rozsah";
		RadarText.AlphaSlider = u8"Prehliadnosť pozadia okna";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Tlačítko";
		TriggerText.Toggle = u8"Vždy aktívne";
		TriggerText.DelaySlider = u8"Oneskorenie výstrelu";
		TriggerText.FakeShotSlider = u8"Trvanie výstrelu";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Crosshair";
		CrosshairsText.PresetList = u8"Predvoľby";
		CrosshairsText.ColorEditor = u8"Farba crosshairu";
		CrosshairsText.Dot = u8"Stredová bodka";
		CrosshairsText.DotSizeSlider = u8"Velkosť bodky";
		CrosshairsText.Outline = u8"Obrys";
		CrosshairsText.Crossline = u8"Kríž";
		CrosshairsText.hLengthSlider = u8"Horizontálna dĺžka";
		CrosshairsText.vLengthSilder = u8"Vertikálna dĺžka";
		CrosshairsText.GapSlider = u8"Medzera";
		CrosshairsText.ThicknessSlider = u8"Hrubosť";
		CrosshairsText.tStyle = u8"T štýl";
		CrosshairsText.Circle = u8"Kruh";
		CrosshairsText.RadiusSlider = u8"Velkosť Kruhu";
		CrosshairsText.TargetCheck = u8"Zameriavanie Crosshairu";
		CrosshairsText.TeamCheck = u8"Kontrola tímu";

		// Misc
		MiscText.FeatureName = u8" Ostatné";
		MiscText.ThemeList = u8"Téma";
		MiscText.StyleList = u8"Štýl";
		MiscText.HeadshotLine = u8"Čiara strely do hlavy";
		MiscText.SpecCheck = u8"Cheat keď si divák";
		MiscText.NoFlash = u8"Žiadny flash";
		MiscText.HitSound = u8"Zvuk udretia";
		MiscText.bmbTimer = u8"Časovač bomby";
		MiscText.SpecList = u8"List divákov";
		MiscText.Bhop = u8"Automatické skákanie";
		MiscText.Watermark = u8"Vodný znak";
		MiscText.CheatList = u8"List cheatov";
		MiscText.TeamCheck = u8"Kontrola tímu";
		MiscText.AntiRecord = u8"Bypass OBS";

		MiscText.LanguageList = u8"Jazyk";

		// Config Menu
		ConfigText.FeatureName = u8" Nastavenie";
		ConfigText.Load = u8"Načítať vybraté";
		ConfigText.Save = u8"Uložiť vybraté";
		ConfigText.Delete = u8"Vymazať vybraté";
		ConfigText.Reset = u8"Obnoviť vybraté";
		ConfigText.Create = u8"Vytvoriť nastavenie";
		ConfigText.OpenFolder = u8"Otvoriť priečinok";
		ConfigText.SeparateLine = u8"Uložiť nastavenie";

		// Readme Menu
		ReadMeText.FeatureName = u8" Prečítaj ma";
		ReadMeText.LastUpdate = u8"Posledná aktulizácia: ";
		ReadMeText.SourceButton = u8" Zdrojový Kód";
		ReadMeText.DiscordButton = u8" Pripoj sa na Discord";
		ReadMeText.OffsetsTitle = u8"Offsety:";
	}

	// Translated by @CowNow
	inline void SimplifiedChinese()
	{
		Global.SwitchButton = u8"启用功能";
		Global.FeatureSettings = u8"详细设置";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"方框";
		ESPtext.BoxRounding = u8"圆角化";
		ESPtext.FilledBox = u8"填充方框";
		ESPtext.FilledAlpha = u8"填充透明度";
		ESPtext.Skeleton = u8"骨骼";
		ESPtext.HeadBox = u8"头部方框";
		ESPtext.EyeRay = u8"视线朝向";
		ESPtext.HealthBar = u8"生命栏";
		ESPtext.Weapon = u8"武器";
		ESPtext.Distance = u8"距离";
		ESPtext.PlayerName = u8"玩家名";
		ESPtext.SnapLine = u8"射线";
		ESPtext.LinePosList = u8"射线位置";
		ESPtext.VisCheck = u8"可视检查";
		ESPtext.Preview = u8"效果预览";
		ESPtext.CollapseHead = u8"性感设置";
		ESPtext.Penis = u8"显示牛子";
		ESPtext.PenisLength = u8"牛子长度";
		ESPtext.PenisSize = u8"牛子粗细";
		ESPtext.MultiColor = u8"渐变色";
		ESPtext.MultiColTip = u8"仅在圆角度为0时显示.";

		// Aimbot
		AimbotText.FeatureName = u8" 瞄准辅助";
		AimbotText.HotKeyList = u8"热键";
		AimbotText.Toggle = u8"热键切换模式";
		AimbotText.DrawFov = u8"显示范围";
		AimbotText.VisCheck = u8"仅可见目标";
		AimbotText.JumpCheck = u8"仅在地面上";
		AimbotText.FovSlider = u8"FOV";
		AimbotText.SmoothSlider = u8"平滑度";
		AimbotText.BoneList = u8"瞄准部位";
		AimbotText.Tip = u8"此功能在菜单打开时不会工作";

		// Glow
		GlowText.FeatureName = u8" 发光";

		// Radar
		RadarText.FeatureName = u8" 外部雷达";
		RadarText.StyleList = u8"雷达样式";
		RadarText.CustomCheck = u8"自定义设置";
		RadarText.CrossLine = u8"十字线";
		RadarText.SizeSlider = u8"标记大小";
		RadarText.ProportionSlider = u8"缩放比例";
		RadarText.RangeSlider = u8"范围";
		RadarText.AlphaSlider = u8"窗口透明度";

		// Triggerbot
		TriggerText.FeatureName = u8" 自动扳机";
		TriggerText.HotKeyList = u8"热键";
		TriggerText.Toggle = u8"保持激活";
		TriggerText.DelaySlider = u8"延迟射击";
		TriggerText.FakeShotSlider = u8"射击持续时间";

		// Crosshairs
		CrosshairsText.FeatureName = u8" 外部准星";
		CrosshairsText.PresetList = u8"预设";
		CrosshairsText.ColorEditor = u8"准星颜色";
		CrosshairsText.Dot = u8"中心点";
		CrosshairsText.DotSizeSlider = u8"中心点大小";
		CrosshairsText.Outline = u8"轮廓线";
		CrosshairsText.Crossline = u8"十字线";
		CrosshairsText.hLengthSlider = u8"水平长度";
		CrosshairsText.vLengthSilder = u8"垂直长度";
		CrosshairsText.GapSlider = u8"间隙";
		CrosshairsText.ThicknessSlider = u8"粗细";
		CrosshairsText.tStyle = u8"T形准星";
		CrosshairsText.Circle = u8"圆环";
		CrosshairsText.RadiusSlider = u8"圆环半径";
		CrosshairsText.TargetCheck = u8"瞄准变色";
		CrosshairsText.TeamCheck = u8"队伍检查";

		// Misc
		MiscText.FeatureName = u8" 杂项功能";
		MiscText.ThemeList = u8"主题配色";
		MiscText.StyleList = u8"窗口样式";
		MiscText.HeadshotLine = u8"爆头线";
		MiscText.SpecCheck = u8"旁观者保持运行";
		MiscText.NoFlash = u8"无视闪光弹";
		MiscText.HitSound = u8"命中音效";
		MiscText.bmbTimer = u8"C4计时器";
		MiscText.SpecList = u8"旁观者列表";
		MiscText.Bhop = u8"连跳";
		MiscText.Watermark = u8"水印浮窗";
		MiscText.CheatList = u8"功能列表";
		MiscText.TeamCheck = u8"队伍检查";
		MiscText.AntiRecord = u8"直播模式";
		MiscText.LanguageList = u8"语言";

		// Config Menu
		ConfigText.FeatureName = u8" 参数配置";
		ConfigText.Load = u8"加载选中";
		ConfigText.Save = u8"保存选中";
		ConfigText.Delete = u8"删除选中";
		ConfigText.Reset = u8"重置配置";
		ConfigText.Create = u8"创建配置";
		ConfigText.OpenFolder = u8"打开文件夹";
		ConfigText.SeparateLine = u8"新建配置";

		// Readme Menu
		ReadMeText.FeatureName = u8" 其他信息";
		ReadMeText.LastUpdate = u8"最后更新: ";
		ReadMeText.SourceButton = u8" 开源代码";
		ReadMeText.DiscordButton = u8" 加入Discord";
		ReadMeText.OffsetsTitle = u8"相关基址: ";
	}


	// Translated by @Yashing
	inline void French()
	{
		Global.SwitchButton = u8"Enable";
		Global.FeatureSettings = u8"Paramètres";

		// ESP
		ESPtext.FeatureName = u8" BOITE";
		ESPtext.Box = u8"Boite";
		ESPtext.BoxRounding = u8"Tour de boite";
		ESPtext.FilledBox = u8"Remplissage de boite";
		ESPtext.FilledAlpha = u8"Remplissage de boite Alpha";
		ESPtext.Skeleton = u8"Squelette";
		ESPtext.HeadBox = u8"Boite de tête";
		ESPtext.EyeRay = u8"Regarde des yeux";
		ESPtext.HealthBar = u8"Barre de vie";
		ESPtext.Weapon = u8"Arme";
		ESPtext.Distance = u8"Distance";
		ESPtext.PlayerName = u8"Nom";
		ESPtext.SnapLine = u8"Line d'allé";
		ESPtext.LinePosList = u8"Position des lignes";
		ESPtext.VisCheck = u8"Vérification visible";
		ESPtext.Preview = u8"Fenêtre de prevision de boite";
		ESPtext.CollapseHead = u8"SexyBoite";
		ESPtext.Penis = u8"MontréPénis";
		ESPtext.PenisLength = u8"Longueur";
		ESPtext.PenisSize = u8"Taille";
		ESPtext.MultiColor = u8"Multi-couleurs";
		ESPtext.MultiColTip = u8"Ne fonctionne que si la boîte a des coins non arrondis.";

		// Aimbot
		AimbotText.FeatureName = u8" Visée automatique";
		AimbotText.HotKeyList = u8"Clef";
		AimbotText.Toggle = u8"Rester activé";
		AimbotText.DrawFov = u8"Déssiner la vue";
		AimbotText.VisCheck = u8"Visible uniquement";
		AimbotText.JumpCheck = u8"Au sol uniquement";
		AimbotText.FovSlider = u8"Visée";
		AimbotText.SmoothSlider = u8"Vitesse";
		AimbotText.BoneList = u8"Os";
		AimbotText.Tip = u8"La visée automatique ne fonctionne pas avec la fenetre ouverte";

		// Glow
		GlowText.FeatureName = u8" Brillance";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Personnalisation";
		RadarText.CrossLine = u8"Ligne ccroisée";
		RadarText.SizeSlider = u8"Taille des points";
		RadarText.ProportionSlider = u8"Proportion";
		RadarText.RangeSlider = u8"Rang";
		RadarText.AlphaSlider = u8"Arrière plan windows";

		// Triggerbot
		TriggerText.FeatureName = u8" Tir a vue";
		TriggerText.HotKeyList = u8"Raccourci clavier";
		TriggerText.Toggle = u8"Toujours actif";
		TriggerText.DelaySlider = u8"Délai de tir";
		TriggerText.FakeShotSlider = u8"Durée du tir";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Viseur personnalisé";
		CrosshairsText.PresetList = u8"Sauvegarde";
		CrosshairsText.ColorEditor = u8"Couleur du viseur";
		CrosshairsText.Dot = u8"Point central";
		CrosshairsText.DotSizeSlider = u8"Taille du point";
		CrosshairsText.Outline = u8"Contour";
		CrosshairsText.Crossline = u8"Ligne croisées";
		CrosshairsText.hLengthSlider = u8"Taille horizontale";
		CrosshairsText.vLengthSilder = u8"Taille";
		CrosshairsText.GapSlider = u8"Ecart";
		CrosshairsText.ThicknessSlider = u8"Epaisseur";
		CrosshairsText.tStyle = u8"Style du T";
		CrosshairsText.Circle = u8"Cercle";
		CrosshairsText.RadiusSlider = u8"Rayon du cercle";
		CrosshairsText.TargetCheck = u8"Cibler la réticule";
		CrosshairsText.TeamCheck = u8"Vérification de l'équipe";

		// Misc
		MiscText.FeatureName = u8" Divers";
		MiscText.ThemeList = u8"Theme";
		MiscText.StyleList = u8"Style";
		MiscText.HeadshotLine = u8"Lignes de tirs a la tête";
		MiscText.SpecCheck = u8"Listes3";
		MiscText.NoFlash = u8"Pas d'effet flash";
		MiscText.HitSound = u8"Bruit de touches";
		MiscText.bmbTimer = u8"Temp de la bombe";
		MiscText.SpecList = u8"Liste des spectateurs";
		MiscText.Bhop = u8"Sauts en continues";
		MiscText.Watermark = u8"Afficher FPS";
		MiscText.CheatList = u8"Lsite des triches";
		MiscText.TeamCheck = u8"Vérifications d'équipe";
		MiscText.AntiRecord = u8"Invisible OBS Studio";

		MiscText.LanguageList = u8"Langue";

		// Config Menu
		ConfigText.FeatureName = u8" Configuration(s)";
		ConfigText.Load = u8"Charger la séléction";
		ConfigText.Save = u8"Sauvegarder la séléction";
		ConfigText.Delete = u8"Supprimer la séléction";
		ConfigText.Reset = u8"Reintiallisé les configuration";
		ConfigText.Create = u8"Crée une configuration";
		ConfigText.OpenFolder = u8"Ouvrir fichier";
		ConfigText.SeparateLine = u8"Sauvegarder la configuration";

		// Readme Menu
		ReadMeText.FeatureName = u8" Lis moi";
		ReadMeText.LastUpdate = u8"Dèrnière MAJ: ";
		ReadMeText.SourceButton = u8" Code de la source";
		ReadMeText.DiscordButton = u8" Rejoindre DISCORD";
		ReadMeText.OffsetsTitle = u8"Compensations:";
	}

	// Translated by @TRINITRAMIN
	inline void Korean()
	{
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

		// Glow
		GlowText.FeatureName = u8" 불타는 듯한 빛깔";

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

		// Readme Menu
		ReadMeText.FeatureName = u8" 주의상황 ";
		ReadMeText.LastUpdate = u8"마지막 업데이트: ";
		ReadMeText.SourceButton = u8" 소스 코드";
		ReadMeText.DiscordButton = u8" 디스코드에 참여하세요";
		ReadMeText.OffsetsTitle = u8"오프셋:";
	}

	// Written by ! FleX#0001 / flex0001
	inline void Turkish()
	{
		Global.SwitchButton = u8"Etkinleştir";
		Global.FeatureSettings = u8"Ayarlar";

		// ESP
		ESPtext.FeatureName = u8" Görüş Hilesi";
		ESPtext.Box = u8"Çerçeve";
		ESPtext.BoxRounding = u8"Köşe Yuvarlaklığı";
		ESPtext.FilledBox = u8"Dolu Çerçeve";
		ESPtext.FilledAlpha = u8"Dolu Çerçeve Saydamlığı";
		ESPtext.Skeleton = u8"İskelet";
		ESPtext.HeadBox = u8"Kafa Göstergesi";
		ESPtext.EyeRay = u8"Göz Işını";
		ESPtext.HealthBar = u8"Can Göstergesi";
		ESPtext.Weapon = u8"Silah Göstergesi";
		ESPtext.Distance = u8"Mesafe Göstergesi";
		ESPtext.PlayerName = u8"İsim Göstergesi";
		ESPtext.SnapLine = u8"Kilitli Çizgi";
		ESPtext.LinePosList = u8"Çizgi Pozisyonu";
		ESPtext.VisCheck = u8"Görünürlük Kontrolü";
		ESPtext.Preview = u8"Önizleme Penceresi";
		ESPtext.CollapseHead = u8"Küçük Baş";
		ESPtext.Penis = u8"Sik Göstergesi";
		ESPtext.PenisLength = u8"Uzunluk";
		ESPtext.PenisSize = u8"Boyut";
		ESPtext.MultiColor = u8"Çoklu Renk";
		ESPtext.MultiColTip = u8"Sadece köşeleri yuvarlatılmamış çerçevelerde çalışır.";

		// Aimbot
		AimbotText.FeatureName = u8" Hedef Bot";
		AimbotText.HotKeyList = u8"Tuş";
		AimbotText.Toggle = u8"Aç/Kapa Modu";
		AimbotText.DrawFov = u8"Görüş Açısı Çizgisi";
		AimbotText.VisCheck = u8"Sadece Görünürler";
		AimbotText.JumpCheck = u8"Sadece Yerdeyken";
		AimbotText.FovSlider = u8"Görüş Açısı";
		AimbotText.SmoothSlider = u8"Hızlandırma";
		AimbotText.BoneList = u8"Hedef Nokta";
		AimbotText.Tip = u8"Menü açıkken Hedefleme Bot'u çalışmaz";

		// Glow
		GlowText.FeatureName = u8" Glow";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Stil";
		RadarText.CustomCheck = u8"Özel";
		RadarText.CrossLine = u8"Çizgi";
		RadarText.SizeSlider = u8"Nokta Boyutu";
		RadarText.ProportionSlider = u8"Oran";
		RadarText.RangeSlider = u8"Görüş Menzili";
		RadarText.AlphaSlider = u8"Pencere Arka Planı Saydamlığı";

		// Triggerbot
		TriggerText.FeatureName = u8" Tetikbot";
		TriggerText.HotKeyList = u8"Kısayol Tuşu";
		TriggerText.Toggle = u8"Her Zaman Aktif";
		TriggerText.DelaySlider = u8"Atış Gecikmesi";
		TriggerText.FakeShotSlider = u8"Atış Süresi";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Nişangah";
		CrosshairsText.PresetList = u8"Ön ayarlar";
		CrosshairsText.ColorEditor = u8"Nişangah Rengi";
		CrosshairsText.Dot = u8"Merkez Nokta";
		CrosshairsText.DotSizeSlider = u8"Nokta Boyutu";
		CrosshairsText.Outline = u8"Çizgi";
		CrosshairsText.Crossline = u8"Çapraz Çizgi";
		CrosshairsText.hLengthSlider = u8"Yatay Uzunluk";
		CrosshairsText.vLengthSilder = u8"Dikey Uzunluk";
		CrosshairsText.GapSlider = u8"Boşluk";
		CrosshairsText.ThicknessSlider = u8"Kalınlık";
		CrosshairsText.tStyle = u8"T Stili";
		CrosshairsText.Circle = u8"Çember";
		CrosshairsText.RadiusSlider = u8"Çember Yarıçapı";
		CrosshairsText.TargetCheck = u8"Hedefleme Nişangahı";
		CrosshairsText.TeamCheck = u8"Takım Arkadaşlarını Öne Çıkar";

		// Misc
		MiscText.FeatureName = u8" Genel";
		MiscText.ThemeList = u8"Tema";
		MiscText.StyleList = u8"Stil";
		MiscText.HeadshotLine = u8"Baş Atışı Çizgisi";
		MiscText.SpecCheck = u8"Hile Seçenekleri";
		MiscText.NoFlash = u8"Flash Yok";
		MiscText.HitSound = u8"İsabet Sesi";
		MiscText.bmbTimer = u8"Bomba Zamanlayıcı";
		MiscText.SpecList = u8"İzleme Listesi";
		MiscText.Bhop = u8"Tavşan Zıplama";
		MiscText.Watermark = u8"Filigran";
		MiscText.CheatList = u8"Hile Listesi";
		MiscText.TeamCheck = u8"Takım Kontrol";
		MiscText.AntiRecord = u8"Kayıt Engelleyici";

		MiscText.LanguageList = u8"Dil";

		// Config Menu
		ConfigText.FeatureName = u8" Konfigürasyon";
		ConfigText.Load = u8"Seçili Olanı Yükle";
		ConfigText.Save = u8"Seçili Olanı Kaydet";
		ConfigText.Delete = u8"Seçili Olanı Sil";
		ConfigText.Reset = u8"Konfigürasyonu Sıfırla";
		ConfigText.Create = u8"Konfigürasyon Oluştur";
		ConfigText.OpenFolder = u8"Klasörü Aç";
		ConfigText.SeparateLine = u8"Konfigürasyonu Kaydet";

		// Readme Menu
		ReadMeText.FeatureName = u8" Beni Oku";
		ReadMeText.LastUpdate = u8"Son Güncelleme: ";
		ReadMeText.SourceButton = u8"Açık Kaynak";
		ReadMeText.DiscordButton = u8"Discord'a Katıl";
		ReadMeText.OffsetsTitle = u8"Ofsetler:";
	}

	inline void Hungarian()
	{
		Global.SwitchButton = u8"Kitiltási eszköz";
		Global.FeatureSettings = u8"Beállítások";

		// ESP
		ESPtext.FeatureName = u8"Extraszenzoros észlelés";
		ESPtext.Box = u8"Doboz";
		ESPtext.BoxRounding = u8"Doboz kerekítés";
		ESPtext.FilledBox = u8"Megtöltött doboz";
		ESPtext.FilledAlpha = u8"Megtöltött Alfa doboz";
		ESPtext.Skeleton = u8"Csontváz";
		ESPtext.HeadBox = u8"Fej doboz";
		ESPtext.EyeRay = u8"Szem sáv";
		ESPtext.HealthBar = u8"Egészségügyi bár";
		ESPtext.Weapon = u8"Deshi oncsel meg";
		ESPtext.Distance = u8"Bombayt a koktelba";
		ESPtext.PlayerName = u8"Név";
		ESPtext.SnapLine = u8"Csattan vonal";
		ESPtext.LinePosList = u8"Vonal pozicio";
		ESPtext.VisCheck = u8"Látható ellenőrzés";
		ESPtext.Preview = u8"Előnézet ablak";
		ESPtext.CollapseHead = u8"Szexi Extraszenzoros észlelés";
		ESPtext.Penis = u8"Pénisz megjelenítése";
		ESPtext.PenisLength = u8"Pénisz hossza";
		ESPtext.PenisSize = u8"Pénisz mérete";

		// Aimbot
		AimbotText.FeatureName = u8" Célzozzon robot";
		AimbotText.HotKeyList = u8"Kulcs";
		AimbotText.Toggle = u8"Mód váltása";
		AimbotText.DrawFov = u8"Rajzolja meg a látómezőt";
		AimbotText.VisCheck = u8"Csak látható";
		AimbotText.JumpCheck = u8"Csak a földön";
		AimbotText.FovSlider = u8"Látómegő";
		AimbotText.SmoothSlider = u8"Kurva anyád";
		AimbotText.BoneList = u8"Buta zsidó";
		AimbotText.Tip = u8"A Célozzon Robot nem fog működni, amíg a menü meg van nyitva, te fasz";

		// Glow
		GlowText.FeatureName = u8" Központi Hírszerző Ügynökség Mód";

		// Radar
		RadarText.FeatureName = u8" Madár";
		RadarText.StyleList = u8"Kipattantba van stiló";
		RadarText.CustomCheck = u8"Egyedi";
		RadarText.CrossLine = u8"Kereszt vonale";
		RadarText.SizeSlider = u8"Pontméret";
		RadarText.ProportionSlider = u8"Hányad";
		RadarText.RangeSlider = u8"Sor";
		RadarText.AlphaSlider = u8"Ablak háttér Alpha";

		// Triggerbot
		TriggerText.FeatureName = u8" Néger robot";
		TriggerText.HotKeyList = u8"Forró kulcs";
		TriggerText.Toggle = u8"Mindig aktív";
		TriggerText.DelaySlider = u8"Lövés késleltetése";
		TriggerText.FakeShotSlider = u8"Lövés időtartama";

		// Crosshairs
		CrosshairsText.FeatureName = u8" Szájkeresztek";
		CrosshairsText.PresetList = u8"Előbeállítások";
		CrosshairsText.ColorEditor = u8"Célkereszt színe";
		CrosshairsText.Dot = u8"Közép pont";
		CrosshairsText.DotSizeSlider = u8"Pont méret";
		CrosshairsText.Outline = u8"Vázlat";
		CrosshairsText.Crossline = u8"kereszt vonal";
		CrosshairsText.hLengthSlider = u8"Vízszintes hossz";
		CrosshairsText.vLengthSilder = u8"Függőleges hossz";
		CrosshairsText.GapSlider = u8"Rés";
		CrosshairsText.ThicknessSlider = u8"Vastagság mérés";
		CrosshairsText.tStyle = u8"Pattintott stiló";
		CrosshairsText.Circle = u8"Kör";
		CrosshairsText.RadiusSlider = u8"Kör sugara";
		CrosshairsText.TargetCheck = u8"Cél kereszt";
		CrosshairsText.TeamCheck = u8"Csapatellenőrzés";

		// Misc
		MiscText.FeatureName = u8" Különféle";
		MiscText.ThemeList = u8"Téma";
		MiscText.StyleList = u8"Pattintott stiló";
		MiscText.HeadshotLine = u8"Fej lövés vonal";
		MiscText.SpecCheck = u8"Csalás a Nézésben";
		MiscText.NoFlash = u8"Nincs villanás";
		MiscText.HitSound = u8"Ütés hang";
		MiscText.bmbTimer = u8"Bomba időzítő";
		MiscText.SpecList = u8"Specifikációs lista";
		MiscText.Bhop = u8"Nyuszi ugrás";
		MiscText.Watermark = u8"Vízpiac";
		MiscText.CheatList = u8"Csal lista";
		MiscText.TeamCheck = u8"Csapat fene";
		MiscText.AntiRecord = u8"Kerülje meg az OBS-t";

		MiscText.LanguageList = u8"Beszélt nyelv";

		// Config Menu
		ConfigText.FeatureName = u8" Konfigurációt";
		ConfigText.Load = u8"Betöltés a kiválaszt";
		ConfigText.Save = u8"Kijelöltek mentése";
		ConfigText.Delete = u8"Apád halott";
		ConfigText.Reset = u8"Anyád baszom";
		ConfigText.Create = u8"Te meg buzi";
		ConfigText.OpenFolder = u8"Nyitott mappa";
		ConfigText.SeparateLine = u8"Konfiguráció mentése";

		// Readme Menu
		ReadMeText.FeatureName = u8" Olvassa el te geci";
		ReadMeText.LastUpdate = u8"Utoljára lemásolva: ";
		ReadMeText.SourceButton = u8" Szar kód";
		ReadMeText.DiscordButton = u8" Ne lépj be a Discordba";
		ReadMeText.OffsetsTitle = u8"Ellentételezések:";
	}

	inline void ChangeLang(int LangIndex)
	{
		switch (LangIndex)
		{
		case 0:
			English();
			break;
		case 1:
			Danish();
			break;
		case 2:
			German();
			break;
		case 3:
			Polish();
			break;
		case 4:
			Portuguese();
			break;
		case 5:
			Russian();
			break;
		case 6:
			SimplifiedChinese();
			break;
		case 7:
			Slovak();
			break;
		case 8:
			French();
			break;
		//case 9:
			//Korean();
			//break;
		case 9:
			Turkish();
			break;
		case 10:
			Hungarian();
			break;
		default:
			English();
			break;
		}
	}
}