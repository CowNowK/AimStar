#pragma once
#include "..\Language.h"

namespace Lang 
{
	inline void Russian()
	{
		Global.Author = "gScream";
		Global.Date = u8"2023/11/19";

		Global.SwitchButton = u8"Включить";
		Global.FeatureSettings = u8"Настройки";

		// ESP
		ESPtext.Toggle = u8"Toggle";
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
		AimbotText.Enable = u8"Enable Aimbot";
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

		// Radar
		RadarText.Toggle = u8"Show Radar";
		RadarText.FeatureName = u8" Радар";
		RadarText.StyleList = u8"Стиль";
		RadarText.CustomCheck = u8"Кастомный";
		RadarText.CrossLine = u8"Перекрестье";
		RadarText.SizeSlider = u8"Размер точки";
		RadarText.ProportionSlider = u8"Пропорции";
		RadarText.RangeSlider = u8"Радиус";
		RadarText.AlphaSlider = u8"Прозрачность радара";

		// Triggerbot
		TriggerText.Enable = u8"Enable Triggerbot";
		TriggerText.FeatureName = u8" Триггербот";
		TriggerText.HotKeyList = u8"Горячая клавиша";
		TriggerText.Toggle = u8"Всегда активен";
		TriggerText.DelaySlider = u8"Задержка перед выстрелом";
		TriggerText.FakeShotSlider = u8"Продолжительность выстрела";

		// Crosshairs
		CrosshairsText.Toggle = u8"Show Crosshairs";
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
		MiscText.MoneyService = u8"Money Services";
		MiscText.ShowCashSpent = u8"Show Cash Spent";
		MiscText.EnemySensor = u8"Enemy Sensor";
		MiscText.RadarHack = u8"Radar Hack";
		MiscText.FastStop = u8"Fast Stop";
		MiscText.VisCheckDisable = u8"Visible Check DISABLED";
		MiscText.NoSmoke = u8"NoSmoke";

		MiscText.FakeDuck = u8"Fake Duck";

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
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" ОТКРОЙ";
		ReadMeText.LastUpdate = u8"Последнее обновление: ";
		ReadMeText.SourceButton = u8" Исходный код";
		ReadMeText.DiscordButton = u8" Присоединиться к дискорд серверу";
		ReadMeText.OffsetsTitle = u8"Оффсеты:";
	}
}