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
}