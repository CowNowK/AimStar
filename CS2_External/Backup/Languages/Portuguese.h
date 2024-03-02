#pragma once
#include "..\Language.h"
namespace Lang
{
	inline void Portuguese()
	{
		Global.Author = u8"vsantos1";
		Global.Date = u8"2023/11/29";

		Global.SwitchButton = u8"Ativar";
		Global.FeatureSettings = u8"Definições";

		// ESP
		ESPtext.FeatureName = u8" ESP";
		ESPtext.Box = u8"Caixa";
		ESPtext.BoxRounding = u8"Borda da Caixa";
		ESPtext.FilledBox = u8"Preenchimento da Caixa";
		ESPtext.FilledAlpha = u8"Preenchimento da Caixa Alfa";
		ESPtext.Skeleton = u8"Esqueleto";
		ESPtext.HeadBox = u8"Caixa na Cabeça";
		ESPtext.EyeRay = u8"Mirando em";
		ESPtext.HealthBar = u8"Barra de Vida";
		ESPtext.Weapon = u8"Arma";
		ESPtext.Distance = u8"Distancia";
		ESPtext.PlayerName = u8"Nome";
		ESPtext.SnapLine = u8"Linha de Distancia";
		ESPtext.LinePosList = u8"Linha de Posição";
		ESPtext.VisCheck = u8"Apenas Visiveis";
		ESPtext.Preview = u8"Janela de Pré-Visualização";
		ESPtext.CollapseHead = u8"ESP Sensual";
		ESPtext.Penis = u8"Mostrar Penis";
		ESPtext.PenisLength = u8"Comprimento";
		ESPtext.PenisSize = u8"Tamanho";
		ESPtext.MultiColor = u8"Multicolorido";
		ESPtext.MultiColTip = u8"Só funciona quando a caixa tem cantos não arredondados.";
		ESPtext.Outline = u8"Contoro";
		ESPtext.BoxType = u8"Tipo de Caixa";
		ESPtext.HealthNum = u8"Numero da vida";
		ESPtext.Ammo = u8"Munição";

		ESPtext.BoxType_Normal = u8"Normal";
		ESPtext.BoxType_Edge = u8"Dinâmico";
		ESPtext.BoxType_Corner = u8"Canto";
		ESPtext.LinePos_1 = u8"Topo";
		ESPtext.LinePos_2 = u8"Centro";
		ESPtext.LinePos_3 = u8"De baixo";

		// Aimbot
		AimbotText.FeatureName = u8" Aimbot";
		AimbotText.HotKeyList = u8"Tecla";
		AimbotText.Toggle = u8"Modo Alternado";
		AimbotText.DrawFov = u8"Campo de Visão ";
		AimbotText.VisCheck = u8"Apenas Visiveis";
		AimbotText.JumpCheck = u8"Apenas no Chão";
		AimbotText.FovSlider = u8"Campo de Visão";
		AimbotText.SmoothSlider = u8"Suavidade";
		AimbotText.BoneList = u8"Alvo";
		AimbotText.Tip = u8"Aimbot não funcionará com menu aberto ";

		// Radar
		RadarText.FeatureName = u8" Radar";
		RadarText.StyleList = u8"Estilo";
		RadarText.CustomCheck = u8"Customizado";
		RadarText.CrossLine = u8"Linha cruzada";
		RadarText.SizeSlider = u8"Tamanho do Ponto";
		RadarText.ProportionSlider = u8"Proporção";
		RadarText.RangeSlider = u8"Alcance";
		RadarText.AlphaSlider = u8"Fundo da Janela em Alfa";

		// Triggerbot
		TriggerText.FeatureName = u8" Triggerbot";
		TriggerText.HotKeyList = u8"Tecla";
		TriggerText.Toggle = u8"Sempre ativo";
		TriggerText.DelaySlider = u8"Tempo de Disparo";
		TriggerText.FakeShotSlider = u8"Duração de Disparo";

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
		CrosshairsText.TargetCheck = u8"Verificação do Alvo";
		CrosshairsText.TeamCheck = u8"Apenas Inimigos";

		// Misc
		MiscText.FeatureName = u8" Diversos";
		MiscText.ThemeList = u8"Tema";
		MiscText.StyleList = u8"Estilo";
		MiscText.HeadshotLine = u8"Linha de Headshot";
		MiscText.SpecCheck = u8"Funcionar no Espectador";
		MiscText.NoFlash = u8"Remover Flashbang";
		MiscText.HitSound = u8"Som de Acerto";
		MiscText.bmbTimer = u8"Tempo da C4 ";
		MiscText.SpecList = u8"Lista de Espectadores";
		MiscText.Bhop = u8"Bunny hop";
		MiscText.Watermark = u8"Marca dagua";
		MiscText.CheatList = u8"Lista de Trapacas Ativas";
		MiscText.TeamCheck = u8"Apenas Inimigos";
		MiscText.AntiRecord = u8"Anti Captura de tela";

		MiscText.LanguageList = u8"Linguagem";

		// Config Menu
		ConfigText.FeatureName = u8" Configuração";
		ConfigText.Load = u8"Carregar Selecionada";
		ConfigText.Save = u8"Salvar Selecionada";
		ConfigText.Delete = u8"Deletar Selecionada";
		ConfigText.Reset = u8"Reseta Configuracao";
		ConfigText.Create = u8"Criar Configuracao";
		ConfigText.OpenFolder = u8"Abrir Pasta";
		ConfigText.SeparateLine = u8"Salvar Configuração";
		ConfigText.AuthorName = u8"Nome do Autor";
		ConfigText.ConfigName = u8"Nome da Configuração";

		// Readme Menu
		ReadMeText.FeatureName = u8" Leia Me";
		ReadMeText.LastUpdate = u8"Ultima Atualização: ";
		ReadMeText.SourceButton = u8" Codigo Fonte";
		ReadMeText.DiscordButton = u8" Entre no Discord";
		ReadMeText.OffsetsTitle = u8"Offsets:";
	}
}