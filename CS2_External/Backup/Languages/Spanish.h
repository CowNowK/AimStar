#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Spanish()
	{
		Global.Author = u8"zsui2354";
		Global.Date = u8"2024/01/21";

		Global.SwitchButton = u8"Activar";	
		Global.FeatureSettings = u8"Ajustes detallados";

		// ESP
		ESPtext.Toggle = u8"interruptor principal";
		ESPtext.FeatureName = u8" ESP";	
		ESPtext.Box = u8"cajas";
		ESPtext.BoxRounding = u8"redondeo:";
		ESPtext.FilledBox = u8"Rellene la casilla";
		ESPtext.FilledAlpha = u8"Transparencia de relleno";
		ESPtext.Skeleton = u8"esqueleto";
		ESPtext.HeadBox = u8"cuadro de cabecera";
		ESPtext.EyeRay = u8"a la altura de los ojos";
		ESPtext.HealthBar = u8"barra de vida";
		ESPtext.Weapon = u8"armas";
		ESPtext.Distance = u8"distancia";
		ESPtext.PlayerName = u8"Nombre del jugador";
		ESPtext.SnapLine = u8"rayos";
		ESPtext.LinePosList = u8"Posición del rayo:";
		ESPtext.VisCheck = u8"inspección visual";
		ESPtext.Preview = u8"Vista previa del efecto";
		ESPtext.CollapseHead = u8"Ajustes sexys";
		ESPtext.Penis = u8"Mostrar pene";
		ESPtext.PenisLength = u8"longitud del pene";
		ESPtext.PenisSize = u8"tamaño del pene";
		ESPtext.MultiColor = u8"color degradado";
		ESPtext.MultiColTip = u8"Sólo se muestra cuando el ángulo del círculo es 0";
		ESPtext.Outline = u8"silueta";
		ESPtext.BoxType = u8"Estilo caja:";
		ESPtext.HealthNum = u8"números vitales";	
		ESPtext.Ammo = u8"portapapeles";

		ESPtext.BoxType_Normal = u8"normalidad";	
		ESPtext.BoxType_Edge = u8"dinámica (ciencia)";	
		ESPtext.BoxType_Corner = u8"los aleros que las cuatro esquinas de un edificio";	
		ESPtext.LinePos_1 = u8"parte superior";
		ESPtext.LinePos_2 = u8"centro";
		ESPtext.LinePos_3 = u8"fondos";

		// Aimbot
		AimbotText.Enable = u8"Aimbot";
		AimbotText.FeatureName = u8" Ayuda a la puntería";
		AimbotText.HotKeyList = u8"Atajos de teclado";
		AimbotText.Toggle = u8"modo de conmutación";
		AimbotText.DrawFov = u8"Rango de visualización";
		AimbotText.VisCheck = u8"Sólo objetivos visibles";
		AimbotText.JumpCheck = u8"Sólo en el suelo";
		AimbotText.FovSlider = u8"FOV: ";
		AimbotText.SmoothSlider = u8"suavidad: ";
		AimbotText.BoneList = u8"zona objetivo  ";
		AimbotText.Tip = u8"Esta función no funciona cuando el menú está abierto";

		// Radar
		RadarText.Toggle = u8"Radar";
		RadarText.FeatureName = u8" Radar externo";
		RadarText.StyleList = u8"Estilo Radar";
		RadarText.CustomCheck = u8"Ajustes personalizados";
		RadarText.CrossLine = u8"retículos";
		RadarText.SizeSlider = u8"Tamaño del marcador:";
		RadarText.ProportionSlider = u8"índice de zoom:";
		RadarText.RangeSlider = u8"reino:";
		RadarText.AlphaSlider = u8"Transparencia de las ventanas:";

		// Triggerbot
		TriggerText.Enable = u8"Triggerbot";
		TriggerText.FeatureName = u8" disparador automático";
		TriggerText.HotKeyList = u8"tecla de acceso rápido";
		TriggerText.Toggle = u8"mantener la activación";
		TriggerText.DelaySlider = u8"acción diferida:";
		TriggerText.FakeShotSlider = u8"Duración del incendio:";

		// Crosshairs
		CrosshairsText.Toggle = u8"Mostrar colimador";
		CrosshairsText.FeatureName = u8" Colimador externo";
		CrosshairsText.PresetList = u8"predisponer";
		CrosshairsText.ColorEditor = u8"el color de la mira delantera (armas de fuego)";
		CrosshairsText.Dot = u8"punto focal";
		CrosshairsText.DotSizeSlider = u8"Tamaño del punto central:";
		CrosshairsText.Outline = u8"silueta";
		CrosshairsText.Crossline = u8"retículos";
		CrosshairsText.hLengthSlider = u8"longitud horizontal:";
		CrosshairsText.vLengthSilder = u8"longitud vertical:";
		CrosshairsText.GapSlider = u8"liquidación:";
		CrosshairsText.ThicknessSlider = u8"espesor (calibre):";
		CrosshairsText.tStyle = u8"Colimador en forma de T";
		CrosshairsText.Circle = u8"rotonda";
		CrosshairsText.RadiusSlider = u8"radio de un círculo:";
		CrosshairsText.TargetCheck = u8"apuntar a una decoloración";
		CrosshairsText.TeamCheck = u8"Inspecciones en equipo";

		// Misc
		MiscText.FeatureName = u8"Funciones varias";
		MiscText.ThemeList = u8"Colores de la interfaz";
		MiscText.StyleList = u8"Estilo ventana";
		MiscText.HeadshotLine = u8"head-banging (argot)";
		MiscText.SpecCheck = u8"El visor permanece activo";
		MiscText.NoFlash = u8"Ignora los flashes.";
		MiscText.FastStop = u8"bloqueo automático";
		MiscText.HitSound = u8"Efecto de sonido de golpe";
		MiscText.bmbTimer = u8"Cuenta atrás C4";
		MiscText.SpecList = u8"Lista de espectadores";
		MiscText.Bhop = u8"saltar";
		MiscText.Watermark = u8"ventana de marca de agua";
		MiscText.CheatList = u8"Lista de funciones";
		MiscText.TeamCheck = u8"Inspecciones en equipo";
		MiscText.AntiRecord = u8"Modo Live";
		MiscText.LanguageList = u8"multilingüismo";
		MiscText.MoneyService = u8"Asistente de saldo";
		MiscText.ShowCashSpent = u8"Visualización del consumo";
		MiscText.EnemySensor = u8"Resplandor enemigo";
		MiscText.RadarHack = u8"penetración del radar";
		MiscText.FastStop = u8"Parada de emergencia rápida  ";
		MiscText.VisCheckDisable = u8"Esta característica interfiere con la inspección visual";

		MiscText.FakeDuck = u8"agacharse";

		MiscText.LanguageList = u8"Selección de idioma  ";

		// Config Menu
		ConfigText.FeatureName = u8" Configuración de parámetros";
		ConfigText.MyConfigs = u8"Mi configuración";
		ConfigText.Load = u8"Carga seleccionada  ";
		ConfigText.Save = u8"Guardar seleccionados  ";
		ConfigText.Delete = u8"Borrar seleccionados  ";
		ConfigText.Reset = u8"Restablecer configuración  ";
		ConfigText.Create = u8"Crear una configuración  ";
		ConfigText.OpenFolder = u8"Abrir la carpeta";
		ConfigText.SeparateLine = u8"Nueva configuración  ";
		ConfigText.AuthorName = u8"autor";
		ConfigText.ConfigName = u8"nombre de configuración  ";

		// Readme Menu
		ReadMeText.FeatureName = u8" Información adicional";
		ReadMeText.LastUpdate = u8"última actualización: ";
		ReadMeText.SourceButton = u8"código abierto";
		ReadMeText.DiscordButton = u8"Únete a Discord";
		ReadMeText.OffsetsTitle = u8"Sitios asociados: ";
	}
}