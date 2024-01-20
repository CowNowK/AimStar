#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Turkish()
	{
		Global.Author = u8"!FleX#0001";
		Global.Date = u8"2023/12/03";

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
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" Beni Oku";
		ReadMeText.LastUpdate = u8"Son Güncelleme: ";
		ReadMeText.SourceButton = u8"Açık Kaynak";
		ReadMeText.DiscordButton = u8"Discord'a Katıl";
		ReadMeText.OffsetsTitle = u8"Ofsetler:";
	}
}