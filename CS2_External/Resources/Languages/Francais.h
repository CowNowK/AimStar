#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void French()
	{
		Global.Author = u8"Yashing";
		Global.Date = u8"2023/11/25";

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
}