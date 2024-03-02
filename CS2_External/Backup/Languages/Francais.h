#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void French()
	{
		Global.Author = u8"Yashing";
		Global.Date = u8"27/01/2024";

		Global.SwitchButton = u8"Active";
		Global.FeatureSettings = u8"Parametres";

		// ESP
		ESPtext.Toggle = u8"basculer";
		ESPtext.FeatureName = u8" Hack des boxs";
		ESPtext.Box = u8"portrait";
		ESPtext.BoxRounding = u8"Boite arrondie: ";
		ESPtext.FilledBox = u8"remplissage de Boite";
		ESPtext.FilledAlpha = u8"Remplissage de boite Alpha";
		ESPtext.Skeleton = u8"Squelette";
		ESPtext.HeadBox = u8"Boite de tete";
		ESPtext.EyeRay = u8"ligne des yeux";
		ESPtext.HealthBar = u8"Barre de vie";
		ESPtext.Weapon = u8"armes";
		ESPtext.Distance = u8"Distances";
		ESPtext.PlayerName = u8"Nom";
		ESPtext.SnapLine = u8"Ligne";
		ESPtext.LinePosList = u8"Psoition des lignes : ";
		ESPtext.VisCheck = u8"Verification visible";
		ESPtext.Preview = u8"Fenetre de prevision";
		ESPtext.CollapseHead = u8"Sexy Mode";
		ESPtext.Penis = u8"Montrer penis";
		ESPtext.PenisLength = u8"longueur";
		ESPtext.PenisSize = u8"taille";
		ESPtext.MultiColor = u8"Multi couleur";
		ESPtext.MultiColTip = u8"Fonctionne que quand les boites sont pas arrondies.";
		ESPtext.Outline = u8"Contour";
		ESPtext.BoxType = u8"Type de boite:";
		ESPtext.HealthNum = u8"Nombre de vie";
		ESPtext.Ammo = u8"Munitions";

		ESPtext.BoxType_Normal = u8"Normale";
		ESPtext.BoxType_Edge = u8"Dynamique";
		ESPtext.BoxType_Corner = u8"Coin";
		ESPtext.LinePos_1 = u8"Haut";
		ESPtext.LinePos_2 = u8"Millieu";
		ESPtext.LinePos_3 = u8"Bas";

		// Aimbot
		AimbotText.Enable = u8"Activer Visée auto";
		AimbotText.FeatureName = u8" Visée auto";
		AimbotText.HotKeyList = u8"Touche d'activation   ";
		AimbotText.Toggle = u8"Basculler mode";
		AimbotText.DrawFov = u8"Dessiner la VUE";
		AimbotText.VisCheck = u8" Uniquement visible";
		AimbotText.JumpCheck = u8"Sur le sol seulement";
		AimbotText.FovSlider = u8"VUE: ";
		AimbotText.SmoothSlider = u8"Vitesse: ";
		AimbotText.BoneList = u8"Os       ";
		AimbotText.Tip = u8"Visée auto ne fonctionne pas avec le menu ouvert.";

		// Radar
		RadarText.Toggle = u8"Montrer radar";
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Style";
		RadarText.CustomCheck = u8"Personnalisation";
		RadarText.CrossLine = u8" Line croisées";
		RadarText.SizeSlider = u8"Taille des points:";
		RadarText.ProportionSlider = u8"Proportion:";
		RadarText.RangeSlider = u8"Grade:";
		RadarText.AlphaSlider = u8"Fenetre d'arriere-plan Alpha:";

		// Triggerbot
		TriggerText.Enable = u8"Activer tire-auto";
		TriggerText.FeatureName = u8" Tire-auto";
		TriggerText.HotKeyList = u8"Touche d'activation   ";
		TriggerText.Toggle = u8"Toujours activer";
		TriggerText.DelaySlider = u8"Delaie du tir:";
		TriggerText.FakeShotSlider = u8"Temp du tir:";

		// Crosshairs
		CrosshairsText.Toggle = u8"Montrer viseur";
		CrosshairsText.FeatureName = u8" Viseur";
		CrosshairsText.PresetList = u8"Configs";
		CrosshairsText.ColorEditor = u8"Couleur du viseur";
		CrosshairsText.Dot = u8" Cercle au centre";
		CrosshairsText.DotSizeSlider = u8"Taille du cercle:";
		CrosshairsText.Outline = u8"Contour";
		CrosshairsText.Crossline = u8"Ligne transversale";
		CrosshairsText.hLengthSlider = u8"Longeur horizontal :";
		CrosshairsText.vLengthSilder = u8"Longeur vertical :";
		CrosshairsText.GapSlider = u8"Ecart:";
		CrosshairsText.ThicknessSlider = u8"Epaisseur:";
		CrosshairsText.tStyle = u8"T Style";
		CrosshairsText.Circle = u8"Cercle";
		CrosshairsText.RadiusSlider = u8"Circle Radius:";
		CrosshairsText.TargetCheck = u8"Targeting Crosshairs";
		CrosshairsText.TeamCheck = u8"TeamCheck";

		// Misc
		MiscText.FeatureName = u8" divers";
		MiscText.ThemeList = u8"Theme     ";
		MiscText.StyleList = u8"Style";
		MiscText.HeadshotLine = u8"Ligne de la tete";
		MiscText.SpecCheck = u8"cheats en spec";
		MiscText.NoFlash = u8"Pas de flash";
		MiscText.FastStop = u8"Stop rapidement";
		MiscText.HitSound = u8"Son au touché";
		MiscText.bmbTimer = u8"Temp de la bombe";
		MiscText.SpecList = u8"listes des specs";
		MiscText.Bhop = u8"Saut en continue";
		MiscText.Watermark = u8"filigrane";
		MiscText.CheatList = u8"Liste des triches";
		MiscText.TeamCheck = u8"Verification d'équipe";
		MiscText.AntiRecord = u8"Anti vidéo";
		MiscText.MoneyService = u8"Services d'argent";
		MiscText.ShowCashSpent = u8"montrer l'argent dépenser";
		MiscText.EnemySensor = u8"Detection d'énemies";
		MiscText.RadarHack = u8"Triche du radar";
		MiscText.FastStop = u8"Stop rapidement";
		MiscText.VisCheckDisable = u8"Visible uniquement desactivé";

		MiscText.FakeDuck = u8"Faux canard";

		MiscText.LanguageList = u8"Langue";

		// Config Menu
		ConfigText.FeatureName = u8" Configuration(s)";
		ConfigText.MyConfigs = u8"liste des configs";
		ConfigText.Load = u8"Charger la séléction";
		ConfigText.Save = u8"Sauvegarder la séléction";
		ConfigText.Delete = u8"Supprimer la séléction";
		ConfigText.Reset = u8"Reintiallisé les configuration";
		ConfigText.Create = u8"Crée une configuration";
		ConfigText.OpenFolder = u8"Ouvrir fichier";
		ConfigText.SeparateLine = u8"Sauvegarder la configuration";
		ConfigText.AuthorName = u8"Author Name";
		ConfigText.ConfigName = u8"Config Name";

		// Readme Menu
		ReadMeText.FeatureName = u8" Lis moi";
		ReadMeText.LastUpdate = u8"Dèrnière MAJ: ";
		ReadMeText.SourceButton = u8" Code de la source";
		ReadMeText.DiscordButton = u8" Rejoindre DISCORD";
		ReadMeText.OffsetsTitle = u8"Compensations:";
	}
}