#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Greek()
	{
		Global.Date = u8"2024/02/25";
		Global.Author = u8"Κανένα";

		Global.SwitchButton = u8"Ενεργοποίηση";
		Global.FeatureSettings = u8"Ρυθμίσεις";

		// ESP
		ESPtext.Toggle = u8"Εναλλαγή";
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Πλαίσιο";
		ESPtext.BoxRounding = u8"Στρογγυλοποίηση Κουτιού: ";
		ESPtext.FilledBox = u8"Γέμισμα Κουτιού";
		ESPtext.FilledAlpha = u8"Γέμισμα Κουτιού Άλφα";
		ESPtext.Skeleton = u8"Σκελετός";
		ESPtext.HeadBox = u8"Κουτί Κεφαλής";
		ESPtext.EyeRay = u8"Ακτίνα Ματιού";
		ESPtext.HealthBar = u8"Μπάρα ζωής";
		ESPtext.Weapon = u8"Όπλο";
		ESPtext.Distance = u8"Απόσταση";
		ESPtext.PlayerName = u8"Όνομα";
		ESPtext.SnapLine = u8"Snap Γραμμή";
		ESPtext.LinePosList = u8"Θέση Γραμμής: ";
		ESPtext.VisCheck = u8"Έλεγχος ορατότητας";
		ESPtext.Preview = u8"Παράθυρο προεπισκόπησης";
		ESPtext.CollapseHead = u8"SexyESP";
		ESPtext.Penis = u8"Show Penis";
		ESPtext.PenisLength = u8"Μήκος";
		ESPtext.PenisSize = u8"Μέγεθος";
		ESPtext.MultiColor = u8"Πολύχρωμο";
		ESPtext.MultiColTip = u8"Λειτουργεί μόνο όταν το κουτί έχει μη στρογγυλεμένες γωνίες";
		ESPtext.Outline = u8"Περίγραμμα";
		ESPtext.BoxType = u8"Τύπος Κουτιού:";
		ESPtext.HealthNum = u8"Αριθμός ζωής";
		ESPtext.Ammo = u8"Πυρομαχικά";
		ESPtext.ScopedESP = u8"Εμφάνιση Στόχων";
		ESPtext.ShowArmorBar = u8"Μπάρα Πανοπλίας";
		ESPtext.ArmorNum = u8"Αριθμός Πανοπλίας";
		ESPtext.RenderDistance = u8"Μέγιστη Απόσταση Απόδοσης: ";

		ESPtext.BoxType_Normal = u8"Κανονικό";
		ESPtext.BoxType_Edge = u8"Δυναμικό";
		ESPtext.BoxType_Corner = u8"Γωνία";
		ESPtext.LinePos_1 = u8"Κορυφή";
		ESPtext.LinePos_2 = u8"Κέντρο";
		ESPtext.LinePos_3 = u8"Κάτω μέρος";

		// Aimbot
		AimbotText.Enable = u8"Ενεργοποίηση Aimbot";
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Hotkey   ";
		AimbotText.Toggle = u8"Λειτουργία Εναλλαγής";
		AimbotText.DrawFov = u8"Σχεδίαση FOV";
		AimbotText.VisCheck = u8"Ορατός μόνο";
		AimbotText.JumpCheck = u8"Μόνο στο έδαφος";
		AimbotText.FovSlider = u8"FOV: ";
		AimbotText.FovMinSlider = u8"MinFOV: ";
		AimbotText.SmoothSlider = u8"Ομαλότητα: ";
		AimbotText.BoneList = u8"Hitbox";
		AimbotText.Tip = u8"Το Aimbot δεν θα λειτουργήσει όσο είναι ανοιχτό το menu";
		AimbotText.ScopeOnly = u8"Στόχος μόνο";
		AimbotText.AimLock = u8"Κλείδωμα Στόχου";
		AimbotText.AutoShot = u8"Αυτόματος Πυροβολισμός";
		AimbotText.BulletSlider = u8"Σφαίρα Έναρξης: ";
		AimbotText.IgnoreFlash = u8"Αγνόοηση Φλας";

		// RCS
		RCStext.Toggle = u8"Έλεγχος Ανάκρουσης";
		RCStext.Yaw = u8"Μήκος: ";
		RCStext.Pitch = u8"Ύψος: ";

		// Radar
		RadarText.Toggle = u8"Εμφάνιση Ραντάρ";
		RadarText.FeatureName = u8" Ραντάρ";
		RadarText.StyleList = u8"Στυλ";
		RadarText.CustomCheck = u8"Προσαρμογή";
		RadarText.CrossLine = u8"Σταυρωτές Γραμμές";
		RadarText.SizeSlider = u8"Μέγεθος Σημείων:";
		RadarText.ProportionSlider = u8"Αναλογία:";
		RadarText.RangeSlider = u8"Εύρος:";
		RadarText.AlphaSlider = u8"Φόντο παραθύρου Άλφα:";

		// Triggerbot
		TriggerText.Enable = u8"Ενεργοποίηση Triggerbot";
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Hotkey   ";
		TriggerText.Toggle = u8"Πάντα ενεργοποιημένο";
		TriggerText.ScopeOnly = u8"Στόχος μόνο";
		TriggerText.DelaySlider = u8"Καθυστέρηση Πυροβολισμού:";
		TriggerText.FakeShotSlider = u8"Διάρκεια Πυροβολισμού:";

		// Crosshairs
		CrosshairsText.Toggle = u8"Εμφάνιση σημείων στόχου";
		CrosshairsText.FeatureName = u8" Σημεία στόχου";
		CrosshairsText.PresetList = u8"Προεπιλογές";
		CrosshairsText.ColorEditor = u8"Χρώματα σημείων στόχου";
		CrosshairsText.Dot = u8"Κεντρική κουκκίδα";
		CrosshairsText.DotSizeSlider = u8"Μέγεθος κουκκίδας:";
		CrosshairsText.Outline = u8"Περίγραμμα";
		CrosshairsText.Crossline = u8"Σταυρωτές γραμμές";
		CrosshairsText.hLengthSlider = u8"Οριζόντιο Μήκος:";
		CrosshairsText.vLengthSilder = u8"Κάθετο Μήκος:";
		CrosshairsText.GapSlider = u8"Κενό:";
		CrosshairsText.ThicknessSlider = u8"Πάχος:";
		CrosshairsText.tStyle = u8"Στυλ Τ";
		CrosshairsText.Circle = u8"Κύκλος";
		CrosshairsText.RadiusSlider = u8"Ακτίνα Κύκλου:";
		CrosshairsText.TargetCheck = u8"Σημεία Στόχου στην Στόχευση";
		CrosshairsText.TeamCheck = u8"Έλεγχος Ομάδας";

		// Misc
		MiscText.FeatureName = u8" Διάφορα";
		MiscText.ThemeList = u8"Θέμα     ";
		MiscText.StyleList = u8"Στυλ";
		MiscText.HeadshotLine = u8"Γραμμή Κεφαλιού";
		MiscText.SpecCheck = u8"Λειτουργία cheat όσο θεατής";
		MiscText.NoFlash = u8"Όχι φλας";
		MiscText.FastStop = u8"Γρήγορο Σταμάτημα";
		MiscText.HitSound = u8"Ήχος Χτυπήματος";
		MiscText.bmbTimer = u8"Χρονόμετρο Βόμβας";
		MiscText.SpecList = u8"Λίστα θεατών";
		MiscText.Bhop = u8"Αυτόματο πήδημα";
		MiscText.Watermark = u8"Σήμα";
		MiscText.CheatList = u8"Λίστα Cheat";
		MiscText.TeamCheck = u8"Έλεγχος Ομάδας";
		MiscText.AntiRecord = u8"Κρυμμένο από Καταγραφή";
		MiscText.MoneyService = u8"Χρηματικές Υπηρεσίες";
		MiscText.ShowCashSpent = u8"Εμφάνιση δαπανημένων μετρητών";
		MiscText.EnemySensor = u8"Αίσθητηρας Εχθρού";
		MiscText.RadarHack = u8"Hack Ραντάρ";
		MiscText.FastStop = u8"Γρήγορο Σταμάτημα";
		MiscText.VisCheckDisable = u8"Έλεγχος Ορατότητας Απενεργοποιημένο";
		MiscText.NoSmoke = u8"Όχι Καπνός";
		MiscText.SmokeColor = u8"Χρώμα καπνού";
		MiscText.fovchanger = u8"Αλλαγή FOV: ";
		MiscText.ForceScope = u8"Αναγκαστικός Στόχος";
		MiscText.FlashImmunity = u8"Ανοσία Φλας: ";
		MiscText.NightMode = u8"Νυχτερινή Λειτουργία ";
		MiscText.Alpha = u8"Άλφα: ";

		MiscText.FakeDuck = u8"Ψεύτικη Πάπια";

		MiscText.LanguageList = u8"Γλώσσα";

		// Config Menu
		ConfigText.FeatureName = u8"Φορτωτής Διαμορφόσεων";
		ConfigText.MyConfigs = u8"Λίστα Διαμορφώσεων";
		ConfigText.Load = u8"Φόρτωση Επιλεγμένου";
		ConfigText.Save = u8"Αποθήκευση Επιλεγμένου";
		ConfigText.Delete = u8"Διαγραφή Επιλεγμένου";
		ConfigText.Reset = u8"Επαναφορά Διαμορφώσεων";
		ConfigText.Create = u8"Δημιουργία";
		ConfigText.OpenFolder = u8"Άνοιγμα Φακέλου";
		ConfigText.SeparateLine = u8"Δημιουργία διαμορφώσεων";
		ConfigText.AuthorName = u8"Όνομα Κατόχου";
		ConfigText.ConfigName = u8"Όνομα Διαμορφώσεων";

		ConfigText.SafeMode = u8"Λειτουργία Ασφάλειας";
		ConfigText.SafeModeHoveredTip = u8"Απενεργοποιήστε όλες τις μη ασφαλές λειτουργίες που τροποποιούν την μνήμη του παιχνιδιού";

		// Readme Menu
		ReadMeText.FeatureName = u8" README";
		ReadMeText.LastUpdate = u8"Τελευταία Ενημέρωση: ";
		ReadMeText.SourceButton = u8"Κώδικας";
		ReadMeText.DiscordButton = u8"Εγγραφείτε στο Discord";
		ReadMeText.OffsetsTitle = u8"Όφσετ:";
	}
}